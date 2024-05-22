#include<iostream>
using namespace std;
int a[10000];
int main(void){
    int len ,n;
    cin>>len>>n;
    int i = len +1;
    while(i--){
        a[i] = -1;
    }
    while(n--){
        int l,r;
        cin>>l>>r;
        a[l] = r;
        a[r] = l;

    }
    for(int j = 0;j<=len;j++){
        if(a[j]!=-1){
            int l = j,r = a[j];
            for(int t = l+1;t<r;t++ ){
                if(a[t] != -1&&a[t]>a[j]){
                    a[a[j]] = -1;
                   a[j] = a[t];
                   a[a[t]] = j;
                   a[t] = -1; 
                }
                else {

                   a[a[t]] = -1;
                    a[t] = -1;
                }
            }
        }
    }
    int sum = 0;
    for(int k = 0;k<=len;k++){
        if(a[k] != -1){
        	
            sum += a[k]-k+1;
            k = a[k]+1;
        }
    }
    cout<<len+1-sum;

}
