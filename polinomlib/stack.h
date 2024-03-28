//#ifndef H_STACK
//#define H_STACK
#pragma once

#include <iostream>

using namespace std;
template <class T> class TStack {
protected:
	size_t size;
	int top;
	T* pMem;
public:
	TStack(size_t _size = 1) : top(-1), size(_size), pMem(new T[size]){
		if (size <= 0)
			throw - 1;
	}
	TStack(TStack& st) {
		this->size = st.size;
		this->pMem = new T[size];
		this->top = st.top;
		for (int i = 0; i < size; i++)
			this->pMem[i] = st.pMem[i];
	}
	~TStack() {
		if(this->pMem != nullptr)
			delete[] this->pMem;
	}


	bool IsFull() {
		return (top == size - 1);
	}
	bool IsEmpty() {
		return top == -1;
	}


	void Push(T val) {
		if (IsFull())
			throw - 1;
		pMem[++top] = val;
	}
	T Pop() {
		if (IsEmpty())
			throw - 1;
		return pMem[top--];
	}
	T Top() {
		if (IsEmpty())
			throw - 1;
		return pMem[top];
	}

	int GetSize() {
		return this->size;
	}
	int GetTopInd() {
		if (IsEmpty())
			throw - 1;
		return this->top;
	}

	TStack& operator=(const TStack<T>& st) {
		if (this == &st)
			return this;

		if (this->size != st.size) {
			if (this->pMem != nullptr) delete[] this->pMem;
			this->size = st.size;
			this->pMem = new T[size];
		}

		std::copy(st.pMem, st.pMem + st.size, this->pMem);
		return *this;
	}

	void print() {
		for (int i = top; i >= 0; i--) {
			if(i == top)
				cout << pMem[i] << "    <-top" << "\n";
			else
				cout << pMem[i] << "\n";
		}
			
	}

	friend istream& operator>>(istream& istr, TStack& st) {
		for (size_t i = 0; i < st.top; i++)
			istr >> st.pMem[i];
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, const TStack& st)
	{
		for (size_t i = st.top; i >= 0; i--) {
			if (i == st.top)
				ostr << st.pMem[i] << "    <-top" << "\n";
			else
				ostr << st.pMem[i] << "\n";
			
		}
		return ostr;
	}
};
//#endif // !H_STACK