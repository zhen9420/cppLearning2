#include<iostream>
using namespace std;
int a[10000];
int main(void){
    int len ,n;
    cin>>len>>n;
    int i = len +1;
    
    while(n--){
        int l,r;
        cin>>l>>r;
        for(int j = l;j<=r;j++){
        	a[j]++ ;
		}

    }
    int sum = 0;
    for(int j = 0;j<=len;j++){
    	if(a[j]){
    		sum++;
		}
	}
   
   
    
    cout<<len+1-sum;

}
