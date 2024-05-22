#include<iostream>
#include<cmath>
using namespace std;
int a[1000],b[1000],c[1000];
int main(void){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int num = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
           if(
            abs(a[i]-a[j])<=5 &&
            abs(b[i]-b[j])<=5&&
            abs(c[i]-c[j])<=5&&
            abs(a[i]+b[i]+c[i]-a[j]-b[j]-c[j]) <=10
           ){
            num++;
           } 
        }
    }
    cout<<num;
}