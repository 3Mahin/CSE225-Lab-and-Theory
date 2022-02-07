#include <iostream>

using namespace std;

bool isPalindrome(string text, string clone){
    char temp;
    for(int i=0; i<=clone.size()/2; i++){
        temp = clone[clone.size()-1-i];
        clone[clone.size()-1-i] = clone[i];
        clone[i] = temp;
    }
    if(clone == text){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string text;
    string clone;

    cout << "Enter text check for Palindrome: ";
    cin >> text;
    clone = text;

    if(isPalindrome(text,clone)==0){
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }

return 0;
}
