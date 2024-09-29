#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include <unistd.h>
using namespace std;

class ShuntingYard
{
public:
    string infixToPostfix(string expression);
    LinkedList<string> split(string s, string delimiter);
private:
    int getPriority(string op);
    bool isOperator(string s);
};

int ShuntingYard::getPriority(string op)
{
    if (op == "(")
        return 1;
    if (op == "+" || op == "-")
        return 2;
    if (op == "*" || op == "/")
        return 3;
    if (op == "sin" || op == "cos")
        return 4;
    if (op == "^")
        return 5;
    return 0;
}

bool ShuntingYard::isOperator(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")"
            || s == "^" || s == "sin" || s == "cos")
    { return true; }

    return false;
}

LinkedList<string> ShuntingYard::split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    LinkedList<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.append(token);
    }

    res.append(s.substr (pos_start));
    return res;
}

string ShuntingYard::infixToPostfix(string infixStr)
{
    Stack<string> operators;
      string postfix = "";
      LinkedList<string> infix = split(infixStr, " ");
      for (int i = 0; i < infix.getSize(); ++i)
      {
        if (!(isOperator(infix[i])))
        {
          postfix += infix[i];
          postfix += " ";
          cout << infix[i] << " - операнд, отправлен в строку" << endl;
          cout << "строка: " << postfix << " стэк: " ;
          operators.print();
          usleep(500000);
        }
        else if (infix[i] == "(")
        {
          operators.push(infix[i]);
          cout << infix[i] << " - открывающая скобка - помещается в стек" << endl;
          cout << "строка: " << postfix << " стэк: " ;
          operators.print();
          usleep(500000);
        }
        else if (infix[i] == ")")
        {
          while (!operators.isEmpty() && operators.top() != "(")
          {
            postfix += operators.top();
            postfix += " ";
            operators.pop();
          }
          if (!operators.isEmpty() && operators.top() == "(")
          {
            operators.pop();
          }
          cout << infix[i] << " - закрывающая скобка, в строку помещаются все операторы до откр. скобки" << endl;
          cout << "строка: " << postfix << " стэк: " ;
          operators.print();
          usleep(500000);
        }
        else
        {
          cout << infix[i] << " - оператор, помещается в стек" << endl;
          if (!((!operators.isEmpty() && getPriority(operators.top()) >= getPriority(infix[i]))))
          {
            operators.push(infix[i]);
            cout << "строка: " << postfix << " стэк: " ;
            operators.print();
            operators.pop();
            usleep(500000);
          }
          while (!operators.isEmpty() && getPriority(operators.top()) >= getPriority(infix[i]))
          {
            postfix += operators.top();
            postfix += " ";
            cout << operators.top() << " - оператор из стека отпр. в строку, приоритет " <<
              infix[i] << " ниже или равен приоритету " << operators.top() << endl;
            operators.pop();
            cout << "строка: " << postfix << " стэк: " ;
            operators.print();
            usleep(500000);
          }
          operators.push(infix[i]);
        }
      }
      while (!operators.isEmpty())
      {
        postfix += operators.top();
        postfix += " ";
        cout << operators.top() << " - оператор из стека отпр. в строку" << endl;
        operators.pop();
        cout << "строка: " << postfix << " стэк: " ;
        operators.print();
        usleep(500000);
      }
      return postfix;
}


#endif // SHUNTINGYARD_H
