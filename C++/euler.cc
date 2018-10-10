void search(int x) {
    for(int i=beg[x];i!=-1;i=next[i]) {
        if(v[i]) continue;
        v[i]=1;
        if(i%2) v[i+1]=1;
        else v[i-1]=1;
        search(edge[i]);
        route++;
        r[route]=x;
    }
}

