#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class mySuffix {
    private:
        struct TreeNode {
            string val;
            TreeNode *lChild;
            TreeNode *sibling;
            TreeNode(): lChild(NULL), sibling(NULL) {}
            TreeNode(string x): val(x), lChild(NULL), sibling(NULL) {}
        };
        TreeNode *root;
        string str; 
        vector<bool> v;
    public:
        mySuffix(): root(NULL),str("")  {}

        ~mySuffix() {
            if(root) DestoryTree();
            root=NULL;
        }

        bool CreateTree(string constant_str) {
            if (root != NULL || constant_str.size() == 0 ) return false;
            str=constant_str;
            root=new TreeNode("root");
            for(int i=0;i<str.size();i++) {
                 fix_suffix(this->root,str.substr(i));
            }
            return true;
        }

        void DestoryTree() {
            Clear(root);
            root=NULL;
        }

        void show_out() {
            out(this->root,0);
        }

    protected:
        void out(TreeNode *parent,int whitspace) {
            if (parent == NULL ) return;
            cout << parent->val <<endl;
            parent=parent->lChild;
            while( parent != NULL )
            {
                for(int i=0;i<whitspace;i++) cout <<"   ";
                if(parent->sibling)
                    cout <<"├─";
                else
                    cout <<"└─";
                out(parent,whitspace+1);
                parent=parent->sibling;
            }
        }

        void fix_suffix(TreeNode *parent,string suffix) {
            TreeNode *pnode=parent->lChild;
            while(pnode) {
                if( suffix[0] == pnode->val[0] ) break;
                pnode=pnode->sibling;
            }              
            if(!pnode) {
                AddToTree(parent,suffix);
                return;
            }
            int suffix_len=suffix.size();
            int branch_len=pnode->val.size();
            for(int i=1;;i++) {
                if( suffix_len < i+1 ) return;
                if( branch_len < i+1 ) { 
                    fix_suffix(pnode,suffix.substr(i)); 
                    return; 
                }
                if( suffix[i] != pnode->val[i] ) {
                    TreeNode *old_child=pnode->lChild;
                    AddToTree(pnode,pnode->val.substr(i));
                    pnode->lChild->sibling=NULL;
                    pnode->lChild->lChild=old_child;
                    AddToTree(pnode,suffix.substr(i));
                    pnode->val=pnode->val.substr(0,i);
                    return;
                }
            }
        }

        void AddToTree(TreeNode *parent,string contex) {
            TreeNode *sub=new TreeNode();
            sub->val=contex;
            if( parent->lChild == NULL ) {
                parent->lChild=sub;
            }
            else {
                sub->sibling=parent->lChild;
                parent->lChild=sub;
            }
        }

        void Clear(TreeNode* parent) {
            if(parent==NULL) return;
            TreeNode *sibling=parent->sibling;
            TreeNode *temp;
            while( sibling != NULL ) {
                if(sibling->lChild != NULL) Clear(sibling->lChild);
                temp=sibling;
                sibling=sibling->sibling;
                delete temp;
            }
            if( parent->lChild != NULL) Clear(parent->lChild);
            delete parent;
        }
};

int main() {
    std::string str="aaaaaaaa";

    mySuffix mytree;
    if( ! mytree.CreateTree(str) ) cout <<"fail" <<endl;
    else {
        mytree.show_out();
    }
    mytree.DestoryTree();

    return 0;
}

