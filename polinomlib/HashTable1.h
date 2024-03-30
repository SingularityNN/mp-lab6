#pragma once
#include "basetable.h"
template <typename TKey, typename TValue>
class HashTable1 : public basetable<TKey, TValue> 
{
private:
    struct Tab {
        TKey key;
        TValue value;
        bool isActive=false;
        Tab() : isActive(false) {}
        Tab(TKey k, TValue v) : key(k), value(v), isActive(true) {}
    };
    size_t curInd = 0;
    vector<Tab> data{};
    int count;

    size_t hashFunction(TKey key) const {
        return std::hash<TKey>{}(key) % MaxSize;
    }

public:
    HashTable1() : data(MaxSize), count(0) {}
    bool IsFull() const override {
        return count == MaxSize;
    }

    TValue* Find(TKey key) override {
        size_t index = hashFunction(key);
        size_t start = index;
        while (data[index].isActive && !(data[index].key == key)) {
            index = (index + 1) % MaxSize;
            if (index == start) return nullptr; // Прошли полный круг
        }
        if (data[index].isActive) return &data[index].value;
        else return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        if (IsFull()) {
            cout << "Таблица заполнена." << endl;
            return;
        }
        size_t index = hashFunction(key);
        while (data[index].isActive) {
            if (data[index].key == key) {
                // Элемент с таким ключом уже существует
                return;
            }
            index = (index + 1) % MaxSize; // Линейное опробование
        }
        data[index] = Tab(key, value);
        count++;
    }

    void Delete(TKey key) override {
        size_t index = hashFunction(key);
        size_t start = index;
        while (data[index].isActive && !(data[index].key == key)) {
            index = (index + 1) % MaxSize;
            if (index == start) return; // Прошли полный круг
        }
        if (data[index].isActive) {
            data[index].isActive = false; // Логическое удаление
            count--;
        }
    }

    int Reset() override {
        for (size_t i = 0; i < MaxSize; ++i) {
            if (data[i].isActive) {
                this->curInd = i;
                return i;
            }
        }
        return -1; // Если таблица пуста
    }

    int IsTabEnded() const override {
        return this->curInd >= MaxSize;
    }

    int GoNext() override {
        for (size_t i = this->curInd + 1; i < MaxSize; ++i) {
            if (data[i].isActive) {
                this->curInd = i;
                return i;
            }
        }
        this->curInd = MaxSize; // Достигли конца таблицы
        return MaxSize;
    }

    TKey GetKey() const override {
        if (this->curInd < MaxSize && data[this->curInd].isActive) {
            return data[this->curInd].key;
        }
        throw std::out_of_range("Current index is out of range");
    }

    TValue GetValuePtr() const override {
        if (this->curInd < MaxSize && data[this->curInd].isActive) {
            return data[this->curInd].value;
        }
        throw std::out_of_range("Current index is out of range");
    }
};

