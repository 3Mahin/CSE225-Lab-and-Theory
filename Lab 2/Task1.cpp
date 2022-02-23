#include <iostream>

using namespace std;

template <class dtype>
class SortedList{
    private:
        int length;
        dtype *list;
        int currentPos;
        int capacity;

    public:
        SortedList(){
            length = 0;
            currentPos = -1;
            capacity = 10;
            list = new dtype[capacity];
        }
        SortedList(int capacity){
            length = 0;
            currentPos = -1;
            this->capacity = capacity;
            list = new dtype[capacity];
        }

        void makeEmpty(){
            length = 0;
        }
        bool isFull(){
            return (length == capacity);
        }
        int lengthIs(){
            return length;
        }
        void resetList(){
            currentPos = -1;
        }
        dtype getNextItem(){
            currentPos++;
            return list[currentPos];
        }
        void insertItem(int item){
            int location = 0;
            while(location < length){
                if(item > list[location]){
                    location++;
                }
                else{
                    break;
                }
            }
            for (int index = length; index < location; index--){
                list[index] = list[index - 1];
            }
            list[location] = item;
            length++;
        }
        void deleteItem(dtype item){
            int location = 0;
            while(item != list[location]){
                location++;
            }
            for(int index = location + 1; index < length; index++){
                list[index - 1] = list[index];
            }
            length--;
        }
        bool searchItem(dtype item){
            int midPoint, first = 0, last = length - 1;
            while(first <= last){
                midPoint = (first + last)/2;
                if(item < list[midPoint]){
                    last = midPoint - 1;
                }
                else if(item > list[midPoint]){
                    first = midPoint + 1;
                }
                else{
                    return true;
                }
            }
            return false;
        }
};

int main(){
    int capacity;
    cout << "Enter list capacity: ";
    cin >> capacity;

    SortedList<char> s1(capacity);

    cout << "Enter " << capacity << " values: ";
    char n; // I had to manually change this as the templete class was out of scope
    
    while (!s1.isFull()){
        cin >> n;
        s1.insertItem(n);
    }

    cout << "List: ";
    for(int i=0; i<s1.lengthIs(); i++){
        cout << s1.getNextItem() << ",";
    }

    cout << "\b " << endl;
    cout << "Enter a value to search: ";
    cin >> n;
    if(s1.searchItem(n)){
        cout << n << " was found" << endl;
    }
    else{
        cout << n << " was not found" << endl;
    }

    cout << "Enter a value to delete: ";
    cin >> n;

    if(s1.searchItem(n)){
        s1.deleteItem(n);
        cout << n << " has been deleted" << endl;
    }else{
        cout << "Delete failed: " << n << " was not found" << endl;
    }

    s1.resetList();
    cout << "List: ";
    for(int i=0; i< s1.lengthIs(); i++){
        cout << s1.getNextItem() << ",";
    }
    cout << "\b " << endl;
    

return 0;
}