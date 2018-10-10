bool find(int x) {
    for(int i=1;i<=n;i++) {
        if(mat[x][i] && !v[i]) {
            v[i]=1;
            if(lnk[i]==0 || find(lnk[i])) {
                lnk[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

for(int i=1;i<=n;i++) {
    memset(v,0,sizeof(v));
    if(find(i)) ans++;
}

