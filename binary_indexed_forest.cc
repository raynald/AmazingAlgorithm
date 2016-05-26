#include<bits/stdc++.h>

using namespace std;

const int MAXN = 110;

class BIT {
private:
    int A[MAXN][MAXN];
    int S[MAXN][MAXN];
    int n, m;

    inline int lowBit(int t) {
        return t & (-t);
    }

    void add(int x, int y, int z) {
        int row, col;
        row = x + 1;
        while(row <= n) {
            col = y + 1;
            while(col <= m) {
                S[row][col] += z;
                col += lowBit(col);
            }
            row += lowBit(row);
        }
    }

    int getResult(int x, int y) {
        int row, col;
        row = x + 1;
        int ans = 0;
        while (row >= 1) {
            col = y + 1;
            while (col >= 1) {
                ans += S[row][col];
                col -= lowBit(col);
            }
            row -= lowBit(row);
        }
        return ans;
    }

public:
    BIT(int x, int y, int a[][MAXN]): n(x), m(y) {
        memset(S, 0, sizeof(S));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                A[i][j] = a[i][j];
                add(i, j, a[i][j]);
            }
        }
    }

    void modify(int x, int y, int z) {
        int v = A[x][y];
        add(x, y, z - v);
        A[x][y] = z;
    }

    int get(int x, int y, int a, int b) {
        int value_1, value_2, value_3, value_4;
        value_1 = getResult(a, b);
        if (x > 0 && y > 0) value_2 = getResult(x - 1, y - 1); else value_2 = 0;
        if (y > 0) value_3 = getResult(a, y - 1); else value_3 = 0;
        if (x > 0) value_4 = getResult(x - 1, b); else value_4 = 0;
        return value_1 + value_2 - value_3 - value_4;
    }

    void print() {
        cout << "Print matrix S...\n";
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                cout << S[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, m, T;
    int A[MAXN][MAXN];
    int t, x, y, z, a, b;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> A[i][j];
        }
    }
    BIT b_tree(n, m, A);
    cout << "Finish building..\n";
    b_tree.print();
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> t; 
        if(t == 1) {
            cin >> x >> y >> z;
            b_tree.modify(x, y, z);
        }
        else {
            cin >> x >> y >> a >> b;
            cout << b_tree.get(x, y, a, b) << endl;
        }
    }
    return 0;
}

