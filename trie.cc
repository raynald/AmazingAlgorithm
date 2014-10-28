#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    char val;
    vector<TreeNode *> child;
    TreeNode() {}
    TreeNode(char x): val(x) {
        child.clear();
    }
};

class Trie {
    private:
        TreeNode *root;
        void insert(TreeNode *node, string s) {
            if(s.length()==0) return;
            bool flag = 0;
            for(int i=0; i<node->child.size();i++) {
                if(node->child[i]->val == s[0]) {
                    insert(node->child[i], s.substr(1));
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                TreeNode *tmp = new TreeNode(s[0]);
                node->child.push_back(tmp);
                insert(node->child[node->child.size()-1], s.substr(1));
            }
        }
        bool search(TreeNode *node, string s) {
            if(node->child.size()==0) {
                if(s.length()==0) return 1; else return 0;
            }
            for(int i=0;i<node->child.size();i++){
                if(node->child[i]->val==s[0]) {
                    return search(node->child[i], s.substr(1));
                }
            }
            return 0;
        }
    public:
        Trie() {
            root = new TreeNode('#');
        }
        void insert(string s) {
            insert(root, s);
        }
        bool search(string s) {
            return search(root, s);
        }
};


int main() {
    Trie t;
    t.insert("about");
    t.insert("amount");
    t.insert("zett");
    cout << t.search("abo") << endl;
    cout << t.search("aboue") << endl;
    cout << t.search("zett") << endl;
    cout << t.search("zatt") << endl;
    return 0;
}
