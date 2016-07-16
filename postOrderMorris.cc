#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    char val;
    TreeNode(char ch): val(ch), left(NULL), right(NULL) {}
};

void toReverse(TreeNode* from, TreeNode* to) {
    TreeNode *tmp = from, *next, *head = NULL;

    while (1) {
        next = tmp -> right;
        tmp -> right = head;
        if (tmp == to) break;
        head = tmp;
        tmp = next;
    }
}

void printReserve(TreeNode *from, TreeNode *to) {
    TreeNode *node;

    toReverse(from, to);
    node = to;
    while(node != from) {
        cout << node -> val << " ";
        node = node -> right;
    }
    cout << node -> val << " ";
    toReverse(to, from);
}

void postOrderMorris(TreeNode * root) {
    TreeNode * dumb = new TreeNode('#');
    dumb -> left = root;
    TreeNode *cur = dumb;  

    while (cur != NULL) {  
        if (cur -> left != NULL) {  
            TreeNode *pre = cur -> left;  
            while (pre -> right != NULL && pre -> right != cur) pre = pre -> right;  
            if (pre -> right == NULL) { // set right to successor  
                pre -> right = cur;  
                cur = cur -> left;  
            } else { // visit and revert the change  
                pre -> right = NULL;  
                printReserve(cur -> left, pre);
                cur = cur -> right;  
            }  
        } else { // visit and move to successor 
            cur = cur -> right;  
        }  
    }  
}  

int main() {
    TreeNode *p;
    TreeNode *node = new TreeNode('a');
    node -> left = new TreeNode('b');
    node -> right = new TreeNode('c');
    p = node -> left;
    p -> left = new TreeNode('d');
    p = p -> left;
    p -> left = new TreeNode('f');
    p -> right = new TreeNode('g');
    p = node -> right;
    p -> right = new TreeNode('e');
    p = p -> right;
    p -> left = new TreeNode('h');
    p -> right = new TreeNode('i');
    postOrderMorris(node);
    return 0;
}

