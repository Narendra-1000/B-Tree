#include<bits/stdc++.h>
using namespace std;
struct Node{

	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data){
	Node* node = new Node;
	node->data = data;
	node->left = node->right = nullptr;
	return node;
}
int idx = -1;
Node* buildTree(int nodes[]){
	idx++;
	if(nodes[idx] == -1){
		return nullptr;
	}
	Node* root = newNode(nodes[idx]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);
	return root;
}
void preOrder(Node* root){
	if(root == nullptr){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void inorder(Node* root){
	if(root == nullptr){
		return;
	}
		
	preOrder(root->left);
	cout<<root->data<<" ";
	preOrder(root->right);
}
void postorder(Node* root){
	if(root == nullptr){
		return;
	}
		
	preOrder(root->left);

	preOrder(root->right);
	cout<<root->data<<" ";
}
void levelorder(Node* root){
	if(root == nullptr){
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(nullptr);
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node == nullptr){
			cout<<endl;
			if(q.empty()){
				break;
			}else{
				q.push(nullptr);
			}
		}else{
			cout<<node->data<<" ";
			if(node->left != nullptr){
				q.push(node->left);
			}
			if(node->right !=nullptr){
				q.push(node->right);
			}
		}
	}
}
int count(Node* root){
	if(root == nullptr){
		return 0;
	}
	int lc = count(root->left);
	int rc = count(root->right);
	return lc+rc+1;
}
int sum(Node* root){
	if(root == nullptr){
		return 0;
	}
	int lc = sum(root->left);
	int rc = sum(root->right);
	return lc+rc+root->data;
}
int height(Node* root){
	if(root == nullptr){
		return 0;
	}
	int lc = height(root->left);
	int rc = height(root->right);
	return max(lc,rc)+1;
}
int diameter(Node* root){
	if(root == nullptr){
		return 0;
	}
	int diam1 = diameter(root->left);
	int diam2 = diameter(root->right);
	int diam3 = height(root->left)+height(root->right)+1;
	
	return max(diam3,max(diam1,diam2));
}
int main(){
	int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

	Node* root = buildTree(nodes);

	//preOrder(root);

	//inorder(root);

	//postorder(root);
	
	//levelorder(root);
	//cout<<count(root)<<endl;
	//cout<<sum(root)<<endl;
	//cout<<height(root);
	cout<<diameter(root);
}
