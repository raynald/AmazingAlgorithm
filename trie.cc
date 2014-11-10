#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

class Trie {
    private:
        struct TrieNode {
            int value;
            TrieNode *children[ALPHABET_SIZE];
            TrieNode() { 
                value = 0;
                for(int i = 0; i < ALPHABET_SIZE; i++) {
                    children[i] = NULL;
                }
            }
        };
        TrieNode *root;
        int count;

    public:
        Trie() {
            root = new TrieNode;
            count = 0;
        }

        void insert(string key) {
            int level;
            int length = key.length();
            int index;
            TrieNode *pCrawl;

            count++;
            pCrawl = root;
            for( level = 0; level < length; level++ ) {
                index = key[level] - 'a';
                if( pCrawl->children[index] ) 
                    pCrawl = pCrawl->children[index];
                else {
                    pCrawl->children[index] = new TrieNode;
                    pCrawl = pCrawl->children[index];
                }
            }
            pCrawl->value = count;
        }

        bool search(string key) {
            int length = key.length();
            int index;

            TrieNode *pCrawl;
            pCrawl = root;
            for(int level = 0; level < length; level++ ) {
                index = key[level] - 'a';
                if( !pCrawl->children[index] ) return 0;
                pCrawl = pCrawl->children[index];
            }
            return (pCrawl!=NULL && pCrawl->value);
        }

        bool leafNode(TrieNode *pNode) {
            return (pNode->value != 0);
        }

        bool isItFreeNode(TrieNode *pNode) {
            for(int i = 0; i < ALPHABET_SIZE; i++) 
                if( pNode->children[i] ) return 0;
            return 1;
        }

        bool deleteHelper(TrieNode *pNode, string key, int level, int len) {
            if( pNode ) {
                if( level == len ) {
                    if( pNode->value ) {
                        pNode->value = 0;
                        if( isItFreeNode(pNode) ) return true;
                        return false;
                    }
                }
                else {
                    int index = key[level] - 'a';

                    if( deleteHelper(pNode->children[index], key, level+1, len) ) {
                        delete pNode->children[index];
                        return ( !leafNode(pNode) && isItFreeNode(pNode) );
                    }
                }
            }
            return false;
        }

        void deleteKey(string key) {
            int len = key.length(); 
            if( len > 0 ) 
                deleteHelper(root, key, 0, len);
        }
};

int main() {
    vector<string> keys  = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    Trie tree;

    for(int i = 0; i < keys.size(); i++) {
        tree.insert(keys[i]);
    }
    printf("%s %s\n", "she", tree.search("she") ? "Present in trie" : "Not present in trie");
    tree.deleteKey(keys[0]);
    printf("%s %s\n", "she", tree.search("she") ? "Present in trie" : "Not present in trie");
 
    return 0;
}
