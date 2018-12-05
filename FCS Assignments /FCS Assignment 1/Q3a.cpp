// Ronak Kumar (2015080)

#include <iostream>
#include <string>
using namespace std;
// Method to get the plain text from the cipherText
string getPlainText(string cipherString) {
	string res = "";
	int key = 19;
	int numChars = 26;
	int startSmallAscii = 97;
	int startLargeAscii = 65;
	for(int i = 0; i < cipherString.length(); i++) {
		if(cipherString[i] == ' ') 
			res += ' ';
		else {
			if(cipherString[i] >= 'A' && cipherString[i] <= 'Z') {
				res += char(int(cipherString[i]+key-startLargeAscii) % numChars + startLargeAscii);
			}
			else if(cipherString[i] >= 'a' && cipherString[i] <= 'z') {
				res += char(int(cipherString[i]+key-startSmallAscii) % numChars + startSmallAscii);
			}
		}	
	}
	return res;
}
// Main Method
int main() {
	ios_base::sync_with_stdio(false);
	string input = "Slnpzshabylzohssthrluvshdylzwljapunhulzahispzotluavmylspnpvuvywyvopipapunaolmylllelyjpz laolylvmvyhiypknpunaolmyllkvtvmzwlljovyvmaolwylzzvyaolypnoavmaolwlvwslwlhjlhisfavhzz ltislhukavwlapapvuaolnvclyutluamvyhylkylzzvmnyplchujlz nhtl vm aoyvulz zlhzvu lpnoa        zwvpslyz qvu zuvd huk khlulyfz ahynhyflu av rpss lhjo vaoly";
	// By uncommenting the below line, you can take any user input
	// getline(cin, input);
	string res = getPlainText(input);
	cout << res << endl;
	return 0;
}