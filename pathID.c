#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef enum { false, true } bool;
// define num of nodes
int Nodes = 6;

// declare some functions
void traversalPath(int parent[], int i, char* p);
int path(int cost[10][10], int s, int d, char* p);
void dijkstra(int cost[10][10], int src, int des, char* p);
int minDistance(int dist[10], bool traversal[10]);

// implicit
int path(int cost[10][10], int s, int d, char* p)
{
   char start = s + '0';
   strcat(p, &start);
   dijkstra(cost, s, d, p);
   
   return 0;  
}

int minDistance(int dist[10], bool traversal[10])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < Nodes; v++) {
      if (traversal[v] == false && dist[v] <= min) {
         min = dist[v], min_index = v;
      }
   }
   return min_index;
}

void dijkstra(int cost[10][10], int src, int des, char* p)
{
   int dist[10]; 
   bool traversal[10];
   int parent[10];
   for (int i = 0; i < Nodes; i++) {
      parent[i] = -1;
      dist[i] = INT_MAX;
      traversal[i] = false;
   }
   dist[src] = 0;

   for (int i = 0; i < Nodes - 1; i++) {
      int u = minDistance(dist, traversal);
      traversal[u] = true;
      
      for (int j = 0; j < Nodes; j++) {
         if (!traversal[j] && cost[u][j] != 1000 && dist[u] + cost[u][j] < dist[j]) {
            parent[j] = u;
            dist[j] = dist[u] + cost[u][j];
         } 
      }
   }
   for (int i = 0; i < Nodes; i++)
   {
      /* code */
   }
   
   traversalPath(parent, des, p);
}

void traversalPath(int parent[], int i, char* p)
{
   if (parent[i] == - 1)
      return;
   traversalPath(parent, parent[i], p);
   strcat(p, ", ");
   char c = '0' + i;
   strcat(p,&c);
   
}


int main()
{
   
    int cost[10][10];
    int n,i,j,s,d;
    char p[100];
 
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        { 
           cost[i][j] = 1000;
        }  
    }

    for(int i =0;i<100;i++) {
       p[i] = 0;
    }

    cost[0][1]=1;
    cost[0][3]=4;
    cost[1][0]=1;
    cost[1][2]=3;
    cost[1][4]=1;
    cost[2][1]=3;
    cost[2][4]=1;
    cost[2][5]=2;
    cost[3][0]=4;
    cost[3][4]=1;
    cost[4][1]=1;
    cost[4][2]=1;
    cost[4][3]=1;
    cost[4][5]=4;
    cost[5][2]=2;
    cost[5][4]=4; 
    
    printf("Source: ");
    scanf("%d",&s);
    printf("Destination: ");
    scanf("%d",&d);
    path(cost,s,d,&p[0]);
    printf("The shortest path: %s\n",p);

   // test code 
  
    return 0;
      
}
