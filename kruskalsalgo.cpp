#include <algorithm>
#include <iostream>
using namespace std;

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int v, int e)
{ // Sort the input array in ascending order based on weights

    Edge *output = new Edge[v - 1];
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    sort(input, input + e, compare);

    int sum = 0;
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        Edge currentEdge = input[i];

        // Check if we can add the currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }

    cout << endl;
    for (int i = 0; i < v - 1; i++)
    {
        cout << output[i].source << "\t" << output[i].dest << "\t" << output[i].weight;
        sum += output[i].weight;
        cout << "\n";
    }
    cout << "Total weight:\t" << sum;
}

int main()
{

    int v, e; // V = No. of vertex in range [0 to v-1]    e = no. of edges
    cout << "Enter the no. of vertex" << endl;
    cin >> v;
    cout << "Enter the no. of edges" << endl;
    cin >> e;

    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cout << "\nEnter Source: ";
        cin >> s;
        cout << "\nDestination: ";
        cin >> d;
        cout << "\nWeight: ";
        cin >> w;

        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, v, e);
}