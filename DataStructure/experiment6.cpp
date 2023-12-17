#include<iostream>
#include<stdlib.h>

using namespace std;
//状态码
const int TRUE= 1;
const int FALSE= 0;
const int OK =1;
const int ERROR =0;
const int INFESIBLE =-1;

#define maxsize 100
#define max 10
 int num[maxsize+1];
 int cpot[maxsize+1];
typedef int ElemType;

typedef struct 
{
    int i,j; //行下标和列下标
    ElemType e;
} Triple;
typedef struct 
{
    Triple data[maxsize+1];//data[0]未用
    int mu,nu,tu;//行数，列数，非零元总个数
} TSMatrix,*Tpointer;
void Inital(TSMatrix &tsm){
    cout<<"请输入行数、列数和非零元总个数（最大为10*10）"<<endl;
    do{
        cin>>tsm.mu;
        cin>>tsm.nu;
        cin>>tsm.tu;
        if(tsm.mu*tsm.nu<tsm.tu) cout<<"输入错误，非零元素个数要小于等于行数乘列数，请重新输入。"<<endl;

    }while (tsm.mu*tsm.nu<tsm.tu);
    int temi =-1,temj =-1;
    int m = 1;
    do{
        int i,j;
        bool isRep = false;
        ElemType e;
        cin>>i>>j>>e;
        for(int k = 1;k<=m;k++){
            if(tsm.data[k].i == i&&tsm.data[k].j==j){
                cout<<"输入错误，输入的下标重复，请重新输入！"<<endl;
                isRep = true;
                break;
            }
        }
        if (isRep) continue;
        if(i<temi||(i==temi&&j<=temj)){
            cout<<"输入错误,下标输入时要递增输入，请重新输入！"<<endl;
        }
        else{
            temi = i;
            temj = j;
            tsm.data[m].i = i;
            tsm.data[m].j = j;
            tsm.data[m].e = e;
            m++;
        }
    }while(m<=tsm.tu);
   
    
}
void Print(TSMatrix tsm){
    int k =1;
    for(int i = 1;i<=tsm.mu;i++){
        for(int j = 1;j<=tsm.nu;j++){
            if(k<=tsm.tu&&i==tsm.data[k].i&&j==tsm.data[k].j){
                cout<<tsm.data[k].e<<' ';
                k++;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
void Destory(Tpointer tsm){
    tsm->mu = 0;
    tsm->nu = 0;
    tsm->tu  = 0;
   // free (tsm);
}
void Transpose(TSMatrix tsm,TSMatrix &Ttsm){
    int q = 1;
    Ttsm.mu= tsm.nu;Ttsm.nu = Ttsm.mu; Ttsm.tu= tsm.tu;
    for(int j = 1;j<=tsm.nu;j++){
        for(int k = 1;k<=tsm.tu;k++){
            if(tsm.data[k].j == j){
                Ttsm.data[q].i = tsm.data[k].j;
                Ttsm.data[q].j = tsm.data[k].i;
                Ttsm.data[q].e = tsm.data[k].e;
                q++;
            }
        }
    }

}
void QTranspose(TSMatrix t,TSMatrix &T){
    T.mu= t.nu;T.nu = T.mu; T.tu= t.tu;
   cpot[1] = 1;
   for(int k = 1;k<=T.tu;k++){
    num[t.data[k].j]++;
   }
   for(int k= 2 ;k<=T.nu;k++){
    cpot[k] = cpot[k-1]+num[k-1];
   }
   for(int k = 1;k<=T.tu;k++){
    int col = t.data[k].j;
    int q = cpot[col];
    T.data[q].i= t.data[k].j;
    T.data[q].j = t.data[k].i;
    T.data[q].e = t.data[k].e;
    cpot[col]++;
   }
   
}
int main(void){
     int order,init=0,des=0;
     int tag = 0;
     TSMatrix tsm,Ttsm;
     Tpointer T = &tsm;
	cout<<"*----------------稀疏矩阵--------------*"<<endl;
	cout<<"*---------1.创建矩阵-------------*"<<endl;
	cout<<"*---------2.销毁矩阵---------------*"<<endl;
	cout<<"*---------3.输出矩阵---------*"<<endl;
    cout<<"*---------4.转置矩阵---------*"<<endl;
	cout<<"*---------5.快速转置矩阵---------*"<<endl;
	do{
	cout<<"请输入指令"<<endl;
	cin>>order;
	if(order==0 || order>5)
		cout<<"没有该指令"<<endl;
	else if(!init && order>1 )
		cout<<"请先创建矩阵"<<endl;
	else if(des && order>1 )
		cout<<"矩阵已销毁，请先初始化"<<endl;
	else
		switch(order)
		{
			case 1:
				Inital(tsm);
				init=1;
				des=0;
				cout<<"创建矩阵完成"<<endl;
				break;
			case 2:
                T = &tsm;
				Destory(T);
				des=1;
				cout<<"矩阵已销毁"<<endl;
				break;
			case 3:
                Print(*T);
                break;
            case 4:
                 Transpose(tsm,Ttsm);
                 T = &Ttsm;
                 break;
            case 5:
                QTranspose(tsm,Ttsm);
                T = &Ttsm;
                 break;
			default:
				cout<<"程序已退出"<<endl;
				break;
		}
	}while(order>=0);
	return 0;
}

