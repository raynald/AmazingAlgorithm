#include<iostream>

using namespace std;

template <typename T, typename W>
class Hash_table {
    private:
        const int a = 11;
        const int b = 7;
        const int N = 100;
        int hash(T x) {
            return (a*x+b)%N;
        }
        struct cmp {
            T key;
            W val;
            cmp() {}
            cmp(T x, W y):key(x),val(y) {}
        };
        cmp buf[110];

    public:
        void insert(T x, W y) {
            int hashcode = hash(x);
            while(buf[hashcode].key>0) hashcode= (hashcode+1)%N;
            buf[hashcode]=cmp(x,y);
        }

        int lookup(T x) {
            int hashcode = hash(x);
            while(buf[hashcode].key) {
                if(buf[hashcode].key==x) return buf[hashcode].val;
                hashcode=(hashcode+1)%N;
            }
            return 0;
        }
};

int main() {
    Hash_table<int, int> h;
    h.insert(100, 10);
    h.insert(20, 3);
    cout << h.lookup(100) << endl;
    cout << h.lookup(20) << endl;
    return 0;
}

