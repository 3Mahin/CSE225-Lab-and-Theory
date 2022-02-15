#include <iostream>

using namespace std;

int main(){
    int row,col;
    cout << "Enter row: ";
    cin >> row;

    int tracker[row];

    int** arr = new int*[row];
    for(int i=0; i<row; i++){
        cout << "Enter size for row[" << i+1 << "]: ";
        cin >> col;
        tracker[i] = col;
        arr[i] = new int[col];
        for(int j=0; j<col; j++){
            cout << "Enter value for the row: ";
            cin >> arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Printing info from the 2D array:\n" << endl;
    for(int i = 0; i<row; i++){
        for(int j=0; j<tracker[i]; j++){
            cout << arr[i][j] << endl;
        }
    }

    cout << "\nDeleting the 2D array" << endl;
    for(int i=0; i<row; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
    cout << "Array deleted!" << endl;

return 0;
}
