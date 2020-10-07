#include <iostream>
#include <string>
using namespace std;

int* getNext(string T);
int* getNextVal(string T);
int KMP(string S, string T);    // SΪ������TΪģʽ��


int main()
{
        string S = "acabaabaabcacaabc";
        string T = "abaabcac";
        int* next = getNextVal(T);
        int* test = getNext(T);
        int num = KMP(S, T);
        cout << num << endl;
        for (int i = 0; i < 9; i++)
            cout << next[i]<< " ";
        cout << endl;
        for (int i = 0; i < 9; i++)
            cout << test[i] << " ";
        system("pause");
        return 0;
    }

//��ȡnext����
int* getNext(string T)
{
    int* next = new int[T.size()];
    int T_len = T.size();
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j])
        {
            j++;
            i++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}
int* getNextVal(string T)
{
    int* next = new int[T.size()];    // ����next����
    int T_len = T.size();
    int i = 0;    // T���±�
    int j = -1;
    next[0] = -1;
    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j])
        {
            if (T[i + 1] == T[j + 1])
            {
                i++;
                j++;       //KMP�Ż�
                next[i] = next[j];
            }
            else
            {
                i++;
                j++;
                next[i] = j;

            }
        }
        else
            j = next[j];
    }
    return next;

}

// KMP�㷨,�� S ���ҵ� T ��һ�γ��ֵ�λ�� 
int KMP(string S, string T)    // SΪ������TΪģʽ��
{

    int* next = getNextVal(T);
    int i = 0;        // S�±�
    int j = 0;        // T�±�
    int s_len = S.size(); //size��length�������󳤶�
    int t_len = T.size();
    while (i < s_len && j < t_len)
    {
        if (j == -1 || S[i] == T[j])    //T �ĵ�һ���ַ���ƥ���S[i] == T[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];        // ��ǰ�ַ�ƥ��ʧ�ܣ�������ת
    }
    if (j == t_len)            // ƥ��ɹ�
        return i - j;
    return -1;
}