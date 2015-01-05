#include<iostream>

using namespace std;

template<typename T>
class Stream {
    public:
        Stream() {
            root = TreeNode(1,3);
        }

        void Peek() {
        }

        void Next() {
        }

        void HasNext() {
        }

        void Append() {
        }
    private:
        struct TreeNode {
            int left;
            int right;
            TreeNode() {}
            TreeNode(const int &x, const int &y): left(x), right(y) {}
        };
        TreeNode root;
    friend ostream& operator<<(ostream &os, const Stream &node);
};

ostream& operator<<(ostream &os, const Stream &node) {
    os << node.root.left << " " << node.root.right << endl;
    return os;
}

int main() {
    Stream s;
    cout << s << endl;
    return 0;
}
