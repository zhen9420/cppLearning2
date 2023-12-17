#include<iostream>
#include<stdlib.h>

using namespace std;
//状态码
const int TRUE= 1;
const int FALSE= 0;
const int OK =1;
const int ERROR =0;
const int INFESIBLE =-1;


const int STACK_INT_SIZE = 100;
const int STACKINCREAMENT = 10;
typedef  int SElemType;
typedef int Status;

typedef struct {
    SElemType * base;
    SElemType * top;
    int stacksize;
}SqStack;
SqStack S,s;
//构造空栈
Status InitStack(SqStack &S){
        S.base = (SElemType *)malloc(STACK_INT_SIZE*sizeof(SElemType));
        if(!S.base) return 0;
        S.top = S.base;
        S.stacksize = STACK_INT_SIZE;
        return OK;

}
Status GetTop(SqStack S,SElemType &e){
    if(S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}
Status Push(SqStack &S,SElemType e){
    if(S.top - S.base>=S.stacksize) {
        //栈满，追加空间
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREAMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
        S.top = S.base;
        S.stacksize += STACK_INT_SIZE;
    }
    *S.top ++ = e;
    return OK;
}
Status Pop(SqStack &S,SElemType &e){
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
int StackLength(SqStack S){
    return (S.top-S.base);
}
Status StackEmpty(SqStack S){
    if(S.top == S.base) return TRUE;
    else return FALSE;
}
Status ClearStack(SqStack &S){
    S.top = S.base;
    return OK;
}
Status DestroyStack(SqStack &S){

    free(S.base);
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}
Status ShowStack(SqStack S)
{
	//cout<<*S.top<<endl;因为栈顶指针始终指向栈顶元素下一位，值始终为空，即这里输出0
	while(S.base!=S.top)//当栈不为空时
		cout<<*--S.top<<' ';//栈顶指针先自减，再输出对应值
	cout<<endl;
	return OK;
}
void conversition(){
    int N;
    int jinzhi;
    int e;
    InitStack(s);
    cout<<"请输入要操作的数字";
    cin>> N;
    cout<<"请输入转换进制（2、8、16）";
    cin>>jinzhi;
    if(N<0){
        cout<<"-";
        N = -N;
    }
    while(N){
        Push(s,N%jinzhi);
        N = N/jinzhi;
    }
    while (!StackEmpty(s))
    {
        Pop(s,e);
        cout<<e;
    }
    cout<<endl;
    
}
int main(void){
    int order,init=0,des=0,len,e;
	cout<<"*----------------栈--------------*"<<endl;
	cout<<"*---------1.初始化栈-------------*"<<endl;
	cout<<"*---------2.销毁栈---------------*"<<endl;
	cout<<"*---------3.清空栈---------------*"<<endl;
	cout<<"*---------4.栈判空---------------*"<<endl;
	cout<<"*---------5.求栈长度-------------*"<<endl;
	cout<<"*---------6.获取栈顶元素---------*"<<endl;
	cout<<"*---------7.插入一个元素---------*"<<endl;
	cout<<"*---------8.删除一个元素---------*"<<endl;
	cout<<"*---------9.输出所有元素---------*"<<endl;
	cout<<"*---------10.进制转换------------*"<<endl;
	do{
	cout<<"请输入指令"<<endl;
	cin>>order;
	if(order==0 || order>10)
		cout<<"没有该指令"<<endl;
	else if(!init && order>1 && order!=10)
		cout<<"请先初始化栈"<<endl;
	else if(des && order>1 && order!=10)
		cout<<"栈已销毁，请先初始化"<<endl;
	else
		switch(order)
		{
			case 1:
				InitStack(S);
				init=1;
				des=0;
				cout<<"初始化栈完成"<<endl;
				break;
			case 2:
				DestroyStack(S);
				des=1;
				cout<<"栈已销毁"<<endl;
				break;
			case 3:
				ClearStack(S);
				cout<<"栈已清空"<<endl;
				break;
			case 4:
				if(!StackEmpty(S))
					cout<<"栈非空"<<endl;
				else
					cout<<"栈为空"<<endl;
				break;
			case 5:
				len=StackLength(S);
				cout<<"栈长度为："<<len<<endl;
				break;
			case 6:	
				if(GetTop(S,e))
					cout<<"栈顶元素为："<<e<<endl; 
				else
					cout<<"空栈，无栈顶元素"<<endl; 
				break;
			case 7:
				cout<<"请输入插入元素：";
				cin>>e;
				Push(S,e);
				cout<<"入栈成功"<<endl;
				break;
			case 8:
				if(Pop(S,e))
					cout<<"栈顶元素"<<e<<"出栈成功"<<endl;
				else
					cout<<"栈为空"<<endl;
				break;
			case 9:
				cout<<"栈为："<<endl;
				ShowStack(S);
				break;
			case 10:
				conversition();
                break;
			default:
				cout<<"程序已退出"<<endl;
				break;
		}
	}while(order>=0);
	return 0;

}