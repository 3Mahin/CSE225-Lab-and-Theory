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

// custom function made by me for checking the operator precedence
int precedence(char ch)
{
    if(ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

int main(){
	string infix;

	cout << "Enter infix: ";
	cin >> infix;

    //string infix = "(2-3)*(4+5)";					// testing input string
    //string infix = "(4+8)*(6-5)/((3-2)*(2+2))";   // testing input string

    string postfix = "";    // outputing postfix format

    Stack<char> s(infix.length());      // char stack

    for(int i=0; i<infix.length(); i++){

        // takes the number and adds to postfix for display
        if(infix[i] >= '0' && infix[i] <= '9'){     
            postfix += infix[i];
        }

        // checks for '(' and pushes into stack
        else if(infix[i] =='('){   
            s.push(infix[i]);
        }

        // used for operator storing and has precidence logic
        else if(infix[i] =='+' || infix[i] =='-' || infix[i] =='*' || infix[i] =='/' || infix[i] =='%'){
            if(!s.isEmpty()){
				s.push(infix[i]);
			}
			else{
				while(!s.isEmpty() && precedence(infix[i]) <= precedence(s.top())){
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
			}
        }

        // check for ')' and pops everything until '('
        else if(infix[i] ==')'){
            while(s.top() !='(' && !s.isEmpty()){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

	// empties all the items from the stack
	while(!s.isEmpty()){
		postfix += s.top();
		s.pop();
	}

    cout << "Postfix: " << postfix << endl;

return 0;
}