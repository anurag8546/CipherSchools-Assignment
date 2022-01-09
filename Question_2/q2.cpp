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

int32_t main(){
  int n;
  cin>>n;
  int a[n],target;
  l(i,0,n){
  cin>>a[i];
  }
  cin>>target;
  sort(a,a+n);
  int ans=a[0]+a[1]+a[2];
  int tem,last,mn=INT_MAX,ans2,as;
  l(i,0,n-1){
     l(j,i+1,n){
         ans=a[i]+a[j];
        int tem=a[i];int temp=a[j];
         a[i]=INT_MIN;
         a[j]=INT_MIN;
         ans2=l_b(a,a+n,target-ans)-a;
         if(abs(target-(ans+a[ans2]))<mn){
             as=ans+a[ans2];
          //   cout<<as<<endl;
         }
         mn=min(abs(target-(ans+a[ans2])),mn);
         
         a[i]=tem;
         a[j]=temp;
         
     }
     
}
cout<<as<<endl;
}
