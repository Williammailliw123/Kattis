#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+9;
int head[N],ver[N],edge[N],nex[N];
ll d[10][N];
int n,m,tol,idx;
bool vis[N];
void add(int x,int y,int z)
{
    ver[++idx]=y,nex[idx]=head[x],edge[idx]=z,head[x]=idx;
}
void spfa(int pos)  //spfa模板
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    q.push(pos);
    vis[pos]=1;
    d[tol][pos]=0;  //tol是第几?最短路
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x]; i>=0; i=nex[i])
        {
            int y=ver[i],z=edge[i];
            if(d[tol][y]>d[tol][x]+z)
            {
                d[tol][y]=d[tol][x]+z;
                if(!vis[y])q.push(y),vis[y]=1;
            }
        }
    }
    tol++;  //tol++
}
int main()
{
    memset(head,-1,sizeof head);
    memset(d,0x3f,sizeof d);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)  //建?
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        add(a,b,t),add(b,a,t);
    }
    spfa(1);   //求1?起?的最短路
    int temp[10];
    int pai[]= {1,2,3,4,5,6,7}; //代表第几?最短路，然后枚??几?最短路的排列方式
    for(int i=1; i<=7; i++) 
    {
        scanf("%d",&temp[i]);
        spfa(temp[i]);  //求以它?起?的最短路
    }
    ll minn=inf;
    do   //枚??7??的排列方式,即走法
    {
        ll s=d[0][temp[pai[0]]];     //第0?最短路(即以1?起?)
        s+=d[pai[0]][temp[pai[1]]];  //d的第一?存的是第几?最短路，就是pai的值
        s+=d[pai[1]][temp[pai[2]]];  //然后以???起?找它的下一??
        s+=d[pai[2]][temp[pai[3]]];
        s+=d[pai[3]][temp[pai[4]]];
        s+=d[pai[4]][temp[pai[5]]];
        s+=d[pai[5]][temp[pai[6]]];
        minn=min(s,minn);  //求最小
    }
    while(next_permutation(pai,pai+7));//全排列函?
    if(minn<inf)printf("%lld\n",minn);
    else printf("-1\n");
    return 0;
}


