#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class OrderedSymbolTable {
private:
    string keys[MAX];
    int values[MAX];
    int sizee;

public:
    OrderedSymbolTable() {
        sizee = 0;
    }

    bool isEmpty() {
        return sizee == 0;
    }

    string min() {
        return keys[0];
        }

    string max() {
         return keys[sizee - 1];
        }

    string floor(string key) {
        int i = rank(key);
        if (i < sizee && keys[i] == key) return keys[i];
        if (i == 0) return "null";
        return keys[i - 1];
    }

    string ceiling(string key) {
        int i = rank(key);
        if (i == sizee) return "null";
        return keys[i];
    }

    int rank(string key) {
        int lo = 0, hi = sizee - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (key < keys[mid]) {
                hi = mid - 1;
            }
            else if (key > keys[mid]) {
                    lo = mid + 1;
            }
            else return mid;
        }
        return lo;
    }

    string select(int k) {
        if (k < 0 || k >= sizee) return "null";
        return keys[k];
    }


    void put(string key, int val) {
        int i = rank(key);
        if (i < sizee && keys[i] == key) {
            values[i] = val;
            return;
        }
        for (int j = sizee; j > i; j--) {
            keys[j] = keys[j - 1];
            values[j] = values[j - 1];
        }
        keys[i] = key;
        values[i] = val;
        sizee++;
    }

    int get(string key) {
        if (isEmpty()) return -1;
        int i = rank(key);
        if (i < sizee && keys[i] == key) return values[i];
        return -1;
    }

    void deleteMin() {
        if (isEmpty()) return;
        for (int i = 1; i < sizee; i++) {
            keys[i - 1] = keys[i];
            values[i - 1] = values[i];
        }
        sizee--;
    }

    void deleteMax() {
        if (isEmpty()) return;
        sizee--;
    }

    void deleteKey(string key) {
        if (isEmpty()) return;
        int i = rank(key);
        if (i == sizee || keys[i] != key) return;
        for (int j = i; j < sizee - 1; j++) {
            keys[j] = keys[j + 1];
            values[j] = values[j + 1];
        }
        sizee--;
    }

    int size(string lo, string hi) {
        if (hi < lo) return 0;
        int rankHi = rank(hi);
        int rankLo = rank(lo);
        if (rankHi < sizee && keys[rankHi] == hi)
            return rankHi - rankLo + 1;
        else
            return rankHi - rankLo;
    }

    void printKeys() {
        for (int i = 0; i < sizee; i++)
            cout << keys[i] << " ";
        cout << endl;
    }

    void printKeys(string lo, string hi) {
        for (int i = 0; i < sizee; i++)
            if (keys[i] >= lo && keys[i] <= hi)
                cout << keys[i] << " ";
        cout << endl;
    }

    int size() {
        return sizee;
    }
};



int main() {
    OrderedSymbolTable st;

    st.put("E", 5);
    st.put("A", 1);
    st.put("S", 19);
    st.put("Y", 25);
    st.put("Q", 17);

    cout << "Min: " << st.min() << endl;
    cout << "Max: " << st.max() << endl;
    cout << "Floor(Q): " << st.floor("Q") << endl;
    cout << "Ceiling(R): " << st.ceiling("R") << endl;
    cout << "Rank(S): " << st.rank("S") << endl;
    cout << "Select(2): " << st.select(2) << endl;

    cout << endl << "All keys: ";
    st.printKeys();

    cout << "Keys between [B, T]: ";
    st.printKeys("B", "T");

    return 0;
}

