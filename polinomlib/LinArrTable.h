#pragma once
#include "basetable.h"
template <typename TKey, typename TValue>
class LinArrTable :public basetable<TKey, TValue> {
private:
    int count = 0;
    size_t curInd = 0;
    struct Tab {
        TKey key;
        TValue value;
    };
    vector<Tab> data{};
public:
    int GetDataCount()   const {
        return data.size();
    }

    bool IsEmpty()        const {
        if (count == 0) return true; else return false;
    }

    bool IsFull() const override {
        return count == MaxSize;
    }
    // �������� ������
    TValue* Find(TKey key)override {
        for (auto& val : data)
            if (val.key == key)
                return &val.value;
        return nullptr;
    };
    void Insert(TKey key, TValue value) override {
        if (Find(key))
            return;
        Tab tmp = { key, value };
        data.push_back(tmp); 
        count++;
    };
    void Delete(TKey key) override {
        for (size_t i = 0; i < data.size(); i++)
            if (data[i].key == key) {
                data[i] = data[data.size() - 1];
                data.pop_back();
                return;
            }
    };
    // ���������
    int Reset() override { // ���������� �� ������ ������
        curInd = 0;
        return curInd;
    };
    int IsTabEnded() const override { // ������� ���������?
        return curInd >= data.size();
    };
    int GoNext() override {// ������� � ��������� ������
        curInd++;
        return curInd;
    }
    // ������
    TKey GetKey() const override { return data[curInd].key; }
    TValue GetValuePtr() const override { return data[curInd].value; }
};
