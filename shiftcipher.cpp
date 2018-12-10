#include<bits/stdc++.h>
using namespace std;

string encryption(string plaintext,int key){
    string ciphertext = "";
    for(int i = 0;i < plaintext.size();i++){
        if(isupper(plaintext[i])){
            ciphertext += char(int((plaintext[i] + key - 65)%26) + 65);
        }
        else{
            ciphertext += char(int((plaintext[i] + key - 97)%26) + 97);
        }
    }
    return ciphertext;
}

string decryption(string ciphertext,int key){
    string plaintext = "";
    for(int i = 0;i < ciphertext.size();i++){
        if(isupper(ciphertext[i])){
            plaintext += char(int((ciphertext[i] - key - 65)%26 +26)%26 + 65);
        }
        else{
            plaintext += char(int((ciphertext[i] - key - 97)%26 + 26)%26 + 97);
        }
    }
    return plaintext;
}

int main(){
    string plaintext,ciphertext;
    int key;
    cout<<"\nenter plaintext :";
    cin>>plaintext;
    cout<<"\nenter key :";
    cin>>key;
    
    ciphertext = encryption(plaintext,key);
    cout<<"\nencrypted plaintext is  :  "<<ciphertext<<endl;
    
    cout<<"\ndecrypting ....";

    cout<<decryption(ciphertext,key);
    return 0;
}