#include <iostream>

using namespace std;

int words(string text){
    int flag =0;
    for(int i=0; text[i]!='\0'; i++){
        flag++;
    }
    return flag;
}

int main(){
    string text;
    cout << "Enter the string: ";
    cin >> text;

    int n = words(text);
    cout << n << endl;

return 0;
}
