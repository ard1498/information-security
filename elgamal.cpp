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

ll modpow(ll e1,ll d,ll p){
    ll e2 = 1;
    while(d){
        if(d&1){
            e2 = (e1*e2 + p) % p;
        }
        e1 = (e1*e1 + p) % p;
        d = d>>1;
    }
    return e2;
}

vector<ll> encryption(ll plain,ll e1,ll e2,ll p){
    vector<ll> ciphers(2);
    ll r;
    cout<<"\nenter a random number r :";
    cin>>r;
    
    ciphers[0] = modpow(e1,r,p);
    ciphers[1] = modpow(e2,r,p);
    ciphers[1] = (ciphers[1]*plain + p) % p;
    
    return ciphers;
}

ll decryption(ll c1,ll c2,ll p,ll d){
    ll plain = modpow(c1,p-1-d,p);
    plain = (c2*plain + p) % p;
    return plain;
}

int main(){
    
    //key generation
    ll p,e1,d;
    cout<<"\nenter a very large prime number :";
    cin>>p;
    cout<<"\nenter a e (is a primitive root) :";
    cin>>e1;
    cout<<"\nenter a number d(less than p-1) :";
    cin>>d;
    ll e2 = modpow(e1,d,p);
    cout<<"\nyour public key is : "<<e1<<","<<e2<<","<<p;
    cout<<"\nyour private key is : "<<d;

    //encryption
    ll plaintext;
    cout<<"\nenter the plaintext :";
    cin>>plaintext;
    vector<ll> ciphers = encryption(plaintext,e1,e2,p);
    cout<<"\nciphers are : "<<ciphers[0]<<","<<ciphers[1];

    //decryption
    cout<<"\ndecrypted text is :"<<decryption(ciphers[0],ciphers[1],p,d);
    return 0;
}