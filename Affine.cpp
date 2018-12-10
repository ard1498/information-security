#include<bits/stdc++.h>
using namespace std;

int inverse(int key1){
    for(int i = 0;i < 26;i++){
        int f = (i*key1)%26;
        if(f == 1){
            return i;
        }
    }
    return -1;
}

string encryption(string plaintext,int key1,int key2){
    string ciphertext = "";
    for(int i = 0;i < plaintext.size();i++){
        if(isupper(plaintext[i])){
            ciphertext += char((key1*int(plaintext[i] - 65) + key2)%26 + 65);
        }
        else{
            ciphertext += char((key1*int(plaintext[i] - 97) + key2)%26 + 97);
        }
    }
    return ciphertext;
}

string decryption(string ciphertext,int invkey1,int key2){
    string plaintext = "";
    for(int i = 0;i < ciphertext.size();i++){
        if(isupper(ciphertext[i])){
            plaintext += char((invkey1*(int(ciphertext[i] - 65) - key2)%26 + 26)%26 + 65);
        }
        else{
            plaintext += char((invkey1*(int(ciphertext[i] - 97) - key2)%26 + 26)%26 + 97);
        }
    }
    return plaintext;
}

int main(){
    string plaintext,ciphertext;
    int key1,key2,invkey1;

    cout<<endl<<"enter the plaintext : ";
    cin>>plaintext;
    cout<<endl<<"enter multiplicative key : ";
    cin>>key1;
    cout<<endl<<"enter aditive key : ";
    cin>>key2;

    ciphertext = encryption(plaintext,key1,key2);
    cout<<endl<<"ciphertext is :"<<ciphertext;

    invkey1 = inverse(key1);
    cout<<endl<<"inverse is :"<<invkey1;
    cout<<endl<<"now decryption";
    cout<<endl<<decryption(ciphertext,invkey1,key2);

    return 0;
}