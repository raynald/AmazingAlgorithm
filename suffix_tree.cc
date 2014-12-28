#include <iostream>
#include <string>
#include <cstring>

using namespace std;

static int a[128]={0};

struct TreeNode {
    string val;
    TreeNode *lChild;
    TreeNode *sibling;
    TreeNode() {
        lChild=NULL;
        sibling=NULL;
    }
};

class mySuffix
{
    public:
        mySuffix(): root(NULL),constant_str("")  {}

        ~mySuffix() {
            if(root) DestoryTree();
            root=NULL;
        }

        bool CreateTree(string& constant_str) {
            if (root != NULL || constant_str.size() == 0 ) return false;
            this->constant_str=constant_str;
            initialise();
            scan_all_suffix();
            return true;
        }

        void DestoryTree() {
            CylClear(root);
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

        void initialise() {
            memset(a,0,128*sizeof(int));
            root=new TreeNode();
            root->val="root";
            for(int i=0;i<constant_str.size();i++) {
                if( a[ constant_str[i] ] == 0 ) {
                    a[ constant_str[i] ] = 1;
                    AddToTree(root,constant_str.substr(i));
                }
            }
        }

        void scan_all_suffix() {
            for(int i=1;i<constant_str.size();i++) {
                fix_suffix(this->root,constant_str.substr(i));
            }
        }

        void fix_suffix(TreeNode *parent,string suffix) {
            TreeNode *pnode=parent->lChild;
            if( ! pnode ) return;
            while(pnode) {
                if( suffix[0] == pnode->val[0] ) break;
                pnode=pnode->sibling;
            }              
            if(!pnode) {
                AddToTree(parent,suffix);
                return;
            }
            int i=1; 
            int suffix_len=suffix.size();
            int branch_len=pnode->val.size();
            while(1) {
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
                i++;
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

        void CylClear(TreeNode* parent) {
            if(parent==NULL) return;
            TreeNode *sibling=parent->sibling;
            TreeNode *temp;
            while( sibling != NULL ) {
                if(sibling->lChild != NULL) CylClear(sibling->lChild);
                temp=sibling;
                sibling=sibling->sibling;
                delete temp;
            }
            if( parent->lChild != NULL) CylClear(parent->lChild);
            delete parent;
        }
    private:
        TreeNode *root;
        string constant_str;
};

int main() {
    std::string str="networkmanagerment";

    mySuffix mytree;
    if( ! mytree.CreateTree(str) ) cout <<"fail" <<endl;
    else {
        mytree.show_out();
    }
    mytree.DestoryTree();

    return 0;
}

