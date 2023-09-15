#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

 
void CheckFile();
int FirstMenu();
int SecondMenu(int i);

void Write();
void Search();
 
typedef struct Student
{
	char sNumber[9];
	char sName[20];
	char sSex[3];
	int iGrade[4];
} Stu;
 
int main()
{
	int flag=0;  
   
	while(flag!=3)
	{
		system("cls");
		flag=SecondMenu(FirstMenu());
	}
}
 
int FirstMenu()
{
	int i; 
	cout << "*****************************************************" << endl;
	cout << "*                                                   *" << endl;
	cout << "*            1    录入学生成绩                      *" << endl;
	cout << "*            2    查询学生成绩                      *" << endl;
	cout << "*            3    退出                              *" << endl;
	cout << "*****************************************************" << endl;
	cout << "请您选择（输入数字）：";
	cin >> i;	
	return i;
}
 
int SecondMenu(int i)
{
	system("cls");
    switch(i)
	{
	   case 1:
		   {
			   Write();
			   break;
		   }
	   case 2:
		   {
			   Search();
			   break;
		   }
	   case 3:
		   {
			   cout << "程序已经退出！" << endl;
			   break;
		   }
	}
	return i;
 
}
 
void Write()
{
	FILE *fp;
	Stu s,*p;
	char s1;
	char s2='n';   
	p=&s;
	if((fp=fopen("学生信息.dat","ab"))==NULL)
	{
		if((fp=fopen("学生信息.dat","wb"))==NULL)
		{
			cout << "打开文件时出错！" << endl;
			exit(1);
		}
	}
	do
	{
		cout << "请输入学生的信息：" << endl;
		cout << "学号：";
		cin >> s.sNumber;
		cout << "姓名：";
		cin >> s.sName;
		cout << "性别：";
		cin >> s.sSex;
		cout << "请输入成绩,要求输入非负整数：" << endl;
		cout << "数学：";
		cin >> s.iGrade[0];
		cout << "英语：";
		cin >> s.iGrade[1];
		cout << "计算机：";
		cin >> s.iGrade[2];
		cout << "体育：";
		cin >> s.iGrade[3];
		cout << "是否确定？（输入：y/n）" << endl;
		cin >> s1;
		if(s1=='y')
		{
			fwrite(p,sizeof(Stu),1,fp);
			system("cls");
			cout << "录入成功，是否继续录入？（输入：y/n）" << endl;
			cin >> s2;
			system("cls");
		}
	}while(s2=='y');
	fclose(fp);
}
  
void Search()
{
    FILE *fp;
	Stu s,*p;
    char sNumber1[9];
	int option;
	p=&s;
	cout << "请输入学号：";
    cin >> sNumber1;
	if((fp=fopen("学生信息.dat","rb"))==NULL)
	{
		cout << "打开文件时出错！";
		exit(1);
	}
	else
	{
		int k;
		do
		{
			fread(p,sizeof(Stu),1,fp);			
		}while(strcmp(p->sNumber,sNumber1)!=0&&feof(fp)==0);

		if(strcmp(p->sNumber,sNumber1)!=0)
		{
			cout << "无此学生信息！" << endl;
            cout << "按任意键确定。";
			getch();
			return;
		}
		cout << endl;
		cout << endl;

		cout << "++++++++++++++++++++++" << endl;
		cout << "+  1  输出数学成绩   +" << endl;
		cout << "+  2  输出英语成绩   +" << endl;
		cout << "+  3  输出计算机成绩 +" << endl;
		cout << "+  4  输出体育成绩   +" << endl;
		cout << "+  5  输出所有成绩   +" << endl;
		cout << "++++++++++++++++++++++" << endl;
		cout << "请选择：";
		cin >> option;
		cout << endl;
        cout << "学号" << '\t' << "姓名" << '\t' << "性别" << endl;
		cout << p->sNumber << '\t' << p->sName << '\t' << p->sSex << endl;		
               
		switch(option)
		{
		  case 1:
			  {
				  cout << "数学" << endl << p->iGrade[0] << endl;
				  break;
			  }
		  case 2:
			  {
				  cout << "英语" << endl << p->iGrade[1] << endl;
				  break;
			  }
		  case 3:
			  {
				  cout << "计算机" << endl << p->iGrade[2] << endl;
				  break;
			  }
		  case 4:
			  {
				  cout << "体育" << endl << p->iGrade[3] << endl;				  
				  break;
			  }
		  case 5:
			  {
				  cout << "数学" << '\t' << "英语" << '\t' << "计算机" << '\t' << "体育" << '\t' << endl;
				  for(k=0;k<4;k++)
					  cout << p->iGrade[k] << '\t';
				  cout << endl;
			  }
		}
		cout << "按任意键确定：";
		getch();
	}
}
