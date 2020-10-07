#include <iostream>
#include <string>
using namespace std;

int* getNext(string T);
int* getNextVal(string T);
int KMP(string S, string T);    // S为主串，T为模式串


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

//获取next数组
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
    int* next = new int[T.size()];    // 声明next数组
    int T_len = T.size();
    int i = 0;    // T的下标
    int j = -1;
    next[0] = -1;
    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j])
        {
            if (T[i + 1] == T[j + 1])
            {
                i++;
                j++;       //KMP优化
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

// KMP算法,在 S 中找到 T 第一次出现的位置 
int KMP(string S, string T)    // S为主串，T为模式串
{

    int* next = getNextVal(T);
    int i = 0;        // S下标
    int j = 0;        // T下标
    int s_len = S.size(); //size和length都可以求长度
    int t_len = T.size();
    while (i < s_len && j < t_len)
    {
        if (j == -1 || S[i] == T[j])    //T 的第一个字符不匹配或S[i] == T[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];        // 当前字符匹配失败，进行跳转
    }
    if (j == t_len)            // 匹配成功
        return i - j;
    return -1;
}