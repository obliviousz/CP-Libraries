//WRITTEN FOR RANGE MINIMUM QUERY, CHANGE ACCORDING TO QUESTION

int seg[1000000];
void build(int a[],int x,int l,int r)
{
    if(l>r)
    {
        return;
    }
    else
    {
        if(l==r)
        {
            seg[x]=a[l-1];
        }
        else
        {
            int m=(l+r)/2;
            build(a,2*x,l,m);
            build(a,2*x+1,m+1,r);
            seg[x]=min(seg[2*x],seg[2*x+1]);
        }
    }
}
int query(int l,int r,int b,int e,int x)
{
    if(l>e||r<b||l>r)
    {
        return inf;
    }
    else
    {
        if(l<=b&&r>=e)
        {
            return seg[x];
        }
        else
        {
            int m=(b+e)/2;
            int ans1=query(l,min(r,m),b,m,2*x);
            int ans2=query(max(m+1,l),r,m+1,e,2*x+1);
            return min(ans1,ans2);
        }
    }
}
void update(int pos,int b,int e,int x,int val)
{
    if(b==e)
    {
        seg[x]=val;
    }
    else
    {
        int m=(b+e)/2;
        if(pos<=m)
        {
            update(pos,b,m,2*x,val);
        }
        else
        {
            update(pos,m+1,e,2*x+1,val);
        }
        seg[x]=min(seg[2*x],seg[2*x+1]);
    }
}




//LAZY PROPAGATION

int lazy[1000000];

void push(int x)
{
    seg[2*x]+=lazy[x];
    seg[2*x+1]+=lazy[x];
    lazy[2*x+1]+=lazy[x];
    lazy[2*x]+=lazy[x];
    lazy[x]=0;
}

void lazyupdate(int l,int r,int b,int e,int add,int x)
{
    if(l>r)
    {
        return;
    }
    else
    {
        if(l==b&&r==e)
        {
            seg[x]+=add;
            lazy[x]+=add;
        }
        else
        {
            push(x);
            int m=(b+e)/2;
            lazyupdate(l,min(m,r),b,m,add,2*x);
            lazyupdate(max(m+1,l),r,m+1,e,add,2*x+1);
            seg[x]=min(seg[2*x],seg[2*x+1]);
        }
    }
}    

int lazyquery(int b,int e,int l,int r,int x)
{
    if(l>r)
    {
        return inf;
    }
    else
    {
        if(l<=b&&r>=e)
        {
            return seg[x];
        }
        else
        {
            push(x);
            int m=(l+r)/2;
            int ans1=lazyquery(b,m,l,min(r,m),2*x);
            int ans2=lazyquery(m+1,e,max(l,m+1),r,2*x+1);
            return min(ans1,ans2);
         }
     }
}
