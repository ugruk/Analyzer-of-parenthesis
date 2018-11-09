### Program module that supposed to analyze sequence of characters and finds out its state in terms of closed parenthesis.
.exe file is exist just to show example: how do those function works with understandable output.
Checker.h is a header file which contains class "Checker"


This class have 2 public functions.
##### 1. check_str - allows you to analyze sequence of characters.

	int check_str(string &s, int &pos, stack<char> &brackets)

You need to create and give to it variables like pos and brackets(stack) so it can work with them. It allows you to get all information you need about sequence's state in terms of closed parenthesis after the function will completed. So, if it returns 0, it means that the sequence is OK. But if it returns other number, "pos" will show where is the first mistake(in brackets) and stack "brackets" will show you state at this point.

##### 2. check_pos - allows you to analyze current state at arbitrary point.

	int check_pos(string &s, int pos, stack<char> &brackets)

Works the same way, but the "pos" is now a number of position, where you want to indicate current state. Also when the function will be completed, you will be able to see all brackets remaining in the stack.

##### EXIT CODES (/errors):

0 - function is completed.
1 - The stack you are giving to check_str is not empty.
2 - The end of file is reached (~).
3 - You are trying to close the bracket, which isn't the last opened.
4 - You are trying to close the bracket, which wasn't opened yet.
5 - You didn't closed all opened brackets.
6 - Checking of the state of the sequence at arbitrary point is finished. The end of the sequence was before this point.

P.S. Functions are sensitive to spaces. So, you can separate strings by space, but if you need to check string which includes spaces, you need to clear them first.
