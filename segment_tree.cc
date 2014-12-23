#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#define Maxn 10000

using namespace std;

int val[1010];
int maxx, minx;

class Segment_Tree {
private:
    struct Node {
        int left,right,cover;
        int max, min;
    };
    Node Tree[Maxn];
    int Number, c, d;
public:
    Segment_Tree() {
    }

    void build(int Now, int a,int b) {
        Tree[Now].left=a;
        Tree[Now].right=b;
        //Tree[Now].cover=0;
        if(b-a>=1) {
            int mid=(a+b)>>1;
            Tree[Now].left=a;
            build(2*Now+1 , a,mid);
            Tree[Now].right=b;
            build(2*Now+2,mid+1, b);
            Tree[Now].max = max(Tree[2*Now+1].max, Tree[2*Now+2].max);
            Tree[Now].min = min(Tree[2*Now+1].min, Tree[2*Now+2].min);
        }
        else {
            Tree[Now].left = Tree[Now].right = a;
            Tree[Now].max = val[a];
            Tree[Now].min = val[a];
        }
    }

    void print(int Now) {
        cout << Tree[Now].left << " " << Tree[Now].right <<  " " << Tree[Now].max << " " << Tree[Now].min << endl;
        if(Tree[Now].right>Tree[Now].left) {
            print(2*Now+1);
            print(2*Now+2);
        }
    }
    /*
    void insert(int Num) {
        if(c<=Tree[Num].a&&Tree[Num].b<=d)
            Tree[Num].cover++;
        else {
            int mid=(Tree[Num].a+Tree[Num].b)>>1;
            if(c<=mid)
                insert(Tree[Num].left);
            if(d>=mid+1)
                insert(Tree[Num].right);
        }
    }

    void del(int Num) {
        if(c<=Tree[Num].a && Tree[Num].b<=d)
            Tree[Num].cover--;
        else {
            int mid = (Tree[Num].a+Tree[Num].b)>>1;
            if(c <= mid)
                del(Tree[Num].left);
            if(d >= mid+1)
                del(Tree[Num].right);
        }
    }

    void Count(int Num) {
        if(Tree[Num].cover)
            Number+=(Tree[Num].b-Tree[Num].a);
        else {
            if(Tree[Num].left)
                Count(Tree[Num].left);
            if(Tree[Num].right)
                Count(Tree[Num].right);
        }
    }
    */

    void query(int num, int left, int right) {
        if(Tree[num].left == left && Tree[num].right==right) {
            maxx = max(Tree[num].max, maxx);
            minx = min(Tree[num].min, minx);
            return;
        }
        const int mid = (Tree[num].left +Tree[num].right)/2;
        if(left > mid) {
            query(2* num+2, left, right);
        }
        else if(right <= mid) {
            query(2*num+1, left, right);
        }
        else {
            query(2*num+1, left, mid);
            query(2*num+2, mid + 1, right);
        }
    }
};

int main() {
    int n, m;
    int a, b;

    Segment_Tree s;
    cin >> n >> m;
    for(int i = 0;i<n;i++) {
        cin >> val[i];
    }
    s.build(0, 0, n-1);
    //s.print(0);
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a --;
        b --;
        maxx = 0;
        minx = INT_MAX;
        s.query(0,a,b);
        printf("%d\n", maxx - minx);
    }
    return 0;
}

