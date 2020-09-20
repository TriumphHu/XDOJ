#include<iostream>
#include<string>
#include "Link.h"
List L, L2;
List bing(List L1, List L2); //��������������Ĳ���������һ��List
List jiao(List L1, List L2); //��������������Ľ���������һ��List
List cha(List L1, List L2);  //��������������Ĳ�  ������һ��List,ֱ�Ӳ�����ԭ����A-B=A-AB,������L1
							 //����һ������ĵ�һ�����ݱ���ȥ�������ֱ�����L1ʱ�ᱨ����Ϊͷָ��λ�ñ��ı�
void newinit(); //��ʼ��L��L2������������

int main()
{
	newinit();
	List L3,L4,L5; //L3,4,5���ǹ����ˣ��ֱ��󲢣�������
	L3 = bing(L, L2);
	printList(L3);
	L4 = jiao(L, L2);
	printList(L4);
	cout << "����L��L2" << endl;
	printList(L);
	printList(L2);
	L5 = cha(L, L2);
	printList(L5);
	cout << "����L��L2" << endl;
	printList(L);
	printList(L2);
	return 0;
}
void newinit()
{
	
	L = init();
	L = insert(9989, 1, L);
	L = insert(999, 1, L);
	L = insert(888, 1, L);
	L = insert(777, 1, L);
	L = insert(66, 1, L);
	L = insert(65, 1, L);
	L = insert(64, 1, L);
	L = insert(6, 1, L);
	L = insert(5, 1, L);
	L = insert(3, 1, L);
	//L = insert(0, 1, L); //��Ϊ���ʱ��һ����ɾ���ͻᱨ��
	printList(L);
	
	L2 = init();
	L2 = insert(9999, 1, L2);
	L2 = insert(9900, 1, L2);
	L2 = insert(9777, 1, L2);
	L2 = insert(8888, 1, L2);
	L2 = insert(777, 1, L2);
	L2 = insert(66, 1, L2);
	L2 = insert(65, 1, L2);
	L2 = insert(64, 1, L2);
	L2 = insert(62, 1, L2);
	L2 = insert(51, 1, L2);
	L2 = insert(30, 1, L2);
	L2 = insert(0, 1, L2);
	printList(L2);
}
List bing(List L1, List L2)
{
	
	List L3 = init();
	int len_a, len_b, len_c = 1; //�����ʼ��λ������
	len_a = length(L1);
	len_b = length(L2);
	int i_a,i_b,temp1,temp2,flag_a,flag_b;
	i_a = i_b = 1;
	flag_a = flag_b = 0;
	while (true)
	{
	
		temp2 = findKth(i_b, L2)->data;
		temp1 = findKth(i_a, L1)->data;
		if (temp2 < temp1 || flag_a)
		{
			if (FindLocate(temp2, L3) == -1 )
			{
				L3 = insert(temp2, len_c, L3);
				len_c++;				
			}
			if(i_b != len_b) 
				i_b++;
			else      //���ѵ���������һ��flag��֮��ֱ�Ӽ�����һ������
			{
				flag_b = 1;
			}
		}
		else if(temp2 >= temp1 || flag_b)
		{
			L3 = insert(temp1, len_c, L3);
			len_c++;
			if(i_a!=len_a)
				i_a++;
			else
			{
				flag_a = 1;
			}
		}
		if (flag_a && flag_b)
			break;
	}
	return L3;
}
List jiao(List L1, List L2)
{
	List L3 = init();
	int len_a = length(L1);
	int len_b = length(L2);
	int len_c = 1;
	int temp;
	while (L2)
	{
		temp = L2->data;
		if (FindLocate(temp, L1) != -1)
		{
			L3 = insert(temp, len_c, L3);
			len_c++;
		}
		L2 = L2->next;
	}
	return L3;
}
List cha(List L1, List L2)
{
	List L3 = init();
	L3 = jiao(L1, L2); //��ȡ��������Ľ���
	
	int temp,locate;
	while (L3)
	{
		temp = L3->data;
		locate = FindLocate(temp, L1);
		if (locate != -1)
		{
			L1 = Delete(locate, L1);
		}
		L3 = L3->next;
	}
	return L1;
}