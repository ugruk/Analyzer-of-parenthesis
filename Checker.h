#include "stdafx.h"
#include "string"
#include <iostream>
#include <stack>

using namespace std;

class Checker {
public:
	int check_str(string &s, int &pos, stack<char> &brackets) {
		pos = 0;
		if (!brackets.empty())
			return 1;
		for (auto c : s) {
			pos++;
			if (isOpen(c))
				brackets.push(c);
			else if (!brackets.empty() && isPair(brackets.top(), c))
				brackets.pop();
			else if (!brackets.empty() && !isPair(brackets.top(), c) && isClosed(c))
				return 3;
			else if (brackets.empty() && isClosed(c))
				return 4;
		}
		if (!brackets.empty())
			return 5;
		return 0;
	}
	int check_pos(string &s, int pos, stack<char> &brackets) {
		int pos_ = 0;
		if (!brackets.empty()) {
			return 1;
		}
		for (auto c : s) {
			pos_++;
			if (pos_ > pos)
				return 0;
			else if (isOpen(c))
				brackets.push(c);
			else if (!brackets.empty() && isPair(brackets.top(), c))
				brackets.pop();
			else if (!brackets.empty() && !isPair(brackets.top(), c) && isClosed(c) || brackets.empty() && isClosed(c))
			{
				brackets.push(c);
			}
		}
		if (pos_ < pos) {
			return 7;
		}
		return 6;
	}
private:
	bool isOpen(char c)
	{
		return c == '(' || c == '[' || c == '{';
	}
	bool isClosed(char c)
	{
		return c == ')' || c == ']' || c == '}';
	}
	bool isPair(char a, char b)
	{
		return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
	}
};