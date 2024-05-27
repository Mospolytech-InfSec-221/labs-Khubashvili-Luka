#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T>
struct Node {
    T data; 
    Node<T>* next;
};


template <typename T>
struct Stack {
private:
    Node<T>* top; 

public:
    
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    // Функция добавления элемента в стек
    void push(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Функция удаления верхнего узла
    void pop() {
        if (isEmpty()) {
            cerr << "Пустой стек" << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    // Возвращает значение верхнего узла
    T topValue() {
        if (isEmpty()) {
            cerr << "Пустой стек" << endl;
            return T();
        }
        return top->data;
    }

    // Функция печати стека
    void printStack() {
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool operator==( Stack<T>& stack) {
        return topValue() == stack.topValue();
    }

    bool operator!=( Stack<T>& stack) {
        return topValue() != stack.topValue();
    }

    bool operator>( Stack<T>& stack) {
        return topValue() > stack.topValue();
    }

    bool operator<( Stack<T>& stack) {
        return topValue() < stack.topValue();
    }

    bool operator>=( Stack<T>& stack) {
        return topValue() >= stack.topValue();
    }

    bool operator<=( Stack<T>& stack) {
        return topValue() <= stack.topValue();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    Stack<char> stack; 
    stack.push('abc');
    stack.push('b');
    stack.push('c');

    Stack<char> stack1;
    stack1.push('a');
    stack1.push('b');
    stack1.push('c');

    // Вызов методов сравнения
    cout << "stack == stack1: " << (stack == stack1 ? "true" : "false") << endl;
    cout << "stack >= stack1: " << (stack >= stack1 ? "true" : "false") << endl;
    cout << "stack <= stack1: " << (stack <= stack1 ? "true" : "false") << endl;
    cout << "stack > stack1: " << (stack > stack1 ? "true" : "false") << endl;
    cout << "stack < stack1: " << (stack < stack1 ? "true" : "false") << endl;
    
    system("pause");
    return 0;
}
