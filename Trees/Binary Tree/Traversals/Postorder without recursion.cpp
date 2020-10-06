#include<bits/stdc++.h>
using namespace std;

//A blue print of what tree will contain
struct node{
	//a variable to store data
	int data;
	//left and right named user defined pointers to point to it's child nodes.
	node *left, *right;
	
	//user defined function to create a node.
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printPostorder_2S(node *root)
{
	stack<node*> s1;
	stack<node*> s2;
	
	s1.push(root);
	
	node *cur;
	while(!s1.empty())
	{
		cur = s1.top();
		s1.pop();
		s2.push(cur);
		
		if(cur->left)
		{
			s1.push(cur->left);
		}
		
		if(cur->right)
		{
			s1.push(cur->right);
		}
		
	}
	
	while(s2.empty()==false)
	{
		cur=s2.top();
		s2.pop();
		cout<<cur->data<<" ";
	}
	
}

void printPostorder_1S(node *root)
{
 if (root == NULL) 
        return; 
      
    stack<node*> s;
    do
    { 
        while (root) 
        { 
            if (root->right) 
                s.push(root->right); 
            s.push(root);   
            root = root->left; 
        } 
 
        root = s.top();
		s.pop(); 
  
        if ( s.empty()==false && root->right && s.top() == root->right) 
        { 
            s.pop();  
            s.push(root);  
            root = root->right; 
                                
        } 
        else  
        { 
            cout<<root->data<<" "; 
            root = NULL; 
        } 
    } while (!s.empty()); 
 
}

int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	
	printPostorder_2S(root);
	cout<<endl;
	printPostorder_1S(root);
	
}
