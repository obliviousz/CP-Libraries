vector <vi> v(200005);
vi dad;
vi intime;
vi outtime;
vi depth;
vector <bool> vis;
int timer=0;
void treemoves(int n)
{
    dad.assign(n+1,1);
    intime.assign(n+1,0);
    outtime.assign(n+1,0);
    depth.assign(n+1,0);
    vis.assign(n+1,false);
}
void dfs_calc(int root)
{
    vis[root]=true;
    intime[root]=timer++;
    for(auto i:v[root])
    {
        if(!vis[i])
        {
            depth[i]=depth[root]+1;
            dad[i]=root;
            dfs_calc(i);
        }
    }
    outtime[root]=timer++;
}
