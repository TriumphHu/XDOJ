#include<iostream>
#include<string>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	int data;
	BinTree parent;
	BinTree left;
	BinTree right;
};
BinTree createTree();
void initTree(int data);
BinTree BT = createTree();
BinTree start = BT;
int main()
{
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		initTree(temp);
	}
	return 0;
}
BinTree createTree()
{
	BinTree tree = (BinTree)malloc(sizeof(struct TreeNode));
	tree->data = NULL;
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
void initTree(int data)
{
	BinTree tempTree = createTree();
	tempTree->data = data;
	if (!BT->data)
	{
		BT->data = data;
		cout << -1 << endl;
		return;
	}
	while (BT->data)
	{
		if (data < BT->data)
		{
			if (BT->left)
			{
				BT = BT->left;
			}
			else
			{
				tempTree->parent = BT;
				BT->left = tempTree;
				cout << tempTree->parent->data << endl;
				break;
			}
		}
		else
		{
			if (BT->right)
			{
				BT = BT->right;
			}
			else
			{
				tempTree->parent = BT;
				BT->right = tempTree;
				cout << tempTree->parent->data << endl;
				break;
			}
		}			
	}
	BT = start;
}