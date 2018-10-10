void search(int x,int fx)
{
    int t;
    int t2;

    dfsnum++;
    dfs[x]=low[x]=dfsnum;
    for(int i=1;i<=num[x];i++)
    {
        t=mat[x][i];
        if(t==fx) continue;
        if(dfs[t]==0)
        {
            search(t,x);
            if(low[t]<low[x]) low[x]=low[t];
            if(dfs[x]<low[t])
            {
                ans++;
                node[ans].a=x;
                node[ans].b=t;
                if(node[ans].a>node[ans].b)
                {
                    t2=node[ans].a;
                    node[ans].a=node[ans].b;
                    node[ans].b=t2;
                }
            }
        }
        else
        {
            if(low[x]>low[t]) low[x]=low[t];
        }
    }
}

