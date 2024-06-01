struct DSU{
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n, 0);
        size.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(size[x] > size[y]){
            swap(x,y);
        }
        parent[x]=y;
        size[y]+=size[x];
    }
};
