#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

std::vector<std::string> Str2Vec(std::string string, char separator);
std::string Vec2Str(std::vector<std::string> vector,char separator);
std::string TrimWhiteSpaces(std::string str);
std::vector<int> FindSubstrMatches(std::string phrase, std::string word);
std::string ReplaceAllSubstring(std::string phrase, std::string word, std::string replacement);
std::string CaesarCypher(std::string str, int key, bool isNotCrypted);

int main(){

/* // PROBLEM 0: String to char Code - Char Code to str
std::cout << "Insert your string: ";
std::string sIn, sCodedString, sDecodedString = "";
std::cin >> sIn;
for(char c: sIn){
    sCodedString += std::to_string((int)c - 23);
}
std::cout << "Your coded string is: " << sCodedString << "\n";
for(int i = 0; i<sCodedString.length(); i += 2){
    int nCharcode = std::stoi(sCodedString.substr(i,2));
    char chCharcode = nCharcode + 23;
    sDecodedString += chCharcode; 
}
std::cout << "Your decoded string is: " << sDecodedString << "\n"; */


/* // PROBLEM 1: String vector to string
std::vector<std::string> vCust(3);
vCust[0] = "Bob";
vCust[1] = "Sue";
vCust[2] = "Tom";

std::string sCust = Vec2Str(vCust,' ');
std::cout << sCust << "\n"; */


/* // PROBLEM 2: Find all matches and store index on a vector
std::string phrase = "To be or not to be";
std::vector<int> matches = FindSubstrMatches(phrase, "be");
for (int i =0; i < matches.size(); i++){
    std::cout << matches[i] << "\n";
} */


/* // PROBLEM 3: Replace a substring for another
std::cout << ReplaceAllSubstring("to know or not to know or knowing to know", "know", "be") << "\n"; */

// PROBLEM 4: Caesar Cypher

std::string str = "Make me secret";
std::string encryptedStr = CaesarCypher(str, 5, true);
std::string decryptedStr = CaesarCypher(encryptedStr, 5 , false);
std::cout << "Encrypted: " << encryptedStr << "\n";
std::cout << "Decrypted: " << decryptedStr << "\n";

return 0;

}
std::vector<std::string> Str2Vec(std::string string, char separator){
    std::vector<std::string> vecWords;
    
    std::stringstream ss(string);
    std::string sCharacter;
    while(getline(ss, sCharacter, separator)){
        vecWords.push_back(sCharacter);
    }
    return vecWords;
}

std::string Vec2Str(std::vector<std::string> vector,char separator){
    std::string text = "";
    for (std::string s: vector){
        text += s + separator;
    }
    return text;
}

std::string TrimWhiteSpaces(std::string str){
    std::string whitespaces(" \t\f\n\r");
    str.erase(str.find_last_not_of(whitespaces) + 1);
    str.erase(0, str.find_first_not_of(whitespaces));
    return str;
}

std::vector<int> FindSubstrMatches(std::string phrase, std::string word){
    std::vector<int> matchingIndex;
    int index = phrase.find(word, 0);
    while(index!= std::string::npos){
        matchingIndex.push_back(index);
        index = phrase.find(word, index + 1);
    }
    return matchingIndex;
}

std::string ReplaceAllSubstring(std::string phrase, std::string word, std::string replacement){
    int index = phrase.find(word, 0);
    int wordLength = word.length();
    while(index!= std::string::npos){
        phrase = phrase.substr(0,index) + replacement + phrase.substr(index + wordLength, phrase.length() - (index + wordLength));
        index = phrase.find(word, index + replacement.length());
    }
    return phrase;
}

std::string CaesarCypher(std::string str, int key, bool isNotCrypted){
    if(isNotCrypted){
        // Crypting
        std::string crypted = "";
        for (char c: str){
            if (isspace(c)){
                crypted += ' ';
            } else if (isalpha(c)){
                switch (isupper(c))
                {
                case 0: // lowercase
                    crypted += (char)(97+(int(c) + key - 97)%26);
                    break;
                case 1: // uppercase
                   crypted += (char)(65+(int(c) + key - 65)%26);
                    break;
                
                default:
                    break;
                }
            } else crypted += c;
        } return crypted;

    }else{
        // Decrypting
        std::string decrypted = "";
        for (char c: str){
            if (isspace(c)){
                decrypted += ' ';
            } else if (isalpha(c)){
                switch (isupper(c))
                {
                case 0: // lowercase
                    (int(c)-key)<0? decrypted += (char)(122 - int(c)-key) : decrypted += (char)(int(c)-key);
                    break;
                case 1: // uppercase
                    (int(c)-key)<0? decrypted += (char)(90 - int(c)-key) : decrypted += (char)(int(c)-key);
                    break;
                
                default:
                    break;
                }
            } else decrypted += c;
        }return decrypted;
    }
}