#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class SuffixArray {
    private:
        struct suffix {
            int index; 
            int rank[2];
        };

        static int cmp(suffix &a, suffix &b) {
            return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
                (a.rank[0] < b.rank[0] ?1: 0);
        }

        int n;
        vector<int> suffixArr;
        string origin;

    public:
        int buildSuffixArray(string txt) {
            origin = txt;
            n = txt.length();
            int ind[n];  
            vector<suffix> suffixes;

            for (int i = 0; i < n; i++) {
                suffixes.push_back({i, {txt[i], i < n - 1 ? txt[i + 1]: -1}});
            }
            sort(suffixes.begin(), suffixes.end(), cmp);
            for (int k = 2; k < n; k = k*2) {
                int rank = 0;
                int prev_rank = suffixes[0].rank[0];
                suffixes[0].rank[0] = rank;
                ind[suffixes[0].index] = 0;

                for (int i = 1; i < n; i++) {
                    if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
                        suffixes[i].rank[0] = rank;
                    } else { 
                        prev_rank = suffixes[i].rank[0];
                        suffixes[i].rank[0] = ++rank;
                    }
                    ind[suffixes[i].index] = i;
                }
                for (int i = 0; i < n; i++) {
                    int nextindex = suffixes[i].index + k;
                    suffixes[i].rank[1] = (nextindex < n)?
                        suffixes[ind[nextindex]].rank[0]: -1;
                }
                sort(suffixes.begin(), suffixes.end(), cmp);
            }
            suffixArr.clear();
           for (int i = 0; i < n; i++)
               suffixArr.push_back(suffixes[i].index);
        }

        int search(string substr) {
            int left = 0, right = n - 1;
            int m = substr.length();

            while (left <= right) {
                int mid = (left + right) / 2;
                int res = substr.compare(origin.substr(suffixArr[mid], m));
                if (res == 0) return suffixArr[mid];
                if (res < 0) right = mid - 1; else left = mid + 1;
            }
            return -1;
        }

        // Print SuffixArray
        void printArr() {
            for (int i = 0; i < suffixArr.size(); i++)
                cout << suffixArr[i] << " ";
            cout << endl;
        }
};

int main() {
    string txt = "banana";

    SuffixArray s;
    s.buildSuffixArray(txt);
    s.printArr();
    cout << s.search("ana") << endl;
    cout << s.search("nan") << endl;
    cout << s.search("ann") << endl;
    cout << s.search("bb") << endl;
    return 0;
}

