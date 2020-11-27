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
BinTree mergeTree(string s1, string s2, int len);
void LastOrderTraversal(BinTree BT);
int main()
{
	string s1, s2;
	getline(cin,s1);
	getline(cin,s2);
	BinTree BT = mergeTree(s1, s2,s1.size());
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
BinTree mergeTree(string s1, string s2, int len)
{
	if (len <= 0)
		return NULL;
	BinTree BT = createTree();
	int head = s2.find(s1[0]);
	BT->data = s1[0];
	string s3, s4, s5;
	s3 = s1.substr(1);
	BT->left = mergeTree(s3, s2, head);
	s4 = s1.substr(head + 1);
	s5 = s2.substr(head + 1);
	BT->right = mergeTree(s4, s5, len - head - 1);
	return BT;
}
void LastOrderTraversal(BinTree BT)
{
	if (BT)
	{
		LastOrderTraversal(BT->left);
		LastOrderTraversal(BT->right);
		cout << BT->data;
	}
}
