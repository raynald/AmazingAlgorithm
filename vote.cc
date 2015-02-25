#include<iostream>
#include<map>

using namespace std;

int A[110];
int N, k;
map<int, int> mmap;
map<int, int>::iterator got;

struct cmp {
    int val;
    int count;
    cmp() {
        val = count = 0;
    }
    cmp(int x, int y): val(x), count(y) {}
};

//Like Tetris
void find() {
    /* Compute the candidate elements in one pass. */

    for(int i=0;i<N;i++) {
        got = mmap.find(A[i]);
        if(got!=mmap.end()) {
            got->second++;
        }
        else {
            mmap.insert(pair<int, int>(A[i],1));
        }
        if(mmap.size()==k) {
            for(got = mmap.begin();got!=mmap.end();) {
                if(got->second==1) {
                    mmap.erase(got++);
                }
                else {
                    got->second--;
                    got++;
                }
            }
        }
    }
    for(got = mmap.begin();got!=mmap.end();got++) {
        got->second=0;
    }
    for(int i=0;i<N;i++) {
        got = mmap.find(A[i]);
        if(got!=mmap.end()) {
            got->second++;
        }
    }
    for(got = mmap.begin();got!=mmap.end();) {
        if(got->second<N/k+1) {
            mmap.erase(got++);
        } else got++;
    }
}

int main() {

    cin >> N >> k;
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }
    find();
    for(got = mmap.begin();got!=mmap.end();got++) {
        cout << got->first <<endl;
    }
    return 0;
}

