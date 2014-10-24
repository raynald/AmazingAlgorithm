#define Maxn 10000

class Segment_Tree {
private:
    struct Node {
        int a,b,left,right,cover;
    };
    Node Tree[Maxn];
    int Number,Tot, c, d;
public
    void build(int a,int b) {
        int Now;
        Tot++;
        Now=Tot;
        Tree[Now].a=a;
        Tree[Now].b=b;
        Tree[Now].cover=0;
        if(b-a>=1) {
            intmid=(a+b)>>1;
            Tree[Now].left=Tot+1;
            build(a,mid);
            Tree[Now].right=Tot+1;
            build(mid+1,b);
        }
    }

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

    void Count(intNum) {
        if(Tree[Num].cover)
            Number+=(Tree[Num].b-Tree[Num].a);
        else {
            if(Tree[Num].left)
                Count(Tree[Num].left);
            if(Tree[Num].right)
                Count(Tree[Num].right);
        }
    }
};
