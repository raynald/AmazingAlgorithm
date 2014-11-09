#include<iostream>
#include<string>

using namespace std;


class Extended_KMP {
    private:
        static const int MAXSIZE = 400005;
        int A[MAXSIZE], B[MAXSIZE];
    public:
        int max(int x, int y) {
            return x > y ? x : y;
        }

        void get_next(string T) {
            int n = T.length();
            int rightmost, L, j, k;
            //rightmost checked
            j = 0;
            while(j + 1 < n && T[j + 0] == T[j + 1]) j = j + 1;
            A[0] = 0; 
            A[1] = j;
            k = 1;
            for(int i = 2; i < n; i ++) {
                rightmost = k + A[k] - 1;
                L = A[i - k];
                //T[i-k]..T[A[k]-1] == T[i]..T[rightmost]
                if( L < rightmost - i + 1 ) A[i] = L;
                else {
                    j = max(0, rightmost - i + 1); //Attention
                    while(i + j < n && T[i + j] == T[0 + j]) j = j + 1;
                    A[i] = j;
                    k = i;
                }
            }
        }

        void get_extend(string S, string T) {
            int sn = S.length();
            int tn = T.length();
            int j, k, Len, L;

            get_next(T);
            j = 0;
            while(j < sn && j < tn && T[0 + j] == S[0 + j]) j = j + 1;
            B[0] = j;
            k = 0;
            for(int i = 1;i < sn; i ++) {
                Len = k + B[k] - 1;
                L = A[i-k];
                if( L < Len - i + 1 ) B[i] = L;
                else {
                    j = max(0,Len - i + 1);
                    while(i + j < sn && j < tn && S[i + j] == T[0 + j]) j = j + 1;
                    B[i] = j;
                    k = i;
                }
            }
        }
};

int main() {
    Extended_KMP kmp;
    kmp.get_extend("abacabacabc", "abcabcab");
    return 0;
}

