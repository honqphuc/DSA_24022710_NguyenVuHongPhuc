#include <iostream>

using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[r]; // phan tu ben phai cung
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    // dua chot ve giua
    ++i;
    swap(a[i], a[r]);
    return i; // vi tri
}

void quicksort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}


int main(){
    int a[] = {9, 4, 6, 2, 8, 1, 3, 7, 5};
    int sz = sizeof(a) / sizeof(a[0]);

    cout << "Mang ban dau: ";
    for(int i = 0; i < sz; i++) cout << a[i] << " ";
    cout << endl;

    quicksort(a, 0, sz - 1);

    cout << "Mang sau khi sap xep: ";
    for(int i = 0; i < sz; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
