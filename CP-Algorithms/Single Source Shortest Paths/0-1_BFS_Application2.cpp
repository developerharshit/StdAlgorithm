// Codechef : Chef and Reversing
// Link : https://www.codechef.com/problems/REVERSE
#include<bits/stdc++.h>
using namespace std;
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<vector<pair<int,int> > > adj;
int n,m;
vector<int> d;
void BFS_01(int s){
    d.resize(n+1,INT_MAX);
    d[s]=0;
    deque<int> q;
    q.push_front(s);

    while(!q.empty()){
        int v = q.front();
        q.pop_front();

        for(auto edge: adj[v]){
            int u=edge.first;
            int w=edge.second;

            if(d[v] + w <d[u]){
                d[u] = d[v] +w;

                if(w==1)
                    q.push_back(u);
                else 
                    q.push_front(u);
            }
        }
    }

}

int main()
{
    // Take Graph Input & Call 0-1 BFS function
        fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>m;
    adj.resize(n+1);

    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(make_pair(v,0));
        adj[v].push_back(make_pair(u,1));
    }
    BFS_01(1);
    if(d[n]!=INT_MAX)
    cout<<d[n]<<"\n";
    else cout<<-1<<"\n";

    return 0;
}