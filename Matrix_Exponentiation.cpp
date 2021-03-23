int n;
int md=mod;
void addself(int &x,int b)
{
    x+=b;
    if(x>=md)
        x%=md;
}
int mulself(int x,int y)
{
    x=x%md;
    x*=y;
    if(x>=md)
    {
        x%=md;
    }
    return x;
}
class matrix
{
    
    public:
    vector <vector<int>> t;
    matrix()//default constructor
    {
        t.resize(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                t[i][j]=0;
            }
        }
    }
    /*
    binary * operator will require one more arg, since it is a binary operator
    one arg is the object itself that will call it, other will be passed as arg(in this case x). also this will return a matrix object
    */
    matrix operator*(matrix x)// overloading * for multiplication
    {
        matrix c;// this will hold our result
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                c.t[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    addself(c.t[i][j],mulself(t[i][k],x.t[k][j]));        
                }
            }
        }
        return(c);
        
    }
};
matrix identity;
void Identity()
{
    identity=matrix();
    for(int i=0;i<n;i++)
    {
        identity.t[i][i]=1;
    }
}
matrix power(matrix m,int k)
{
  if(k==0)
  {
     return identity;
  }
  else
  {
      if(k%2==0)
      {
         return power(m*m,k/2);
      }
      else
      {
         return m*power(m*m,(k-1)/2);
      }
  }
}



//ANOTHER BETTER TEMPLATE

const int MOD=1e9+7;
struct Matrix
{
    vector< vector<int> > mat;
    int n_rows, n_cols;
 
    Matrix() {}
 
    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}
 
    static Matrix identity_matrix(int n)
    {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }
 
    Matrix operator*(const Matrix &other) const 
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    tmp%=MOD;
                }
                result[i][j] = tmp % MOD;
            }
 
        return move(Matrix(move(result)));
    }
 
    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
    
    void print(){
        for(auto &x:mat){
            for(int y:x){
                cout << y << " ";
            }
            cout << "\n";
        }
    }
};
Matrix pw(Matrix a,int p){
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}
