#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int val = 0;
		Node *left = nullptr;
		Node *right = nullptr;
		
		Node(int val){
			this->val = val;
		}
		
};


Node* buildTree(vector<int>& preorder,int psi,int pei,vector<int>& inorder,int isi,int iei){
        if(isi>iei){
            return NULL;
        }
        int idx = isi;
        while(inorder[idx]!=preorder[psi]){
            idx++;
        }
        int colse = idx-isi;
        Node* node = new Node(preorder[psi]);
        node->left = buildTree(preorder,psi+1,psi+colse,inorder,isi,idx-1);
        node->right = buildTree(preorder,psi+colse+1,pei,inorder,idx+1,iei);
        return node;
       
       
    }
void inorderPrint(Node* root){
	if(root == NULL){
		return;
	}
	inorderPrint(root->left);
	cout<<root->val<<" ";
	inorderPrint(root->right);
	
	
}
int main(){
	
	vector<int> preorder = {1,2,4,3,5};
	vector<int> inorder = {4,2,1,5,3};
	
	//build tree
	Node* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
	inorderPrint(root);
	

}
