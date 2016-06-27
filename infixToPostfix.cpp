œ#include <iostream>
#include <cctype>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

bool isLowerOrEqual(char first, char second);

void infixToPostfix(const string& infix, string& postfix)
{
  stack<char> operatorStack;
  postfix = "";
  for(int i = 0; i < infix.size(); i++)
  {
    if(isdigit(infix[i]))
        postfix += infix[i];

    if(infix[i] == '(')
        operatorStack.push(infix[i]);

    if(infix[i] == ')')
    {
      while(operatorStack.top() != '(')
      {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.pop();
    }

    if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
    {
      while(!operatorStack.empty() && operatorStack.top()!='(' && isLowerOrEqual(infix[i], operatorStack.top()))
      {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.push(infix[i]);
    }
  }

    while(!operatorStack.empty())
    {
      postfix += operatorStack.top();
      operatorStack.pop();
    }
}


bool isLowerOrEqual(char first, char second)
{
  if(first == '*' || first == '/')
  {
    if(second == '*' || second == '/')
        return true;
    return false;
  }

  return true;
}
/*
int main()
{
  string infix = "6 - (3 + 5)/ 2 + 1";
  string postfix;
  infixToPostfix(infix, postfix);
  for(int i = 0; i < postfix.size(); i++)
      cout << postfix[i];

  cout << endl;
}*/
