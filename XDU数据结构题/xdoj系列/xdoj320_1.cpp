#include<iostream>
#include<string>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	int data;
	BinTree left;
	BinTree right;
};
BinTree createTree();
//求num在ar数组中的位置
int FindInt(int* ar, int num);
BinTree mergeIntTree(int* ar1, int* ar2, int len);
void LeaveNode(BinTree BT);
void PreOrderTraversal(BinTree BT);
void LastOrderTraversal(BinTree BT);
int main()
{
	int n;
	cin >> n;
	int arr1[1036] = {};
	int arr2[1036] = {};
	int* ar1;
	int* ar2;
	ar1 = arr1;
	ar2 = arr2;
	for (int i = 0; i < n; i++)
	{
		cin >> ar1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ar2[i];
	}
	BinTree BT = mergeIntTree(ar1, ar2, n);
	LeaveNode(BT);
	cout << endl;
	PreOrderTraversal(BT);
	cout << endl;
	LastOrderTraversal(BT);
	return 0;
}
BinTree createTree()
{
	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->left = NULL;
	BT->right = NULL;
	return BT;
}
int FindInt(int* ar, int num)
{
	int i = 0;
	while (ar[i] != num)
	{
		i++;
	}
	return i;
}
BinTree mergeIntTree(int* ar1, int* ar2, int len)
{
	if (len <= 0)
	{
		return NULL;
	}
	BinTree BT = createTree();
	int left[1036] = {};
	int right[1036] = {};
	int leftCount = 0;
	int rightCount = 0;
	int* left1 = left;
	int* right1 = right;
	int pos = FindInt(ar2, ar1[0]);
	BT->data = ar1[0];
	for (int i = 1; i < len; i++)
	{
		if (FindInt(ar2, ar1[i]) < pos)
		{
			left1[leftCount] = ar1[i];
			leftCount++;
		}
		else
		{
			right1[rightCount] = ar1[i];
			rightCount++;
		}
	}
	BT->left = mergeIntTree(left1, ar2, leftCount);
	BT->right = mergeIntTree(right1, ar2, rightCount);
	return BT;
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
void LastOrderTraversal(BinTree BT)
{
	if (BT)
	{
		LastOrderTraversal(BT->left);
		LastOrderTraversal(BT->right);
		cout << BT->data << " ";
	}
}
void LeaveNode(BinTree BT)
{
	if (BT->left == NULL && BT->right == NULL)
	{
		cout << BT->data << " ";
	}
	else
	{
		if (BT->left)
			LeaveNode(BT->left);
		if (BT->right)
			LeaveNode(BT->right);
	}
}
