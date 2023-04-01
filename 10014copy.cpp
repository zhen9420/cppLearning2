#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=0,y=0;
    int n;cin>>n;
    getchar();
    string s;cin>>s;
    int l=s.size();
    int a;
    while((a=s.find('Z'))!=-1)
    {
        s[a]='0';
        int cnt=1;
       for(int i=a-1;i>=0&&cnt==1;i--)
       {
           if(s[i]!='Z'&&s[i]!='0')
           {
               s[i]='0';cnt=0;
           }
       }
        
    }
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0')continue;
        if(s[i]=='W')y++;
        if(s[i]=='A')x--;
        if(s[i]=='S')y--;
        if(s[i]=='D')x++;
    }
    cout<<x<<" "<<y;
    return 0;
}
