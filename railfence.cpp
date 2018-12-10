#include<bits/stdc++.h>
using namespace std;

string encryption(string plaintext){
    int l = plaintext.size();
    string ciphertext = "";

    for(int i =0;i < l ;i+=2){
        ciphertext += plaintext[i];
    }
    for(int i = 1;i < l;i+=2){
        ciphertext += plaintext[i];
    }
    return ciphertext;
}

string decryption(string ciphertext){
    int l = ciphertext.size();
    string plaintext = "";
    if(l%2 == 0){
        int j = l/2;
        for(int i = 0;i < (l/2);i++){
            plaintext = plaintext + ciphertext[i] + ciphertext[j];
            j++;
        }
    }
    else{
        int j = (l/2) + 1;
        for(int i = 0;i < (l/2);i++){
            plaintext = plaintext + ciphertext[i] + ciphertext[j];
            j++;
        }
        plaintext += ciphertext[(l/2)];
    }
    return plaintext;
}

int main(){
    string plaintext,ciphertext;
    cout<<"enter the plaintext : ";
    cin>>plaintext;
    ciphertext = encryption(plaintext);
    cout<<endl<<"encrypted text is :"<<ciphertext;
    cout<<endl<<"decryption ......";
    cout<<endl<<decryption(ciphertext);
    return 0;
}