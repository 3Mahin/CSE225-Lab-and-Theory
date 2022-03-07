#include <iostream>
using namespace std;

// Exception class thrown by push() when stack is full.
class FullStack{};

// Exception class thrown by pop() and Top when stack is empty.
class EmptyStack{};

template <class T>
// Class
class Stack
{
private:
   int stackSize;
   int topIndex;
   T *items;

public:
   Stack();
   Stack(int);
   ~Stack();
   void makeEmpty();
   bool isFull();
   bool isEmpty();
   void push(T);
   void pop();
   T top();
};

// Definitions
template <class T>
Stack<T>::Stack()
{
  stackSize = 5;
  items = new int[stackSize];
  topIndex = -1;
}

template <class T>
Stack<T>::~Stack()
{
  delete [] items;
}

template <class T>
Stack<T>::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new T[stackSize];
  topIndex = -1;
}

template <class T>
void Stack<T>::makeEmpty()
{
  topIndex = -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
  return (topIndex == -1);
}

template <class T>
bool Stack<T>::isFull()
{
  return (topIndex ==  stackSize-1);
}

template <class T>
void Stack<T>::push(T newItem)
{
  if(isFull())
    throw FullStack();
  topIndex++;
  items[topIndex] = newItem;
}

template <class T>
void Stack<T>::pop()
{
  if(isEmpty())
    throw EmptyStack();
  topIndex--;
}

template <class T>
T Stack<T>::top()
{
  if (isEmpty())
    throw EmptyStack();
  return items[topIndex];
}

// main
int main()
{
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;
    Stack <int> s(n);

    int c;
    cout << "Enter some values into the stack.." << endl;
    while(!s.isFull()){
        cin>>c;
        s.push(c);
    }
    cout << endl;

    cout << "Printing stack.." << endl;
    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }
}
