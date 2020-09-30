//https://codeforces.com/contest/1418/problem/C
//Optimisation DP, 2 states used

#include<bits/stdc++.h>
using namespace std;
#define ll int
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const ll MAXX=2e5+5;
vector<ll> a;

ll dp[MAXX][2];
ll n;
int solve(int idx,int turn){
        if(idx>n)
    return 0;
    if(dp[idx][turn]!=-1)
        return dp[idx][turn];


    ll nT=!turn;
    ll res=INT_MAX;
    

    if(turn==1){
        if(a[idx]){
            res=min(res,1+solve(idx+1,nT));
            if(idx+1<=n){
                if(a[idx+1])
                    res=min(res,2+solve(idx+2,nT));
                else    res=min(res,1+solve(idx+2,nT));
            }
        }
        else{
              res=min(res,solve(idx+1,nT));
            if(idx+1<=n){
                if(a[idx+1])
                    res=min(res,1+solve(idx+2,nT));
                else    res=min(res,solve(idx+2,nT));
            }
        }
    }
    else{
        res=min(res,min(solve(idx+1,nT),solve(idx+2,nT)));
        
    }

     dp[idx][turn]=res;
     return res;

}


int main()
{
    fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;

    while(t--){
       cin>>n;
       a.resize(n+1);
       for(ll i=1;i<=n;i++)
            cin>>a[i];

        memset(dp,-1,sizeof(dp));

        cout<<solve(1,1)<<"\n";
       


    }

}
