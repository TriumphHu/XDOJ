#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef struct TreeNode* BinTree; //指向树节点的指针
struct TreeNode
{
	int data;
	BinTree left;
	BinTree right;
};
//创建一个树
BinTree createBinTree();
void Insert(BinTree BT,int data);
BinTree BB = createBinTree();
//先序遍历
void PreOrderTraversal(BinTree BT);
//后序遍历
void PostOrderTraversal(BinTree BT);

int main()
{
	
	int n,temp;
	cin >> n;
	cin >> BB->data;
	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		Insert(BB, temp);
	}
	PreOrderTraversal(BB);
	cout << endl;
	PostOrderTraversal(BB);
	cout << endl;
	return 0;
}
BinTree createBinTree()
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->left = NULL;
	BT->right = NULL;
	return BT;
}
void Insert(BinTree BT,int data)
{
	BinTree start = BT;
	BinTree tree = createBinTree();
	tree->data = data;
	while (BT)
	{
		if (data < BT->data)
		{
			if (BT->left)
			{
				BT = BT->left;
			}
			else
			{
				BT->left = tree;
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
				BT->right = tree;
				break;
			}
		}
	}
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
void PostOrderTraversal(BinTree BT)
{
	if (BT)
	{
		PostOrderTraversal(BT->left);
		PostOrderTraversal(BT->right);
		cout << BT->data << " ";
	}
}
