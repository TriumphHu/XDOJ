#include<iostream>
#include<string>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	int data;
	int sum;
	BinTree left;
	BinTree right;
};
BinTree createTree();
BinTree mergeIntTree(int *ar1, int *ar2, int len);
int FindInt(int* ar,int num);
BinTree sumTree(BinTree BT);
void MidOrderTraversal(BinTree BT);
int main()
{
	int arr1[1036] = {};
	int arr2[1036] = {};
	int* ar1, * ar2;
	ar1 = arr1;
	ar2 = arr2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ar2[i];
	}
	
	BinTree BT = mergeIntTree(ar1, ar2, n);
	
	BinTree BTT = sumTree(BT);
	MidOrderTraversal(BTT);
	return 0;
}
BinTree createTree()
{
	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->left = NULL;
	BT->right = NULL;
	BT->sum = 0;
	return BT;
}
BinTree mergeIntTree(int* ar1, int* ar2, int len)
{
	if (len <= 0)
		return NULL;
	BinTree BT = createTree();
	int head = FindInt(ar2, ar1[0]);

	BT->data = ar1[0];
	BT->left = mergeIntTree(ar1 + 1, ar2, head);
	
	BT->right = mergeIntTree(ar1 + head + 1, ar2 + head + 1, len - head - 1);
	return BT;
}

void MidOrderTraversal(BinTree BT)
{
	if (BT)
	{
		MidOrderTraversal(BT->left);
		cout << BT->sum<<" ";
		MidOrderTraversal(BT->right);
		
	}
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
BinTree sumTree(BinTree BT)
{
	if (BT)
	{
		sumTree(BT->left);
		sumTree(BT->right);
		if (BT->left != NULL && BT->right != NULL)
		{
			BT->sum = BT->left->data + BT->right->data + BT->left->sum + BT->right->sum;
			
		}
		
	}
	return BT;
}
