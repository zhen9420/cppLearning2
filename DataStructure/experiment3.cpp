#include<iostream>
#include<stdlib.h>

using namespace std;
#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0;
#define INFESIBLE -1;
#define OVERFLOW -2;

typedef  int ElemType;
typedef int Status;

typedef struct LNode{
	ElemType data;
	struct LNode*next;
}LNode,*LinkList;

Status InitList( LinkList *L){
	*L = (LinkList) malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
	
}
Status DestroyList(LinkList L){
	LNode *p ;
	while(L){
		p = L;
		L =L->next;
		free(p);
	}
	return OK;
}
Status ClearList(LinkList L){
	LNode *p, *q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
	
}
Status ListLength(LinkList L){
	int len = 0;
	LNode *p = L->next;
	while(p){
		++len;
		p = p->next;
	}
	return len;
}
Status GetElem(LinkList L,int i ,ElemType *e){
	int j = 1;
	LNode *p;
	p = L->next;
	while(p && j<i){
		p = p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	*e = p->data;
	return OK;
}
//返回元素在链表中的位置
int LocateElem(LinkList L,ElemType e){
	LNode *p = L->next;
	int postion = 1;
	int len = ListLength(L);
	while(p->data!=e){
		p = p->next;
		postion++;
		if(postion>len){
			return ERROR;
		}
	}
	return postion;

}
Status ListDelete(LinkList L,int i)
{
	LNode *p,*q;
	p = L;   //指针p指向头结点
	int j=0;
	while(p->next && j<i-1)    //判断前驱结点指针域是否为空和前驱位置值
	{
		p = p->next;
		j++;
	}
	if(!(p->next) || j>i-1) return ERROR;    //判断删除位置合理与否：前驱结点指针域是否为空，为空证明超链长了
	q = p->next;
	p->next = q->next;   //前驱结点指针域指向的指针域的值 赋给 前驱结点的指针域   有点向二重指针的感觉
	free(q);    //释放空间
	return OK;
}

/*头插法（前插法）
 */
void CreateList_H(LinkList *L,int n)   //形参L 是指向inkList类型的指针变量指针（用于指向新开辟储存单元），逆序储存n个元素值
{
	*L = (LinkList)malloc(sizeof(LNode));   //为头结点开辟储存空间，并使头指针指向头节点 
	(*L)->next = NULL;  //含头结点的空链表
	int i;    //元素数量计数
	printf("请输入%d个链表元素:",n);
	for(i=0;i<n;i++)    //循环输入元素
	{
		LNode *p=(LinkList)malloc(sizeof(LNode));   //为新结点开辟空间并令指针指向该地址
		scanf("%d",&p->data);    //向新结点数据域输入数据
		p->next = (*L)->next;       //头结点指针域的值（即新结点后继结点地址）赋给新结点指针域进行连接
		(*L)->next = p;    //指针域指针连接顺序不可颠倒   新结点地址赋值给头结点指针域进行连接
	}
}

/*尾插法（后插法）
 */
void CreateList_R(LinkList *L,int n)
{
	LNode *r;
	*L = (LinkList)malloc(sizeof(LNode));   //头指针指向新开辟的头结点
	(*L)->next = NULL;   //创建空链表，指针域设置为NULL
	r = (*L);    //尾指针指向头结点
	int i;    
	printf("请输入%d个链表元素:",n);
	for(i=0;i<n;i++)
	{
		LNode *p = (LinkList)malloc(sizeof(LNode));   //为新结点p开辟储存空间
		scanf("%d",&p->data);           //为新结点输入数据
		p->next = NULL;         //新结点作为尾结点，其指针域设置为NULL
		r->next = p;            //尾指针指向的结点的指针域设置为p结点的地址进行连接
		r = p;          //尾指针向前移动，指向新的尾结点
	}
}

Status PriorElem(LinkList L,ElemType e){
    LNode* p=L->next;
    if(e==p->data){
        cout<<"无前驱"<<endl;
        return ERROR;
    }
    LinkList q;
	int i = 1;
	int len = ListLength(L);
    while(p && p->data!=e){
        q=p;
        p=p->next;
		i++;
    }
	if(i>len) {
		cout<<"无前驱"<<endl;
        return ERROR;
	}
    cout<<"前驱为："<<q->data<<endl;
    return OK;
}
Status NextElem(LinkList L,ElemType e){
    LinkList p=L->next;
    while(p && p->data!=e){
        p=p->next;
    }
    if(p->next==NULL){
        cout<<"无后继"<<endl;
        return ERROR;
    }
    p=p->next;
    cout<<"后继为："<<p->data;
    return OK;
}
Status print(LinkList L){
    LinkList p=L->next;
    while(p){
        cout<< p->data <<" ";
        p=p->next;
    }
    cout<<endl;
    return OK;
}
Status ListInsert(LinkList L,int i,ElemType e)   //输入插入位置i、同类型ElemType元素值
{
	LNode *p,*s;  //定义LNode类型指针变量
	p = L;  //p指向L头结点
	int j = 0;   //定义计数
	while(p && j<i-1)   //循环条件 p非空和j小于i-1（i的前驱结点位置）一般情况下：j=i-1结束循环
	{
		p = p->next;  //p继续指向下一个结点
		j++;  //位置数累计
	}
	if(!p || j>i-1) return ERROR;    //p为前驱结点的指针值（地址），为NULL则超链表长；j>i-1表示位置小于0
	s = (LinkList)malloc(sizeof(LNode));    //为新插入结点开辟空间并指针s指向该储存单元
	s->data = e;       //将插入数据赋值给储存单元数据域
	s->next = p->next;    //新结点指针域指向下一个结点ai
	p->next = s;      //前去结点指针域指向新结点
	return OK;
}
Status ListReverse(LinkList *L){
	if((*L)->next== NULL||((*L)->next )->next ==NULL) return OK;//空链表或者只有一个节点无需操作

	LNode *p = (*L)->next,*q ;
	(*L)->next = NULL;
	while(p!=NULL){
		q = p->next;
		p->next = (*L)->next;
		(*L)->next = p;
		p = q;

	}
	return OK;
}

int main(void){
	LinkList L;  //定义指向LNode类型的指针变量L
	ElemType *e;
	int num,status,num_1,n,i; 
    cout << "1----初始化或重置链表" << endl;
	cout << "2----销毁链表" << endl;
	cout << "3----清空链表" << endl;
	cout << "4----求链表长度" << endl;
	cout << "5----链表中指定位置的元素" << endl;
	cout << "6----链表已存在元素的位序" << endl;
	cout << "7----求前驱" << endl;
	cout << "8----求后继" << endl;
	cout << "9---在链表指定位置插入元素" << endl;
	cout << "10---删除链表指定位置的元素" << endl;
	cout << "11---输出有的链表元素"<<endl;
	cout << "12---初始化并用头插法输入元素" << endl;
	cout << "13---实现单链表的逆序存放" << endl;
	cout << "14---退出" << endl;
	while(1)
	{
		printf("\n请输入操作序号:");
		scanf("%d",&num);
		switch (num)
		{
			case 1: 
				{
					status = InitList(&L);
					if(status)printf("链表初始化已完成～\n");
					else printf("链表初始化失败～\n");
				}; 
				break;
			case 12:
				{
					printf("\n***********选择赋值方式***************\n");
					printf("	1-头插法		2-尾插法\n");
					printf("选择赋值方式:");
					scanf("%d",&num_1);
					printf("为多少个元素赋值:");
					scanf("%d",&n);
					if(num_1==1) CreateList_H(&L,n);
					else if(num_1==2) CreateList_R(&L,n);
					else printf("方式选择有误～\n");
				}; break;
			
			case 4:
				{
					status = ListLength(L);
					printf("链表长度为%d\n",status);
				};break;
			case 5:
				{
					
					printf("请输入取出元素位置:");
					scanf("%d",&i);
					GetElem(L,i,e);
					printf("位置%d元素值为%d\n",i,*e);
				};break;
			case 6:
				{
					int pos;
					printf("请输入目标元素值:");
					scanf("%d",&n);
					pos=LocateElem(L,n);
					printf("该值位置为:%d\n",pos);
				};break;
			  case 7:{
                cout<<"请输入要查询的元素：";
                cin >> *e;
                
                PriorElem(L,*e);
                break;
            }
            case 8:{
                cout<<"请输入要查询的元素：";
                cin >> *e;
                NextElem(L,*e);
                break;
            }

			case 9:
				{
					printf("请输入需插入的目标元素:");
					scanf("%d",&n);
					printf("请输入插入目标位置:");
					scanf("%d",&i);
					ListInsert(L,i,n);
				};break;
			case 10:
				{
					printf("请输入删除结点位置：");
					scanf("%d",&i);
					if(ListDelete(L,i)) printf("删除操作已完成～\n");
				};break;
			case 3:
				{
					if(ClearList(L)) printf("链表已清空～\n");
					else printf("清空操作失败～\n");
				};break;
			case 2:
				{
					if(DestroyList(L)) printf("链表已销毁～\n");
					else printf("销毁操作失败～\n");
				};break;
			case 11:
				{
					printf("当前链表:");
					print(L);
					printf("\n");
				};break;
			case 13:
			{
				if(ListReverse(&L)) printf("链表逆序存放～\n");
				 
			};break;
			case 14:
				{
					printf("成功退出测试系统~\n");
					exit(1); 
				};break;
			
			default: printf("输入操作序号有误～\n");
		}
	}

}