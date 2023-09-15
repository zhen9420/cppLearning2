#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>



using namespace std;



void tentoeight(int num)      //十进制数转八进制数         
{
	int  m = 0, a[100], i = 0, k = 0;

	while (num / 8 != 0) {
		m = num % 8;
		num /= 8;
		a[i] = m;
		++i;
		++k;
	}
	a[k] = num;
	for (int i = k; i >= 0; --i) {
		cout << a[i];
	}


}

void tentosixteen(int n)         //十进制数转十六进制数
{
	int i = 0;
	char s[200];
	while (n)
	{
		if (n % 16 >= 10)
			s[i] = n % 16 + 55;
		else
			s[i] = n % 16 + 48;
		i++;
		n = n / 16;
	}
	for (i = i - 1; i >= 0; i--)
		printf("%c", s[i]);


}

void digit(int n)     //判断位数，以及输出各位数的数字
{
	int i = 1;
	int a[3] = { 0 };
	while (n)
	{
		if (n / 10 != 0)
		{

			a[i - 1] = n % 10;

			++i;
		}
		else
			a[i - 1] = n;
		n = n / 10;

	}

	cout << "该数为" << i << "位数" << "，";
	cout << '\n';

	while (i)
	{
		switch (i)
		{
		case 1:cout << "个位是:" << a[i - 1] << ","; cout << '\n'; break;
		case 2:cout << "十位是:" << a[i - 1] << ","; cout << '\n'; break;
		case 3:cout << "百位是:" << a[i - 1] << ","; cout << '\n'; break;
		}
		--i;
	}

}

void leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d年是闰年\n", year);
	else
		printf("%d年不是闰年\n", year);


}

void gradechange(int grade)     //成绩等级转换
{
	if (grade > 100 || grade < 0)
	{
		cout << "成绩输入错误";
	}
	else
		switch (grade / 10)
		{
		case 10:
		case 9:printf("优秀"); break;
		case 8:printf("良"); break;
		case 7:printf("中"); break;
		case 6:printf("及格"); break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:printf("不及格"); break;

		}

	cout << '\n';

}

void odd(int n)        //for循环
{
	int t = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		if (i % 2 != 0)
		{
			t = t + i;
		}

	}

	cout << "1到该输入数的奇数和为：" << t;

	cout << '\n';

}

void even(int n)     //while判断
{

	int t = 0, j = 1, i = 1;
	while (j)
	{
		if (i % 2 == 0 || i == 1)
		{
			t = t + i;
		}

		if (i == n)
		{
			j = 0;
		}

		++i;

	}

	cout << "1到该输入数的偶数和为：" << t;

	cout << '\n';

}

void three(int n)    //3的倍数
{
	int k = 1, i = 1;

	do
	{
		if (i == 1 || i % 3 == 0)
		{
			cout << i << ' ';

		}

		if (i == n)
		{
			k = 0;
		}

		++i;

	} while (k);

	cout << '\n';

}

void divisible(int n, int m)    //判断被三和五整除的数
{
	if (n % 3 == 0 && n % 5 == 0)
	{
		cout << n << "可被3和5整除";
	}

	else if (m % 3 == 0 && m % 5 == 0)
	{
		cout << n << "不可被3和5整除，" << m << "可被3和5整除";
	}

	else
	{
		cout << n << "和" << m << "都不可被3和5整除";
	}

	cout << '\n';

}

void daffidil()    //判断1000以内的水仙花数
{

	int a, b, c, num1, num2;
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				num1 = a * a * a + b * b * b + c * c * c;
				num2 = a * 100 + b * 10 + c;
				if (num1 == num2)
				{
					cout << num2 << ' ';
				}
			}
		}

	}

	cout << '\n';

}

void max1(int x, int y)    //两个数求最大值
{

	cout << "两个数中较大的是：";
	if (x > y)
	{
		cout << x;
	}
	else if (x < y)
	{
		cout << y;
	}
	else
	{
		cout << "两个数一样大";
	}

	cout << '\n';

}

void max2(int* x, int* y)    //（指针）两个数求最大值和最小值
{

	if (*x > *y)
	{
		cout << "两个数中较大的是：" << *x << ' ' << "两个数中较小的是：" << *y;
	}
	else if (*x < *y)
	{
		cout << "两个数中较大的是：" << *y << ' ' << "两个数中较小的是：" << *x;
	}
	else
	{
		cout << "两个数一样大";
	}

	cout << '\n';
}

void maopao(int q[])   //冒泡循环
{
	int t;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9 - i; ++j)
		{
			if (q[j] > q[j + 1])
			{
				t = q[j];
				q[j] = q[j + 1];
				q[j + 1] = t;
			}



		}



	}

	cout << "排序后的数为：";

	for (int i = 0; i < 10; ++i)
	{
		cout << q[i] << ' ';
	}

	cout << '\n';

}

void zhuanzhi()     //矩阵转置
{
	int arr1[3][4], arr2[4][3];
	for (int i = 0; i < 3; ++i)
	{
		cout << "请输入3x4的矩阵第" << i + 1 << "行的元素：";
		for (int j = 0; j < 4; ++j)
		{
			cin >> arr1[i][j];
		}
	}

	cout << "转置后的矩阵为：" << '\n';

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr2[i][j] = arr1[j][i];
		}

	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr2[i][j] << ' ';
		}
		cout << '\n';
	}

}

void duijiaoxian()   //主对角线元素和
{
	int arr[3][3] = { 0 };

	for (int i = 0; i < 3; ++i)
	{
		cout << "输入3x3矩阵第" << i + 1 << "行的元素：";

		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}

	}

	int t = arr[0][0] + arr[1][1] + arr[2][2];
	cout << "主对角线的元素和是：" << t;
	cout << '\n';

}

void dancishu()   //统计单词个数
{
	char a[101];
	int i, num = 0, word = 0;
	char c;

	printf("请输入一行英文（100词以下）：");
	getchar();
	gets_s(a);


	for (i = 0; ((c = a[i]) != '\0'); i++)
		if (c == ' ') word = 0;
		else if (word == 0)
		{
			word = 1;
			num++;
		}
	printf("总共有%d个单词\n", num);

}

void static1()         //创建静态链表
{
	struct student
	{
		char name[10];
		int age;
		student* next; //节点数据类型的指针	
	};

	student d = { "学生1",23,NULL }; //尾指针null 
	student c = { "学生2",22,&d };
	student b = { "学生3",21,&c };
	student a = { "学生4",20,&b };
	student* head = &a; //头指针 

	student* point = head;

	while (point)
	{
		cout << point->name << " " << point->age << endl;
		point = point->next;
	}

	cout << '\n';

}

void trends1()    //创建动态链表
{
	typedef struct node
	{
		int data;
		struct node* next;
	} *nodes;

	int count;

	nodes head, p;

	p = (nodes)malloc(sizeof(node));
	p->next = NULL;
	head = p;
	p = head;

	cout << "请输入链表数据，输入负数为截止标识：";

	while (cin >> count && count > 0)
	{
		nodes q = (nodes)malloc(sizeof(node));
		q->data = count;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	cout << "输出链表数据：";

	p = head->next;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << '\n';

}

void paixv()      //结构体学生成绩排序
{
	typedef struct students                                      //定义此种结构体为新类型st 
	{
		int num;
		char name[10];
		float grade;
	} st;

	struct students students[10];

	int i, j, t;

	st z;
	float sumgrade = 0;

	for (i = 0; i < 10; ++i)
	{
		cout << "请输入第" << i + 1 << "位学生的信息：";
		cout << "请输入学号：";
		cin >> students[i].num;
		cout << "请输入姓名：";
		cin >> students[i].name;
		cout << "请输入成绩：";
		cin >> students[i].grade;

		sumgrade = sumgrade + students[i].grade;
	}

	for (j = 0; j < 10; j++)
	{

		for (i = 0; i < -j - 1; i++)
		{
			if (students[i].grade > students[i + 1].grade)
			{
				z = students[i];
				students[i] = students[i + 1];
				students[i + 1] = z;
			}
		}
	}

	for (i = 0; i < 2; i++)
	{
		printf("学号是%d,姓名是%s,成绩是%.1f\n", students[i].num, students[i].name, students[i].grade);
	}
	printf("\n");
	printf("总成绩是%.1f,平均成绩是%.1f", sumgrade, sumgrade / 10);

}

void fileopen()
{
	int i, a[10];

	FILE* fp;
	fp = fopen("d:\\my.txt", "r+"); //读写方式打开 

	for (i = 0; i < 10; ++i)
	{
		fscanf(fp, "%d", &a[i]);	  //文件读取 
	}

	rewind(fp);   //重回开头 

	for (i = 0; i < 10; ++i)
		fprintf(fp, "%d\n", a[i] + 10);  //加10分并重新写入 

	fclose(fp); //关闭文件 

	printf("已完成操作\n");
}





int main()
{



	//以下是界面的设计

	//开始的空格
	for (int i = 0; i < 40; ++i)
	{
		cout << ' ';
	}


	//开始的*号
	for (int i = 0; i < 40; ++i)
	{
		cout << '*';
	}
	cout << '\n';

	//文字界面
	for (int j = 0; j < 25;++j)
	{
		for (int i = 0; i < 40; ++i)
		{
			cout << ' ';
		}

		cout << '*';

		for (int i = 0; i < 13; ++i)
		{
			cout << ' ';
		}

		switch (j + 1)
		{
		case 1:
			cout << "小小计算器";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 2:
			cout << '1' << ' ' << "加法";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 3:
			cout << '2' << ' ' << "减法";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 4:
			cout << '3' << ' ' << "乘法";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 5:
			cout << '4' << ' ' << "除法";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 6:
			cout << '5' << ' ' << "取模运算";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 7:
			cout << '6' << ' ' << "计算圆面积";
			for (int i = 0; i < 13; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 8:
			cout << '7' << ' ' << "判断数字的位数";
			for (int i = 0; i < 9; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 9:
			cout << '8' << ' ' << "判断闰年";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 10:
			cout << '9' << ' ' << "成绩转换";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 11:
			cout << "10" << ' ' << "奇数和";
			for (int i = 0; i < 16; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 12:
			cout << "11" << ' ' << "偶数和";
			for (int i = 0; i < 16; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 13:
			cout << "12" << ' ' << "3的倍数";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 14:
			cout << "13" << ' ' << "被3和5整除";
			for (int i = 0; i < 12; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 15:
			cout << "14" << ' ' << "水仙花数";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 16:
			cout << "15" << ' ' << "求最大值";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 17:
			cout << "16" << ' ' << "求最大最小值";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 18:
			cout << "17" << ' ' << "冒泡循环";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 19:
			cout << "18" << ' ' << "矩阵转置";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 20:
			cout << "19" << ' ' << "对角线和";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 21:
			cout << "20" << ' ' << "统计单词个数";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 22:
			cout << "21" << ' ' << "创建静态链表";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 23:
			cout << "22" << ' ' << "创建动态链表";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 24:
			cout << "23" << ' ' << "学生成绩排序";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 25:
			cout << "24" << ' ' << "成绩普涨10分";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;




		case 26:
			cout << "25" << ' ' << "退出";
			for (int i = 0; i < 18; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		}

	}

	//结尾空格
	for (int i = 0; i < 40; ++i)
	{
		cout << ' ';
	}


	//结尾*号
	for (int i = 0; i < 40; ++i)
	{
		cout << '*';
	}
	cout << '\n';
	cout << '\n';

	//界面的设计结束

	//进入计算器功能
	int t;
	int a, b;
	float c, d;
	int* m, * n;
	int arr[10] = { 0 };
	double e; double pai = 3.14;


	for (int l = 0; l < 1000; ++l)  //通过for循环实现只有选择退出才会结束程序，否则会进行下一次计算
	{
		cout << ' ' << ' ' << ' ' << ' ' << "请输入你想使用的计算方式:";
		cin >> t;


		switch (t)
		{
		case 1:
			cout << "请输入被加数和加数：";
			cin >> a >> b;
			cout << "十进制形式：" << a + b << '\n';
			cout << "八进制形式：" << ' '; tentoeight(a + b); cout << '\n';
			cout << "十六进制形式：" << ' ';   tentosixteen(a + b); cout << '\n';
			cout << '\n';
			break;


		case 2:
			cout << "请输入被减数和减数：";
			cin >> a >> b;
			cout << "十进制形式：" << a - b << '\n';
			cout << "八进制形式：" << ' '; tentoeight(a - b); cout << '\n';
			cout << "十六进制形式：" << ' ';   tentosixteen(a - b); cout << '\n';
			cout << '\n';
			break;

		case 3:
			cout << "请输入被乘数和乘数：";
			cin >> c >> d;
			cout << "小数形式：";  printf("%.6f\n", c * d);
			cout << "指数形式："; printf("%.6e\n", c * d);
			cout << '\n';
			break;


		case 4:
			cout << "请输入被除数和除数：";
			cin >> c >> d;
			cout << "小数形式：";  printf("%.6f\n", c / d);
			cout << "指数形式："; printf("%.6e\n", c / d);
			cout << '\n';
			break;


		case 5:
			cout << "请输入被取模数和取模数：";
			cin >> a >> b;
			if (b == 0)
			{
				cout << "除数不能为0";
				cout << '\n'; cout << '\n';
			}
			else
				cout << "十进制形式：" << a % b << '\n';
			cout << "八进制形式：" << ' '; tentoeight(a % b); cout << '\n';
			cout << "十六进制形式：" << ' ';   tentosixteen(a % b); cout << '\n';
			cout << '\n';
			break;


		case 6:
			cout << "请输入圆的半径：";
			cin >> e;
			cout << "该圆的面积是："; printf("%.6f\n", pai * e * e);
			cout << "保留两位小数的结果是："; printf("%.2f\n", pai * e * e);
			cout << '\n';

		case 7:
			cout << "请输入要判断的数字：";
			cin >> a;
			if (a / 1000 != 0)
			{
				cout << "要求输入的数为3位以内的正整数";
				cout << '\n';
			}
			digit(a);
			cout << '\n';
			break;


		case 8:
			cout << "请输入要判断的年份：";
			cin >> a;
			leapyear(a);
			cout << '\n';
			break;


		case 9:
			cout << "请输入成绩：";
			cin >> a;
			cout << "成绩对应的等级是："; gradechange(a);
			cout << '\n';
			break;


		case 10:
			cout << "请输入一个数字：";
			cin >> a;
			odd(a);
			cout << '\n';
			break;


		case 11:
			cout << "请输入一个数字：";
			cin >> a;
			even(a);
			cout << '\n';
			break;


		case 12:
			cout << "请输入一个数字：";
			cin >> a;
			three(a);
			cout << '\n';
			break;


		case 13:
			cout << "请输入两个数字：";
			cin >> a >> b;
			divisible(a, b);
			cout << '\n';
			break;


		case 14:

			cout << "1000以内的水仙花数为：";
			daffidil();
			cout << '\n';
			break;


		case 15:
		{
			cout << "请输入两个数字：";
			cin >> a >> b;

			max1(a, b);
			cout << '\n';
			break;

		}


		case 16:
		{
			cout << "请输入两个数字：";
			cin >> a >> b;

			m = &a, n = &b;

			max2(m, n);
			cout << '\n';
			break;
		}


		case 17:
		{
			cout << "请输入10个数：";
			for (int i = 0; i < 10; ++i)
			{
				cin >> arr[i];
			}
			maopao(arr);
			cout << '\n';
			break;
		}


		case 18:
			zhuanzhi();
			cout << '\n';
			break;


		case 19:
			duijiaoxian();
			cout << '\n';
			break;


		case 20:
			dancishu();
			cout << '\n';
			break;


		case 21:
			static1();
			cout << '\n';
			break;


		case 22:
			trends1();
			cout << '\n';
			break;


		case 23:
			paixv();
			cout << '\n';
			break;


		case 24:
			fileopen();
			cout << '\n';
			break;


		case 25:
			l = 1000;
			cout << "小小计算器已成功退出";
			break;

		}



	}





	return 0;
}