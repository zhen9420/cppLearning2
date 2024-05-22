#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int m,n;

// int letter[27] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168};
// 64 13 22 32 103 21 15 47 57 1 5 32 20 57 63 15 1 48 51 80 23 8 18 1 16 1 168
int letter[28]; // 用于存储26个字母以及空格的出现的概率次数
char lee[28] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};

// 动态分配数组存储哈夫曼编码表
typedef char** HCode;

// 哈夫曼树的存储结构
typedef struct
{
    int w;
    int parent,lchild,rchild;
} HTNode,*HTree;

// 全局调用
HTree T;
HCode HC;

// ======================= 哈夫曼树的构造 ===========================

// 在树T中，k为节点的总个数，获取两个节点权值最小的值
void Select(HTree T,int k,int &s1,int &s2)
{
    int tmp = 100000,tmp1 = 100000;
    // 先获得一个最小的，然后再获得倒数第二小的，依次遍历，求最小权值
    for(int i = 1; i <= k; i ++)
    {
        if(!T[i].parent)
        {
            if(tmp > T[i].w)
            {
                tmp = T[i].w;
                s1 = i;
            }
        }
    }
    for(int i = 1; i <= k; i ++)
    {
        if(!T[i].parent && i != s1)
        {
            if(tmp1 > T[i].w)
            {
                tmp1 = T[i].w;
                s2 = i;
            }
        }
    }
}

// 构造哈夫曼编码树
void CreateHuffmanTree(HTree &T,int n) // n 是指叶子节点的个数
{
    if(n <= 1) return ;
    m = 2 * n - 1; // 拥有n个叶子结点的哈夫曼树共有2n-1个结点
    T = new HTNode[m + 1]; // 分配单元，存放结点
    for(int i = 1; i <= m; i ++)
    {
        T[i].parent = 0;
        T[i].lchild = 0;
        T[i].rchild = 0;
        T[i].w = 0;
    }
    for(int i = 1; i <= n; i ++) T[i].w = letter[i]; // 将输入的权值赋给每个结点的权值

    for(int i = n+1; i <= m; i ++)
    {
        int s1 = 0,s2 = 0;
        // 选择两个双亲域为0，且权值最小的节点，并返回他们的序号s1,s2;
        Select(T,i - 1, s1,s2);

        // 得到新节点i，从森林中删除s1,s2，将s1,s2的双亲域由0变为i
        T[s1].parent = i;
        T[s2].parent = i;

        // s1,s2为新节点的两个孩子，i的权值是两个子孩子的和
        T[i].lchild = s1;
        T[i].rchild = s2;
        T[i].w = T[s1].w + T[s2].w;
    }
}

// ======================= 哈夫曼树编码的生成 ===========================

// 创建哈夫曼编码
void CreateHCode(HTree T, HCode &HC, int n)
{
    HC = new char* [n + 1]; // 存放n个字符的编码的表
    char* cd = new char[n]; // 临时存放每个字符的编码

    cd[n - 1] = '\0'; // 编码结束符

    // 一次得到每个结点的编码
    for(int i = 1; i <= n; i ++)
    {
        // start 一般指向最后一个 ，倒着开始遍历
        int start = n - 1;
        int c = 0, f = 0;
        c = i;
        f = T[i].parent;
        while(f != 0)
        {
            -- start ;
            if(T[f].lchild == c) cd[start] = '0';
            else cd[start] = '1';
            c = f ;
            f = T[f].parent;
        }
        HC[i] = new char[n - start];
        // 从 start 后的所有值 复制给 HC[i]
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}

// 打印哈夫曼编码的打印
void PrintHTree(HCode &HC,int n)
{
    cout << std::left << setw(10) <<"字母" << std::left << setw(10) << "编码" << endl;

    for(int i = 1; i <= n; i ++)
    {
        // std::left 使后面输出的值向左对齐
        cout << std::left << setw(10) << lee[i] ;
        string str = HC[i];
        cout << std::left << setw(10) << str << endl;
    }
}


//======================= 字符的转码功能 ============================


// 按输入的字符打印编码
void Printe(HCode &HC,int l)
{
    string str = HC[l];
    cout <<str;
}

// 字符的转码
void change()
{
    cin.ignore();
    char a[100]; // 最多输入一百个字符，包含空格
    cin.getline(a,100);
    int len = strlen(a);
    for(int i = 0; i < len ; i ++)
    {
        int l = a[i]; // 转化为ASCII值
        if(a[i] == ' ') l = 27;
        else if(l >= 97)
        {
            l -= 96;
        }
        else if(l < 97 && l >= 65)
        {
            l -= 64;
        }
        Printe(HC,l);
    }
    cout << endl;
}


// ======================== 哈夫曼编码解码 =================================

void decoding(HCode &HC,int n,string s)
{
    string temp = ""; // 依次获取一个字符，并和编码表里面的字符串对比
    char str[1000]; // 用来存放解码后的数字
    for(int i = 0; i < 1000; i ++) str[i] = '1'; // 每次定义char ，防止上次的结果影响这次的答案
    int h = 0; // str 存储的下标
    for(unsigned int i = 0; i < s.length(); i ++)
    {
        temp = temp + s[i]; // 依次获取一个字符
        for(int j = 1; j <= n; j ++)
        {
            string str2 = HC[j];
            if(temp == str2)
            {
                str[h ++] = lee[j];
                temp = "";
            }
            else if(i == s.length() - 1&& j == n  && temp != "")
            {
                cout <<"解码错误";
                break;
            }
        }
    }
    for(int i = 0; i < 1000 ; i ++)
    {
        if(str[i] != '1') cout << str[i];
        else break;
    }
    cout << endl;
}

// ==================== 功能的展示 ============================

void show()
{
    cout <<"1 ---- 输入26字母的出现频率" << endl;
    cout <<"2 ---- 创建哈夫曼树和编码表，并输出编码表" << endl;
    cout <<"3 ---- 输入字符，并实现转码" << endl;
    cout <<"4 ---- 输入编码，并翻译为字符" << endl;
    cout <<"5 ---- 退出" << endl;

}

int main()
{
    show();
    memset(letter, 0,sizeof letter);
    n = 27;
    m = 2*n - 1;
    char fir;
    while(cin >> fir)
    {
        if(fir == '1')
        {
            for(int i = 1; i <= n; i ++)
            {
                cin >> letter[i];
            }
        }
        else if(fir == '2')
        {
            CreateHuffmanTree(T,n);
            CreateHCode(T,HC,n);
            PrintHTree(HC,n);
        }
        else if(fir == '3')
        {
            change();
        }
        else if(fir == '4')
        {
            string s;
            cin >> s;
            decoding(HC,n,s);
        }
        else if(fir == '5')
        {
            exit(0);
        }
        else
        {
            cout << "请输入合法的字符"<<endl;
            show();
        }
    }

    return 0;
}

