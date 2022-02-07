#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n==1){
        return 0;
    }
    else{
        int count;
        for(int i=2; i<n; i++){
            if(n%i==0){
                count++;
            }
        }
        if(count==0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if(isPrime(n)==0){
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }
return 0;
}
