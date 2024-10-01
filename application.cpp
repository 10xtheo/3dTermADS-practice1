#include "application.h"
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "ArrayList.h"
#include "ShuntingYard.h"
using namespace std;

int TApplication::exec()
{
    int sm = 1;
    while (sm != 0)
    {
        sm = startMenu();

        switch (sm)
        {
            case 1:
            {
                ShuntingYard sh;
                cout << "Выбран пункт 1 - Сортировочная станция" << "\n";
                int ch = 1;
                while (ch != 0)
                {
                    cout << "1. Использовать алгоритм сортировочной станции" << "\n";
                    cout << "0. Выйти в меню" << "\n";
                    ch = getInt();
                    switch (ch)
                    {
                        case 0:
                        {
                            cout << "program stopped by user" << "\n";
                            break;
                        }
                        case 1:
                        {
                            cout << "Введите выражение, содержащее символы "
                                    "{+, -, *, /, ^, sin, cos, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << '\n' << "> ";
                            string expression;
                            cin.ignore();
                            std::getline(std::cin, expression);
                            string postfixExpression = sh.infixToPostfix(expression);
                            cout << postfixExpression << endl;
                            break;
                        }
                        default:
                        {
                            cout << "wrong menu item";
                            break;
                        }
                    }
                }
            break;
            }
            case 2:
            {
                LinkedList<int> listik;
                int ch = 1;
                while (ch != 0)
                {
                    ch = listMenu();
                    switch (ch)
                    {
                        case 1:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index >= listik.getSize() || index < 0)
                            {
                                cout << "index out of range to get value" << "\n";
                            }
                            else
                            {
                                cout << "Элемент: " << listik[index] << "\n";
                            }

                            break;
                        }

                        case 2:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            cout << "Значение: ";
                            int value = getInt();
                            listik.insert(value, index);
                            listik.print();
                            break;
                        }
                        case 3:
                        {
                            cout << "Значение: ";
                            int value = getInt();
                            listik.append(value);
                            listik.print();
                            break;
                        }

                        case 4:
                        {
                            if (listik.getSize() > 1)
                                listik.sort();
                            else
                            {
                                cout << "nothing to sort" << "\n";
                            }
                            listik.print();
                            break;
                        }
                        case 5:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index < listik.getSize() && index >= 0)
                            {
                                listik.remove(index);
                            }
                            else
                                cout << "index out of range to remove" << "\n";
                            listik.print();
                            break;
                        }
                        case 6:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index <= listik.getSize() && index >= 0)
                            {
                                cout << "Значение: ";
                                int value = getInt();
                                listik.insert(value, index);
                            }
                            else
                                cout << "index out of range to insert" << "\n";
                            listik.print();
                            break;
                        }
                        case 7:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index < listik.getSize() && index >= 0)
                            {
                                cout << "Значение: ";
                                int value = getInt();
                                listik[index] = value;
                                listik.print();
                            }
                            else
                            {
                                cout << "index out of range to set value" << "\n";
                            }

                            break;
                        }
                    case 8:
                    {
                        listik.print();
                        break;
                    }


                        case 0:
                        {
                            cout << "program stopped by user" << "\n";
                            break;
                        }


                        default:
                        {
                            cout << "wrong menu item" << "\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                ArrayList<int> arrList;
                int ch = 1;
                while (ch != 0)
                {
                    ch = arrListMenu();
                    switch (ch)
                    {
                        case 1:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index >= arrList.getSize() || index < 0)
                            {
                                cout << "index out of range to get value" << "\n";
                            }
                            else
                            {
                                cout << "Элемент: " << arrList[index] << "\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index <= arrList.getSize() || index < 0)
                            {
                                cout << "Значение: ";
                                int value = getInt();
                                arrList.add(value, index);
                            }
                            else
                                cout << "index out of range to add" << "\n";
                            arrList.print();
                            break;
                        }
                        case 3:
                        {
                            cout << "Значение: ";
                            int value = getInt();
                            arrList.append(value);
                            arrList.print();
                            break;
                        }

                        case 4:
                        {
                        if (arrList.getSize() > 1)
                            arrList.sort();
                        else
                        {
                            cout << "nothing to sort" << "\n";
                        }
                        arrList.print();
                            break;
                        }
                        case 5:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index < arrList.getSize() && index >= 0)
                                arrList.remove(index);
                            else
                                cout << "index out of range to remove" << "\n";
                            arrList.print();
                            break;
                        }
                        case 6:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index <= arrList.getSize() && index >= 0)
                            {
                                cout << "Значение: ";
                                int value = getInt();
                                arrList.add(value, index);
                            }
                            else
                                cout << "index out of range to add" << "\n";
                            arrList.print();
                            break;
                        }
                        case 7:
                        {
                            cout << "Индекс: ";
                            int index = getInt();
                            if (index < arrList.getSize() && index >= 0)
                            {
                                cout << "Значение: ";
                                int value = getInt();
                                arrList[index] = value;
                            }
                            else
                                cout << "index out of range to set value" << "\n";
                            arrList.print();
                            break;
                        }
                        case 0:
                        {
                            cout << "program stopped by user" << "\n";
                            break;
                        }
                        default:
                        {
                            cout << "wrong menu item" << "\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                Stack<int> stackan;
                int ch = 1;
                while (ch != 0)
                {
                    ch = stackMenu();
                    switch (ch)
                    {
                        case 1:
                        {
                            cout << "Значение: ";
                            int value = getInt();
                            stackan.push(value);
                            stackan.print();
                            break;
                        }
                        case 2:
                        {
                            if (!(stackan.isEmpty()))
                                cout << "Получен элемент: " << stackan.pop() << "\n";
                            else
                            {
                                cout << "stack is empty nothing to pop" << "\n";
                            }
                            stackan.print();
                            break;
                        }
                        case 3:
                        {
                            if (!(stackan.isEmpty()))
                                cout << "Вершина: " << stackan.top() << "\n";
                            else
                                cout << "stack is empty nothing to top" << "\n";
                            stackan.print();
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
                        case 0:
                        {
                            cout << "program stopped by user" << "\n";
                            break;
                        }
                        default:
                        {
                            cout << "wrong menu item" << "\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 0:
            {
                cout << "program stopped by user" << "\n";
                break;
            }
            default:
            {
                cout << "wrong menu item" << "\n";
                break;
            }
        }
    }
    return 0;
}

int TApplication::startMenu()
{
   cout << "Выберите пункт программы" << '\n';
   cout << "1 - Сортировочная станция" << "\n";
   cout << "2 - Операции с списком" << "\n";
   cout << "3 - Операции с динамическим массивом" << "\n";
   cout << "4 - Операции с стэком" << "\n";
   cout << "0 - Выход" << "\n" << "> ";
   int ch = getInt();
   return ch;
}

int TApplication::getInt()
{
    int a;
      cin >> a;
      while (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cin >> a;
      }
      return a;
}

int TApplication::listMenu()
{
    cout << "Выбран пункт 2 - Операции с списком" << "\n";
    cout << "1. Получить элемент по индексу" << "\n";
    cout << "2. Вставить элемент в список по индексу" << "\n";
    cout << "3. Вставить элемент в конец списка" << "\n";
    cout << "4. Отсортировать список" << "\n";
    cout << "5. Удалить элемент по индексу" << "\n";
    cout << "6. Добавить элемент в список по индексу" << "\n";
    cout << "7. Изменить элемент по индексу" << "\n";
    cout << "0 - Выход" << "\n" << "> ";
    int ch = getInt();
    return ch;
}

int TApplication::arrListMenu()
{
    cout << "Выбран пункт 3 - Операции с динамическим массивом" << "\n";
    cout << "1. Получить элемент по индексу" << "\n";
    cout << "2. Вставить элемент в массив по индексу" << "\n";
    cout << "3. Вставить элемент в конец массива" << "\n";
    cout << "4. Отсортировать массив" << "\n";
    cout << "5. Удалить элемент по индексу" << "\n";
    cout << "6. Добавить элемент в массив по индексу" << "\n";
    cout << "7. Изменить элемент по индексу" << "\n";
    cout << "0 - Выход" << "\n" << "> ";
    int ch = getInt();
    return ch;
}

int TApplication::stackMenu()
{
    cout << "Выбран пункт 4 - Операции с стэком" << "\n";
    cout << "1. Добавить элемент в стэк" << "\n";
    cout << "2. Удалить и получить верхний элемент" << "\n";
    cout << "3. Получить верхний элемент" << "\n";
    cout << "4. Состояние стэка" << "\n";
    cout << "0 - Выход" << "\n" << "> ";
    int ch = getInt();
    return ch;
}
