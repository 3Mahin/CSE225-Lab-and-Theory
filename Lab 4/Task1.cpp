#include <iostream>

using namespace std;

// Exception class thrown by push() when stack is full.
class FullStack{};

// Exception class thrown by pop() and Top when stack is empty.
class EmptyStack{};

// Class
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

// Definitions
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


class FullQueue{};
class EmptyQueue{};

class Queue
{
  private:
    int front;
    int rear;
    int* items;
    int queueSize;

  public:
    Queue();
    Queue(int queueSize);
    ~Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(int item);
    int dequeue();
};

// Definitions
Queue::Queue(int qSize){
    queueSize = qSize + 1;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new int[queueSize];
}

Queue::Queue(){
    queueSize = 11;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new int[queueSize];
}

Queue::~Queue(){
    delete [] items;
}

void Queue::makeEmpty(){
    front = queueSize - 1;
    rear = queueSize - 1;
}

bool Queue::isEmpty(){
    return (rear == front);
}

bool Queue::isFull(){
    return ((rear+1)%queueSize == front);
}

void Queue::enqueue(int item){
    if(isFull()){
        throw FullQueue();
    }else{
        rear = (rear +1) % queueSize;
        items[rear] = item;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        throw EmptyQueue();
    }else{
        front = (front + 1) % queueSize;
        return items[front];
    }
}

int main(){

    int var;
    Queue q1(10);

    cout << "Enter the 10 integers in the queue: " << endl;
    for(int i=0; i<10; i++){
        cin >> var;
        q1.enqueue(var);
    }

    Stack s1(10);

    while(!q1.isEmpty()){
        s1.push(q1.dequeue());
    }

    while(!s1.isEmpty()){
        q1.enqueue(s1.top());
        s1.pop();
    }

    cout << "Displaying items after reversed: " << endl;
    while(!q1.isEmpty()){
        cout << q1.dequeue() << endl;
    }

return 0;
}