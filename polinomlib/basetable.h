#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <locale>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define MaxSize 100
template <typename TKey, typename TValue>
class basetable
{
    size_t count = 0;
public:
    // �������������� ������
    int GetDataCount()   const {
        return count;
    } 
    bool IsEmpty()        const {
        return count == 0;
    }

    virtual bool IsFull() const = 0;                       // ���������?
    // �������� ������
    virtual TValue* Find(TKey key) = 0;         // ����� ������
    virtual void Insert(TKey key, TValue* value) = 0; // ��������
    virtual void Delete(TKey key) = 0;         // ������� ������
    // ���������
    virtual int Reset() = 0; // ���������� �� ������ ������
    virtual int IsTabEnded() const = 0; // ������� ���������?
    virtual int GoNext() = 0; // ������� � ��������� ������
    // (=1 ����� ���������� GoNext ��� ��������� ������ �������)
    // ������
    virtual TKey GetKey() const = 0;
    virtual TValue* GetValuePtr() const = 0;
    // ������ �������
    friend ostream& operator<<(ostream& os, basetable& tab)
    {
        os << "=======================================================" << endl;
        os << "Table printing" << endl;
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << " Key: " << tab.GetKey() << " Val: " << *(tab.GetValuePtr()) << endl;
        }
        os << "=======================================================" << endl;
        return os;
    }
};

