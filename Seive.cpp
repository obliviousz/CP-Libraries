const int M=10000000;
int spf[M+1];
void seive()
{
    FILL(spf,0);
    spf[1]=1;
    for(int i=2;i<=M;i+=2)
    {
        spf[i]=2;
    }
    for(int i=3;i<=M;i+=2)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            for(int j=i*i;j<=M;j+=i)
            {
                if(spf[j]==0)
                    spf[j]=i;
            }
        }
    }
}
