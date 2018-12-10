#include<bits/stdc++.h>
using namespace std;

string encryption(string plaintext,int rails){
    int l = plaintext.size();
    string ciphertext = "";

    for(int j = 0;j < rails;j++){
        for(int i =j;i < l ;i+=(2*rails -2-j)){
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

int main(){
    string plaintext,ciphertext;
    cout<<"enter the plaintext : ";
    cin>>plaintext;
    ciphertext = encryption(plaintext,5);
    cout<<endl<<"encrypted text is :"<<ciphertext;
    cout<<endl<<"decryption ......";
    //cout<<endl<<decryption(ciphertext);
    return 0;
}