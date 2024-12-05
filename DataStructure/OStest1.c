#include<stdio.h>

int main(){
    printf("请选择操作\n1.加法\n2.减法\n3.乘法\n4.除法\n5.阶乘\n");
    int x;
    scanf("%d",&x);
    
    
   
    switch(x){
        case 1:
        int a,b;
        printf("请输入两个整数\n");
        scanf("%d %d",&a,&b);
        printf("结果是%d\n",a+b);
        break;
        case 2:
        printf("请输入两个整数\n");
        scanf("%d %d",&a,&b);
        printf("结果是%d\n",a-b);
        break;
        case 3:
        printf("请输入两个整数\n");
        scanf("%d %d",&a,&b);
        printf("结果是%d\n",a*b);
        break;
        case 4:
        printf("请输入两个整数\n");
        scanf("%d %d",&a,&b);
        
        if(b!=0){
            printf("结果是%d\n",a/b);
            break;
        }
        else{
            printf("Error! 被0 除!\n");
            break;
        }
        case 5:
        int c;
        printf("请输入一个整数\n");
        scanf("%d",&c);
        if(c<0){
            //阶乘

            printf("Error! 阶乘定义为非负整数!\n");
        }else{
            int sum=1;
            for(int i=1;i<=c;i++){
                sum*=i;
            }
            printf("结果是%d\n",sum);
        }
        break;
        default:
        printf("Error! 输入有误!\n");

    }
}