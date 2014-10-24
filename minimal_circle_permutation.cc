int MCP() {
    int i = 0, j = 1, count = 0, t,len=n;
    while (i < len && j < len && count < len){      
        tt++;        
        int x = i + count;        
        int y = j + count;        
        if (x >= len) x -= len;        
        if (y >= len) y -= len;
        if (s[x] == s[y])
            count++;
        else{
            if (s[x] > s[y])
                i = i + count + 1;
            else
                j = j + count + 1;
            count = 0;
        }
        if(j==i)
            j=i+1;
    }
    return i;                  
}

