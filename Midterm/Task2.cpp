#include <iostream>

using namespace std;

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
    Queue q(5);

    int count = 0;

    int input;
    int min = 0;

    while(!q.isFull()){
        cin >> input;

        if(count == 0){
            min  = input;
        }

        else if(input < min){
            min = input;
        }
        q.enqueue(input);

        count++;
    }

    cout << "Minimum value: " << min << endl;

return 0;
}