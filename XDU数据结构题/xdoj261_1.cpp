#include<iostream>
#include<string>
#include<queue>
#define HEAPCAPACITY 64 //���öѵĳ�ʼ�������
#define MINWEIGHT 0 //���ù�����������СȨ��
using namespace std;
typedef struct TreeNode* HuffmanTree; //���ù������������Ҷ���
typedef struct Heap* MinHeap; //�ѵ�ָ��
struct TreeNode  //��
{
	int weight;
	HuffmanTree left;
	HuffmanTree right;
};
struct Heap //��
{
	HuffmanTree* data; //���ڴ洢��������
	int size; //�ѵĴ�С
};
MinHeap createHeap(); //����һ����
HuffmanTree createWeightTree(); //����һ�ô�Ȩ��
void sortHeap(MinHeap H, int i); //������С�ѽ��������������iΪ��Ҫ�����Ľ��
void adjust(MinHeap H); //�����ѣ�ͨ������sortHeap����
MinHeap initHeap(int n); //��ʼ���ѣ�nΪ�������ݵĸ���
HuffmanTree Delete(MinHeap H); //ɾ���ѵĵ�һ��Ԫ�أ�������delete�ģ����������һ���ؼ��ʲ���ֱ���ã�ֻ�ܸĴ�д��-_-
void insert(MinHeap H, HuffmanTree Huff); //��Huff�������
HuffmanTree createHuffman(MinHeap H); //�Ӷ���ȡ��Ԫ�ع����������
int roadLength(HuffmanTree Huff); //���ڲ����������������Ĵ�Ȩ·������
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
MinHeap createHeap() //����һ����
{
	MinHeap H;
	H = (MinHeap)malloc(sizeof(struct Heap));
	H->data = (HuffmanTree*)malloc(sizeof(struct TreeNode) * HEAPCAPACITY);
	H->size = 0;
	HuffmanTree Huff = createWeightTree(); //����һ���ڱ�
	H->data[0] = Huff;
	return H;
}
HuffmanTree createWeightTree() //����һ����������
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = MINWEIGHT;
	Huff->left = NULL;
	Huff->right = NULL;
	return Huff;
}
void sortHeap(MinHeap H, int i) //������С�ѽ��������������iΪ��Ҫ�����Ľ��
{
	int parent, child;
	HuffmanTree Huff = H->data[i]; //�õ���ǰ�ڵ�Ĺ�������
	for (parent = i; parent * 2 <= H->size;parent = child)
	{
		child = parent * 2;
		//��������������������Һ������ҽ�С�ģ���Ϊ������������С��
		if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
			child++;
		//û�и�С���ˣ��Ѿ��ȵ�����ˣ��ͽ���ѭ��
		if (Huff->weight <= H->data[child]->weight)
			break;
		//����ͰѶ��ӽ������ȥ
		H->data[parent] = H->data[child];
	}
	H->data[parent] = Huff; //���������������ʼ������Ľ��Ӧ�ô��ĵط�
}
void adjust(MinHeap H) //�����ѣ�ͨ������sortHeap����
{
	for (int i = H->size / 2; i > 0; i--) //�Ӻ��濪ʼ����һ���к��ӵĽ�㿪ʼ���е���
	{									  //����ÿ�ε�������С
		sortHeap(H, i);
	}
}
MinHeap initHeap(int n) //��ʼ���ѣ�nΪ�������ݵĸ���
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
	adjust(H);  //���ݶ������˾��Ÿ���
	return H;
}
HuffmanTree Delete(MinHeap H) //ɾ���ѵĵ�һ��Ԫ�أ�������delete�ģ����������һ���ؼ��ʲ���ֱ���ã�ֻ�ܸĴ�д��-_-
{
	HuffmanTree T = H->data[1]; //�õ���һ����Ҳ����Ҫɾ����Ԫ��
	HuffmanTree Huff = H->data[H->size--]; //�õ����һ��Ԫ�أ�������������ֱ��--��Ϊɾ����һ��Ԫ��
	int parent, child;
	//Ϊʲô��1��ʼ�أ���Ϊ��һ��Ԫ�ر�ɾ��ȡ�����ˣ����Դӵ�һ����ʼ
	for (parent = 1; parent * 2 <= H->size;parent = child)
	{
		child = parent * 2;
		//��һ�������Ҷ���������С��
		if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
			child++;
		//���û�и�С���˾��˳�
		if (Huff->weight <= H->data[child]->weight)
			break;
		//��Ȼ�ͼ���ѭ��
		H->data[parent] = H->data[child]; //����������油
	}
	H->data[parent] = Huff; //���ڸ����һ��Ԫ���ҵ��˹���^_^
	return T; //�ʼȡ�ģ����ڷ��س�ȥ
}
void insert(MinHeap H, HuffmanTree Huff)//��Huff�������
{
	H->size++;
	int i = H->size;
	for (;Huff->weight < H->data[i / 2]->weight; i /= 2) //�����һ���򵥵��ж�ѭ��
	{
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = Huff;
}
HuffmanTree createHuffman(MinHeap H) //�Ӷ���ȡ��Ԫ�ع����������
{
	HuffmanTree Huff;
	int times = H->size;
	for (int i = 1; i < times; i++)
	{
		Huff = createWeightTree();
		Huff->left = Delete(H);
		Huff->right = Delete(H);
		Huff->weight = Huff->left->weight + Huff->right->weight;
		insert(H, Huff); //�ٰ����ͷ���������
	}
	Huff = Delete(H); //���ֻ��Ҫ���ͷ��㼴��
	return Huff;
}
int roadLength(HuffmanTree Huff) //���ڲ����������������Ĵ�Ȩ·������
{
	int first = Huff->weight;
	int length = 0;
	queue<HuffmanTree> q;
	HuffmanTree T;
	if (!Huff)  //���������ǿյĻ�
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

