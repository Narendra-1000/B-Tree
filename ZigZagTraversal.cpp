#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	
};
TreeNode* newnode(int val){
		TreeNode* node = new TreeNode;
		node->val = val;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
void ZigZagTraversal(TreeNode* root){
	stack<TreeNode*> currlevel;
	stack<TreeNode*> nextlevel;
	bool LeftToRight = true;
	currlevel.push(root);
	while(currlevel.size()!=0){
		TreeNode* temp = currlevel.top();
		currlevel.pop();
		if(temp!=nullptr){
			cout<<temp->val<<" ";
			if(LeftToRight){
				if(temp->left!=nullptr){
					nextlevel.push(temp->left);
				}
				if(temp->right!=nullptr){
					nextlevel.push(temp->right);
				}
			}else{
				if(temp->right!=nullptr){
					nextlevel.push(temp->right);
				}
				if(temp->left!=nullptr){
					nextlevel.push(temp->left);
				}
			}
		}
		if(currlevel.size() == 0){
			LeftToRight = !LeftToRight;
			swap(currlevel,nextlevel);
		}
	}
}
int main(){
	TreeNode* root = newnode(12);
	root->left = newnode(9);
	root->right = newnode(15);
	root->left->left = newnode(5);
	root->left->right = newnode(10);
	ZigZagTraversal(root);
}
