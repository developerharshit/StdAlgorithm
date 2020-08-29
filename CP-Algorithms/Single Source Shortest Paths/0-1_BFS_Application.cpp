// AtCoder Beginner Contest 176
// Link to Problem : https://atcoder.jp/contests/abc176/tasks/abc176_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


bool mat[1005][1005];
bool vis[1005][1005];

ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {1, -1, 0, 0};
    ll H,W;
bool valid(ll r, ll c) {
	return r >= 0 && r < H && c >= 0 && c < W;
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


    cin>>H>>W;

    ll sx,sy,dx,dy;
    cin>>sx>>sy;
    cin>>dx>>dy;

    --sx,--sy,--dx,--dy;
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
         char c;
         cin>>c;
         mat[i][j]=(c=='.');
        }
    }

    deque<pair<pair<ll,ll>,ll> > q;
    q.push_front(make_pair(make_pair(sx,sy),0));

    ll ind=0;
    while(!q.empty()){
        pair<pair<ll,ll>,ll > p=q.front();
        q.pop_front();

        pair<ll,ll> pos=p.first;

        if(vis[pos.first][pos.second]) continue;
        vis[pos.first][pos.second]=1;
        
        if (pos.first == dx && pos.second == dy) {
			cout << p.second << '\n';
            ind=1;
			break;
		}

        for (ll d = 0; d < 4; d++) {
			ll nr = pos.first + dr[d];
			ll nc = pos.second + dc[d];
			
			if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc]) {
				q.push_front(make_pair(make_pair(nr, nc), p.second));
			}
		}
        for (ll dr = -2; dr <= 2; dr++) {
			for (ll dc = -2; dc <= 2; dc++) {
				ll nr = pos.first + dr;
				ll nc = pos.second + dc;
				
				if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc]) {
					q.push_back(make_pair(make_pair(nr, nc), p.second + 1));
				}
			}
		}

    }

    if(!ind)
        cout<<-1<<"\n";

}
