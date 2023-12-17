#include <iostream>
#include <stdlib.h>
#include <windows.h> 
using namespace std;

#define s 100
#define l 10
typedef int Etype;
typedef struct{
	Etype* ele;
	int len;
	int size;
}list;
int chushi(list&);
int xiaohui(list& L);
int qingkong(list& L);
int kongfou(list& L);
int getlen(list& L);
int getele(list& L, int m, int& data1);
int locate(list& L, int data2);
int getPre(list& L, int data3);
int getNext(list& L, int data4);
int charu(list&, int, int);
int shanchu(list& L, int m);
int hebing(list L, list& L2, list& L3);
int main()
{
	int m,data;//m为插入元素的位置，data为插入元素的数据
	int data1, data2;
	list L;
	list L2;
	list L3;
	int sel;
	int flag=1;
	cout << "1----初始化一个线性表" << endl;
	cout << "2----销毁线性表" << endl;
	cout << "3----清空线性表" << endl;
	cout << "4----判断线性表是否为空" << endl;
	cout << "5----求线性表长度" << endl;
	cout << "6----获取线性表中指定位置的元素" << endl;
	cout << "7----获取线性表元素的位置" << endl;
	cout << "8----求前驱" << endl;
	cout << "9----求后继" << endl;
	cout << "10---在线性表指定位置插入元素" << endl;
	cout << "11---删除线性表指定位置的元素" << endl;
	cout << "12---显示线性表" << endl;
	cout << "13---合并两个非递减有序线性表" << endl;
	cout << "输入一个负数退出" << endl;
	while(flag)
	{
		cin >> sel;
		if (sel == 1) {
			chushi(L);
			chushi(L2);
			cout << "线性表已初始化" << endl;
			flag = 0;
		}
		else {
			cout << "请先初始化线性表"<<endl;
		}
	}
	flag = 1;
	while (flag) {
		cin >> sel;
		int f = 1;
		switch (sel)
		{
		case 2:
			xiaohui(L);
			break;
		case 3:
			qingkong(L);
			break;
		case 4:
			kongfou(L);
			break;
		case 5:
			getlen(L);
			break;
		case 6:
			cout << "请输入你想获取的元素的位置" << endl;
			cin >> m;
			getele(L, m, data1);
				break;
		case 7:
			cout << "请输入要查找的元素" << endl;
			cin >> data2;
			locate(L,data2);
			break;
		case 8:
			cout << "请输入一个线性表内的元素" << endl;
			cin >> data;
			getPre(L, data);
			break;
		case 9:
			cout << "请输入一个线性表内的元素" << endl;
			cin >> data;
			getNext(L, data);
			break;
		case 10:
			cout << "请输入插入元素的位置与数字,并且在输入的位置小于0时结束插入操作" << endl;
			while (f) {
				cin >> m;
				if (m < 0)
				{
					cout << "插入操作结束" << endl;
					f = 0;
					break;
				}
				cin >> data;
				charu(L, m, data);
			}
			for (int i = 0; i < L.len; i++)
			{
				cout << L.ele[i] << " " ;
			}
			cout << endl;
			break;
		case 11:
			cout << "请输入要删除的位置" << endl;
			cin >> m;
			shanchu(L, m);
			break;
			break;
		case 12:
			for (int i = 0; i < L.len; i++)
			{
				cout << L.ele[i] << " ";
			}
			cout << endl;
			break;
		case 13:
			hebing(L, L2, L3);
			break;
		default:
			if (sel < 0)
			{
				cout << "退出程序" << endl;
				flag = 0;
			}
			else {
				cout << "输入无效选项，请重新输入" << endl;
			}break;
			}
		}
	}

int chushi(list& L) {
	L.ele = (Etype*)malloc(s * sizeof(Etype));
	if (!L.ele)
	{
		cout << "分配空间失败" << endl;
		exit(0);
	}
	L.len = 0;
	L.size = s;
	return 1;
}
int xiaohui(list& L) {
	free(L.ele);
	L.ele = NULL;
	L.len = 0;
	L.size = 0;
	return 1;
}
int qingkong(list& L) {
	L.len = 0;
	return 1;
}
int kongfou(list& L) {
	if (L.len <= 0)
	{
		cout << "线性表为空" << endl;
		return 0;
	}
	cout << "线性表不为空" << endl;
	return 1;
}
int getlen(list& L) {
	cout << "线性表的长度为" << L.len << endl;
	return 1;
}
int getele(list& L,int m,int &data1) {
	if (m<1 || m>L.len + 1) {
		cout << "输入范围有误。" << endl;
		return 0;
	}
	data1 = L.ele[m - 1];
	cout << "该位置的元素为： " << data1 << endl;
	return 1;
}
int locate(list& L,int data2) {
	int nu = 0;
	for (int i = 0; i < L.len; i++)
	{
		if (L.ele[i] == data2)
		{
			cout << "该元素在第" << i + 1 << "位" << endl;
		}
		else
		{
			nu++;
		}
	}
	if (nu == L.len) {
		cout << "线性表内没有你输入的元素" << endl;
	}
	return 1;
}
int getPre(list& L,int data3) {
	int nu = 0;
	for (int i = 0; i < L.len; i++)
	{
		if (L.ele[i] == data3)
		{
			if (i == 0)
			{
				cout << "该元素为首元素，没有前驱。" << endl;
				return 0;
			}
			else {
				cout << "该元素的前驱为" << L.ele[i-1] << endl;
				return 1;
			}
		
		}
		else
		{
			nu++;
		}
	}
	if (nu == L.len) {
		cout << "线性表内没有你输入的元素" << endl;
	}
	return 1;
}
int getNext(list& L,int data4) {
	int nu = 0;
	for (int i = 0; i < L.len; i++)
	{
		if (L.ele[i] == data4)
		{
			if (i == L.len-1)
			{
				cout << "该元素为尾元素，没有后继。" << endl;
				return 0;
			}
			else {
				cout << "该元素的后继为" << L.ele[i + 1] << endl;
				return 1;
			}

		}
		else
		{
			nu++;
		}
	}
	if (nu == L.len) {
		cout << "线性表内没有你输入的元素" << endl;
	}
	return 1;
}
int charu(list& L,int m,int data) {
	Etype* newSize=L.ele;
	if (m<1 || m>L.len + 1) {
		cout << "输入范围有误。" << endl;
		return 0;
	}
	if (L.len > L.size)
	{
		newSize = (Etype*)realloc(L.ele, (L.size + s) * sizeof(Etype));//?为什么不用循环判断
	}
	if (!newSize)
	{
		cout << "未申请到足够空间" << endl;
		return 0;
	}
	L.ele = newSize;
	L.size += s;
	int* q, * p;
	q = &L.ele[m - 1];
	for (p = &(L.ele[L.len - 1]); p >= q; --p)//数组通过指针实现时，下标是与当前指针地址的偏移量，所以下标可以为负数。
	{
		*(p + 1) = *p;
	}
	*q = data;
	L.len++;
	return 1;
}
int shanchu(list& L, int m) {
	if (m<1 || m>L.len)
	{
		cout << "输入的位置不在线性表范围内" << endl;
		return 0;
	}
	int* p, * q;
	q = &L.ele[L.len - 1];
	for (p = &L.ele[m - 1]; p < q; ++p)
	{
		*p = *(p + 1);
	}
	L.len--;
	return 1;
}
int hebing(list L, list &L2, list& L3)
{
	int fg = 1;
	int m2;
	int datal;
	cout << "使用插入操作生成线性表B,输入一个负数结束插入操作" << endl;
	while (fg) {
		cin >> m2;
		if (m2 < 0)
		{
			cout << "插入操作结束" << endl;
			fg = 0;
			break;
		}
		cin >> datal;
		charu(L2, m2, datal);
	}
	cout << "线性表B为： ";
	for (int i = 0; i < L2.len; i++)
	{
		cout << L2.ele[i] << " ";
	}
	cout << endl;
	int* p, * q;
	int* last_p, * last_q;
	p = &L.ele[0];
	q = &L2.ele[0];
	last_p = &L.ele[L.len - 1];
	last_q = &L2.ele[L2.len - 1];
	L3.size = L3.len = L.len + L2.len;
	L3.ele = (Etype*)malloc(L3.size * sizeof(Etype));
	int*k=L3.ele; 
	while (p <= last_p && q <= last_q)
	{
		if (*p <= *q)
		{
			*k++ = *p++;
		}
		else
		{
			*k++ = *q++;
		}
	}
	while (p <= last_p)
	{
		*k++ = *p++;
	}
	while (q <= last_q)
	{
		*k++ = *q++;
	}
	cout << "合并结果为：" << endl;
	//cout<<L3.len;
	for (int i = 0; i < L3.len; i++)
	{
		cout << L3.ele[i] << " ";
	}
	cout << endl;
	return 1;
}