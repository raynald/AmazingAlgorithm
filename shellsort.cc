#include<iostream>

using namespace std;

void shell_insert(int a[], int left, int right, int gap) {
    int tmp;
    int i, j;
    for(i=left+gap;i<right;i++) {
        tmp = a[i];
        for(j=i-gap;tmp<a[j] && j>=left;j-=gap) {
            a[j+gap] = a[j];
        }
        a[j+gap] = tmp;
    }
}

void shell_sort(int a[], int left, int right) {
    int gap = right - left;
    while(gap>1) {
        gap = gap / 3 + 1;
        shell_insert(a, left, right, gap);
    }
}

int main() {
    int a[10];
    for(int i=0;i<10;i++) cin >> a[i];
    shell_sort(a, 0, 10);
    for(int i=0;i<10;i++) cout<< a[i]<<" " ;
    cout << endl;
    return 0;
}

