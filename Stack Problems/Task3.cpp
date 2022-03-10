#include <iostream>

using namespace std;

class FullStack{};
class EmptyStack{};

class Stack
{
private:
   int stackSize;
   int topIndex;
   int *items;

public:
   Stack();
   Stack(int);
   ~Stack();
   void makeEmpty();
   bool isFull();
   bool isEmpty();
   void push(int);
   void pushSorted(int);
   void pop();
   int top();
};

Stack::Stack()
{
  stackSize = 5;
  items = new int[stackSize];
  topIndex = -1;
}

Stack::~Stack()
{
  delete [] items;
}

Stack::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new int[stackSize];
  topIndex = -1;
}

void Stack::makeEmpty()
{
  topIndex = -1;
}

bool Stack::isEmpty()
{
  return (topIndex == -1);
}

bool Stack::isFull()
{
  return (topIndex ==  stackSize-1);
}

void Stack::push(int newItem)
{
  if(isFull())
    throw FullStack();
  topIndex++;
  items[topIndex] = newItem;
}

void Stack::pop()
{
  if(isEmpty())
    throw EmptyStack();
  topIndex--;
}

int Stack::top()
{
  if (isEmpty())
    throw EmptyStack();
  return items[topIndex];

}

void Stack::pushSorted(int newItem){
    Stack temp(stackSize);

    while(!isEmpty() && top() > newItem){
        temp.push(top());
        pop();
    }

    push(newItem);

    while(!temp.isEmpty()){
        push(temp.top());
        temp.pop();
    }
}

int main(){
    Stack s(5);

    s.pushSorted(5);
    s.pushSorted(2);
    s.pushSorted(7);
    s.pushSorted(4);
    s.pushSorted(1);

    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }

return 0;
}