#include<bits/stdc++.h>
using namespace std;

int inverse(int key){
    int r2 = key;
    int r1 = 26;
    int t1 = 0;
    int t2 = 1;
    int q,r,t;
    while(r2 > 0){
        q = r1/r2;
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    while(t1 < 0){
        t1 += 26;
    }
    return t1;
}

string encryption(string plaintext,int key){
    string ciphertext = "";
    for(int i = 0;i < plaintext.size();i++){
        if(isupper(plaintext[i]))
            ciphertext += char((int(plaintext[i]-65)*key)%26 + 65);
        else
            ciphertext += char((int(plaintext[i]-97)*key)%26 + 97);
    }
    return ciphertext;
}

string decryption(string ciphertext,int keyinv){
    string plaintext = "";
    for(int i = 0;i < ciphertext.size();i++){
        if(isupper(ciphertext[i])){
            plaintext += char(((int(ciphertext[i] - 65)*keyinv)%26 + 26)%26 + 65);
        }
        else{
            plaintext += char(((int(ciphertext[i] - 97)*keyinv)%26 + 26)%26 + 97);
        }
    }
    return plaintext;
}

int main(){
    string plaintext,ciphertext;
    int key;
    cout<<endl<<"enter the plaintext :";
    cin>>plaintext;
    cout<<endl<<"enter the key:";
    cin>>key;

    ciphertext = encryption(plaintext,key);

    cout<<ciphertext;
    int keyinv = inverse(key);
    cout<<endl<<"decryption algos...........";
    cout<<endl<<decryption(ciphertext,keyinv);
    return 0;
}