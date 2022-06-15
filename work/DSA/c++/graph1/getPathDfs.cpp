#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e,v1,v2;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    vector<int> visited(v,0);
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            print(graph,visited)
        }
    }
}