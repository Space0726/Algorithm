#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int set_pointer;

struct nodetype
{
    int parent;
    int depth;
};

struct edge
{
    pair<int, int> vertexes;
    int weight;

    // Overrides operator<() to sort edges using std::sort().
    bool operator<(const edge &other) const
    {
        if (this->weight < other.weight)
            return true;
        else if (this->weight == other.weight)
            if (this->vertexes.first < other.vertexes.first)
                return true;
        return false;
    }
};

vector<nodetype> U;

void makeset(int i)
{
    U[i].parent = i;
    U[i].depth = 0;
}

set_pointer find(int i)
{
    int j;
    j = i;
    while (U[j].parent != j)
        j = U[j].parent;
    return j;
}

void merge(set_pointer p, set_pointer q)
{
    if (U[p].depth == U[q].depth)
    {
        U[p].depth += 1;
        U[q].parent = p;
    }
    else if (U[p].depth < U[q].depth)
        U[p].parent = q;
    else
        U[q].parent = p;
}

bool equal(set_pointer p, set_pointer q)
{
    if (p == q)
        return true;
    else
        return false;
}

void initial(int n)
{
    int i;
    for (i = 0; i < n; i++)
        makeset(i);
}

void kruskal(int n, int m, vector<edge> E, vector<edge> &F)
{
    int i, j;
    set_pointer p, q;
    edge e;

    sort(E.begin(), E.end());
    F = vector<edge>();
    initial(n);

    int edge_idx = 0;
    while (F.size() < n-1)
    {
        e = E[edge_idx];
        i = e.vertexes.first;
        j = e.vertexes.second;
        p = find(i);
        q = find(j);
        if (!equal(p, q))
        {
            merge(p, q);
            F.push_back(e);
        }
        edge_idx++;
    }
}

void print_edges(vector<edge> &e)
{
    for (const auto &edge: e)
    {
        cout << "Vertexes: "<< edge.vertexes.first+1 << ", " << edge.vertexes.second+1 << endl;
        cout << "Weight: " << edge.weight << endl << endl;
    }
}

int main()
{
    int n;
    cout << "Type n: ";
    cin >> n;
    U = vector<nodetype> (n);

    int m;
    vector<edge> E, F;
    cout << "Type number of edges: ";
    cin >> m;
    cout << "Type edges in the order vertex1, vertex2, weight: " << endl;
    for (int i = 0; i < m; i++)
    {
        edge e;
        cin >> e.vertexes.first >> e.vertexes.second >> e.weight;
        e.vertexes.first--;
        e.vertexes.second--;
        E.push_back(e);
    }

    kruskal(n, m, E, F);
    cout << endl << "F: " << endl;
    print_edges(F);
    return 0;
}
