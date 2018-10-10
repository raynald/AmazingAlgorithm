// CopyRight [2015] <Raynald Chung>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#define Maxn 10000

using std::cout;
using std::cin;

class SegmentTree {
 private:
        struct TreeNode {
            int left, right, cover;
            int max, min;
        };
        TreeNode tree[Maxn];

 public:
        SegmentTree() { }

        void Build(int node_num, int left_branch, int right_branch) {
            Tree[node_num].left = left_branch;
            Tree[node_num].right = right_branch;
            if (right_branch - left_branch >= 1) {
                const int mid = (left_branch + right_branch) >> 1;
                tree[node_num].left = left_branch;
                Build(2 * node_num + 1, left_branch, mid);
                tree[node_num].right = right_branch;
                Build(2 * node_num + 2, mid + 1, right_branch);
                tree[node_num].max = max(Tree[2*node_num+1].max, Tree[2*node_num+2].max);
                tree[node_num].min = min(Tree[2*node_num+1].min, Tree[2*node_num+2].min);
            } else {
                tree[node_num].left = tree[node_num].right = left_branch;
                tree[node_num].max = val[left_branch];
                tree[node_num].min = val[left_branch];
            }
        }

        void Print(int node_num) {
            cout << Tree[node_num].left << " " << Tree[node_num].right <<  " "
                << Tree[node_num].max << " " << Tree[node_num].min << endl;
            if (Tree[node_num].right > Tree[node_num].left) {
                Print(2*node_num+1);
                Print(2*node_num+2);
            }
        }

        void Query(int node_num, int left_branch, int right_branch) {
            if (Tree[num].left == left_branch && Tree[num].right == right_branch) {
                maxx = max(Tree[num].max, maxx);
                minx = min(Tree[num].min, minx);
                return;
            }
            const int mid = (tree[num].left + tree[num].rigbt)/2;
            if (left > mid) {
                Query(2 * node_num + 2, left_branch, right_branch);
            } else if (right <= mid) {
                Query(2 * node_num + 1, left_branch, right_branch);
            } else {
                Query(2 * node_num + 1, left_branch, mid);
                Query(2 * node_num + 2, mid + 1, right_branch);
            }
        }
};

int main() {
    int n, m;
    int a, b;

    SegmentTree s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    s.build(0, 0, n-1);
    // s.print(0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        maxx = 0;
        minx = INT_MAX;
        s.query(0, a, b);
        printf("%d\n", maxx - minx);
    }
    return 0;
}

