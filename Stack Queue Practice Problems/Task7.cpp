#include <iostream>

using namespace std;

class FullStack{};
class EmptyStack{};

template <class dtype>
class Stack
{
private:
   int stackSize;
   int topIndex;
   dtype *items;

public:
   Stack();
   Stack(int);
   ~Stack();
   void makeEmpty();
   bool isFull();
   bool isEmpty();
   void push(dtype);
   void pop();
   dtype top();
};

template <class dtype>
Stack<dtype>::Stack()
{
  stackSize = 5;
  items = new dtype[stackSize];
  topIndex = -1;
}

template <class dtype>
Stack<dtype>::~Stack()
{
  delete [] items;
}

template <class dtype>
Stack<dtype>::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new dtype[stackSize];
  topIndex = -1;
}

template <class dtype>
void Stack <dtype>::makeEmpty()
{
  topIndex = -1;
}

template <class dtype>
bool Stack <dtype>::isEmpty()
{
  return (topIndex == -1);
}

template <class dtype>
bool Stack <dtype>::isFull()
{
  return (topIndex ==  stackSize-1);
}

template <class dtype>
void Stack<dtype>::push(dtype newItem)
{
  if(isFull())
    throw FullStack();
  topIndex++;
  items[topIndex] = newItem;
}

template <class dtype>
void Stack <dtype>::pop()
{
  if(isEmpty())
    throw EmptyStack();
  topIndex--;
}

template <class dtype>
dtype Stack <dtype>::top()
{
  if (isEmpty())
    throw EmptyStack();
  return items[topIndex];
}

int main(){
    Stack<int> s(5); 
    int input;
    int count = 0;

    cout << "Enter items into the stack: " << endl;
    while(!s.isFull()){
        cin >> input;
        s.push(input);
        count++;
    }

    cout << "After removing odd items: " << endl;

    for(int i=count; i>=1; i--){
        if(i%2 != 0){
            s.pop();
        }
        else{
            cout << s.top() << endl;
            s.pop();
        }
    }

return 0;
}