#include <iostream>

using namespace std;

#include <iomanip>

template <typename T>
class Stack
{
private:
    T *stackPtr;
    int size;
    T top;
public:
    Stack(int = 7);
    ~Stack();
    bool push(const T );
    bool pop();
    void printStack();
};


template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s: 7;
    stackPtr = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr;
}

template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false;

    top++;
    stackPtr[top] = value;

    return true;
}

template <typename T>
bool Stack<T>::pop()
{
    if (top == - 1)
        return false;

    stackPtr[top] = 0;
    top--;

    return true;
}

template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        cout << " " << setw(4) << stackPtr[ix] << endl;
}
int main()
{
    Stack <int> myStack(10);
    cout << "Заполняем стек элементами: \n";
    int ct = 0;
    while (ct++ != 10)
    {
        int temp;
        cin >> temp;
        myStack.push(temp);
    }

    myStack.printStack();

    cout << "\nУдаляем элемент из стека:\n";

    myStack.pop();
    myStack.printStack();

    return 0;
}
