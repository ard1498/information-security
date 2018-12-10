#include<bits/stdc++.h>
using namespace std;

long getinverse(long r1,long r2,long t1,long t2){
    long q,r,t;
    while(r2>0){
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

struct point{
    long x;
    long y;

    void print(){
        cout<<"("<<x<<","<<y<<")";
    }
};

bool isequal(point p1,point p2){
    if(p1.x == p2.x && p1.y == p2.y){
        return true;
    }
    return false;
}

point addpoints(point e1,point e2,long p,long a){
    point e3;
    long lambda;
    if(isequal(e1,e2)){
        long x2_3_a = (((3*e1.x*e1.x + a)%p) + p) % p;
        long e1_y_2 = ((2*e1.y)%p + p) % p;
        long y2__1 = getinverse(p,2*e1.y,0,1);
        lambda = (((x2_3_a*y2__1)%p) + p) % p;
        long lambda_2 = (((lambda*lambda)%p) + p) % p;
        e3.x = ((lambda_2 - (2*e1.x)) + p) % p;
        e3.y = ((((lambda*(e1.x - e3.x)) - e1.y) % p)+p)%p;
    }
    else{
        long e1_e2_x = (((e1.x-e2.x)%p) + p) %p;
        long x1_x2_1 = getinverse(p,e1_e2_x,0,1);
        lambda = ((((e1.y - e2.y)*(x1_x2_1)) %p)+p) % p;
        long lambda_2 = ((lambda*lambda)%p + p) % p;
        e3.x = (((lambda_2 - e1.x - e2.x) % p)+p)%p;
        e3.y = ((lambda*(e1.x - e3.x) - e1.y)%p + p) % p;
    }
    return e3;    
}

point getpoints(point e1,long d,long p,long a){
    point e2 = e1;
    for(int i = 0;i < d-1;i++){
        e2 = addpoints(e2,e1,p,a);
    }
    return e2;
}

vector<point> encryption(point e1,point e2,point P,long p,long a,long r){
    vector<point> ciphers(2);
    ciphers[0] = getpoints(e1,r,p,a);
    ciphers[1] = getpoints(e2,r,p,a);
    ciphers[1] = addpoints(ciphers[1],P,p,a);
    return ciphers;
}

point decryption(vector<point> ciphers,long d,long p,long a){
    point c1d = getpoints(ciphers[0],d,p,a);
    point c1_d;
    c1_d.x = c1d.x;
    c1_d.y = (-c1d.y + p)%p;
    point plain = addpoints(ciphers[1],c1_d,p,a);
    return plain;
}

int main(){
    long p;
    cout<<"\nselect the field value p (GF(p)):";
    cin>>p;
    long a,b;
    cout<<"\nenter the value of a and b:";
    cin>>a>>b;
    point e1;
    cout<<"\nchoose a point e1(x1,y1) :";
    cin>>e1.x>>e1.y;
    long d;
    cout<<"\nenter an integer d (from zp*):";
    cin>>d;
    point e2 = getpoints(e1,d,p,a);
    
    cout<<"\npublic key : (";
    e1.print();
    cout<<",";
    e2.print();
    cout<<",E("<<a<<","<<b<<"))";
    cout<<"\nprivate key is :"<<d;

    //encryption
    long r;
    cout<<"\nenter any random number r:";
    cin>>r;
    point P;
    cout<<"\nenter the plain point(x,y):";
    cin>>P.x>>P.y;
    vector<point> ciphers = encryption(e1,e2,P,p,a,r);
    cout<<"\nciphers are : ";
    ciphers[0].print();
    cout<<",";
    ciphers[1].print();

    //decryption
    cout<<"\ndecrypted data is :";
    point dplain  = decryption(ciphers,d,p,a);
    cout<<"\n";
    dplain.print();
    return 0;
}