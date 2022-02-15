#include <iostream>

using namespace std;

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int* ptr = new int[size];

    cout << "Enter the numbers in the array: " << endl;
    for(int i=0; i<size; i++){
        cin >> *(ptr+i);
    }
    cout << "Printing the dynamic array: " << endl;
    for(int i=0; i<size; i++){
        cout << *(ptr+i) << endl;
    }
    cout << "\nDeleting the array" << endl;
    delete[] ptr;
    cout << "Array deleted!";

return 0;
}
