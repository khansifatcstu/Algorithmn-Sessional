#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ranki;

bool sortbywt(const tuple<int, int, int>& a,
              const tuple<int, int, int>& b)
{
    return get<2>(a) < get<2>(b);
}

int findOp(int u)
{
    if (parent[u] == -1)
        return u;

    return parent[u] = findOp(parent[u]);
}

void unionOp(int u, int v)
{
    if (ranki[u] > ranki[v])
        parent[v] = u;

    else if (ranki[v] > ranki[u])
        parent[u] = v;

    else
    {
        parent[u] = v;
        ranki[v]++;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < e; i++)
    {
        int sc, des, wt;

        cin >> sc >> des >> wt;

        edges.push_back(make_tuple(sc, des, wt));
    }

    sort(edges.begin(), edges.end(), sortbywt);

    parent.assign(v, -1);
    ranki.assign(v, 0);

    vector<tuple<int, int, int>> mst;

    long long totalWeight = 0;

    for (const auto& edge : edges)
    {
        int sc = get<0>(edge);
        int des = get<1>(edge);
        int wt = get<2>(edge);

        int rootSc = findOp(sc);
        int rootDes = findOp(des);

        if (rootSc != rootDes)
        {
            unionOp(rootSc, rootDes);

            mst.push_back(edge);

            totalWeight += wt;

            if ((int)mst.size() == v - 1)
                break;
        }
    }

    if (v > 0 && (int)mst.size() == v - 1)
    {
        cout << "Edges in the MST:" << endl;

        for (const auto& edge : mst)
        {
            cout << get<0>(edge) << " "
                 << get<1>(edge) << " "
                 << get<2>(edge) << endl;
        }

        cout << "Total weight: "
             << totalWeight << endl;
    }
    else
    {
        cout << "The graph is disconnected; no MST exists."
             << endl;
    }

    return 0;
}
