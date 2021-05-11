#include <iostream>
#include <iomanip>
#include <limits.h>

#define SIZE 100
using namespace std;

class Graph
{
    int V, e;
    int graph[SIZE][SIZE];
    int distance[SIZE];
    int visited[SIZE];

public:
    Graph() {}
    Graph(int, int);
    void create();
    void display();
    int findminvertex();
    void dijkstras();
};

Graph::Graph(int vertices, int edges)
{
    V = vertices;
    e = edges;

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }
    distance[0] = 0;
}

void Graph::create()
{
    int src, des, weight;
    for (int i = 0; i < e; i++)
    {
        cout << "\nEnter the source vertex:- ";
        cin >> src;
        cout << "Enter the destination vertex:- ";
        cin >> des;

        if (src != des)
        {
            if (graph[src - 1][des - 1] == 0 && graph[src - 1][des - 1] == 0)
            {
                cout << "Enter the weight of the graph:- ";
                cin >> weight;
                graph[src - 1][des - 1] = weight;
                graph[des - 1][src - 1] = weight;
            }
            else
            {
                cout << "\nEdge already exists. Please select a new edge" << endl;
                i--;
                continue;
            }
        }
        else
        {
            cout << "\nSource and destination cannot be the same\n";
            i--;
            continue;
        }
    }
    cout << "\n\nGraph created successfully" << endl;
}

void Graph::display()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << "\t" << graph[i][j];
        cout << endl;
    }
}

int Graph::findminvertex()
{
    int minvertex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
            minvertex = i;
    }
    return minvertex;
}

void Graph::dijkstras()
{
    for (int i = 0; i < V - 1; i++)
    {
        int minvertex = findminvertex();
        visited[minvertex] = 1;
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && graph[minvertex][j] != 0)
            {
                int dist = distance[minvertex] + graph[minvertex][j];
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }
    cout << "Vertex\t"
         << "Minimum Distance" << endl;
    for (int i = 0; i < V; i++)
        cout << i + 1 << "\t    " << distance[i] << endl;
}

int main()
{
    Graph g;
    int choice, edges, vertices;

    while (1)
    {

        cout << "\nImplementation of Dijkstra's algorithm" << endl;
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Find shortest path using Dijkstra's algorithm" << endl;
        cout << "4. Exit the program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number of vertices:- ";
            cin >> vertices;
            cout << "\nEnter the number of edges:- ";
            cin >> edges;
            g = Graph(vertices, edges);
            g.create();
            break;

        case 2:
            g.display();
            break;

        case 3:
            g.dijkstras();
            break;

        case 4:
            return 0;

        default:
            cout << "\nEnter valid choice" << endl;
        }
    }
    return 0;
}