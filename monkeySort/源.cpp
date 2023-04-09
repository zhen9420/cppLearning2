#include <stdio.h>     
#include <stdbool.h>
#include <stdlib.h>  
#include <math.h>
#include <time.h>
void change(int* a, int* b)   //交换两元素的值
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printArray(int a[], int count)   //打印数组元素
{
    int i;
    for (i = 0; i < count; i++)
        printf("%d ", a[i]);
    printf("\n");
}

bool isOrder(int a[], int n)  //判断序列是否已经有序
{
    int i;
    for (i = 0; i < n - 1; i++)//这里i是比较次数，所以<n-1 
    {
        if (a[i] > a[i + 1])  return false;
    }
    return true;
}

void shuffle(int a[], int n)
{
    int i, changePosition;
    for (i = 0; i < n; i++)
    {
        changePosition = rand() % n;
        change(&a[i], &a[changePosition]);//随机交换下标不同的元素
    }
}

void bogoSort(int a[], int n)
{
    int count = 0;
    while (!isOrder(a, n))
    {
        shuffle(a, n);
        count++;
        printf("第%d次排序\n", count);
    }
    printf("\n\n排序次数为：%d次\n\n", count);
}

int main(void)
{
    int a[] = { 7,4,0,9,2,6};
    int n = sizeof(a) / sizeof(*a);//计算数组元素个数
    srand((unsigned)time(NULL)); //随机数种子 
    printArray(a, n);//遍历输出
    bogoSort(a, n);//猴子排序
    printArray(a, n);//遍历输出 
    system("pause");
    return 0;
}
