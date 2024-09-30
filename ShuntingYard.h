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
private:
    LinkedList<string> split(string s, string delimiter);
    int getPriority(string op);
    bool isOperator(string s);
    bool isValidSym(string s);
    bool expressionIsValid(LinkedList<string> splitted);

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

bool ShuntingYard::isValidSym(string s)
{
    string allowedSyms = "0123456789";
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (allowedSyms.find(s[i]) == string::npos)
        {
            return false;
        }
    }
    return true;
}

bool ShuntingYard::expressionIsValid(LinkedList<string> splitted)
{
    for (int i = 0; i < splitted.getSize(); ++i)
    {
        if (!(isOperator(splitted[i])) && !(isValidSym(splitted[i])))
        {
            return false;
        }
    }
    return true;
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

      LinkedList<string> infix = split(infixStr, " ");

      if (!expressionIsValid(infix))
      {
          cout << "error: wrong token" << '\n';
          return " ";
      }

      Stack<string> operators;

      string postfix = "";
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
