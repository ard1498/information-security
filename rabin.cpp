#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getinverse(ll r1,ll r2,ll t1,long t2){
    ll q,r,t;
    while(r2 > 0){
        q = r1/r2;
        r = (r1-q*r2);
        r1 = r2;
        r2 = r;
        t = (t1 - q*t2);
        t1 = t2;
        t2 = t;
    }
    return t1;
}

ll encryption(ll p,ll n){
    ll cipher;
    cipher = (p*p + n)% n;
    return cipher;
}

ll getmodmulti(ll p,ll p1,ll cipher){
    ll a = 1;
    while(p1){
        if(p1&1){
            a = (a*cipher + p) % p;
        }
        cipher = (cipher*cipher + p) % p;
        p1=p1>>1;
    }
    return a;
}

void decryption(ll cipher,ll p,ll q){
    ll p1 = ((p+1)/4), q1 = ((q+1)/4);
    
    ll a1 = getmodmulti(p,p1,cipher);
    ll a2 = (-a1 + p);
    ll b1 = getmodmulti(q,q1,cipher);
    ll b2 = (-b1 + q);

    ll n = p*q;
    ll p_1 = getinverse(q,p,0,1);
    ll q_1 = getinverse(p,q,0,1);

    ll P1 = ((a1*q*q_1 + b1*p*p_1)+n) % n;
    ll P2 = ((a1*q*q_1 + b2*p*p_1)+n) % n;
    ll P3 = ((a2*q*q_1 + b1*p*p_1)+n) % n;
    ll P4 = ((a2*q*q_1 + b2*p*p_1)+n) % n;

    cout<<"\nP1 :"<<P1<<"\nP2 :"<<P2<<"\nP3 :"<<P3<<"\nP4 :"<<P4;
    return;
}

int main(){
    ll p,q;
    cout<<"\nenter the two large prime numbers (of form 4k+3) :";
    cin>>p>>q;
    ll n = p*q,plain;
    cout<<"\nenter the plaintext :";
    cin>>plain;
    ll cipher = encryption(plain,n);
    cout<<"\ncipher is : "<<cipher;
    cout<<"\ndecrypted num is :";
    decryption(cipher,p,q);
    return 0;
}