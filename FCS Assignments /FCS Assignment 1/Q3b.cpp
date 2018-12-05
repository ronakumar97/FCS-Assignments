// Ronak Kumar (2015080)

#include <iostream>
#include <string>
using namespace std;
string alphabets = "abcdefghijklmnopqrstuvwxyz";
string cipherStringLarge = "BIRDWATCHNGEFJKLMOPQSUVXYZ";
string cipherStringSmall = "birdwatchngefjklmopqsuvxyz";
// Search method for character in the cipherString
int search(string cipherString, char c) {
	for(int i = 0; i < cipherString.length(); i++) {
		if(cipherString[i] == c) return i;
	}
}
// Method to get the cipherText from the input
string getCipherText(string input) {
	string res = "";
	for(int i = 0; i < input.length(); i++) {
		if(input[i] >= 'A' && input[i] <= 'Z') {
			res += toupper(alphabets[search(cipherStringLarge, input[i])]);
		}
		else if(input[i] >= 'a' && input[i] <= 'z') {
			res += alphabets[search(cipherStringSmall, input[i])];
		}
		else {
			res += input[i];
		}
	}
	return res;
}
// Main Method
int main() {
	string input = "Qcw Hjdhbj lbobdhpw aeyrbqrcwo (Qwolphlckjw lbobdhph) hp b fwdhsf-phzwd lbppwohjw ihod jbqhuw qk Bphb qcbq hp vhdwey dhpqohisqwd. Bp qcw tekibe lklsebqhkj hp rkjphdwowd pqbiew, hq cbp iwwj ehpqwd bp Ewbpq Rkjrwoj kj qcw HSRJ Owd Ehpq phjrw 2004. Hq hp jbqhuw qk qcw Hjdhbj psirkjqhjwjq, Rwjqobe Bphb bjd Fybjfbo";
	// By uncommenting the below line, you can take any user input
	// getline(cin, input);
	string res = getCipherText(input);
	cout << res << endl;
	return 0;
}