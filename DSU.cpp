int mom[N],sze[N];
int parent(int x)
{
    if(mom[x]==x)
        return x;
    return mom[x]=parent(mom[x]);
}
void make(int x)
{
    mom[x]=x;
    sze[x]=1;
}
void join(int x,int y)
{
    int a=parent(x),b=parent(y);
    if(a!=b)
    {
        if(sze[a]>sze[b])
            swap(a,b);
        mom[b]=a;
        sze[a]+=sze[b];
    }
}
