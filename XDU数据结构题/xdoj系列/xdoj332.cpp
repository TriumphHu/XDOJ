#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	int data;
	BinTree left;
	BinTree right;
};
BinTree createTree();
void LevelOrderTraversal(BinTree BT);
void initTree();
void initBinTree(BinTree BT, int data, int left, int right);
int pre = -300;
int n, root;
int arr[10005][5] = {};
void init();
int flag = 1;
void ExamBinTree3(BinTree BT);
int exam[1005] = {};
int t = 0;
int main()
{
	BinTree BT = createTree();
	BinTree start = BT;
	init();
	initBinTree(BT, arr[root][0], arr[root][1], arr[root][2]);
	ExamBinTree3(BT);
	for (int i = 0; i < n-1; i++)
	{
		if (exam[i] >= exam[i + 1])
			flag = 0;
	}
	if (flag)
		cout << "true";
	else
		cout << "false";

	return 0;
}
void init()
{
	cin >> n >> root;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1];
		cin >> arr[i][2];
	}
}
BinTree createTree()
{
	BinTree tree = (BinTree)malloc(sizeof(struct TreeNode));
	tree->data = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

void initBinTree(BinTree BT, int data, int left, int right)
{
	BT->data = data;
	if (left == 0 && right == 0)
	{
		return;
	}
	if (left != 0)
	{
		BinTree	Lefttemp = createTree();
		BT->left = Lefttemp;
		
		initBinTree(BT->left, arr[left][0], arr[left][1], arr[left][2]);
	}	
	if (right != 0)
	{
		BinTree	Righttemp = createTree();
		BT->right = Righttemp;
		
		initBinTree(BT->right, arr[right][0], arr[right][1], arr[right][2]);
	}
		
}
void ExamBinTree3(BinTree BT)
{
	if (BT)
	{
		ExamBinTree3(BT->left);
		exam[t] = BT->data;
		t++;
		ExamBinTree3(BT->right);
	}
	
}
