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
        t = t1- q*t2;
        t1 = t2;
        t2 = t;
    }
    return t1;
}

ll encryption(ll plaintext,ll e,ll p,ll q){
    ll n = p*q;
    ll cipher = 1;

    //APPLYING MOD EXPONENTIATION P^(10) = p^(BIN(1010)) = P^(2^0*0 + 2^1*1 + 2^2*1 + 2^3*1) = P^(2^0*0)*P^(2^1*1)*P(2^2*1)*P(2^2*1)
    while(e > 0){
        if(e&1){            //checking if leftmost bit is 1 then multiply to the answer
            cipher=((cipher*plaintext)+n)%n;            
        }
        plaintext = ((plaintext*plaintext)+n)%n;
        e = e>>1;
    }
    return cipher;
}

ll decryption(ll ciphertext,ll d,ll n){
    ll p = 1;
    while(d > 0){
        if(d&1){
            p = ((p*ciphertext)+n)%n;
        }
        ciphertext = ((ciphertext*ciphertext)+n)%n;
        d = d>>1;
    }
    return p;
}

int main(){
    //key generation!
    ll p,q;
    cout<<"\nenter the two large prime numbers (p and q):";
    cin>>p>>q;
    ll n = p*q;
    ll phi_n = (p-1)*(q-1);
    ll e;
    cout<<"\nEuler Totient is :"<<phi_n;
    cout<<"\nenter the e such that gcd(e,phi_n)=1 and e<phi_n:";
    cin>>e;
    while(__gcd(e,phi_n) != 1 || e>phi_n || e<=1){
        cout<<"\nenter e again :";
        cin>>e;
    }
    ll d = getinverse(phi_n,e,0,1);
    cout<<"\npublic key is : (e,p,q) = ("<<e<<","<<p<<","<<q<<")";
    cout<<"\nprivate key is :(d) = ("<<d<<")";

    //encryption using public key and decryptioin usig private key

    //encryption----
    ll plaintext;
    cout<<"\nenter the plaintext:";
    cin>>plaintext;
    ll ciphertext = encryption(plaintext,e,p,q);
    cout<<"\nciphertest is :"<<ciphertext;
    cout<<"\ndecrypted text :"<<decryption(ciphertext,d,n);
    return 0;
}