#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Edge
{
    int u,
        v,
        w;
};

struct Graph
{
    int V,
        E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
};

struct subset
{
    int parent,
        rank;
};

int myComp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;

    return a1->w > b1->w;
}

int find(struct subset subsets[], int i)
{
    // setiap node dijadikan parent
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
    
}

// union 2 buah vertex u,v
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // menambhkan rank tree dibawah parent
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = xroot;
    // jika nilai bobot sama, maka increment rank ++
    else
    {
        subsets[yroot].parent = xroot;
        subsets[yroot].rank++;
    }
    
}

void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge hasil[V];
    int e = 0; // index utk menghitung hasil
    int i = 0; //index utk menghitung sorting edge

    // 1. Sorting semua edge mulai terkecil sampai terbesar
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    //alokasi memory
    struct subset *subsets = new subset;
    //menjadi single elemen
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // 2. Melakukan perulangan jika V - 1
    while (e < V-1)
    {
        // ambil nilai terkecil
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        //compare 2 buah nilai x dan y
        if (x != y)
        {
            hasil[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Edge yang terbentuk menjadi MST\n";
    int total;
    for (int i = 0; i < e; i++)
    {
        total = total + hasil[i].w;
        cout << "( " << hasil[i].u << " , " << hasil[i].v << " ) = " << hasil[i].w << endl;
    }
    cout << "Nilai MST = " << total;

    // 3. Ulangi proses no. 2 sampai tidak melakukan cycle
}

int main()
{
    int V = 4;
    int E = 5;

    struct Graph *graph = createGraph(V, E);

    graph->edge[0].u = 1;
    graph->edge[0].v = 0;
    graph->edge[0].w = 10;

    graph->edge[1].u = 0;
    graph->edge[1].v = 2;
    graph->edge[1].w = 6;

    graph->edge[2].u = 0;
    graph->edge[2].v = 3;
    graph->edge[2].w = 5;

    graph->edge[3].u = 2;
    graph->edge[3].v = 3;
    graph->edge[3].w = 4;

    graph->edge[4].u = 1;
    graph->edge[4].v = 3;
    graph->edge[4].w = 15;

    for (int i = 0; i <= 4; i++)
    {
        cout << "( " << graph->edge[i].u << " , " << graph->edge[i].v << " ) = " << graph->edge[i].w << endl;
    }
    KruskalMST(graph);
}