#include <iostream>

using namespace std;

int n,s1,s2,m,i,j,count2;
typedef struct HTNode
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree &HT, int end, int &s1, int &s2)
{
    int min1=100000,min2=100000;
    for(int i=1;i<=end;i++)
    {
        if(HT[i].parent==0&&HT[i].weight<min1)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    for(int i=1;i<=end;i++)
    {
        if(HT[i].parent==0&&HT[i].weight<min2&&s1!=i)
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}

void CreatHuffmanTree(HuffmanTree &HT, int n)
{
    m = 2*n-1;
    HT = new HTNode[m+1];
    for(i=1;i<=m;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>HT[i].weight;
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[i].weight = HT[s1].weight+HT[s2].weight;
        HT[s1].parent = i;
	 	HT[s2].parent = i;
	 	HT[i].lchild = s1;
	 	HT[i].rchild = s2;
    }

}

void creatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    int start,c,f;
    HC=new char*[n+1];
    char *cd=new char[n];
    cd[n-1]='\0';
    for(int i=1; i<=n; i++)
    {
        start = n-1;
        c=i;
        f=HT[c].parent;
        while(f!=0)
        {
            start--;
            if(HT[f].lchild==c)
            {
                cd[start]='0';
            }
            else
            {
                cd[start]='1';
            }
            c=f;
            f=HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    delete cd;
}



void TransCode(HuffmanTree HT,char a[],char ch[],char b[],int n)
{
    count2=0;
    int q=2*n-1;
    int k=0;
    for(int i=0; a[i]!='%'; i++)
    {
        if(a[i]=='0')
        {
            q=HT[q].lchild;
        }
        else if(a[i]=='1')
        {
            q=HT[q].rchild;
        }
        if(HT[q].lchild==0 && HT[q].rchild==0)
        {
            b[k++]=ch[q-1];
            q=2*n-1;
        }
    }
    count2=k;
    b[k]='\0';
}

void show()
{
    cout<<"********************************************************************"<<endl;
    cout<<"********* 1.输入HuffmanTree的参数.                        **********"<<endl;
    cout<<"********* 2.初始化HuffmanTree参数(含有26字母及空格).      **********"<<endl;
    cout<<"********* 3.创建HuffmanTree和编码表.                      **********"<<endl;
    cout<<"********* 4.输出编码表.                                   **********"<<endl;
    cout<<"********* 5.输入编码，并翻译为字符.                       **********"<<endl;
    cout<<"********* 6.输入字符，并实现编码.                         **********"<<endl;
    cout<<"********* 7.退出.                                         **********"<<endl;
    cout<<"********* 以%为结束标识                                   **********"<<endl;
    cout<<"********************************************************************"<<endl;
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int OpCode;
    int count1=0;
    char a[1000];
    char b[1000];
    char c[1000];
    char ch[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
    show();
    bool flag=true;
    while(flag)
    {
        cout<<"请输入操作码:"<<endl;
        cin>>OpCode;
        if(OpCode==1)
        {
            cout<<"请输入编码字符个数: ";
            cin>>n;
        }
        else if(OpCode==2)
        {
            cout<<"请输入权值: ";
            CreatHuffmanTree(HT,n);
        }
        else if(OpCode==3)
        {
            creatHuffmanCode(HT,HC,n);
        }
        else if(OpCode==4)
        {
            cout<<"结点"<<"\t"<<"字符"<<"\t"<<"权值"<<"\t"<<"编码"<<endl;
            for(int i=1;i<=n;i++)
            {
                cout<<i<<"\t"<<ch[i-1]<<"\t"<< HT[i].weight<<"\t"<<HC[i]<<endl;
            }
            cout<<endl;
        }
        else if(OpCode==5)
        {
            cout<<"输入二进制编码: ";
            for(i=0;i<1000;i++)
            {
                cin>>a[i];
                char data = a[i];
                if(a[i]=='%')
                {
                    break;
                }

            }
            TransCode(HT,a,ch,b,n);
            cout<<"输出: ";
            for(i=0;i<count2;i++)
            {
                cout<<b[i];
            }
            cout<<endl;
        }
        else if(OpCode==6)
        {
            count1=0;
            cout<<"请输入一串字符: ";
            for(i=0;i<1000;i++)
            {
                cin>>c[i];
                char data = c[1];
                count1++;
                if(c[i]=='%')
                {
                    break;
                }
            }
            cout<<"输出: ";
            for(i=0;i<count1-1;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(c[i]==ch[j])
                    {
                        cout<<HC[j+1];
                        break;
                    }
                }
            }
            cout<<endl;
        }
        else if(OpCode==7)
        {
            flag=false;
        }
    }
    return 0;
}

