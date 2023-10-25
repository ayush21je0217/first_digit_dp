//my first digit dp code :) from cses Counting Numbers
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define ninf -1e18
#define frl(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvvvi vector<vector<vector<vector<int>>>>
#define print(x) cout<<x<<"\n";
void output(vector<int>&v,int n,int a,int b)
{
for(int i=a;i<=b;i++)cout<<v[i]<<" ";
cout<<"\n";
}
int solve(string num,int n,int f,int can_use_adj_zero,int prev_used,vvvvi &dp)
{
    if(n==1)
    {
        if(can_use_adj_zero==0)
        {
            if(f)
            {
                int maxi=num[num.size()-1]-'0';
                if(maxi>=prev_used)return maxi;
                return maxi+1;
            }
            else
            {
                return 9;
            }
        }
        return 10;
    }
    if(dp[n][f][can_use_adj_zero][prev_used]!=-1)return dp[n][f][can_use_adj_zero][prev_used];
    int ub=(f==1)?(num[num.size()-n]-'0'):9;
    int ans=0;
    frl(i,0,ub+1)
    {
        if(can_use_adj_zero==1)
        {
           if(i==prev_used && i!=0)continue;
           ans+=solve(num,n-1,f&&(i==ub),can_use_adj_zero&&(i==0),i,dp);
        }
        else
        {
           if(i==prev_used)continue;
           ans+=solve(num,n-1,f&&(i==ub),0,i,dp);
        }
    }
    return dp[n][f][can_use_adj_zero][prev_used]=ans;
}
int get0_num(string &num)
{
    vvvvi dp(20,vvvi(3,vvi(3,vi(10,-1))));
    return solve(num,num.size(),1,1,0,dp);
}
void s()
{
    int l,r;
    cin>>l>>r;
    if(l!=0 && l>=10)l--;
    string ls=to_string(l);
    string rs=to_string(r);
    int ans1=0,ans2=0;
    if(l<10)ans1=l;
    else ans1=get0_num(ls);
    if(r<10)ans2=r+1;
    else ans2=get0_num(rs);
    cout<<ans2-ans1<<"\n";
}
int32_t main()
{
int t=1;
// cin>>t;
while(t--)s();
}


