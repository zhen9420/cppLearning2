#include<iostream>
using namespace std;

typedef struct 
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
    /* data */
}HTNode,*HuffmanTree;

typedef char * * Huffmancode;
//选出两个权值最小且无双亲的节点
void Select(HuffmanTree &HT,int end,int &s1,int &s2){
    int min1 = 100000,min2 = 100000;
    for(int i = 1;i<=end;i++){
        if(HT[i].parent == 0&&HT[i].weight<min1){
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    for(int i = 1;i<=end;i++){
        if(HT[i].parent == 0&&HT[i].weight<min2&&i!=s1){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}

void CreateHuffmanTree(HuffmanTree &HT,int n){
  int m = 2*n-1;//哈夫曼树的总结点个数等于叶子节点个数*2 - 1
  HT = new HTNode[m+1];//0号单元未用；
  for(int i = 1;i<=m;i++){
    HT[i].weight = 0;
    HT[i].parent = 0;
    HT[i].lchild = 0;
    HT[i].rchild = 0;
  }


}
