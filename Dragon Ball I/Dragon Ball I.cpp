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
void spfa(int pos)  //spfa�ҪO
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    q.push(pos);
    vis[pos]=1;
    d[tol][pos]=0;  //tol�O�ĤL?�̵u��
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
    for(int i=0; i<m; i++)  //��?
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        add(a,b,t),add(b,a,t);
    }
    spfa(1);   //�D1?�_?���̵u��
    int temp[10];
    int pai[]= {1,2,3,4,5,6,7}; //�N��ĤL?�̵u���A�M�Z�T??�L?�̵u�����ƦC�覡
    for(int i=1; i<=7; i++) 
    {
        scanf("%d",&temp[i]);
        spfa(temp[i]);  //�D�H��?�_?���̵u��
    }
    ll minn=inf;
    do   //�T??7??���ƦC�覡,�Y���k
    {
        ll s=d[0][temp[pai[0]]];     //��0?�̵u��(�Y�H1?�_?)
        s+=d[pai[0]][temp[pai[1]]];  //d���Ĥ@?�s���O�ĤL?�̵u���A�N�Opai����
        s+=d[pai[1]][temp[pai[2]]];  //�M�Z�H???�_?�䥦���U�@??
        s+=d[pai[2]][temp[pai[3]]];
        s+=d[pai[3]][temp[pai[4]]];
        s+=d[pai[4]][temp[pai[5]]];
        s+=d[pai[5]][temp[pai[6]]];
        minn=min(s,minn);  //�D�̤p
    }
    while(next_permutation(pai,pai+7));//���ƦC��?
    if(minn<inf)printf("%lld\n",minn);
    else printf("-1\n");
    return 0;
}


