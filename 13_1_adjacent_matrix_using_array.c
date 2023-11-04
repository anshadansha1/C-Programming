// PROGRAM 13_1 : Demonstrate the data structure of adjacent matrix  using arrays.
#include <stdio.h>
#include <conio.h>
#define max 20
int adj[max][max];
int n;
void create_graph();
void display();
int main()
{
    create_graph();
    display();
    return 0;
}
void create_graph()
{
    int i, max_edges, origin, destin;
    printf("\nEnter number of Vertices(nodes) : ");
    scanf("%d", &n);
    printf("\n[NOTE: Enter 0 0 to quit]");
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        printf("\nEnter edge %d  : \n", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge!.Enter valid edge.\n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}
void display()
{
    int i, j;
    printf("\n---- Adjacency matrix----\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

