#include <iostream>
#include <math.h>
#include <algorithm>


struct Treenode {
    int val; 
    Treenode *left; 
    Treenode *right;
};
class Solution
{
public:
    int answer = 0; 
    int maxpathsum(Treenode *root) {
        helper(root);
        return answer;
    }
    int helper(Treenode *node) {
        if (node == nullptr) {
            return 0;
        }
        int Maxleftpath = std::max(helper(node->left), 0);
        int Maxrightpath = std::max(helper(node->right), 0);
        answer = std::max(answer, Maxleftpath + Maxrightpath + node->val);
        return std::max(Maxleftpath, Maxrightpath) + node->val;
    }



};





int main()
{
    Treenode* root = new Treenode{ 10, nullptr, nullptr };
    root->left = new Treenode{ 5, nullptr, nullptr };
    root->right = new Treenode{ 15, nullptr, nullptr };
    root->left->left = new Treenode{ 2, nullptr, nullptr };
    root->left->right = new Treenode{ 7, nullptr, nullptr };
    root->right->left = new Treenode{ 12, nullptr, nullptr };
    root->right->right = new Treenode{ 20, nullptr, nullptr };
    Solution s;
    int max_sum = s.maxpathsum(root);
    std::cout << "Max path sum: " << max_sum << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

}

