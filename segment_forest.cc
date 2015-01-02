#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
#define Maxn 100

using namespace std;

int mat[101][101];

class Segment_Forest {
private:
    struct TreeNode {
        int left,right;
        int val;
    };
    struct ForestNode {
        int left,right;
        TreeNode Tree[Maxn];
    };
    ForestNode f[Maxn];
    int n, m;
public:
    Segment_Forest(int _n, int _m) {
        n = _n;
        m = _m;
    }

    void double_build(int a, int Row, int Col, int c, int d) {
        f[Row].Tree[Col].left = c;
        f[Row].Tree[Col].right = d;
        if(d-c>=1) {
            int mid=(d+c)>>1;
            double_build(a, Row, 2*Col+1, c, mid);
            double_build(a, Row, 2*Col+2, mid+1, d);
            f[Row].Tree[Col].val = f[Row].Tree[2*Col+1].val + f[Row].Tree[2*Col+2].val;
        }
        else {
            f[Row].Tree[Col].val = mat[a][c];
        }
    }

    void build(int Row, int a,int b) {
        f[Row].left=a;
        f[Row].right=b;
        if(b-a>=1) {
            int mid=(a+b)>>1;
            build(2*Row+1 , a,mid);
            build(2*Row+2,mid+1, b);
            for(int i=0;i<=2*m;i++) {
                f[Row].Tree[i].val = f[2*Row+1].Tree[i].val + f[2*Row+2].Tree[i].val;
                f[Row].Tree[i].left = f[2*Row+1].Tree[i].left;
                f[Row].Tree[i].right = f[2*Row+1].Tree[i].right;
            }
        }
        else {
            double_build(b, Row, 0, 0, m-1);
        }
    }

    vector<int> double_modify(int Row, int Col, int y, int v) {
        vector<int> tmp;

        tmp.clear();
        if(f[Row].Tree[Col].left<=y && f[Row].Tree[Col].right>=y) {
            if(f[Row].Tree[Col].right-f[Row].Tree[Col].left>=1) {
                int mid=(f[Row].Tree[Col].left+f[Row].Tree[Col].right)/2;
                if(y<=mid) {
                    tmp = double_modify(Row, Col*2+1, y, v);
                }
                else {
                    tmp = double_modify(Row, Col*2+2, y, v);
                }
                f[Row].Tree[Col].val = f[Row].Tree[2*Col+1].val + f[Row].Tree[Col*2+2].val;
            }
            else {
                f[Row].Tree[Col].val = v;
            }
            tmp.push_back(Col);
        }
        return tmp;
    }

    vector<int> modify(int Num, int x, int y, int v) {
        vector<int> tmp;

        tmp.clear();
        if(f[Num].left<=x && f[Num].right>=x) {
            if(f[Num].right-f[Num].left>=1) {
                int mid=(f[Num].left+f[Num].right)>>1;
                if(x<=mid)
                    tmp = modify(2*Num+1, x,  y, v);
                if(x>=mid+1)
                    tmp = modify(2*Num+2, x, y, v);
                for(int i=0;i<tmp.size();i++) {
                    f[Num].Tree[tmp[i]].val = f[2*Num+1].Tree[tmp[i]].val+ f[2*Num+2].Tree[tmp[i]].val;
                }
                return tmp;
            }
            else {
                return double_modify(Num, 0, y, v);
            }
        }
    }

    int double_query(int Row, int Col, int a,int b,int c, int d) {
        if(f[Row].Tree[Col].left==b && f[Row].Tree[Col].right==d) {
            return f[Row].Tree[Col].val;
        }
        else if(f[Row].Tree[Col].left<=b && f[Row].Tree[Col].right>=d) {
            int mid = (f[Row].Tree[Col].left+f[Row].Tree[Col].right)/2;
            if(d<=mid) {
                return double_query(Row, 2*Col+1, a,b,c,d);
            }
            else if(b>=mid+1) {
                return double_query(Row, 2*Col+2, a,b,c,d);
            }
            else {
                return double_query(Row, 2*Col+1, a,b,c, mid) + double_query(Row, 2*Col+2, a,mid+1,c,d);
            }
        }
    }

    int query(int Num, int a, int b, int c, int d) {
        if(f[Num].left==a && f[Num].right==c) {
            return double_query(Num, 0, a,b,c,d);
        }
        else if(f[Num].left<=a && f[Num].right>=c) {
            int mid = (f[Num].left+f[Num].right)/2;
            if(c<=mid) {
                return query(2*Num+1, a,b,c,d);
            }
            else if(a>=mid+1) {
                return query(2*Num+2, a,b,c,d);
            }
            else {
                return query(2*Num+1, a,b,mid,d) + query(2*Num+2, mid+1,b,c,d);
            }
        }
    }
};

int main() {
    int n, m, q;
    int a, b, c, d;
    bool ind;

    cin >> n >> m;
    Segment_Forest s(n,m);
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin >> mat[i][j];
        }
    }
    s.build(0, 0, n-1);
    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> ind;

        if(ind) {
            cin >> a >> b >> c;
            s.modify(0, a,b,c);
        }
        else {
            cin >> a >> b >> c >> d;
            cout << s.query(0, a,b,c,d) << endl;
        }
    }
    return 0;
}

