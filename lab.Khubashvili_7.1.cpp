#include <iostream>
#include <Windows.h>

using namespace std;

template<typename T1, typename T2, typename T3>
struct Pair {
    T3 name;
    T1 surname;
    T2 age;
};

template<typename T1, typename T2, typename T3>
bool compareByAge(const Pair<T1, T2, T3>& p1, const Pair<T1, T2, T3>& p2) {
    return p1.age < p2.age;
}

template<typename T1, typename T2, typename T3>
bool compareByName(const Pair<T1, T2, T3>& p1, const Pair<T1, T2, T3>& p2) {
    return p1.name < p2.name;
}

template<typename T1, typename T2, typename T3>
bool compareBySurname(const Pair<T1, T2, T3>& p1, const Pair<T1, T2, T3>& p2) {
    return p1.surname < p2.surname;
}

template<typename T1, typename T2, typename T3, typename Comparator>
void quicksort(Pair<T1, T2, T3>* arr, int left, int right, Comparator comparator) {
    if (left >= right) {
        return;
    }
    int pivot = right;
    int partition = left - 1;
    for (int i = left; i < right; i++) {
        if (comparator(arr[i], arr[pivot])) {
            partition++;
            swap(arr[partition], arr[i]);
        }
    }
    swap(arr[partition + 1], arr[right]);
    quicksort(arr, left, partition, comparator);
    quicksort(arr, partition + 2, right, comparator);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создание массива пар с полями фамилия и возраст
    Pair<string, int, string> arr[] = {
        {"Олег", "Иванов", 20},
        {"Вася", "Петров", 30},
        {"Кирилл", "Сидоров", 25},
        {"Никита", "Васильев", 40},
        {"Степан", "Козлов", 35}
    };

    cout << "Сортировка по возрасту\n\n";
    // Сортировка по возрасту
    quicksort(arr, 0, 4, compareByAge<string, int, string>);
    for (int i = 0; i < 5; i++) {
        cout << arr[i].name << " " << arr[i].surname << " " << arr[i].age << endl;
    }

    cout << "\n=======================\nСортировка по имени\n\n";
    // Сортировка по фамилии
    quicksort(arr, 0, 4, compareByName<string, int, string>);
    for (int i = 0; i < 5; i++) {
        cout << arr[i].name << " " << arr[i].surname << " " << arr[i].age << endl;
    }

    cout << "\n=======================\nСортировка по фамилии\n\n";
    // Сортировка по фамилии
    quicksort(arr, 0, 4, compareBySurname<string, int, string>);
    for (int i = 0; i < 5; i++) {
        cout << arr[i].name << " " << arr[i].surname << " " << arr[i].age << endl;
    }

    system("pause");
    return 0;
}