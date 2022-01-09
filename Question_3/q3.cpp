#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define ll          long long 
#define ull         unsigned long long 
#define ld          long double
#define mp          map<ll,ll> 
#define mpc         map<char,ll>
#define mps         map<string,ll>
#define pb          push_back
#define pll         pair<ll,ll> 
#define vll         vector<ll>
#define vpll        vector<pair<ll,ll>>
#define prq         priority_queue<ll>// max priority heap
#define prqs        priority_queue<ll,vector<ll>,greater<ll>>  //min priority heap
#define m_p         make_pair
#define ff          first
#define ss          second
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define l(i,s,e)  for(int i=s;i<e;i++)
#define Test        ll t;cin>>t;while(t--)
#define all(v)      v.begin(),v.end()
#define mem(a,x)    memset(a,x,sizeof(a))
const ll mod =1e9+7;
const ull INF=1e9+1;
const ll  MOD =  998244353;
const ll  N   =  2e5+7;

bool isPrime(ll n){
    if(n==1)
    return 0;
    
    if(n==2||n==3)
    return 1;
    
    for(ll i=2;i*i<=n;i++)
     if(n%i==0)
     return 0;
     
 return 1;
}
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%(mod);
       base=(base*base)%(mod);
       exp/=2;
    }
    return res;
}


bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second > b.second);
}
  

ll modinv(ll n){
    return fast_exp(n,mod-2);
}

bool cmp1(ll x,ll y){
    return (x%2<y%2);
} 
 
 
 void dfs(ll node,vll arr[],ll vis[]){

    if(!vis[node])
        vis[node]=1;

    if(arr[node].size()>0){
        for(auto child:arr[node]){
            if(!vis[child]){
                dfs(child,arr,vis);
            }
        }
    }

 }
 

 bool cmp( pair<ll,ll> &a, pair<ll,ll> &b){

    if(a.ff==b.ff)
        return a.ss>b.ss;
    else
       return a.ff<b.ff;
 }

bool isKthBitSet(ll n, ll k)
{
    if (n & (1 << (k - 1)))
        return true;
    else
       return false;
}

int maxMoney(int money[],int n1)
{
    if(n1 == 0) 
        return 0; 
    if(n1 == 1) 
        return money[0]; 
    if(n1 == 2) 
        return max(money[0], money[1]); 
    int DP[n1]; 
    DP[0] = money[0]; 
    DP[1] = max(money[0], money[1]); 

    for (int i = 2; i<n1; i++) 
        DP[i] = max(money[i]+DP[i-2], DP[i-1]); 
  
    return DP[n1-1]; 
}

int32_t main(){
int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  
  cout<<maxMoney(a,n);
  return 0;
}
