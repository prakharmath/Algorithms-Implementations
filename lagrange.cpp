#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*Contains the implementation of lagrange interpolation in a modular prime field*/
const int mod=1000003;
int inverse[mod];
int add(int a,int b)
{
      a=(a%mod+b%mod)%mod;
      a+=mod;
      a%=mod;
      return a;
}
int multiply(int a,int b)
{
     return ((a%mod)*(b%mod))%mod;
}
int normalise(int a)
{
     if(a<0)
      a+=mod;
     return a;
}
void precompute()
{ 
    inverse[0]=inverse[1]=1; 
    for (int i = 2; i <mod; i++)  
        inverse[i]=inverse[mod%i]*(mod-mod/i)%mod;     
} 
int lagrangeInterpolation(vector<int> &y, int x)
{
    int ans = 0, current = 1; 
    for(int i=1;i<=10 ;++i)
    {
        current = multiply(current, normalise(x - i)); 
        current = multiply(current, inverse[normalise(-i)]); 
    }
    ans = add(ans, multiply(current, y[0])); 
    for(int i=1;i<=10;++i)
    {
        current = multiply(current, normalise(x - (i - 1))); 
        current = multiply(current, inverse[normalise(x - i)]); 
        current = multiply(current, normalise(i - 11)); 
        current = multiply(current, inverse[i]); 
        ans = add(ans, multiply(current, y[i])); 
    }
    return ans; 
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    precompute();
    vector<int>y(11);
    y[0]=0;
    for(int i=0;i<=10;i++)
    {
        cout<<"? "<<i<<endl;
        cout.flush();
        cin>>y[i];
        if(y[i]==-1)
          exit(0);
        if(y[i]==0)
        {
            cout<<"! "<<i<<endl;
            return 0;
        }
    }
    for(int i=11;i<=mod;i++)
    {
         if(lagrangeInterpolation(y,i)==0)
         {
             cout<<"! "<<i<<endl;
             return 0;
         }
    }
    cout<<"! "<<-1<<endl;
    return 0;
}
