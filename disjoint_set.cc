#include<cstdio>

using namespace std;

class ds {
    private:
        vector<int> p;
    public:
        ds (int n) {
            for(int i=0;i<n;i++) {
                p.push_back(-1);
            }
        }
        int find(int x) {
            if(p[x]<0) return x; 
            p[x] = find(p[x]);
            return p[x];
        }
        int union(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if(rx==ry) return -1;
            p[rx] += p[ry];
            p[ry] = rx;
            return 0;
        }
        int get_size(int x) {
            int rx = find(x);
            return -p[rx];
        }
        ~ds() {
            p.clear();
        }
};

