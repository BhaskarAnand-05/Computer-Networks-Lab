#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int cost[MAX][MAX],dist[MAX],Prev[MAX];
bool selected[MAX];
void dijkstra(int source)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
        Prev[i]=-1;
        selected[i]=false;
    }
    dist[source]=0;
    for(int i=1;i<=n-1;i++)
    {
        int u=-1;
        for(int j=1;j<=n;j++)
            if(!selected[j]&&(u==-1||dist[j]<dist[u]))
                u=j;
        selected[u]=true;
        for(int v=1;v<=n;v++)
            if(cost[u][v])
                if(dist[u]+cost[u][v]<dist[v])
                {
                    dist[v]=dist[u]+cost[u][v];
                    Prev[v]=u;
                }
    }
}
int main()
{
    cout<<"Enter no of vertices\n";
    cin>>n;
    cout<<"Enter cost matrix\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>cost[i][j];
    int source;
    cout<<"Enter source vertex\n";
    cin>>source;
    dijkstra(source);
    cout<<"Shortest path:\n";
    for(int i=1;i<=n;i++)
        if(i!=source)
        {
            cout<<"Vertex "<<i<<": ";
            int j=i;
            while(Prev[j]!=-1)
            {
                cout<<j<<"<-";
                j=Prev[j];
            }
            cout<<source<<" Distance="<<dist[i]<<endl;
        }
}