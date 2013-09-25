
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode * last = 0, * p = 0, *next;
        next = root;
        TreeLinkNode header(0);
        while (next) {
            p = next;
            last = &header;
            last->next = 0;
            while (p) {
                if (p->left) {
                    last->next = p->left;
                    last = last->next;
                }
                if (p->right) {
                    last->next = p->right;
                    last = last->next;
                }
                p = p->next;
            }
            next = header.next;
        }
    }
};
