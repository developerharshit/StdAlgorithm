// Link : https://cp-algorithms.com/graph/01_bfs.html
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > adj;
int n;

void BFS_01(int s){
    vector<int> d(n,INT_MAX);
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
    return 0;
}