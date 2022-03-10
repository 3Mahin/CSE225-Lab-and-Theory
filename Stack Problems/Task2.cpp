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

int main(){
    Stack s1(5),s2(5),s3(5);

    s1.push(71);
    s1.push(34);
    s1.push(87);
    s1.push(45);
    s1.push(23);

    while(!s1.isEmpty()){
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.isEmpty()){
        s3.push(s2.top());
        s2.pop();
    }

    while(!s3.isEmpty()){
        s1.push(s3.top());
        s3.pop();
    }

    while(!s1.isEmpty()){
        cout << s1.top() << endl;
        s1.pop();
    }

return 0;
}