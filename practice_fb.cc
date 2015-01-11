1. strStr

void CalcNextTable(const string &needle, int next[]) {
    next[0] = -1;
    next[1] = 0;
    int pos_new = 2;
    int pos_old = 0;
    while(pos_new < needle.length()) {
        if(needle[pos_new-1] == needle[pos_old]) {
            ++pos_old;
            next[pos_new] = pos_old;
            ++pos_new;
        } else {
            if(pos_old > 0) pos_old = next[pos_old];
            else {
                pos_old = 0;
                next[pos_new] = 0;
                pos_new ++;
            }
        }
    }
}

int KMPMatching(const string &haystack, const string &needle) {
    int hay_len = heystack.length();
    int nee_len = needle.length();
    int next[nee_len];
    CalcNextTable(needle, next);
    int pos_h = 0; 
    int len = 0;
    while (pos_h + len < hay_len) {
        if(haystack[pos_h + len] == needle[len]) {
            len ++;
            if(len == nee_len) return pos_h;
        } else {
            if(next[len] > -1) {
                pos_h += len - next[len];
                len = next[len];

                else {
                    len = 0;
                    pos_h ++;
                }
            }
        }
    }

2. Word Break
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string>::iterator got;
        vector<string> ans;
        vector<string> store;
        if(s.length()==0) return ans;
        got = dict.find(s);
        if(got!=dict.end()) ans.push_back(s);
        for(int i=1;i<s.length();i++) {
            got = dict.find(s.substr(0,i));
            if(got!=dict.end()) {
                store = wordBreak(s.substr(i), dict);
                for(int j=0;j<store.size();j++) {
                    ans.push_back(s.substr(0,i) + " " + store[j]);
                }
            }
        }
        return ans;
    }

3. Merge K sorted List
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multimap<int, ListNode*> mmap;
        multimap<int, ListNode*>::iterator got;
        ListNode *head, *cur, *point;

        for(int i=0;i<lists.size();++i) {
            if(lists[i]!=NULL) {
                mmap.insert(pair<int, ListNode*>(lists[i]->val, lists[i]));
            }
        }
        head = cur = NULL;
        while(mmap.size()>0) {
            if(head == NULL) {
                head = new ListNode(mmap.begin()-> first);
                cur = head;
            } else {
                cur -> next = new ListNode(mmap.begin()->first);
                cur = cur -> next;
            }
            point = mmap.begin()->second->next;
            if(point !=NULL) {
                mmap.insert(pair<int, ListNode*>(point->val, point));
            }
            mmap.erase(mmap.begin());
        }
        return head;
    }

4. Word Search
5. Is Valid Palindrome
6. Binary Search 
7. Letter Combination of Phone Nubmer
8. 3 Sum
9. Edit Distance 1
bool OneEditDistance(const string &x, const string &y) {
    if(x.length()>y.length()) return OneEditDistance(y,x);
    if(x.length()<y.length()-1) return 0;
    bool flag = 0;
    for(int i=0;i<x.length();i++) {
        if(x[i]!=y[i+flag]) {
            if(!flag) {
                flag = 1;
                if(x[i+1]!=y[i]) return 0;
            } else {
                return 0;
            }
        }
    }
    if(!flag && x.length()==y.length()) return 0; else return 1;
}
10. Anagrams
11. Three Color Partition
void ThreeColorPartion(int color[], int n) {
    int head = -1;
    int tail = n;
    int pos = 0;
    while(pos < tail) {
        if(color[pos] == -1) {
            head ++;
            swap(color[head], color[pos]);
            pos ++;
        }
        else if(color[i] == 1) {
            tail --;
            swap(color[tail], color[pos]);
        } else pos ++;
    }
}
12. Pow
13. Read4K


