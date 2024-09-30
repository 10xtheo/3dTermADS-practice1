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

    int sm;
    sm = startMenu();




    switch (sm)
    {
        case 1:
        {
            cout << "Выбран пункт 1 - Сортировочная станция" << "\n";
            ShuntingYard sh;
            cout << "Введите выражение, содержащее символы "
                    "{+, -, *, /, ^, sin, cos, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << '\n' << "> ";
            string expression;
            cin.ignore();
            std::getline(std::cin, expression);
            string postfixExpression = sh.infixToPostfix(expression);
            cout << postfixExpression << endl;
        break;
        }

        case 2:
        {
            cout << "Выбран пункт 2 - Операции с списком" << "\n";
            LinkedList<int> listik;

            break;
        }

        case 3:
        {
            cout << "Выбран пункт 3 - Операции с динамическим массивом" << "\n";
            ArrayList<int> arrList;

            break;
        }

        case 4:
        {
            cout << "Выбран пункт 4 - Операции с стэком" << "\n" << "> ";
            Stack<int> stackan;
            break;
        }

        default:
        {
            cout << "defauktx";
            break;
        }
    }
    return 0;
}

int TApplication::startMenu()
{
   int sm;
   cout << "Выберите пункт программы" << '\n';
   cout << "1 - Сортировочная станция" << "\n";
   cout << "2 - Операции с списком" << "\n";
   cout << "3 - Операции с динамическим массивом" << "\n";
   cout << "4 - Операции с стэком" << "\n" << "> ";
   cin >> sm;
   return sm;
}
