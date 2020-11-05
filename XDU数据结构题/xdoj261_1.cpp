#include<iostream>
#include<string>
#include<queue>
#define HEAPCAPACITY 64 //设置堆的初始最大容量
#define MINWEIGHT 0 //设置哈夫曼树的最小权重
using namespace std;
typedef struct TreeNode* HuffmanTree; //设置哈夫曼树的左右儿子
typedef struct Heap* MinHeap; //堆的指针
struct TreeNode  //树
{
	int weight;
	HuffmanTree left;
	HuffmanTree right;
};
struct Heap //堆
{
	HuffmanTree* data; //用于存储哈夫曼树
	int size; //堆的大小
};
MinHeap createHeap(); //创建一个堆
HuffmanTree createWeightTree(); //创造一棵带权树
void sortHeap(MinHeap H, int i); //对子最小堆进行排序，输入参数i为你要调整的结点
void adjust(MinHeap H); //调整堆，通过调用sortHeap方法
MinHeap initHeap(int n); //初始化堆，n为堆里数据的个数
HuffmanTree Delete(MinHeap H); //删除堆的第一个元素，本来想delete的，结果好像是一个关键词不能直接用，只能改大写了-_-
void insert(MinHeap H, HuffmanTree Huff); //将Huff插入堆中
HuffmanTree createHuffman(MinHeap H); //从堆里取出元素构造哈夫曼树
int roadLength(HuffmanTree Huff); //基于层序遍历求哈夫曼树的带权路径长度
int main()
{
	MinHeap H;
	HuffmanTree Huff;
	int n,length;
	cin >> n;
	H = initHeap(n);
	Huff = createHuffman(H);
	length = roadLength(Huff);
	cout << length << endl;
	return 0;
}
MinHeap createHeap() //创建一个堆
{
	MinHeap H;
	H = (MinHeap)malloc(sizeof(struct Heap));
	H->data = (HuffmanTree*)malloc(sizeof(struct TreeNode) * HEAPCAPACITY);
	H->size = 0;
	HuffmanTree Huff = createWeightTree(); //设置一个哨兵
	H->data[0] = Huff;
	return H;
}
HuffmanTree createWeightTree() //创建一个哈夫曼树
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = MINWEIGHT;
	Huff->left = NULL;
	Huff->right = NULL;
	return Huff;
}
void sortHeap(MinHeap H, int i) //对子最小堆进行排序，输入参数i为你要调整的结点
{
	int parent, child;
	HuffmanTree Huff = H->data[i]; //拿到当前节点的哈夫曼树
	for (parent = i; parent * 2 <= H->size;parent = child)
	{
		child = parent * 2;
		//下面这种情况，是在左右孩子里找较小的，因为咱们这是子最小堆
		if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
			child++;
		//没有更小的了，已经比到最后了，就结束循环
		if (Huff->weight <= H->data[child]->weight)
			break;
		//否则就把儿子结点拿上去
		H->data[parent] = H->data[child];
	}
	H->data[parent] = Huff; //最后这个结点就是咱最开始输入进的结点应该待的地方
}
void adjust(MinHeap H) //调整堆，通过调用sortHeap方法
{
	for (int i = H->size / 2; i > 0; i--) //从后面开始，第一个有孩子的结点开始进行调整
	{									  //这样每次调整的最小
		sortHeap(H, i);
	}
}
MinHeap initHeap(int n) //初始化堆，n为堆里数据的个数
{
	MinHeap H = createHeap();
	HuffmanTree Huff;
	int weight;
	for (int i = 0; i < n; i++)
	{
		cin >> weight;
		Huff = createWeightTree();
		Huff->weight = weight;
		H->size++;
		H->data[H->size] = Huff;
	}
	adjust(H);  //数据都进来了就排个序
	return H;
}
HuffmanTree Delete(MinHeap H) //删除堆的第一个元素，本来想delete的，结果好像是一个关键词不能直接用，只能改大写了-_-
{
	HuffmanTree T = H->data[1]; //拿到第一个，也就是要删除的元素
	HuffmanTree Huff = H->data[H->size--]; //拿到最后一个元素，对他进行排序，直接--因为删除了一个元素
	int parent, child;
	//为什么从1开始呢，因为第一个元素被删掉取出来了，所以从第一个开始
	for (parent = 1; parent * 2 <= H->size;parent = child)
	{
		child = parent * 2;
		//第一步，左右儿子里面挑小的
		if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
			child++;
		//如果没有更小的了就退出
		if (Huff->weight <= H->data[child]->weight)
			break;
		//不然就继续循环
		H->data[parent] = H->data[child]; //下面的往上面补
	}
	H->data[parent] = Huff; //终于给最后一个元素找到了归宿^_^
	return T; //最开始取的，现在返回出去
}
void insert(MinHeap H, HuffmanTree Huff)//将Huff插入堆中
{
	H->size++;
	int i = H->size;
	for (;Huff->weight < H->data[i / 2]->weight; i /= 2) //这就是一个简单的判断循环
	{
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = Huff;
}
HuffmanTree createHuffman(MinHeap H) //从堆里取出元素构造哈夫曼树
{
	HuffmanTree Huff;
	int times = H->size;
	for (int i = 1; i < times; i++)
	{
		Huff = createWeightTree();
		Huff->left = Delete(H);
		Huff->right = Delete(H);
		Huff->weight = Huff->left->weight + Huff->right->weight;
		insert(H, Huff); //再把这个头结点加入堆中
	}
	Huff = Delete(H); //最后只需要这个头结点即可
	return Huff;
}
int roadLength(HuffmanTree Huff) //基于层序遍历求哈夫曼树的带权路径长度
{
	int first = Huff->weight;
	int length = 0;
	queue<HuffmanTree> q;
	HuffmanTree T;
	if (!Huff)  //如果传入的是空的话
		return NULL;
	q.push(Huff);
	while (!q.empty())
	{
		T = q.front();
		q.pop();
		length += T->weight;
		if (T->left)
			q.push(T->left);
		if (T->right)
			q.push(T->right);
	}
	return length - first;
}

