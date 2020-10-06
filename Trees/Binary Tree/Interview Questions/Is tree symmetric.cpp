#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node *left, *right;
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


bool isSymmetric(node *root1, node *root2)
{
	if(root1==NULL && root2==NULL)
	{
		return true;
	}
	if(root1 && root2 && root1->data == root2->data)
	{
		return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
	}
	return false;
}

int main() 
{ 
    node *root        = new node(1); 
    root->left        = new node(2); 
    root->right       = new node(2); 
    root->left->left  = new node(3); 
    root->left->right = new node(4); 
    root->right->left  = new node(4); 
    root->right->right = new node(3); 
    //root->right->right->right = new node(9); 
  
    cout << isSymmetric(root, root); 
    return 0; 
} 
