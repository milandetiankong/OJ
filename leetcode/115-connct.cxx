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
        while (next) {
            p = next;
            next = next->left;

            if (! p->left) break;
            last = p->right;
            p->left->next = last;
            p = p->next;
            while (p) {
                if (! p->left) break;
                last->next = p->left;
                last = p->right;
                p->left->next = last;
                if (! p->right) break;
                p = p->next;
            }
        }
    }
};
