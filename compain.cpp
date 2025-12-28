#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<conio.h>
#include <algorithm>  
#include <cstring> 
#include<limits>
#include<vector>
using namespace std;

void clear();
void saveCeaser(string Ceptext, string ctext, char Cekey);
void ceaserCipher(string text, char Cekey);
void saverail(string railptext, string railctext, string railkey);
void railFenceCipher(string text, int railkey);
void savevigenere(string Viptext, string Victext, string Vikey);
void vigenereCipher(string text, string Vikey);
void saverow(string rowptext, string rowctext, string rowkey);
void rowTranspositionCipher(string text, string key);
void save(string rowptext, string rowctext, string rowkey);
string vernamCipherEncrypt(string text, string Vernamkey);
void savevernam(string Vernamptext, string Vernamctext, string Vernamkey);

void clear() {
	cout << "Press any key to continue!";
	getch();
	system("CLS");
}
bool compareStringWithFile(string myString) {
    ifstream file("words.txt");
    string fileString;
    while (getline(file, fileString)) {
        if (fileString == myString) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
void saveCeaser(string Ceptext, string ctext, char Cekey) {
    ofstream outfile("encryption.txt", ios::app);

    if (outfile.is_open()) {
        outfile << "Plain text: " << Ceptext << endl;
        outfile << "Cipher text: " << ctext << endl;
        outfile << "Key: " << Cekey << endl;
        outfile << endl;
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}
void ceaserCipher(string text, char Cekey) {
    int k = 0;
    string ctext;

    if (isupper(Cekey)) {
        Cekey = tolower(Cekey);
    }

    for (int i = 97; i <= 122; i++) {
        if (Cekey == i)
            k = i - 96;
    }

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == 32)
            continue;
        if (isupper(text[i])) {
            text[i] = tolower(text[i]);
        }
    }

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == 32)
            continue;
        ctext += (text[i] - 'a' + k) % 26 + 'a';
    }

    cout << "Encrypted text: " << ctext << endl;
    saveCeaser(text, ctext, Cekey);
}
void ceasercipherD(char Cetext[], int textsize) {
    char Cedecrypt[100];
    bool check = false;

    for (int i = 0; i < textsize; i++) {
        if (Cetext[i] >= 'A' && Cetext[i] <= 'Z') {
            Cetext[i] += 32;
        }
    }

    for (int shift = 1; shift <= 26; shift++) {
        for (int j = 0; j < textsize; j++) {
            if (Cetext[j] >= 'a' && Cetext[j] <= 'z') {
                Cedecrypt[j] = 'a' + (Cetext[j] - 'a' - shift + 26) % 26;
            }
            else {
                Cedecrypt[j] = Cetext[j];
            }
        }

        check = compareStringWithFile(Cedecrypt);

        if (check) {
            cout << "Decrypted text: " << Cedecrypt << endl;
            return;
        }
    }

    cout << "Decryption failed." << endl;
}
void saverail(string railptext, string railctext, string railkey) {
    ofstream outfile("rail_fence_encryption.txt", ios::app);

    if (outfile.is_open()) {
        outfile << "Plain text: " << railptext << endl;
        outfile << "Cipher text: " << railctext << endl;
        outfile << "Key: " << railkey << endl;
        outfile << endl;
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}
void railFenceCipher(string text, int railkey) {
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

    string railctext;

    for (int i = 0; i < railkey; i++) {
        int j = i;
        bool down = true;

        while (j < text.size()) {
            railctext += text[j];

            if (i == 0 || i == railkey - 1) {
                j += 2 * (railkey - 1);
            }
            else {
                if (down) {
                    j += 2 * (railkey - i - 1);
                }
                else {
                    j += 2 * i;
                }
                down = !down;
            }
        }
    }

    cout << "Encrypted text: " << railctext << endl;
    saverail(text, railctext, to_string(railkey));
}
void railFenceCipherD(string railcipherText, int railkey) {
    if (railkey == 1) {
        if (compareStringWithFile(railcipherText)) {
            cout << "Decrypted with key " << railkey << ": " << railcipherText << endl;
        }
        return;
    }

    string raildecryptedText;
    int length = railcipherText.length();
    raildecryptedText.resize(length);

    int cycleLen = 2 * (railkey - 1);
    int index = 0;

    for (int i = 0; i < railkey; i++) {
        int j = i;
        bool down = true;
        while (j < length) {
            raildecryptedText[j] = railcipherText[index++];
            if (i == 0 || i == railkey - 1) {
                j += cycleLen;
            }
            else {
                if (down) {
                    j += cycleLen - 2 * i;
                }
                else {
                    j += 2 * i;
                }
                down = !down;
            }
        }
    }

    for (char& c : raildecryptedText) {
        c = tolower(c);
    }

    if (compareStringWithFile(raildecryptedText)) {
        cout << "Decrypted with key " << railkey << ": " << raildecryptedText << endl;
    }
}
void savevigenere(string Viptext, string Victext, string Vikey) {
    ofstream outfile("vigenere_encryption.txt", ios::app);
    if (outfile.is_open()) {
        outfile << "Plain text: " << Viptext << endl;
        outfile << "Cipher text: " << Victext << endl;
        outfile << "Key: " << Vikey << endl;
        outfile << endl;
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}

void vigenereCipher(string text, string Vikey) {
    string Victext;

    for (int i = 0, j = 0; i < text.size(); i++) {
        if (Victext[i] == 32) {
            continue;
        }
        else {
            char currentChar = text[i];
            char keyChar = Vikey[j % Vikey.length()];

            if (isupper(currentChar)) {
                currentChar = tolower(currentChar);
            }
            if (isupper(keyChar)) {
                keyChar = tolower(keyChar);
            }

            Victext += ((currentChar - 'a' + keyChar - 'a') % 26) + 'a';
            j++;
        }
    }

    cout << "Encrypted text: " << Victext << endl;
    savevigenere(text, Victext, Vikey);
}
bool isWord(string myString) {
    return compareStringWithFile(myString);
}
vector<string> findValidKeys(int VigenerekeyLength) {
    vector<string> validKeys;

    string Vigenerekey(VigenerekeyLength, 'a');

    while (true) {
        if (isWord(Vigenerekey)) {
            validKeys.push_back(Vigenerekey);
        }

        int index = VigenerekeyLength - 1;
        while (index >= 0) {
            if (Vigenerekey[index] < 'z') {
                Vigenerekey[index]++;
                break;
            }
            else {
                Vigenerekey[index] = 'a';
                index--;
            }
        }

        if (index < 0) {
            break;
        }
    }

    return validKeys;
}
void vigenereCipherD(string Vigeneretext, int maxKeyLength) {
    for (int i = 0; i < Vigeneretext.size(); i++) {
        if (isupper(Vigeneretext[i])) {
            Vigeneretext[i] = tolower(Vigeneretext[i]);
        }
    }

    for (int VigenerekeyLength = 1; VigenerekeyLength <= maxKeyLength; VigenerekeyLength++) {
        vector<string> validKeys = findValidKeys(VigenerekeyLength);

        for (const string& Vigenerekey : validKeys) {
            string VigeneredecryptedText = "";

            for (int i = 0, j = 0; i < Vigeneretext.size(); i++) {
                char base = 'a';
                VigeneredecryptedText += isalpha(Vigeneretext[i]) ? (char)((((Vigeneretext[i] - base) - (Vigenerekey[j] - base) + 26) % 26) + base) : Vigeneretext[i];
                j = (j + 1) % VigenerekeyLength;
            }

            if (isWord(VigeneredecryptedText) && isWord(Vigenerekey)) {
                cout << "Decrypted Text with key " << Vigenerekey << ": " << VigeneredecryptedText << endl;
            }
        }
    }
}

void saverow(string rowptext, string rowctext, string rowkey) {
    ofstream outfile("row_transposition_encryption.txt", ios::app);

    if (outfile.is_open()) {
        outfile << "Plain text: " << rowptext << endl;
        outfile << "Cipher text: " << rowctext << endl;
        outfile << "Key: " << rowkey << endl;
        outfile << endl;
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}

void rowTranspositionCipher(string text, string rowkey) {
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

    int numRows = text.length() / rowkey.length() + (text.length() % rowkey.length() == 0 ? 0 : 1);

    char** grid = new char* [numRows];
    for (int i = 0; i < numRows; ++i) {
        grid[i] = new char[rowkey.length()];
    }

    for (int i = 0, k = 0; i < numRows; i++) {
        for (int j = 0; j < rowkey.length(); j++) {
            if (k < text.length()) {
                grid[i][j] = text[k++];
            }
        }
    }

    string rowctext;
    for (char c : rowkey) {
        int col = c - '0' - 1;
        for (int row = 0; row < numRows; row++) {
            if (grid[row][col] != ' ') {
                rowctext += tolower(grid[row][col]);
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    cout << "Encrypted text: " << rowctext << endl;
    saverow(text, rowctext, rowkey);
}
void rowTranspositionDecipher(string rowcipherText) {
    int n = rowcipherText.length();

    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    do {
        string rowdecryptedText;
        rowdecryptedText.resize(n);

        for (int i = 0; i < n; i++) {
            rowdecryptedText[indices[i]] = rowcipherText[i];
        }

        for (char& c : rowdecryptedText) {
            c = tolower(c);
        }

        if (compareStringWithFile(rowdecryptedText)) {
            cout << "Decrypted Text: ";
            cout << rowdecryptedText << endl;
        }
    } while (next_permutation(indices.begin(), indices.end()));
}

string vernamCipherEncrypt(string text, string Vernamkey) {
    int textLength = text.size();
    string Vernamctext;

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            int valueText = toupper(text[i]) - 'A';
            int valueKey = toupper(Vernamkey[i]) - 'A';

            int result = (valueText ^ valueKey) % 26;

            Vernamctext += static_cast<char>(result + 'A');
        }
    }

    return Vernamctext;
}
void savevernam(string Vernamptext, string Vernamctext, string Vernamkey) {
    ofstream outfile("vernam_cipher_encryption.txt", ios::app);

    if (outfile.is_open()) {
        outfile << "Plain text: " << Vernamptext << endl;
        outfile << "Cipher text: " << Vernamctext << endl;
        outfile << "Key: " << Vernamkey << endl;
        outfile << endl;
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    a = a % m;
    for (unsigned long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1; 
}

unsigned long long generateRandomPrime() {
    return 17;  // Replace this with an actual random prime generation
}

pair<unsigned long long, unsigned long long> generateRSAKeys() {
    unsigned long long p = generateRandomPrime();
    unsigned long long q = generateRandomPrime();
    unsigned long long n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);
    unsigned long long e = 17;
    unsigned long long d = modInverse(e, phi);

    return make_pair(n, e);
}

unsigned long long encryptChar(char c, unsigned long long n, unsigned long long e) {
    unsigned long long encryptedChar = 1;
    for (unsigned long long i = 0; i < e; i++) {
        encryptedChar = (encryptedChar * c) % n;
    }
    return encryptedChar;
}

int main(){
	while(1){
	
    cout<<"Welcome to the Cryptography demystified"<<endl;
    a:
    cout << "What do you want, encryption or decryption or Key Encryption? (Enter 'E' or 'D' or 'K'): ";
    string choice_ED;
    cin>>choice_ED;
       if(choice_ED == "E"){
        	int choice1;
        cout<<"Which kind of Encryption do you want?"<<endl;
        cout<<"1. Ceaser Cipher"<<endl;
        cout<<"2. Vigenere Cipher"<<endl;
        cout<<"3. Rail Fence Cipher"<<endl;
        cout<<"4. Row transposition Cipher"<<endl;
        cout<<"5. Vernam Cipher"<<endl;
        cin>>choice1;
        cin.ignore();
        switch(choice1){
        	
        	case 1:{
				string Ceptext;
                char Cekey;
                cout << "Enter plain text to encrypt: ";
                getline(cin, Ceptext);
                cout << "Enter key: ";
                cin >> Cekey;
                ceaserCipher(Ceptext, Cekey);
        		break;
			}
        		
        		
        	case 2:{
        		string Viptext;
                string Vikey;
                cout << "Enter plain text to encrypt: ";
                getline(cin, Viptext);
                cout << "Enter key: ";
                getline(cin, Vikey);
                vigenereCipher(Viptext, Vikey);
			    break;
			}
        		
			    
			case 3:{
				string railptext;
                int railkey;
                cout << "Enter plain text to encrypt: ";
                getline(cin, railptext);
                cout << "Enter key (number of rails): ";
                cin >> railkey;
                railFenceCipher(railptext, railkey);
			    break;
			}
			    
			case 4:{
				string rowptext;
                string rowkey;
                cout << "Enter plain text to encrypt: ";
                getline(cin, rowptext);
                cout << "Enter key (e.g., 23154): ";
                getline(cin, rowkey);
                rowTranspositionCipher(rowptext, rowkey);
			    break;
			}
				
			    
			case 5:{
				string Vernamptext;
                string Vernamkey;
                cout << "Enter plain text to encrypt: ";
                getline(cin, Vernamptext);
                cout << "Enter key (must be the same length as the plain text): ";
                getline(cin, Vernamkey);
                if (Vernamptext.size() != Vernamkey.size()) {
                    cout << "Error: The length of the key must be the same as the length of the plain text." << endl;
                    return 1;
                }

                string Vernamctext = vernamCipherEncrypt(Vernamptext, Vernamkey);
                cout << "Encrypted text: " << Vernamctext << endl;
                savevernam(Vernamptext, Vernamctext, Vernamkey); 
			    break;
			}
			    
			default:
			    cout<< "Error Not found"<<endl;
			 break;		
			 
		}
	}
        
    
        
        	else if(choice_ED == "D"){
			
        int choice2;
        cout<<"Which kind of Decryption do you want?"<<endl;
        cout<<"1. Ceaser Cipher"<<endl;
        cout<<"2. Vigenere Cipher"<<endl;
        cout<<"3. Rail Fence Cipher"<<endl;
        cout<<"4. Row transposition Cipher"<<endl;
        cout<<"5. Vernam Cipher"<<endl;
        cin>>choice2;
        cin.ignore();
        switch(choice2){
        	case 1:{
        		char Cetext[100];
                for (int i = 0; i < 100; i++){
                	Cetext[i] = '\0';
				}
                    cout << "Enter encrypted text: ";
                    cin.getline(Cetext, 100);
                    int n = sizeof(Cetext) / sizeof(Cetext[0]);
                    ceasercipherD(Cetext, n);
				break;
			}
        	case 2:{
        		string Vigeneretext;
                cout << "Enter encrypted text: ";
                getline(cin, Vigeneretext);
                int maxKeyLength = 3;
                vigenereCipherD(Vigeneretext, maxKeyLength);
				break;
			}
			case 3:{
				string railtext;
                cout << "Enter encrypted text: ";
                getline(cin, railtext);
                for (char &c : railtext) {
                        c = tolower(c);
                }
                for (int railkey = 2; railkey <= railtext.length(); railkey++) {
                        railFenceCipherD(railtext, railkey);
                }
				break;
			}
			case 4:{
				string rowtext;
                cout << "Enter encrypted text: ";
                getline(cin, rowtext);
                for (char& c : rowtext) {
                    c = tolower(c);
                }
                rowTranspositionDecipher(rowtext);
				break;
			}
			case 5:{
				break;
			}
			default:
			 cout<< "Error Not found"<<endl;
			 break;		
		}
	}
	else if(choice_ED == "K"){
		cout << "Enter plain text: ";
    string inputContent;
    cin>>inputContent;

    pair<unsigned long long, unsigned long long> keys = generateRSAKeys();

    unsigned long long n = keys.first;
    unsigned long long e = keys.second;

    cout << "RSA Public Key (n, e): (" << n << ", " << e << ")" << endl;

    ofstream outputFile("cipher.txt");
    if (!outputFile) {
        cerr << "Error: Unable to create the output file." << endl;
        return 1;
    }

    for (char c : inputContent) {
        unsigned long long encryptedChar = encryptChar(c, n, e);
        outputFile << encryptedChar << " ";
    }

    outputFile.close();

    cout << "File encrypted and saved as cipher.txt" << endl;
	}
	
	else{
		cout << "Error! Invalid input, please enter a valid choice!" << endl;
            clear();
            goto a;
	}
	char continueChoice;
        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;
        cin.ignore();

        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
        clear();
}
}
    

    

