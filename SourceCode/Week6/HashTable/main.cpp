#include <iostream>
#include "LinkedList.cpp"
using namespace std;

const int P = 100;

struct HashTable {
    LinkedList table[P];

    int hashFunction(int key) {
        return key % P;
    }

    void insert(int key) {
        int index = hashFunction(key);
        if (!table[index].find(key))
            table[index].addFirst(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        if (table[index].deleteValue(key))
            cout << "Da xoa key " << key << " o bucket " << index << endl;
        else
            cout << "Khong tim thay key " << key << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        return table[index].find(key);
    }

    void display() {
        for (int i = 0; i < P; ++i) {
            if (table[i].head != NULL) {
                cout << "[" << i << "]: ";
                table[i].print();
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(110);
    ht.insert(25);

    cout << "Bang bam ban dau:\n";
    ht.display();

    cout << "\nTim 25: " << (ht.search(25) ? "Co" : "Khong") << endl;
    cout << "Tim 99: " << (ht.search(99) ? "Co" : "Khong") << endl;

    cout << "\nXoa key 10:\n";
    ht.remove(10);

    cout << "\nBang bam sau khi xoa:\n";
    ht.display();

    return 0;
}
