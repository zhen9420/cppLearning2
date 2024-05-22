#include<iostream>
using namespace std;
int a[34];
int ans[8];
int main(void){
    int n;
    cin>>n;
    for(int i = 0;i <7;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    
    while (n--)
    {
        int sum = 0;
        for (int i = 0; i < 7; i++)
        {
            int x;
            cin >> x;
            if(a[x]){
                sum++;
            }
        }
        ans[sum]++;
    }
    for(int i = 7;i >0;i--){
        cout<<ans[i]<<' ';
    }
}