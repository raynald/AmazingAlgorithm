#include<iostream>
#include<string>

class Extended_KMP {
    private:
        const int MAXSIZE  = 400005;
        int extend[MAXSIZE], next[MAXSIZE];
    public:
        void get_next(strint t) {
            int n = t.length();
            int a, p, k, i;

            next[0] = 0;
            a = 0;
            p = 1;
            for (k = 1; k < n; k++) {
                if (k == p)    {
                    i = k;
                    while (t[i] == t[i - k]) i++;
                    next[k] = i - k;
                    if (i == p) p++; else p = i;
                    a = k;
                }
                else if (k + next[k - a] <= p)
                    next[k] = next[k - a];
                else {
                    next[k] = p - k;
                    i = p;
                    while (t[i] == t[i - k]) {
                        i++;
                        next[k]++;
                    }
                    if (i > p) {
                        p = i;
                        a = k;
                    }
                }
            }
        }

        void get_extend(string s, string t) {
            int sn = s.length();
            int tn = t.length();
            int a, p, k, i;
            
            get_next(t);
            p = a = 0;
            for (k = 0; k < sn; k++) {
                if (k == p)    {
                    i = k;
                    while (i - k < tn && s[i] == t[i - k]) i++;
                    extend[k] = i - k;
                    if (i == p) p++; else p = i;
                    a = k;
                }
                else if (k + next[k - a] <= p)
                    extend[k] = next[k - a];
                else {
                    extend[k] = p - k;
                    i = p;
                    while (i - k < tn && s[i] == t[i - k]) {
                        i++;
                        extend[k]++;
                    }
                    if (i > p) {
                        p = i;
                        a = k;
                    }
                }
            }
        }
};

