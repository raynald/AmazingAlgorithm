#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class LeftistHeap {
    public:
        LeftistHeap() {
            root = NULL;
        }

        LeftistHeap(LeftistHeap &rhs) {
            root = NULL;
            *this = rhs;
        }

        ~LeftistHeap() {
            makeEmpty( );
        }

        bool isEmpty() {
            return root == NULL;
        }

        int &findMin() {
            return root->element;
        }

        void Insert(int &x) {
            root = Merge(new LeftistNode(x), root);
        }

        void deleteMin() {
            LeftistNode *oldRoot = root;
            root = Merge(root->left, root->right);
            delete oldRoot;
        }

        void deleteMin(int &minItem) {
            if (isEmpty()) {
                cout<<"Heap is Empty"<<endl;
                return;
            }
            minItem = findMin();
            deleteMin();
        }

        void makeEmpty() {
            reclaimMemory(root);
            root = NULL;
        }   

        void Merge(LeftistHeap &rhs) {
            if (this == &rhs) return;
            root = Merge(root, rhs.root);
            rhs.root = NULL;
        }

        LeftistHeap & operator=(LeftistHeap &rhs) {
            if (this != &rhs) {
                makeEmpty();
                root = clone(rhs.root);
            }
            return *this;
        }

    private:
        struct LeftistNode {
            T element;
            LeftistNode *left;
            LeftistNode *right;
            int npl;
            LeftistNode(T & _element, LeftistNode *lt = NULL, LeftistNode *rt = NULL, int np = 0) {
                element = _element;
                right = rt;
                left = lt;
                npl =  np;
            }
        };

        LeftistNode *root;

        LeftistNode *Merge(LeftistNode *h1, LeftistNode *h2) {
            if (h1 == NULL) return h2;
            if (h2 == NULL) return h1;
            if (h1->element < h2->element)
                return Merge1(h1, h2);
            else
                return Merge1(h2, h1);
        }

        LeftistNode *Merge1(LeftistNode *h1, LeftistNode *h2) {
            if (h1->left == NULL) h1->left = h2;
            else {
                h1->right = Merge(h1->right, h2);
                if (h1->left->npl < h1->right->npl) swapChildren(h1);
                h1->npl = h1->right->npl + 1;
            }
            return h1;
        }

        void swapChildren(LeftistNode * t) {
            LeftistNode *tmp = t->left;
            t->left = t->right;
            t->right = tmp;
        }

        void reclaimMemory(LeftistNode * t) {
            if (t != NULL) {
                reclaimMemory(t->left);
                reclaimMemory(t->right);
                delete t;
            }
        }

        LeftistNode *clone(LeftistNode *t) {
            if (t == NULL) return NULL;
            else return new LeftistNode(t->element, clone(t->left), clone(t->right), t->npl);
        }
};

int main() {
    LeftistHeap<int> h;
    LeftistHeap<int> h1;
    LeftistHeap<int> h2;

    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            h.Insert(i);
            cout<<"Element"<<i<<" inserted in Heap 1"<<endl;
        }
        else {
            h1.Insert(i);
            cout<<"Element"<<i<<" inserted in Heap 2"<<endl;
        }
    }
    h.Merge(h1);
    h2 = h;
    for (int i = 0; i < 20; i++) {
        int x;
        h2.deleteMin(x);
        cout<<"Element "<<x<<" Deleted"<<endl;
        if (h2.isEmpty()) {
            cout<<"The Heap is Empty"<<endl;
            break;
        }
    }

    return 0;
}

