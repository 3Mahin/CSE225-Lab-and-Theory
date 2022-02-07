#include <iostream>

using namespace std;

bool isSorted(int arr[], int size){

    int count=0;
    for(int i=0; i<size-2; i++){
        if(arr[i]<=arr[i+1] && arr[i+1]<=arr[i+2]){
            count++;
            if(count == size-2){
                return 1;
            }
        }
        else{
            return 0;
        }
    }
}

int main(){
    int arr[] = {3,6,7,4,1,8,2,9};
    //int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(isSorted(arr,size) == 0){
        cout << "False" << endl;
        cout << "Manually Change the array from source code" << endl;
    }
    else{
        cout << "True" << endl;
        cout << "Manually Change the array from source code" << endl;
    }

return 0;
}
