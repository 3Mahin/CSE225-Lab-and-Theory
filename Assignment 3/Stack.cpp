#include<iostream>
using namespace std;

struct Item{
    int data;
    Item *next;
};

class Stack{
private:
    Item *topItem;
public:
    Stack(){
        topItem = NULL;
    }

    void push(int data){
        Item *n = new Item;

        n->data = data;
        n->next = topItem;
        topItem = n;
    }

    void pop(){
        if(topItem == NULL){
            cout << "Stack empty!" << endl;
        }
        else{
            Item *temp = topItem;
            topItem = topItem->next;
            delete temp;
        }
    }

    int top(){
        if(isEmpty()){
            return NULL;
        }
        else{
            return topItem->data;
        }
    }

    bool isEmpty(){
        return topItem == NULL;
    }

    void makeEmpty(){
        while(!isEmpty()){
            pop();
        }
    }
};

int main(){
    //Complete the functions above
    //Call each function here in the main()
    //to test if they are working correctly
    Stack s;
    s.push(1);
    s.push(2);

    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    //if it returns 0 its false if 1 its true
    cout << s.isEmpty() << endl;

    s.makeEmpty();
    cout << s.top() << endl;
}
