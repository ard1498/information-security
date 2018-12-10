#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getinverse(ll r1,ll r2,ll t1,ll t2){
    ll q,r,t;
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

ll getmodmulti(ll e1,ll d,ll n){
    ll e2 = 1;
    while(d > 0){
        if(d&1){
            e2 = ((e2*e1)%n + n) % n;
        }
        e1 = ((e1*e1)%n + n) % n;
        d = d>>1;
    }
    return e2;
}

int main(){
    
    //key generation
    ll p,q,e0,d;
    cout<<"\nenter a prime number p (512 <= len <= 1024 bits , num_of_bits(p) mod 64 = 0): ";
    cin>>p;
    cout<<"\nenter a prime number q (len = 160 bits and (p-1)mod q = 0 ):";
    cin>>q;
    cout<<"\nselect e0 (a generator in Zp*):";
    cin>>e0;
    ll p_1_q = ((p-1)/q);
    ll e1 = getmodmulti(e0,p_1_q,p);
    cout<<"\nchoose an integer d :";
    cin>>d;
    ll e2 = getmodmulti(e1,d,p);
    cout<<"\npublic key :(e1,e2,p,q) - ("<<e1<<","<<e2<<","<<p<<","<<q<<")";
    cout<<"\nprivate key : (d) - ("<<d<<")";

    //signing
    ll r,h_m;
    cout<<"\nenter h(m):";
    cin>>h_m;
    cout<<"\nchoose an integer r :";
    cin>>r;

    ll s1 = (getmodmulti(e1,r,p)%q + q) % q;
    ll r_1 = (getinverse(q,r,0,1)%q + q) % q;
    ll s2 = (((h_m + d*s1)*r_1)%q + q)%q;

    cout<<"\n signatures : "<<s1<<","<<s2;
    cout<<"\n h(m) : "<<h_m;

    //verification
    if(s1 > 0 && s1 < q){
        if(s2 > 0 && s2 < q){
            ll s2_1 = (getinverse(q,s2,0,1)%q + q) % q;
            ll V = ((getmodmulti(e1,(h_m*s2_1),p)*getmodmulti(e2,s1*s2_1,p))%p + p)%p;
            V = (V%q + q ) % q;
            if( (V%s1 == 0) || (s1%V == 0)){
                cout<<"\nverified.";
                cout<<"\ns1 :"<<s1<<", V :"<<V;
                return 0;
            } 
        }
    }
    cout<<"\nnot verified.";
    return 0;
}