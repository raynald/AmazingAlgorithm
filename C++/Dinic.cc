#define min(x,y) ((x<y)?(x):(y))

bool BFS()
{
    memset(dis,-1,sizeof(dis));
    dis[0]=0;
    now=0;z=1;
    q[1]=0;
    while (now<z)
    {
        now ++;
        for (int i=0;i<=n;i++)
            if (dis[i]<0 && mat[q[now]][i]>0)
            {
                dis[i]=dis[q[now]]+1; 
                z++;
                q[z]=i;
            }
    }
    if (dis[n]>0) return 1; else return 0;
}

int find(int x, int low)
{
    int a;

    if (x==n)return low; 
    for (int i=0;i<=n;i++)
    {
        if (mat[x][i] >0 && dis[i]==dis[x]+1)
        {
            a=find(i,min(low,mat[x][i])); 
            if(a>0)
            {
                mat[x][i]-=a;
                mat[i][x]+=a;
                return a;
            }
        }
    }
    return 0;
}

int main()
{
    memset(mat,0,sizeof(mat));
    init();
    ans=0;
    while (BFS())
    {
        while(1)
        {
            sum = find(0,1000000000);
            if (sum == 0) break;
            ans+=sum;
        }
    }
    if(ans>=s) puts("yes"); else puts("no");

    return 0;
}

