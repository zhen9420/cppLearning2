#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 100
using namespace std;
 
bool vis[N];
struct Graph{
	int vex[N];
	int graph[N][N];
	int sum_vex, sum_arc;
};
void print();
void init(Graph &g) {
	for (int i = 1; i <= g.sum_vex; ++i) {
		for (int j = 1; j <= g.sum_vex; ++j) {
			g.graph[i][j] = 0;
		}
	}
	return;
}
void creat(Graph &g) {
	cout << "请输入顶点数和边数：";
	cin >> g.sum_vex >> g.sum_arc;
	cout << endl;
	init(g);
	cout << "请输入" << g.sum_vex << "个顶点：";
	for (int i = 1; i <= g.sum_vex; ++i) {
		cin >> g.vex[i];
	}
	sort(g.vex + 1, g.vex + g.sum_vex + 1);
	cout << "请输入" << g.sum_arc << "个边: ";
	for (int i = 0; i < g.sum_arc; ++i) {
		int s, e;
		cin >> s >> e;
		g.graph[s][e] = g.graph[e][s] = 1;
	}
	return;
}
void print_graph(Graph g) {
	for (int i = 1; i <= g.sum_vex; ++i) {
		for (int j = 1; j <= g.sum_vex; ++j) {
			cout << g.graph[i][j] << " ";
		}
		cout << endl;
	}
 
}
void DFS(Graph g, int vex) {
	cout << vex << " ";
	vis[vex] = true;
	for (int i = 1; i <= g.sum_vex; ++i) {
		if (g.graph[vex][g.vex[i]] == 0 ||  vis[g.vex[i]] == true)	continue;
		DFS(g, g.vex[i]);
	}
}
 
struct Node{
	int data;
	Node *next;
};
struct Queue{
	Node *front, *rear;
};
void Init(Queue &Q) {
	Q.front = Q.rear = (Node*)malloc(sizeof(Node));
	Q.front->next = NULL;
	Q.front->data = 0;
}
int Empty(Queue Q) {
	if (Q.front == Q.rear)	return true;
	return false;
}
int Top(Queue Q, int &e) {
	if (Empty(Q))	return -1;
	e = Q.front->next->data;
	return 1;
}
void Push(Queue &Q, int e) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.front->data++;
}
int Pop(Queue &Q, int &e) {
	if (Empty(Q))	return -1;
	Node *p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (p == Q.rear)	Q.rear = Q.front;
	free(p);
	Q.front->data--;
	return 1;
}
 
void BFS(Graph g, int vex) {
	for (int i = 1; i <= g.sum_vex; ++i)
		vis[g.vex[i]] = false;
	Queue que;
	Init(que);
	Push(que, vex);
	vis[vex] = true;
	while (!Empty(que)) {
		int top;
		Pop(que, top);
		cout << top << " ";
		for (int i = 1; i <= g.sum_vex; ++i) {
			if (vis[g.vex[i]] || g.graph[top][g.vex[i]] == 0)	continue;
			vis[g.vex[i]] = true;
			Push(que, g.vex[i]);
		}
	}
}
int main() {
	print();
	Graph g;
    int t;
	while (cin >> t) {
		if (t == 5)	break;
		switch (t) {
			case 1:	// 创建
				creat(g);
				break;
			case 2: // 输出
				print_graph(g);
				break;
			case 3: // 深度
				for (int i = 1; i <= g.sum_vex; ++i)
					vis[g.vex[i]] = false;
				DFS(g, g.vex[1]);
				break;
			case 4: // 广度
				BFS(g, g.vex[1]);
				break;
 
			default:
				printf("输入序号错误! ");
				break;
		}
		printf("\n请输入操作代码：");
	}
	return 0;
}
 
void print() {
	cout << "**************************************************************\n";
	cout << "******************  1.创建网图              ******************\n";
	cout << "******************  2.输出邻接矩阵          ******************\n";
	cout << "******************  3.深度优先遍历          ******************\n";
	cout << "******************  4.广度优先遍历          ******************\n";
	cout << "******************  5.退出                  ******************\n";
	cout << "请输入你的选择：";
} 