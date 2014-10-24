#define MAXSIZE 400005
int extend[MAXSIZE], next[MAXSIZE];

void get_next(char *t, int n)
{
    int a, p, k, i;

    next[0]    = 0;
    a = 0;
    p = 1;
    for (k = 1; k < n; k++)
    {
        if (k == p)    
        {
            i = k;
            while (t[i] == t[i - k])
                i++;
            next[k] = i - k;
            if (i == p)
                p++;
            else
                p = i;
            a = k;
        }
        else if (k + next[k - a] <= p)
            next[k] = next[k - a];
        else
        {
            next[k] = p - k;
            i = p;
            while (t[i] == t[i - k])
            {
                i++;
                next[k]++;
            }
            if (i > p)
            {
                p = i;
                a = k;
            }
        }
    }
}

void get_extend(char *s, int sn, char *t, int tn)
{
    int a, p, k, i;

    p = a = 0;
    for (k = 0; k < sn; k++)
    {
        if (k == p)    
        {
            i = k;
            while (i - k < tn && s[i] == t[i - k])
                i++;
            extend[k] = i - k;
            if (i == p)
                p++;
            else
                p = i;
            a = k;
        }
        else if (k + next[k - a] <= p)
            extend[k] = next[k - a];
        else
        {
            extend[k] = p - k;
            i = p;
            while (i - k < tn && s[i] == t[i - k])
            {
                i++;
                extend[k]++;
            }
            if (i > p)
            {
                p = i;
                a = k;
            }
        }
    }
}
