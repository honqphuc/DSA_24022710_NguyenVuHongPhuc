#include <iostream>

using namespace std;

class MaxHeap{
private:
    int arr[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void swim(int k){
        while(k > 0 && arr[(k - 1) / 2] < arr[k]){
            swap(arr[(k - 1) / 2], arr[k]);
            k = (k - 1) / 2;
        }
    }

    void sink(int k){
        while(2*k + 1 < size){
            int larger = 2*k + 1;
            if(2*k + 2 < size && arr[2*k + 1] < arr[2*k + 2]){
                larger = 2*k +2;
            }

            if(arr[k] > arr[larger]){
                break;
            }
            else{
            swap(arr[k], arr[larger]);
            k = larger;
            }
        }
    }

    void insert(int data){
        arr[size++] = data;
        swim(size - 1);
    }

    int delMax(){
        if(size == 0) {
            cout<<"Cannot delete"<<endl;
            return -1;
        }
        int Max = arr[0];
        swap(arr[size- 1 ], arr[0]);
        size--;
        sink(0);
        return Max;
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else return false;
    }

    int getMax(){
        if(size == 0){
            cout<<"Mang rong\n";
            return -1;
        }
        return arr[0];
    }

    int getSize(){
        return size;
    }

    void print() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


