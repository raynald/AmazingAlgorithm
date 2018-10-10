#include<iostream>

using namespace std;

int num;
int array[10010];

void Qsort(int left, int right) {
    if(left==right) return;
    int i = left;
    int j = right;
    int mid = a[i];
    while(j>i) {
        while(j>i && a[j]>mid) j--;
        if(j>i) {
            a[i]=a[j];
            i++;
        }
        while(j>i && a[i]<mid) i++;
        if(j>i) {
            a[j]=a[i];
            j--;
        }
    }
    a[i] = mid;
    if (i>left) Qsort(left, i-1);
    if (j<right) Qsort(j+1, right);
}

int main() {
    freopen("in.txt","r",stdin);
    cin >> num;
    for(int i=1;i<=num;i++)
        cin >> a[i];
    Qsort(1, num);
    for(int i=1;i<=num;i++)
        cout << array[i] << " ";
    cout << endl;
}
