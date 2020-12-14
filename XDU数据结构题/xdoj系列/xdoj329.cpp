#include<iostream>
#include<string>
using namespace std;
typedef struct BinTree* TreeNode;
struct BinTree
{
	int data;
	TreeNode left;
	TreeNode right;
};
TreeNode createTree();
TreeNode initTree(string s);
void PreOrderTraversal(TreeNode tree);
bool cmpTree(TreeNode tree1, TreeNode tree2);
int flag;
int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		string std;
		cin >> std;
		TreeNode stdTree = initTree(std);
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			TreeNode tempTree = initTree(temp);
			flag = 1;
			if (cmpTree(stdTree, tempTree))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		cin >> n;
	}
	
	return 0;
}
TreeNode createTree()
{
	TreeNode tree = (TreeNode)malloc(sizeof(struct BinTree));
	tree->data = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
TreeNode initTree(string s)
{
	TreeNode tree = createTree();
	int len = s.size();
	int loc = 0;
	char c = s[loc];
	int temp = c - '0';
	tree->data = temp;
	loc++;
	TreeNode start = tree;
	for (int i = 1; i < len; i++)
	{
		temp = s[loc] - '0';
		loc++;
		TreeNode tempTree = createTree();
		tempTree->data = temp;
		while (tree->data)
		{
			if (temp < tree->data)
			{
				if (tree->left)
				{
					tree = tree->left;
				}
				else
				{
					tree->left = tempTree;
					break;
				}
			}
			else
			{
				if (tree->right)
				{
					tree = tree->right;
				}
				else
				{
					tree->right = tempTree;
					break;
				}
			}
		}
		tree = start;
	}
	return start;
}
void PreOrderTraversal(TreeNode tree)
{
	if (tree)
	{
		cout << tree->data << " ";
		PreOrderTraversal(tree->left);
		PreOrderTraversal(tree->right);
	}
}
bool cmpTree(TreeNode tree1, TreeNode tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	else if (tree1 == NULL || tree2 == NULL)
	{
		flag = 0;
		return false;

	}
	else if (tree1->data == tree2->data)
	{
		cmpTree(tree1->left, tree2->left);
		cmpTree(tree1->right, tree2->right);
	}
	else
	{
		flag = 0;
		return false;
	}
	return flag;
}
