#include <iostream>

using namespace std;

string toUppercase(string text){
    for(int i=0; i<text.size(); i++){
        text[i] -= 32;
    }
    return text;
}

int main(){
    string text;

    cout << "Enter lowercase text to convert: ";
    cin >> text;

    text = toUppercase(text);
    cout << text << endl;
}
