#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp {
    int x;
    int y;
    cmp() {}
    cmp(int u, int v): x(u), y(v) {}
};

bool operator<(const cmp &u, const cmp& v) {
        return u.x > v.x;
}

class Dselection {
    public:
        int partition(int A[], int left, int right, int i) {
            int v = A[i];
            swap(A[i], A[right-1]);
            int index = left;
            for(int i=left;i<right;i++) {
                if(A[i]<=v) {
                    swap(A[i], A[index]);
                    index++;
                }
            }
            return index-1;
        }

        int select_heap(int A[], int left, int right, int k) {
            priority_queue<cmp> q;
            while(!q.empty()) q.pop();
            for(int i=left;i<right;i++) q.push(cmp(A[i], i));
            for(int i=1;i<=k;i++) q.pop();
            return q.top().y;
        }

        int median(int A[], int left, int right) {
            int sub_left, sub_right;
            int m_index;
            int num = (right-left-1)/5;
            for(int i=0;i<=num;i++) {
                sub_left = left + i * 5;
                sub_right = min(sub_left + 5, right);
                m_index = select_heap(A, sub_left, sub_right, (sub_right-sub_left)/2);
                swap(A[left+i], A[m_index]);
            }
            cmp ss = select(A, left, left+num+1, (num+1)/2);
            return ss.y;
        }

        cmp select(int A[], int left, int right, int k) {
            int pivot;
            int index;
            int dist;

            while(right-left>1) {
                pivot = median(A, left, right);
                index = partition(A, left, right, pivot);
                dist = index - left + 1;
                if(dist == k) {
                    return cmp(A[index], index);
                }
                if(dist<k) {
                    k -= dist;
                    left = index + 1;
                }
                else {
                    right = index;
                }
            }
            return cmp(A[left], left);
        }
};

int main() {
    Dselection d;
    int n;
    int A[1010];
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    cout << d.select(A, 0, n, 3).x << endl;

    return 0;
}
