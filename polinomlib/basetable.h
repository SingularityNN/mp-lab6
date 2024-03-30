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
    // информационные методы
    int GetDataCount()   const {
        return count;
    } 
    bool IsEmpty()        const {
        return count == 0;
    }

    virtual bool IsFull() const = 0;                       // заполнена?
    // основные методы
    virtual TValue* Find(TKey key) = 0;         // найти запись
    virtual void Insert(TKey key, TValue value) = 0; // вставить
    virtual void Delete(TKey key) = 0;         // удалить запись
    // навигация
    virtual int Reset(void) = 0; // установить на первую запись
    virtual int IsTabEnded(void) const = 0; // таблица завершена?
    virtual int GoNext(void) = 0; // переход к следующей записи
    // (=1 после применения GoNext для последней записи таблицы)
    // доступ
    virtual TKey GetKey(void) const = 0;
    virtual TValue GetValuePtr(void) const = 0;
    // Печать таблицы
    friend ostream& operator<<(ostream& os, basetable& tab)
    {
        cout << "____________________________" << endl;
        cout << "Table printing" << endl;
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << " Key: " << tab.GetKey() << " Val: " << tab.GetValuePtr() << endl;
        }
        os << "____________________________" << endl;
        return os;
    }
};

