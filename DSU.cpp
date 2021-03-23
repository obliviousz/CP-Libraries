int parent[1000000];
void create(int a)
{
    if(parent[a]!=-1)
    {
        parent[a]=a;
    }
}
int find_parent(int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    else
    {
        return parent[x]=find_parent(parent[x]);
    }
}
void merge(int a,int b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b)
    {
        parent[b]=a;
    }
}
