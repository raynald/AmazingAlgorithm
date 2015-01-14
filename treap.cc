template <typename DType>
class Treap { 
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
            Erase(root);
            //delete null;
            //delete root;
        }

        void Insert(DType key) {
            insert_node(root, key);
        }

        void Del(DType key) {
            delete_node(root, key);
        }

        void Print() {
            prt(root);
            cout << " --"<<endl;
        }

        bool Empty() {
            return root==null;
        }

        DType Headtop() {
            if(root==null) return 0;
            else return root->key;
        }

        DType Find() {
            DType left, right;
            pnode cur;

            cur = root;
            while (cur -> left != null) {
                cur = cur->left;
            }
            return cur->key;
        }

    private:
        struct Node;
        typedef struct Node* Pnode;

        struct Node {
            DType key;
            int value;
            pnode left, right;
            int priority;
        };

        Pnode null, root;

        void RightRotate(pnode &cur) {
            pnode tmp;
            tmp = cur->left;
            cur->left = tmp->right;
            tmp->right = cur;
            cur = tmp;
        }

        void LeftRotate(pnode &cur) {
            pnode tmp;
            tmp = cur->right;
            cur->right = tmp->left;
            tmp->left = cur;
            cur = tmp;
        }

        void InsertNode(pnode &cur, DType key) {
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

        void DeleteNode (pnode &cur, DType key) {
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

        void Erase(pnode cur) {
            if (cur->left != null) erase(cur->left);
            if (cur->right != null) erase(cur->right);
            delete cur;
        }

        void Prt(pnode cur) { 
            if(cur != null) {
                prt(cur->left);
                cout << cur->key1 << " " << cur->key2 << " " << cur->value << endl;
                prt(cur->right);
            }
        }

};
