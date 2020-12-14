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
void PreOrderTraversal(BinTree BT);
void MidOrderTraversal(BinTree BT);
void LastOrderTraversal(BinTree BT);
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
	PreOrderTraversal(start);
	cout << endl;
	MidOrderTraversal(start);
	cout << endl;
	LastOrderTraversal(start);
	cout << endl;
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
		
		return;
	}
	while (BT->data)
	{
		if (data == BT->data)
		{
			break;
		}
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
				
				break;
			}
		}
	}
	BT = start;
}
void PreOrderTraversal(BinTree BT)
{
	if (BT)
	{
		cout << BT->data << " ";
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
	}
}
void MidOrderTraversal(BinTree BT)
{
	if (BT)
	{
		
		MidOrderTraversal(BT->left);
		cout << BT->data << " ";
		MidOrderTraversal(BT->right);
	}
}
void LastOrderTraversal(BinTree BT)
{
	if (BT)
	{

		LastOrderTraversal(BT->left);
		
		LastOrderTraversal(BT->right);
		cout << BT->data << " ";
	}
}