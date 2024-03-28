#pragma once
//#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "stack.h"

using namespace std;

class TArithmeticExpression {
private:
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, double> operands;
	/*static*/ map<char, int> priority;

	void Parse() {
		for (char c : infix) {
			if(c != ' ')
				lexems.push_back(c);
		}
	}

	void ToPostfix() {
		bool flag = false;
		Parse();
		TStack<char> st(20);
		char stackItem;

		for (char item : lexems) {

			switch (item) {

			case '(':
				st.Push(item);
				break;

			case ')':
				stackItem = st.Pop();
				while (stackItem != '(') {
					postfix += stackItem;
					stackItem = st.Pop();
				}
				break;

			case '+': case '-': case '*': case '/':
				flag = false;
				if (st.IsEmpty())
					st.Push(item);
				else {
					while (!st.IsEmpty()) {
						
						stackItem = st.Top();

						if (priority[item] <= priority[stackItem]) {
							postfix += stackItem;
							st.Pop();
						}
							
						else {
							st.Push(item);
							break;
						}
						if(st.IsEmpty()) flag = true; 
						
					}
					if(flag) st.Push(item);
				}
				break;

			default:
				operands.insert({ item, 0.0 });
				postfix += item;
			}//end of switch
		}//end of for

		while (!st.IsEmpty()) {
			stackItem = st.Pop();
			postfix += stackItem;
		}
	}

public:
	TArithmeticExpression(const string& _infix) {
		priority = { {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}, {')', 0}};
		infix = _infix;
		ToPostfix();
	}

	string GetInfix() const {
		return this->infix;
	}

	string GetPostfix() const {
		return this->postfix;
	}

	vector<char> GetOperands() const {
		vector<char> op;
		for (const auto& item : operands)
			op.push_back(item.first);
		return op;
	}

	double Calculate(const map<char, double>& values) {
		for (auto& val : values) {
			try {
				operands.at(val.first) = val.second;
			}
			catch(out_of_range &e){}
		}

		TStack<double> st(20);
		double leftOperand, rightOperand;
		for (char lexem : postfix) {
			switch (lexem)
			{
			case '+':
				rightOperand = st.Pop();
				leftOperand = st.Pop();
				st.Push(leftOperand + rightOperand);
				break;

			case '-':
				rightOperand = st.Pop();
				leftOperand = st.Pop();
				st.Push(leftOperand - rightOperand);
				break;

			case '*':
				rightOperand = st.Pop();
				leftOperand = st.Pop();
				st.Push(leftOperand * rightOperand);
				break;

			case '/':
				rightOperand = st.Pop();
				leftOperand = st.Pop();
				st.Push(leftOperand / rightOperand);
				break;

			default:
				st.Push(operands[lexem]);
				break;
			}
		}
		return st.Pop();
	}
};