#include <bits/stdc++.h>
# define pb push_back
# define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
using namespace std;
unordered_set<int> pos;
string encrypt(string plain_text, string key[5]) {
	string pText = "";
	for(int i = 0; i < plain_text.size(); i++) {
		if(plain_text[i] == 'j') {
			pText += 'i';
		} else {
			pText += plain_text[i];
		}
	}
	string pText2 = "";
	pText2 += pText[0];
	for(int i = 1; i < plain_text.size(); i++) {
		if(pText[i] == pText[i-1]) {
			for(char ch = 'a'; ch <= 'z'; ch++) {
				if(ch != pText[i]){
					pText2 += ch;
					break; 
				}
			}
			pos.insert(pText2.size()-1);
		} 
		pText2 += pText[i];
	}
	int N = pText2.length();
	if(N % 2 != 0) {
		for(char ch = 'a'; ch <= 'z'; ch++) {
			if(ch != pText[pText2.length()-1]){
				pText2 += ch;
				break; 
			}
		}
		pos.insert(N);
	}
	cout << pText2 << endl;
//	for(int i = 0; i < pos.size(); i++) {
//		cout << pos[i] << " ";
//	}
	cout << endl;
	
	string cipher_text = "";
	for(int i = 0; i < pText2.length(); i+= 2) {
		char ch1 = toupper(pText2[i]);
		char ch2 = toupper(pText2[i+1]);
		int i1, j1, i2, j2;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j <5; j++) {
				if(key[i][j] == ch1) {
					i1 = i;
					j1 = j;
				}
				if(key[i][j] == ch2) {
					i2 = i;
					j2 = j;
				}
			}
		}
		
		if(i1 == i2) {
			cipher_text += key[i1][(j1 + 1)%5];
			cipher_text += key[i2][(j2 + 1)%5];
		}
		else if(j1 == j2) {
			cipher_text += key[(i1 + 1)%5][j1];
			cipher_text += key[(i2 + 1)%5][j2];
		} 
		else {
			cipher_text += key[i1][j2];
			cipher_text += key[i2][j1];
		}
	}
	cout << cipher_text << endl;
	return cipher_text;
}

void decrypt(string cipher_text, string key[5]) {
	string plain_text = "";
	for(int i = 0; i < cipher_text.length(); i+= 2) {
		char ch1 = toupper(cipher_text[i]);
		char ch2 = toupper(cipher_text[i+1]);
		int i1, j1, i2, j2;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j <5; j++) {
				if(key[i][j] == ch1) {
					i1 = i;
					j1 = j;
				}
				if(key[i][j] == ch2) {
					i2 = i;
					j2 = j;
				}
			}
		}
		
		if(i1 == i2) {
			plain_text += key[i1][((j1 - 1)%5 + 5)%5];
			plain_text += key[i2][((j2 - 1)%5 + 5)%5];
		}
		else if(j1 == j2) {
			plain_text += key[((i1 - 1)%5 + 5)%5][j1];
			plain_text += key[((i2 - 1)%5 + 5)%5][j2];
		} 
		else {
			plain_text += key[i1][j2];
			plain_text += key[i2][j1];
		}
		//cout << plain_text << endl;
	}
	cout << plain_text << endl << endl;
	for(int i = 0; i < plain_text.size(); i++) {
		if(pos.find(i) == pos.end())
			cout << plain_text[i];
	}
}

int main(){
	// code here
	string key[5] = {"LGDBA", "QMHEC", "URNIF", "XVSOK", "ZYWTP"};
	string plain_text;
	cout << "Enter plain text: \n";
	cin >> plain_text;
	
	string cipher_text = encrypt(plain_text, key);
	//string cipher_text = "LAHALBLBCIDMDCDCOTXALG";
	decrypt(cipher_text, key);
	return 0;
}

/*
abcdddefghhhiokll

LAHALBLBCIDMDCDCOTXALG

ABCDADADEFGHAHAHIOKLAL
*/

