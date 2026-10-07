#include<bits/stdc++.h>
using namespace std;

vector<int> adj[6];
bool visited[6];

void dfs(int node)
{
    visited[node] = true;

    cout << node << " ";

    for(int next : adj[node])
    {
        if(!visited[next])
        {
            dfs(next);
        }
    }
}

int component = 0;

int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[4].push_back(5);
    adj[5].push_back(4);

    for(int i = 0; i < 6; i++)
    {
        if(!visited[i])
        {
            component++;

            cout << "Component: ";

            dfs(i);

            cout << endl;
        }
    }

    cout << "Total Connected Components = " << component << endl;

    return 0;
}
