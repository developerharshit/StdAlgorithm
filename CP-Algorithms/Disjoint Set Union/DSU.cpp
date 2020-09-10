#include<bits/stdc++.h>
using namespace std;
const long long MAXX=1e5+5;
int parent[MAXX];


//Disjoint set union find data structure
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main()
{

    return 0;
}