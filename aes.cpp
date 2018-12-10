#include<bits/stdc++.h>
using namespace std;
string hex2bin(string s){
	unordered_map<char, string> mp;
	mp['0']= "0000";
	mp['1']= "0001";
	mp['2']= "0010";
	mp['3']= "0011";
	mp['4']= "0100";
	mp['5']= "0101";
	mp['6']= "0110";
	mp['7']= "0111";
	mp['8']= "1000";
	mp['9']= "1001";
	mp['A']= "1010";
	mp['B']= "1011";
	mp['C']= "1100";
	mp['D']= "1101";
	mp['E']= "1110";
	mp['F']= "1111";
	string bin="";
	for(int i=0; i<s.size(); i++){
		bin+= mp[s[i]];
	}
	return bin;
}
string bin2hex(string s){
	unordered_map<string, string> mp;
	mp["0000"]= "0";
	mp["0001"]= "1";
	mp["0010"]= "2";
	mp["0011"]= "3";
	mp["0100"]= "4";
	mp["0101"]= "5";
	mp["0110"]= "6";
	mp["0111"]= "7";
	mp["1000"]= "8";
	mp["1001"]= "9";
	mp["1010"]= "A";
	mp["1011"]= "B";
	mp["1100"]= "C";
	mp["1101"]= "D";
	mp["1110"]= "E";
	mp["1111"]= "F";
	string hex="";
	for(int i=0; i<s.length(); i+=4){
		string ch="";
		ch+= s[i];
		ch+= s[i+1];
		ch+= s[i+2];
		ch+= s[i+3];
		hex+= mp[ch];
	}
	return hex;
}
int bin2dec(string s){
	unordered_map<string, int> mp;
	mp["0000"]= 0;
	mp["0001"]= 1;
	mp["0010"]= 2;
	mp["0011"]= 3;
	mp["0100"]= 4;
	mp["0101"]= 5;
	mp["0110"]= 6;
	mp["0111"]= 7;
	mp["1000"]= 8;
	mp["1001"]= 9;
	mp["1010"]= 10;
	mp["1011"]= 11;
	mp["1100"]= 12;
	mp["1101"]= 13;
	mp["1110"]= 14;
	mp["1111"]= 15;
	int dec;
	for(int i=0; i<s.length(); i+=4){
		string ch="";
		ch+= s[i];
		ch+= s[i+1];
		ch+= s[i+2];
		ch+= s[i+3];
		dec= mp[ch];
	}
	return dec;
}

string xor_(string a, string b){
	string ans= "";
	for(int i=0; i<a.size(); i++){
		if(a[i]==b[i]){
			ans+= "0";
		}else{
			ans+= "1";
		}
	}
	return ans;
}

string shiftRow(string word, int numShifts){//32 bits
	string temp= "";
	for(int i=0; i<numShifts; i++){
		temp= word.substr(8, 24)+ word.substr(0, 8);//8bits i.e. 1 byte left shift
		word= temp;
		temp= "";
	}
	return word;
}
string subByte(string byte){
	string sbox[16][16] =
	{{	"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
	{	"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
	{	"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"}, 
	{	"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
	{	"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"}, 
	{	"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"}, 
	{	"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
	{	"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
	{	"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
	{	"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
	{	"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
	{	"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"}, 
	{	"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
	{	"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"}, 
	{	"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
	{	"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}};
	int row= bin2dec( byte.substr(0, 4) );
	int col= bin2dec( byte.substr(4, 4) );
	return hex2bin(sbox[row][col]);//return binary string
}

string invSubByte(string byte){
	
}

string multiplyBinary(string p1, string p2){
	string ans= "00000000";
	string xi= p2;
	bool flag;//to remember msb of previous result
	if(xi[0]=='1'){
		flag= true;
	}else{
		flag= false;
	}
	if(p1[p1.length()-1]=='1'){
		ans= p2;
	}
	for(int i=p1.length()-2; i>=0; i--){
		//left shift
		xi= xi.substr(1)+ "0";
		
		if (flag){
			//if msb of previous result is 1
			xi= xor_(xi, "00011011");//irreducible polynomial is x^8+ x^4+ x^3+ x+ 1 i.e. 100011011 
		}
		
		if(xi[0]=='1'){
			flag= true;
		}else{
			flag= false;
		}
		if (p1[i]=='1'){
			//Updating final ans
			ans= xor_(ans, xi);
		}
	}
	return ans;
}

void print(string state[][4]){
	//print current state
	for(int i=0; i<4;i++){
		for(int j=0; j<4; j++){
			cout<<bin2hex(state[i][j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void printRoundKey(string w){
	string round[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			round[i][j]= w.substr(8*i+32*j,8);
		}
	}
	print(round);
}
string encrypt(string pt, vector<string> w){
	//Converting plain text from hexadecimal to 128-bit binary
	pt= hex2bin(pt);
	
	//Creating a 4*4 state matrix of plain text
	string state[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			state[i][j]= pt.substr(8*i+32*j,8);
		}
	}
	
	//Pre-round
	cout<<"Pre-round\n";
	cout<<"Input State\n";
	print(state);
	for(int j=0; j<4; j++){
		string _= xor_(state[0][j]+ state[1][j]+ state[2][j]+ state[3][j], w[j]);
		state[0][j]= _.substr(0, 8);
		state[1][j]= _.substr(8, 8);
		state[2][j]= _.substr(16, 8);
		state[3][j]= _.substr(24, 8);
	}
	cout<<"Output State\n";
	print(state);
	cout<<"Round Key\n";
	printRoundKey(w[0]+ w[1]+ w[2]+ w[3]);
	
	//Round 1-10
	for(int round=1; round<=10; round++){
		cout<<"\nRound "<<round<<"\n";
		cout<<"Input State\n";
		print(state);
		
		//SubByte
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				state[i][j]= subByte(state[i][j]);
			}
		}

		//Shift Row
		for(int j=1; j<4; j++){
			string _= shiftRow(state[j][0]+ state[j][1]+ state[j][2]+ state[j][3], j);
			state[j][0]= _.substr(0, 8);
			state[j][1]= _.substr(8, 8);
			state[j][2]= _.substr(16, 8);
			state[j][3]= _.substr(24, 8);
		}
		
		//Mixing
		if(round!=10){
			//Column-wise mixing
			for(int j=0; j<4; j++){
				string t0= state[0][j], t1= state[1][j], t2= state[2][j], t3= state[3][j];
				state[0][j]= xor_( xor_( xor_(multiplyBinary(hex2bin("02"),t0),  multiplyBinary(hex2bin("03"),t1) ), t2), t3);
				state[1][j]= xor_( xor_( xor_(multiplyBinary(hex2bin("02"),t1),  multiplyBinary(hex2bin("03"),t2) ), t3), t0);
				state[2][j]= xor_( xor_( xor_(multiplyBinary(hex2bin("02"),t2),  multiplyBinary(hex2bin("03"),t3) ), t0), t1);
				state[3][j]= xor_( xor_( xor_(multiplyBinary(hex2bin("02"),t3),  multiplyBinary(hex2bin("03"),t0) ), t1), t2);
			}
		}
		
		//Adding Round Key
		for(int j=0; j<4; j++){
			string _= xor_(state[0][j]+ state[1][j]+ state[2][j]+ state[3][j], w[round*4+ j]);
			state[0][j]= _.substr(0, 8);
			state[1][j]= _.substr(8, 8);
			state[2][j]= _.substr(16, 8);
			state[3][j]= _.substr(24, 8);
		}
		
		cout<<"Output State\n";
		print(state);
		
		cout<<"Round Key\n";
		printRoundKey(w[round*4]+ w[round*4+ 1]+ w[round*4+ 2]+ w[round*4+ 3]);
	}
	
	//Cipher Text
	string cipher= "";
	for(int i=0;i<4; i++){
		for(int j=0; j<4; j++){
			cipher+= state[j][i];
		}
	}
	cipher= bin2hex(cipher);
	return cipher;
}

int main(){
	string pt, key;
	cout<<"Enter plain text(in hexadecimal form): ";
	cin>>pt;
	
	cout<<"Enter cipher key(in hexadecimal form): ";
	cin>>key;

	//Key Expansion
	
	//Converting key from hexadecimal to 128-bit binary
	key= hex2bin(key);
	
	//Words
	vector<string> w(44);
	
	for(int i=0; i<4; i++){
		w[i]= key.substr(32*i, 8) + key.substr(32*i +8, 8) + key.substr(32*i+16, 8) + key.substr(32*i+ 24, 8);
		///cout<<i<<"\t"<<bin2hex(w[i])<<endl;
	}
	
	//Round Constants
	string rCon[10];
	rCon[0]= hex2bin("01000000");
	rCon[1]= hex2bin("02000000");
	rCon[2]= hex2bin("04000000");
	rCon[3]= hex2bin("08000000");
	rCon[4]= hex2bin("10000000");
	rCon[5]= hex2bin("20000000");
	rCon[6]= hex2bin("40000000");
	rCon[7]= hex2bin("80000000");
	rCon[8]= hex2bin("1B000000");
	rCon[9]= hex2bin("36000000");
	
	for(int i=4; i<44; i++){
		if(i%4!=0){
			w[i]= xor_(w[i-1], w[i-4]);
		}else{
			//t= SubWord(RotWord(w[i-1]) xor rCon[i/4]
			string temp= shiftRow(w[i-1], 1), temp1;
			temp1= subByte(temp.substr(0, 8));
			temp1+= subByte(temp.substr(8, 8));
			temp1+= subByte(temp.substr(16, 8));
			temp1+= subByte(temp.substr(24, 8));
			string t= xor_(temp1, rCon[i/4 -1]);
			
			w[i]= xor_(t, w[i-4]);
		}
		//cout<<i<<"\t"<<bin2hex(w[i])<<endl;
	}
	
	cout<<"\nEncryption\n";
	string cipher= encrypt(pt, w);
	cout<<"Cipher Text: "<<cipher<<endl;
	
}
/*
00041214120412000C00131108231919
2475A2B33475568831E2120013AA5487
*/
