#include<iostream>
#include<stdlib.h>

using namespace std;
//状态码
const int TRUE= 1;
const int FALSE= 0;
const int OK =1;
const int ERROR =0;
const int INFESIBLE =-1;

typedef char TElemType;
typedef int Status;
const int STACK_INT_SIZE = 100;
const int STACKINCREAMENT = 10;
//树
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
   
}BiTNode,*BiTree;



//栈
typedef  BiTree SElemType;
typedef struct {
    SElemType * base;
    SElemType * top;
    int stacksize;
}SqStack;

//队列
typedef  BiTree QElemType;
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



//树操作
Status CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse1(BiTree T);
Status InOrderTraverse2(BiTree T);
Status PostOrderTraverse(BiTree);
Status LevelOrderBiTree(BiTree T);
int BitreeDepth(BiTree T);
//栈操作
Status Pop(SqStack &S,SElemType &e);
Status Push(SqStack &S,SElemType e);
Status Pop(SqStack &S,SElemType &e);
Status Pop(SqStack &S,SElemType &e);
Status StackEmpty(SqStack S);
Status DestroyStack(SqStack &S);

SqStack S;
SElemType p;
//队列操作
Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType e);
Status DeQueue(LinkQueue &Q,QElemType &e);
Status EmptyQueue(LinkQueue Q);
Status GetTop(LinkQueue Q ,QElemType &e);


int main(void){
     int order,init=0;
     int tag = 0;
     BiTree T;
	
	cout<<"*---------1.创建二叉树-------------*"<<endl;
    cout<<"*---------2.先序遍历二叉树---------*"<<endl;
	cout<<"*---------3.中序遍历二叉树1---------------*"<<endl;
	cout<<"*---------4.中序遍历二叉树2---------*"<<endl;
    cout<<"*---------5.后序遍历二叉树---------*"<<endl;
	cout<<"*---------6.层序遍历二叉树---------*"<<endl;
    cout<<"*---------7.求二叉树深度---------*"<<endl;
    cout<<"*---------8.退出---------*"<<endl;
    do{
	cout<<"请输入指令"<<endl;
	cin>>order;
	if(order<=0 || order>8)
		cout<<"没有该指令"<<endl;
	else if(!init && order>1 )
		cout<<"请先创建二叉树"<<endl;
	
	else
		switch(order)
		{
			case 1:
				CreateBiTree(T);
				init=1;
				cout<<"创建二叉树完成"<<endl;
				break;
			case 2:
                PreOrderTraverse(T);cout<<endl;
				cout<<"先序遍历完成"<<endl;
				break;
			case 3:
                InOrderTraverse1(T);cout<<endl;
                cout<<"中序遍历1完成"<<endl;
                break;
            case 4:
                 InOrderTraverse2(T);cout<<endl;
                 cout<<"中序遍历2完成"<<endl;
                
                 break;
            case 5:
                PostOrderTraverse(T);cout<<endl;
                cout<<"后序遍历完成"<<endl;
                break;
            case 6:
                LevelOrderBiTree(T);
                cout<<endl;
                cout<<"层序遍历完成"<<endl;
                break;
            case 7:
                
                cout<<"二叉树深度为"<<BitreeDepth(T)<<endl;
                break;
			default:
                order = -1;
				cout<<"程序已退出"<<endl;
				break;
		}
	}while(order>0);
}

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
Status StackEmpty(SqStack S){
    if(S.top == S.base) return TRUE;
    else return FALSE;
}
Status DestroyStack(SqStack &S){

    free(S.base);
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}


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


Status CreateBiTree(BiTree &T){
    //按先序次序输入二叉树中节点的值（一个字符），空格字符表示空树，
    //构建二叉链表表示的二叉树T
    char ch;
    cin>>ch;
    if(ch == '*') T  = NULL;
    else {
        if(!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return  OK;

}
Status PreOrderTraverse(BiTree T){
    //先序遍历的递归算法
    if(T){
        cout<<T->data<<' ';
        if(PreOrderTraverse(T->lchild))
            if(PreOrderTraverse(T->rchild)) return OK;
    }else return OK;
}
Status InOrderTraverse1(BiTree T){
    //中序遍历算法1（空指针入栈）
    InitStack(S); Push(S,T);
    while(!StackEmpty(S)){
        while (GetTop(S,p)&&p)
        {
            Push(S,p->lchild);
            /* code */
        }
        Pop(S,p);
        if(!StackEmpty(S)){
            Pop(S,p);
            cout<<p->data<<' ';
            Push(S,p->rchild);

        }
    }
    
    DestroyStack(S);
    return OK;
}
Status InOrderTraverse2(BiTree T){
    //中序遍历算法2（空指针不入栈）
    InitStack(S);
    p  = T;
    while(p || !StackEmpty(S)){
        if(p) {
            Push(S,p);
            p = p ->lchild;
        }
        else{
            Pop(S,p);
            cout<<p->data<<' ';
            p  = p->rchild;
        }
    }
    DestroyStack(S);
    return OK;
}
Status PostOrderTraverse(BiTree T){
    //后序遍历的递归算法
    if(T){
        PostOrderTraverse(T->lchild);
        (PostOrderTraverse(T->rchild)) ;
        cout<<T->data<<' ';
        return OK;
    }else return OK;
}

Status LevelOrderBiTree(BiTree T)
{
    //层序输出
	InitQueue(Q);
    
	EnQueue(Q,T);//取出二叉树的根节点，子节点存入队列
	while (Q.rear != Q.front)//当队列不为空
	{
        BiTree x;
		DeQueue(Q,x);//x用于输出队列弹出元素的数据
		printf("%c ", x->data);
		if (x->lchild!=NULL)
		{
			EnQueue(Q, x->lchild);//递归左节点
		}
		if (x->rchild!=NULL)
		{
			EnQueue(Q, x->rchild);//递归右节点
		}
	}
    return OK;
}
int BitreeDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;//左子树，右子树，最大深度
	if (T != NULL) //如果为空树
	{
		leftHeight = BitreeDepth(T->lchild);//左子树深度
		rightHeight = BitreeDepth(T->rchild);//右子树深度
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//最大深度
		return maxHeight+1;//二叉树深度=最大深度+1
	}
	else
	{
		return 0;
	}
}
