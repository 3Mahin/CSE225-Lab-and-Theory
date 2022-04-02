#include<iostream>
using namespace std;

struct Item{
    int data;
    Item *next;
};

class Queue{
private:
    Item *first;
    Item *last;
public:
    Queue(){
        first = NULL;
        last = NULL;
    }

    void enqueue(int data){
        Item *temp=new Item;
        if(temp==NULL){
            return;
        }
        temp->data = data;
        temp->next = NULL;

        //for first node
        if(first == NULL){
            first = last = temp;
        }
        else{
            last -> next=temp;
            last = temp;
        }
    }

    void dequeue(){
        if (first == NULL){
            return;
        }

        if(first == last){
            first = last = NULL;
        }
        else{
            first = first->next;
        }
    }

    // returns the first item (int) without removing it
    int firstItem(){
        if(first == NULL){
            return NULL;
        }
        else{
            return first->data;
        }
    }

    bool isEmpty(){
        return (first == NULL);
    }

    void makeEmpty(){
        while(!isEmpty()){
            dequeue();
        }
    }
};

int main(){
    //Complete the functions above
    //Call each function here in the main()
    //to test if they are working correctly
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.firstItem() << endl;

    q.dequeue();
    cout << q.firstItem() << endl;

    //if it prints 0 then its false if 1 then true
    cout << q.isEmpty() << endl;

    q.makeEmpty();
    cout << q.firstItem() << endl;
}
