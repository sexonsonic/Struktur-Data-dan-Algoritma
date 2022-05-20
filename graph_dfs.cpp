#include <iostream>
using namespace std;

int vertex,
    edge,
    visited[20],
    **adj;

void createGraph(int v, int e)
{
    vertex = v;
    edge = e;

    adj = new int *[v];

    // membuat matrix [m x n]
    for (int line = 0; line < v; line++)
    {
        adj[line] = new int[v];
        for (int column = 0; column < v; column++)
        {
            adj[line][column] = 0; //mengartikan bahwa matrix belum mempunyai elemen atau edge
        }
        
    }
}

void addEdge(int vFirst, int vGoals)
{
    adj[vFirst][vGoals] = 1; // 1 berarti ada hubungan diantara 2 vertex
    adj[vGoals][vFirst] = 1; // menunjukan graph tak berarah dan tak berbobot, awal dan tujuan dibuat sama
}

void DFS(int start)
{
    // output vertex
    cout << start << " ";

    visited[start] = 1;

    // mengunjungi beberapa vertex yang berdekatan dgn vertex yang sedang dikunjungi dan belum pernah dikunjungi
    for (int i = 0; i < vertex; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int v = 13, e = 13;
    createGraph(v, e);

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(4, 8);
    addEdge(4, 9);
    addEdge(2, 5);
    addEdge(5, 10);
    addEdge(3, 6);
    addEdge(6, 11);
    addEdge(3, 7);
    addEdge(7, 12);

    DFS(1);
    return 0;
}