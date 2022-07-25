//#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define Fori(x) for(int i=0;i<(x);i++)
#define gcd(a,b)        __gcd(a,b)
#define pb(x)           push_back(x)
#define L               length()
#define mkp(x,y)        make_pair(x,y)
#define int             long long
#define bs              binary_search
#define mod             1e9+7
#define IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define allr(v)         v.rbegin(),v.rend1()
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define F               first
#define S               second
#define pii             pair<int,int>
#define vi              vector<int>
#define vs              size()
#define all(v)          v.begin(),v.end()  
#define endl            '\n'
#define atoi            stoi
#define elasped_time    1.0 * clock() / CLOCKS_PER_SEC
#define si              set <int>
#define vpii            vector < pair <int,int> >
#define memf(a)         memset(a,false,sizeof(a))
#define memt(a)         memset(a,true,sizeof(a))
#define xxx             998244353
#define pi              3.141592653589
#define ninf            INT_MIN
#define inf             1e18
#define sz(v)           ((int)(v).size())
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define FILL(a,x)       memset(a,x,sizeof(a))
int max(int a,int b){if(a>b){return a;}else{return b;}}
int min(int a,int b){if(a<b){return a;}else{return b;}}
int rand_int(int l, int r) { //[l, r]
    #ifdef LOCAL
    static mt19937_64 gen;
    #else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    #endif
    return uniform_int_distribution<int>(l, r)(gen);
}
int power(int b,int e)
{
    if(e==0)
    return 1;
    if(e%2)
    return ((b*power((b)*(b),(e-1)/2)));
    else
    return power((b)*(b),e/2);
}
int modpower(int b,int e,int q)
{
    int MOD=q;
    if(e==0)
    return 1;
    if(e%2)
    return ((b%MOD)*modpower((b%MOD)*(b%MOD),(e-1)/2,q))%MOD;
    else
    return modpower((b%MOD)*(b%MOD),e/2,q)%MOD;
}
void dpv(vi v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void dpv(vpii v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i].F<<" "<<v[i].S<<endl;
    }
}
void dpv(set <int> v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    
    cout<<endl;
}
int ceil1(int x,int y)
{
    int r=x/y;
    if(x%y==0)
    {
        return r;
    }
    else
    {
        return r+1;
    }
}
////*SOLUTION TO THE QUESTION STARTS HERE*//////
//const int N=2e5+5;
vector<int> manacher(string s){
    string s1='^' + s + '$';
    int n=s1.size();
    vector<int> p(n);
    for(int i=1,l=0,r=1;i<n-1;i++){
        p[i]=max(0ll,min(r-i,p[l+r-i]));
        while(i+p[i]<n and s1[i-p[i]]==s1[i+p[i]]){
            p[i]++;
        }
        if(i+p[i] > r){
            r=i+p[i];
            l=i-p[i];
        }
    }
    return vector<int> (p.begin() + 1, p.end()-1);
}
vector<int> kmp(string s){
    int n=s.size();
    vector<int> lps(n);
    int i=0,j=1;
    while(j<n){
        if(s[i]==s[j]){
            lps[j]=i+1;
            j++;
            i++;
        }else{
            if(i){
                i=lps[i-1];
            }else{
                j++;
            }
        }
    }
    return lps;
}
vector<int> Zfunction(string s){
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}
void oblivious(){
    string s;
    cin>>s;
    int n=s.size();
    string s1;
    s1.push_back('#');
    for(int i=0;i<n;i++){
        s1.push_back(s[i]);
        s1.push_back('#');
    }
    vector<int> d=manacher(s1);
    dpv(d);
    vector<int> d1(n),d2(n);
    for(int i=0;i<n;i++){
        d1[i]=(d[2*i+1])/2; // odd length in b/w i-1 and i.
        d2[i]=(d[2*i]-1)/2; //even length with center in b/w i-1 and i.
    }
    dpv(d1);
    dpv(d2);
    vector<int> k=kmp(s);
    dpv(k);
    dpv(Zfunction(s));
}   
signed main()
{
    IOS;
    //FILL(dp,0);
    //Try this case
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int t=1;
    //cin>>t;
    //int z=t;
    while(t--)
    {
        //cout<<"Case #"<<(z-t)<<": ";
        oblivious();
    }
    return 0;
}
//Editorial
/*
//*/
