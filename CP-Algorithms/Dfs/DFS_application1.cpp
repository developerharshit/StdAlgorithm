#include<bits/stdc++.h>
using namespace std;
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int m,n;
vector<vector<int> > adj;
vector<int> cats;
vector<bool> vis;
int ans=0;
void dfs(int v,int c,int f) {
   vis[v]=true;
   if(cats[v]&&f)
    c++;
    if(cats[v])
        f=1;
    else {
        f=0;
        c=0;
    }
    if(adj[v].size()==0){
        if(c<=m)
        ans++;
        c=0;
        return;
    }
    for (int u : adj[v])
        if (!vis[u])
            dfs(u,c+cats[u],f);

}

int main(){

        fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 
    cin>>n>>m;
    adj.resize(n+1);
    cats.resize(n+1);
    vis.resize(n+1,false);

    for(int i=1;i<=n;i++)
        cin>>cats[i];
    
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
      //  cout<<u<<" "<<v<<"\n"; 
        adj[u].push_back(v);
    }
    dfs(1,cats[1],cats[1]);
    cout<<ans<<"\n";
    return 0;
}