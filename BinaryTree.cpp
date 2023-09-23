#include<iostream>
#include<queue>
using namespace std;
class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d)
		{
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
};
Node* buildTree(Node* root)
{
	int data;
	cout<<"Enter data: "<<endl;
	cin>>data;
	if(data==-1)
	return NULL;
	root=new Node(data);
	cout<<"Enter left data: "<<endl;
	root->left=buildTree(root->left);
	cout<<"Enter right data: "<<endl;
	root->right=buildTree(root->right);
	return root;
}
void levelOrderTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node*temp=q.front();
		cout<<"Data: "<<temp->data<<" ";
		q.pop();
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
	}
}
int main()
{
	Node*root=NULL;
	root=buildTree(root);
	levelOrderTraversal(root);
}