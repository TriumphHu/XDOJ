#include<iostream>
#include<string>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	char data;
	BinTree left;
	BinTree right;
};
BinTree createTree();
BinTree init();
void InOrderTraversal(BinTree BT);
int i = 0;
string s;
int main()
{
	
	getline(cin, s);
	BinTree BT = createTree();
	BT = init();
	InOrderTraversal(BT);
	return 0;
}
BinTree createTree()
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->left = NULL;
	BT->right = NULL;
	return BT;
}
BinTree init()
{
	char c = s[i];
	i++;
	BinTree BT = createTree();
	if (c != '#')
	{
		BT->data = c;
		BT->left = init();
		BT->right = init();
	}
	else
	{
		return NULL;
	}
	return BT;
}
void InOrderTraversal(BinTree BT)
{
	if (BT)
	{
		InOrderTraversal(BT->left);
		cout << BT->data << " ";
		InOrderTraversal(BT->right);
	}
}
