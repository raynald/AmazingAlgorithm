#include<iostream>
#include<vector>

using namespace std;

struct MergeSort {
    vector<int> data;
    MergeSort() {
        data.clear();
    }
    void insert(int x) {
        data.push_back(x);
    }
    void sort_merge(int left, int right) {
        vector<int> final;
        int i,j;
        final.clear();
        if(left>=right) return;
        int mid = (left+right)/2;
        sort_merge(left, mid);
        sort_merge(mid+1, right);
        i=left;
        j=mid+1;
        while(i<=mid && j<=right) {
            if(data[i]<data[j]) {
                final.push_back(data[i]);
                i++;
            }
            else {
                final.push_back(data[j]);
                j++;
            }
        }
        while(i<=mid) {
            final.push_back(data[i]);
            i++;
        }
        while(j<=right) {
            final.push_back(data[j]);
            j++;
        }
        for(int i=0;i<final.size();i++) {
            data[left+i]=final[i];
        }
    }
    void sort() {
        sort_merge(0, data.size()-1);
    }
    void print() {
        for(int i=0;i<data.size();i++) {
            cout << data[i]<< " ";
        }
        cout << endl;
    }
};

int main() {
    int t,n;

    MergeSort ms;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t;
        ms.insert(t);
    }
    ms.sort();
    ms.print();
    return 0;
}
