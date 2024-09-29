#include "application.h"
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "ArrayList.h"
#include "ShuntingYard.h"
using namespace std;

TApplication::TApplication()
{

}

int TApplication::exec()
{

    int ch;
    ch = menu();
    LinkedList<double> myList;
    Stack<int> stackan;
    ArrayList<int> arrList;
    ShuntingYard sh;
    switch (ch)
    {
        case 0:
        {
            string infixExpression = "sin 0.5 + 2 ^ 3";
            string postfixExpression = sh.infixToPostfix(infixExpression);
            cout << postfixExpression << endl;
        break;
        }
        case 1:
        {
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:

            break;
        default:
            cout << "defauktx";
            break;

    }
    return 0;
}

int TApplication::menu()
{
   int ch;
   cout << "0 - " << "\n";
   cout << "1 - " << "\n";
   cout << "2 - " << "\n";
   cout << "3 - " << "\n";
   cout << "4 - " << "\n";
   cout << "5 - " << "\n";
   cout << "6 - " << "\n" << "> ";
   cin >> ch;
   return ch;
}
