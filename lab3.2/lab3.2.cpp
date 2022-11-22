#include <iostream> 
using namespace std;
void vvod(int*& mass, int* size)
{
    cout << "введите размер массива\n";
    cin >> *size;
    mass = new int[*size];
    for (int i = 0; i < *size; i++)
    {
        cin >> mass[i];
    }
}
void vuvod(int*& mass, int* size)
{
    if (*size != 0)
    {
        for (int i = 0; i < *size; i++)
        {
            cout << mass[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Проблемы с массивом" << endl;
    }
}

int main()
{

    setlocale(LC_ALL, "Rus");
    int* mass;
    int size = 0;

    int choice = 0; // в этой переменной будет храниться выбор пользователя

    while (true) // непрерывный цикл 

    {
        cout << "Что вы хотите выполнить? \n"
            << "1. задание 1\n"
            << "2. задание 2\n"
            << "3. задание 3\n"
            << "4. задание 4\n"
            << "5. выход\n";

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            /*вызов функции для решения задания 1*/;
            vvod(mass, &size);
            break;
        }

        case 2:
        {
            /*вызов функции для решения задания 2*/;
            vuvod(mass, &size);
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}