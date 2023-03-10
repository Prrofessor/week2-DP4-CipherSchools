/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef TreeNode Node;
class Solution {
public:
    void build(unordered_map<int,int> &mp,vector<int> &inorder){
        for(int i =0 ;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return;
    }

    Node* solve(vector<int> &pre,vector<int> &in,int &index,int start,int end,int size,unordered_map<int,int> &mp){
        if(index < 0 || start > end) return NULL;
        int ele = pre[index--];
        Node * root = new Node(ele);
        root->right = solve(pre,in,index,mp[ele]+1,end,size,mp);
        root->left = solve(pre,in,index,start,mp[ele]-1,size,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        build(mp,inorder);
        int n = postorder.size();
        int index = n-1 ;
        return solve(postorder,inorder,index,0,n-1,n,mp);
    }
};
