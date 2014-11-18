//Establish big root tree
//exchange root with furthermost leaf
//maintain the tree again
//
//
#include<iostream>
#include<vector>
using namespace std;

template <class T> class Heap {
private:
    vector<T> data;
    int capacity;
public:
    Heap() {
        data.clear();
    }
    void insert(T x) {
        data.push_back(x);
    }
    void heapify(int x) {
        T tmp = data[x];
        int left = x * 2;
        if(left >= capacity) return;
        if(data[left]> tmp) tmp = data[left];
        int right = x * 2 + 1;
        if(right<capacity) {
            if(data[right]>tmp) tmp = data[right];
        }
        if(tmp==data[left]) {
            swap(data[x],data[left]);
        }
        else if(tmp!=data[x]) {
            swap(data[x],data[right]);
        }
    }
    void sort() {
        capacity=data.size();
        for(int i=data.size()-1;i>=0;i--) {
            for(int j=i/2;j>=0;j--)
                heapify(j);
            swap(data[i],data[0]);
            capacity--;
        }
    }
    void print() {
        cout << "capacity" << data.size() << endl;
        for(int i=0;i<data.size();i ++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int x, n;

    cin >> n;
    Heap<int> h;
    for(int i=0;i<n;i++) {
        cin >> x;
        h.insert(x);
    }
    h.sort();
    h.print();
    return 0;
}
