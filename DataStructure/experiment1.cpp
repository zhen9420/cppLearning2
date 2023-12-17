#include<iostream>
using namespace std;
int A[100],B[100],C[200];
int la,lb;
bool isInput = 0;
void f1();
void f2(int a[],int b[],int la,int lb);
void f3(int a[],int b[],int la,int lb);
void f4(int a[],int b[],int la,int lb);

int main(){
	
	cout<<"1--输入集合A和B"<<endl;
	cout<<"2--求集合A交B"<<endl;
	cout<<"3--求集合A并B"<<endl;
	cout<<"4--求集合A-B"<<endl;
	cout<<"退出：输入一个负数！"<<endl;
	int n =0;
	while(1){
		cin>>n;
		if(n>4) cout<<"数字错误,请重新输入";
		if(n==1) f1();
		if(isInput == 1){
			if(n==2 ) f2(A,B,la,lb);
			if(n==3 ) f3(A,B,la,lb);
			if(n==4 ) f4(A,B,la,lb);
		}
		else  {
			cout<<"当前还未输入集合"<<endl;
		}
		
		if(n<0) break;
		
	}
	cout<<"已退出！"; 
}
void f1(){
	cout<<"请分别输入集合A和B的长度"<<endl;
	cin>>la>>lb;
	cout<<"集合A="<<endl;
	for(int i = 0;i<la;i++){
		
		while(1){
			cin>>A[i];
			bool IsRepeat = 0;
			for(int j = 0;j<i;j++){
				if(A[j]==A[i]){
					IsRepeat = 1;
					cout<<"数字重复,请重新输入"<<endl;
					break;
				}
				
			}
			if(!IsRepeat){
				break;
			}
		}

	}
	//额外输入的数字会流入B;
	cout<<"请输入B="<<endl;
	for(int i = 0;i<lb;i++){
		
		while(1){
			cin>>B[i];
			bool IsRepeat = 0;
			for(int j = 0;j<i;j++){
				if(B[j]==B[i]){
					IsRepeat = 1;
					cout<<"数字重复,请重新输入"<<endl;
					break;
				}
				
			}
			if(!IsRepeat){
				break;
			}
		}

	}
	 isInput = 1;
	cout<<"输入完毕"<<endl;
	
}
void f2(int a[],int b[],int la,int lb){
	for(int i = 0;i<la;i++){
		for(int j =0 ;j<lb;j++){
			if(a[i]==b[j]) {
				cout<<a[i]<<' ';
				break;
			}
		}
	}
	cout<<endl;
}
void f3(int a[],int b[],int la,int lb){
	for(int i = 0;i<la;i++){
		cout<<a[i]<<' ';
	}
	for(int i = 0;i<lb;i++){
		bool IsSame = 0;
		for(int j = 0;j<la;j++){
			if(b[i] == a[j]){
				IsSame = 1;
				break;
			}
		}
		if(!IsSame){
			cout<<b[i]<<" ";
		}
	}
}
void f4(int a[],int b[],int la,int lb){
	int lc = 0;
	for(int i = 0;i<la;i++){
		for(int j =0 ;j<lb;j++){
			if(a[i]==b[j]) {
				C[lc++]=a[i];
				break;
			}
		}
	}
	for(int i = 0;i<la;i++){
		bool IsSame = 0;
		for(int j = 0;j<lc;j++){
			if(a[i] == C[j]){
				IsSame = 1;
				break;
			}
		}
		if(!IsSame){
			cout<<a[i]<<" ";
		}
	}
}