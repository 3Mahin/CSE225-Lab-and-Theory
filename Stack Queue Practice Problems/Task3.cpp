#include <iostream>

using namespace std;

class FullStack{};
class EmptyStack{};

class Stack
{
private:
   int stackSize;
   int topIndex;
   char *items;

public:
   Stack();
   Stack(int);
   ~Stack();
   void makeEmpty();
   bool isFull();
   bool isEmpty();
   void push(char);
   void pop();
   char top();
};

Stack::Stack()
{
  stackSize = 5;
  items = new char[stackSize];
  topIndex = -1;
}

Stack::~Stack()
{
  delete [] items;
}

Stack::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new char[stackSize];
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

void Stack::push(char newItem)
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

char Stack::top()
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
    string sen;
    cin >> sen;

    Stack s(sen.length());

    for(int i=0; i<sen.length(); i++){
        s.push(sen[i]);
    }

    cout << "Printing the reverse of the word: " << endl;
    while(!s.isEmpty()){
        cout << s.top();
        s.pop();
    }

return 0;
}