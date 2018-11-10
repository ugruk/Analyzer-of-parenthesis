#include "stdafx.h"
#include "string"
#include <iostream>
#include <stack>
#include "checker.h"

using namespace std;
void newst(stack<char> &brackets) {
	while (!brackets.empty()) { brackets.pop(); }
}
int main()
{
	Checker ch;
	stack<char> brackets;
	string a;
	int pos;
	
	while (getline(cin, a)) {
		if (cin.bad()) { exit(2); }
		if (!cin.eof()) {
			cout << ch.check_str(a, pos, brackets);
			newst(brackets);
		}
		else { exit(3); }
	}
	exit(1);
	system("pause");
    return 0;
}

