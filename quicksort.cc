#include<iostream>

using namespace std;

int n;
int a[10010];

void qsort(int left, int right) {
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
    if (i>left) qsort(left, i-1);
    if (j<right) qsort(j+1, right);
}

int main() {
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    qsort(1, n);
    for(int i=1;i<=n;i++)
        cout << a[i] << " ";
    cout << endl;
}
