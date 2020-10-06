#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return (newNode); 
} 

int findMaxSum (Node *root, int &res)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int l = findMaxSum(root->left, res);
	int r = findMaxSum(root->right, res);
	
	//first case
	int temp = max(max(l,r)+root->data, root->data);
	//2nd case
	int ans = max(temp, l+r+root->data);
	
	res = max(res, ans);
	
	return temp;
}

  
int main(void) 
{ 
    struct Node *root = newNode(10); 
    root->left        = newNode(2); 
    root->right       = newNode(10); 
    root->left->left  = newNode(20); 
    root->left->right = newNode(1); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4); 
    int res = INT_MIN;
    findMaxSum(root, res);
    cout<<res<<endl;
    return 0; 
} 
