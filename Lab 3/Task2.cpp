#include <iostream>
#include <stack>

using namespace std;

void reverse(string &sen){
    int length = sen.length();

    stack<char> st;

    for(int i=0; i<length; i++){
        st.push(sen[i]);
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    
}

int main(){
    string a;
    cout << "Enter a string: ";
    cin >> a;

    reverse(a);
    
return 0;
}