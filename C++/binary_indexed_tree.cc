//Application: 4 3 1 2
//Pre(n) is the number of elements that is larger than n and before n
//0 + 1 + 2 + 2 = 5
#include<iostream>

using namespace std;

class BIT {
private:
    int A[110];
    int c[110];
    int n;
public:
    BIT(int x, int a[]) {
        n = x;
        for(int i=1;i<=n;i++)
            A[i] = a[i];
    }

    int lowBit(int t) {
        return t&(-t);
    }

    void build() {
        for(int i=1;i<=n;i++) {
            c[i] = A[i];
            for(int j=i-1;j>i-lowBit(i);j-=lowBit(j))
                c[i] += c[j];
        }
    }

    void modify(int t, int delta) {
        while(t<=n) {
            c[t]+=delta;
            t+=lowBit(t);
        }
    }

    int getResult(int t) {
    //return sum_{i=1}^{t} A[i]
        int num = 0;
        while(t>0) {
            num+=c[t];
            t-=lowBit(t);
        }
        return num;
    }
    
    int get(int x, int y) {
        return getResult(y) - getResult(x-1);
    }
};

int main() {
    int n, m;
    int a[110];
    int t, x, y;

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    BIT b(n, a);
    b.build();
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> t >> x >> y;
        if(t==1) {
            b.modify(x,y);
        }
        else {
            cout << b.get(x, y) << endl;
        }
    }
    return 0;
}

