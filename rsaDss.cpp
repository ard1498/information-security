#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getinverse(ll r1,ll r2,ll t1,ll t2){
    ll r,t,q;
    while(r2 > 0){
        q = r1/r2;
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    return t1;
}

ll getmodmulti(ll message,ll d,ll n){
    ll ans = 1;
    while(d>0){
        if(d&1){
            ans = ((message*ans)%n + n)%n;
        }
        message = ((message*message)%n + n )%n;
        d = d>>1;
    }
    return ans;
}

int main(){
    //key generation
    ll p,q;
    cout<<"\nenter two large prime numbers:";
    cin>>p>>q;
    
    ll n = p*q;
    ll phi_n = (p-1)*(q-1);
    
    ll e1;
    cout<<"\nenter e1 such that gcd(e1,"<<phi_n<<")=1 :";
    cin>>e1;
    while(__gcd(e1,phi_n) != 1){
        cout<<"\nenter e1 again :";
        cin>>e1;
    }

    ll d = (getinverse(phi_n,e1,0,1)%phi_n + phi_n )%phi_n;

    //keys
    cout<<"\nprivate key is:"<<d;
    cout<<"\npublic keys :("<<e1<<","<<p<<","<<q<<")";

    ll m;
    cout<<"\nenter the message :";
    cin>>m;
    
    //signing
    ll s = getmodmulti(m,d,n);
    cout<<"\nsignature :"<<s<<" , message :"<<m;

    //verification
    ll rev_m = getmodmulti(s,e1,n);
    if(rev_m == m){
        cout<<"\n\nverified(rec_v message :"<<rev_m<<")";
    }
    else{
        cout<<"\n\nnot verified(rec_v message :"<<rev_m<<")";
    }
    return 0;
}