#pragma once
#include "basetable.h"
template <typename TKey, typename TValue>
class ChainHashTable : public basetable<TKey, TValue>
{
private:
    struct Tab {
        TKey key;
        TValue value;

        Tab(TKey k, TValue v) : key(k), value(v) {}
    };

    vector<list<Tab>> data;
    int count; // ������� ���������� ���������

    // ��� ���������
    typedef typename std::list<Tab>::iterator ListIterator;
    size_t curBucket; // ������ �������� ������
    ListIterator curIterator; // �������� �������� �������� � ������

public:
    ChainHashTable() : count(0), curBucket(0) {
        data.resize(MaxSize);
        curIterator = data[curBucket].end();
    }

    bool IsFull() const override {
        
        return count == MaxSize * 10; // ��������� �����������
    }

    TValue* Find(TKey key) override {
        size_t index = hashFunction(key);
        auto& chain = data[index];
        auto it = std::find_if(chain.begin(), chain.end(), [&key](const Tab& item) {
            return item.key == key;
            });

        if (it != chain.end()) {
            return &(it->value);
        }
        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        if (IsFull()) {
            std::cout << "������� ���������." << std::endl;
            return;
        }
        size_t index = hashFunction(key);
        auto& chain = data[index];
        auto it = std::find_if(chain.begin(), chain.end(), [&key](const Tab& item) {
            return item.key == key;
            });

        if (it == chain.end()) {
            chain.emplace_back(key, value);
            count++;
        }
        else {
            // ������� � ����� ������ ��� ����������, ��������� ��������
            it->value = value;
        }
    }

    void Delete(TKey key) override {
        size_t index = hashFunction(key);
        auto& chain = data[index];
        auto prevSize = chain.size();
        chain.remove_if([&key](const Tab& item) {
            return item.key == key;
            });
        count -= prevSize - chain.size();
    }

    int Reset() override {
        for (size_t i = 0; i < MaxSize; ++i) {
            if (!data[i].empty()) {
                curBucket = i;
                curIterator = data[i].begin();
                return 0;
            }
        }
        return -1; // ���� ������� �����
    }

    int IsTabEnded() const override {
        if (curBucket >= MaxSize) return 1;
        if (curBucket < MaxSize - 1) return 0;
        return curIterator == data[curBucket].end();
    }

    int GoNext() override {
        if (curIterator != data[curBucket].end()) ++curIterator;
        while (curIterator == data[curBucket].end() && curBucket < MaxSize - 1) {
            ++curBucket;
            curIterator = data[curBucket].begin();
        }
        return IsTabEnded();
    }

    TKey GetKey() const override {
        if (curIterator != data[curBucket].end()) {
            return curIterator->key;
        }
        throw std::out_of_range("Current index is out of range");
    }

    TValue GetValuePtr() const override {
        if (curIterator != data[curBucket].end()) {
            return curIterator->value;
        }
        throw std::out_of_range("Current index is out of range");
    }

private:
    size_t hashFunction(TKey key) const {
        return std::hash<TKey>{}(key) % MaxSize;
    }
};

