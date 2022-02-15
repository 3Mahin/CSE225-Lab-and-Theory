#include <iostream>

using namespace std;

int main(){
    int row,col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> col;

    string** ptr = new string*[row];
    for(int i=0; i<row; i++){
        ptr[i] = new string[col];
    }

    cout << "Enter the info into the 2D array:\n" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> ptr[i][j];
        }
    }

    cout << "Printing the contents of the 2D array:\n" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << ptr[i][j] << endl;
        }
    }

    cout << "\nDeleting array" << endl;
    for(int i=0; i<row; i++){
        delete[] ptr[i];
    }
    delete[] ptr;
    ptr = NULL;

    cout << "\nArray deleted!" << endl;

return 0;
}
