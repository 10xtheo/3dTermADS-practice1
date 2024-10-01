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
            listik.append(9);
            listik.append(2);
            listik.append(5);
            cout << "1. Получить элемент по индексу" << "\n";
            cout << "2. Вставить элемент в список по индексу" << "\n";
            cout << "3. Вставить элемент в конец списка" << "\n";
            cout << "4. Отсортировать список" << "\n";
            cout << "5. Удалить элемент по индексу" << "\n";
            cout << "6. Добавить элемент в список по индексу" << "\n";
            cout << "7. Изменить элемент по индексу" << "\n";
            cout << "> ";
            int ch;
            cin >> ch;
            switch (ch)
            {
                case 1:
                {

                    cout << "Индекс: ";
                    int index;
                    cin >> index;
                    cout << "Элемент: " << listik[index] << "\n";
                    break;
                }

                case 2:
                {
                    cout << "Индекс: ";
                    int index;
                    cin >> index;
                    cout << "Значение: ";
                    int value;
                    cin >> value;
                    listik.insert(value, index);
                    listik.print();
                    break;
                }
                case 3:
                {
                    cout << "Значение: ";
                    int value;
                    cin >> value;
                    listik.append(value);
                    listik.print();
                    break;
                }

                case 4:
                {
                    listik.sort();
                    listik.print();
                    break;
                }
                case 5:
                {
                    cout << "Индекс: ";
                    int index;
                    cin >> index;
                    listik.remove(index);
                    listik.print();
                    break;
                }

                case 6:
                {
                    cout << "Индекс: ";
                    int index;
                    cin >> index;
                    cout << "Значение: ";
                    int value;
                    cin >> value;
                    listik.insert(value, index);
                    listik.print();
                    break;
                }
                case 7:
                {
                    cout << "Индекс: ";
                    int index;
                    cin >> index;
                    cout << "Значение: ";
                    int value;
                    cin >> value;
                    listik[index] = value;
                    listik.print();
                    break;
                }

                default:
                {
                    cout << "wrong choice" << "\n";
                    break;
                }

            }

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
            stackan.push(5);
            stackan.push(6);
            stackan.push(7);
            cout << "1. Добавить элемент в стэк" << "\n";
            cout << "2. Удалить и получить верхний элемент" << "\n";
            cout << "3. Получить верхний элемент" << "\n";
            cout << "4. Состояние стэка" << "\n";
            cout << "> ";
            int ch;
            cin >> ch;
            switch (ch)
            {
                case 1:
                {
                    cout << "Значение: ";
                    int value;
                    cin >> value;
                    stackan.push(value);
                    stackan.print();
                    break;
                }

                case 2:
                {
                    cout << stackan.pop() << "\n";
                    stackan.print();
                    break;
                }
                case 3:
                {
                     cout << stackan.top() << "\n";
                    break;
                }

                case 4:
                {
                   if (stackan.isEmpty())
                       cout << "Стэк пуст" << "\n";
                   else
                       cout << "Стэк содержит элементы" << "\n";
                    break;
                }

                default:
                {
                    cout << "wrong choice" << "\n";
                    break;
                }

            }

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
