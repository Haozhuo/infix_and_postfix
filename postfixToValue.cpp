#include <iostream>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

int postfixToValue(const string& postfix)
{
    stack<int> operandStack;

    for(int i = 0; i < postfix.size(); i++)
    {
        if(isdigit(postfix[i]))
        {
            int value = postfix[i] - '0';
            operandStack.push(value);
        }

        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result = 0;

            if(postfix[i] == '+')
                result = operand1 + operand2;

            if(postfix[i] == '-')
                result = operand1 - operand2;

            if(postfix[i] == '*')
                result = operand1 * operand2;

            if(postfix[i] == '/')
                result = operand1 / operand2;

            operandStack.push(result);
        }
    }

    return operandStack.top();
}

/*
int main()
{
    string postfix = "362/-1+";
    int a = postfixToValue(postfix);
    assert(a == 1);
    cout << "Passed" << endl;
}*/
