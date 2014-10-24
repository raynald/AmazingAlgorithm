const int INF = 1<<30;
const int DIVISOR = 1000000;
const int MAXH=500010;

int t,n,k;
long long dp[MAXH];
int A;
long long tmp;

template <class DType>
class Treap { 
    private:
        struct node;
        typedef struct node *pnode;

        struct node {
            DType key;
            int value;
            pnode left, right;
            int priority;
        };

        pnode null, root;

        void right_rotate(pnode &cur) {
            pnode tmp;
            tmp = cur->left;
            cur->left = tmp->right;
            tmp->right = cur;
            cur = tmp;
        }

        void left_rotate(pnode &cur) {
            pnode tmp;
            tmp = cur->right;
            cur->right = tmp->left;
            tmp->left = cur;
            cur = tmp;
        }

        void insert_node(pnode &cur, DType key) {
            if (cur == null) {
                cur = new struct node;
                cur->key = key;
                cur->value = 1;
                cur->left = null;
                cur->right = null;
                cur->priority = rand();
            }
            else if (key< cur->key) {
                insert_node(cur->left, key);
                if (cur->left->priority < cur->priority) right_rotate(cur);
            }
            else 
                if (key > cur->key) {
                    insert_node(cur->right, key);
                    if (cur->right->priority < cur->priority) left_rotate(cur);
                }
                else cur->value++;
        }

        void delete_node (pnode &cur, DType key) {
            if (cur != null) {
                if (key < cur->key) delete_node(cur->left, key);
                else 
                    if (key > cur->key) delete_node(cur->right, key);
                    else {
                        if(cur->value>1) cur->value--;
                        else {
                            if ((cur->left == null) && (cur->right == null)) {
                                delete cur;
                                cur = null;
                            }
                            else {
                                if((cur->left==null)) cur = cur->right; else
                                    if(cur->right==null) cur = cur -> left; else {
                                        if (cur->left->priority < cur->right->priority) right_rotate(cur); else left_rotate(cur);
                                        delete_node(cur, key);
                                    }
                            }
                        }
                    }
            }
        }

        void erase(pnode cur) {
            if (cur->left != null) erase(cur->left);
            if (cur->right != null) erase(cur->right);
            delete cur;
        }

        void prt(pnode cur) { 
            if(cur != null) {
                prt(cur->left);
                cout << cur->key1 << " " << cur->key2 << " " << cur->value << endl;
                prt(cur->right);
            }
        }

    public:
        Treap () 
        {
            null = new struct node;
            null->key = INF;
            null->value = 0;
            null->left = null;
            null->right = null;
            null->priority = INF;
            root = null;
        }

        ~Treap () 
        {
            erase(root);
            //delete null;
            //delete root;
        }

        void insert(DType key) {
            insert_node(root, key);
        }

        void del(DType key) {
            delete_node(root, key);
        }

        void print() {
            prt(root);
            cout << " --"<<endl;
        }

        bool empty() {
            return root==null;
        }

        DType headtop() {
            if(root==null) return 0;
            else return root->key;
        }

        DType find() {
            DType left, right;
            pnode cur;

            cur = root;
            while (cur -> left != null) {
                cur = cur->left;
            }
            return cur->key;
        }
};
