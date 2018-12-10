#include<bits/stdc++.h>
using namespace std;

string encryption(string plaintext,string key){
    string ciphertext = "";
    int j = 0;
    for(int i = 0;i < plaintext.size();i++){
        if(isupper(plaintext[i])){
            if(isupper(key[j])){
                ciphertext += char((int(plaintext[i] - 65) + int(key[j] - 65))%26 + 65);
            }
            else{
                ciphertext += char((int(plaintext[i] - 65) + int(key[j] - 97))%26 + 65);
            }
        }
        else{
            if(isupper(key[j])){
                ciphertext += char((int(plaintext[i] - 97) + int(key[j] - 65))%26 + 97);
            }
            else{
                ciphertext += char((int(plaintext[i] - 97) + int(key[j] - 97))%26 + 97);
            }
        }
        j = (j+1)%key.size();
    }
    return ciphertext;
}

string decryption(string ciphertext,string key){
    string plaintext = "";
    int j = 0;
    for(int i = 0;i < ciphertext.size();i++){
        if(isupper(ciphertext[i])){
            if(isupper(key[j])){
                plaintext += char(((int(ciphertext[i] - 65) - int(key[j] - 65))%26 + 26)%26 + 65);
            }
            else{
                plaintext += char(((int(ciphertext[i] - 65) - int(key[j] - 97))%26 + 26)%26 + 65);
            }
        }
        else{
            if(isupper(key[j])){
                plaintext += char(((int(ciphertext[i] - 97) - int(key[j] - 65))%26 + 26)%26 + 97);
            }
            else{
                plaintext += char(((int(ciphertext[i] - 97) - int(key[j] - 97))%26 + 26)%26 + 97);
            }
        }
        j = (j+1)%key.size();
    }
    return plaintext;
}

int main(){
    string plaintext,ciphertext,key;
    cout<<"\nenter the plaintext : ";
    cin>>plaintext;
    cout<<"\nenter the key : ";
    cin>>key;
    ciphertext = encryption(plaintext,key);
    cout<<"\nencrypted data is : "<<ciphertext;
    cout<<"\ndecryption...";
    cout<<"\n"<<decryption(ciphertext,key);
}