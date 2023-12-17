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
typedef  int QElemType;
typedef int Status;

typedef struct QNode {
    QElemType data;
    struct QNode * next;
}QNode, *QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

LinkQueue Q;

Status InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) return ERROR;
    Q.front ->next = NULL;
    return OK;
}
Status DestroyQueue(LinkQueue &Q){
    while(Q.front){
        Q.rear = Q.front ->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}
Status EnQueue(LinkQueue &Q,QElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)  return ERROR;
    p ->data =e;
    p->next =NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK; 
}
Status DeQueue(LinkQueue &Q,QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p;
    p = Q.front ->next;
    e = p->data;
    Q.front ->next = p->next;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}
Status EmptyQueue(LinkQueue Q){
    if(Q.front == Q.rear) return TRUE;
    else return FALSE;
}
Status GetTop(LinkQueue Q ,QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    else e = Q.front->next->data;
    return OK;

}
int QueueLength(LinkQueue Q){
    QueuePtr p;
    int len = 0;
    p = Q.front;
    while(p->next){
        len ++;
        p = p->next;
    }
    return len;
}
Status ClearQueue(LinkQueue &Q){
    //先将队尾指针指向对头指针的下一个结点
	Q.rear=Q.front->next;
	while(Q.front->next)
	{
		//队尾指针后移
	    Q.rear=Q.rear->next; 
		//释放对头指针和队尾指针中间的结点
		free(Q.front->next);
		//连接队列
		Q.front->next=Q.rear; 
	 } 
	 //队列为空时，调整队尾指针
	 Q.rear=Q.front; 
    return OK;

}
Status PrintQueue(LinkQueue Q){
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p;
    p = Q.front->next;
    while(p){
        cout<<p->data<<' ';
        p = p->next;
    }
    return OK;
}
int main (void){
    int order,init=0,des=0,len,e;
	cout<<"*----------------链队列--------------*"<<endl;
	cout<<"*---------1.初始化队列-------------*"<<endl;
	cout<<"*---------2.销毁队列---------------*"<<endl;
	cout<<"*---------3.清空队列---------------*"<<endl;
	cout<<"*---------4.队列判空---------------*"<<endl;
	cout<<"*---------5.求队列长度-------------*"<<endl;
	cout<<"*---------6.获取队头元素---------*"<<endl;
	cout<<"*---------7.插入一个元素---------*"<<endl;
	cout<<"*---------8.删除一个元素---------*"<<endl;
	cout<<"*---------9.输出所有元素---------*"<<endl;
	
	do{
	cout<<"请输入指令"<<endl;
	cin>>order;
	if(order==0 || order>9)
		cout<<"没有该指令"<<endl;
	else if(!init && order>1 && order!=9)
		cout<<"请先初始化队列"<<endl;
	else if(des && order>1 && order!=9)
		cout<<"队列已销毁，请先初始化"<<endl;
	else
		switch(order)
		{
			case 1:
				InitQueue(Q);
				init=1;
				des=0;
				cout<<"初始化队列完成"<<endl;
				break;
			case 2:
				DestroyQueue(Q);
				des=1;
				cout<<"队列已销毁"<<endl;
				break;
			case 3:
				ClearQueue(Q);
				cout<<"队列已清空"<<endl;
				break;
			case 4:
				if(!EmptyQueue(Q))
					cout<<"队列非空"<<endl;
				else
					cout<<"队列为空"<<endl;
				break;
			case 5:
				len=QueueLength(Q);
				cout<<"栈长度为："<<len<<endl;
				break;
			case 6:	
				if(GetTop(Q,e))
					cout<<"队头为："<<e<<endl; 
				else
					cout<<"空队列"<<endl; 
				break;
			case 7:
				cout<<"请输入插入元素：";
				cin>>e;
				EnQueue(Q,e);
				cout<<"插入成功"<<endl;
				break;
			case 8:
				if(DeQueue(Q,e))
					cout<<"删除元素"<<e<<"成功"<<endl;
				else
					cout<<"队列为空"<<endl;
				break;
			case 9:
				cout<<"队列为："<<endl;
				PrintQueue(Q);
				break;
			
			default:
				cout<<"程序已退出"<<endl;
				break;
		}
	}while(order>=0);
	return 0;

}