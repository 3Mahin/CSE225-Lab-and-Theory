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
	int temp;
    Stack s(5); // original stack

	s.push(25);
	s.push(83);
	s.push(19);
	s.push(67);
	s.push(34);

    Stack s2(5); // temporary stack

    temp = s.top(); // max value from original stack

	// transfering items from s to s2
    while(!s.isEmpty()){
        if(s.top() >= temp){
            temp = s.top();
        }
        s2.push(s.top());
        s.pop();
    }

    while(!s2.isEmpty()){
    	if(temp == s2.top()){
        	s2.pop();
    	}
		else{
			s.push(s2.top());
			s2.pop();
		}
    }

	s.push(temp);

	while(!s.isEmpty()){
		cout << s.top() << endl;
		s.pop();
	}

return 0;
}