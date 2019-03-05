#include <iostream>
#include <string>
using namespace std;

void PrintMenu(char usrChoice) {
  cout << "MENU" << endl;
  cout << "c - Number of non-whitespace characters" << endl;
  cout << "w - Number of words" << endl;
  cout << "f - Find text" << endl;
  cout << "r - Replace all !'s" << endl;
  cout << "s - Shorten spaces" << endl;
  cout << "q - Quit" << endl;
}

int GetNumOfNonWSCharacters(const string searchText) {
  unsigned int nonWSCount = 0;
  for (unsigned int i = 0; i < searchText.length(); i++) {
    if (!isspace(searchText[i])) {
      nonWSCount++;
    }
  }
  return nonWSCount;
}

//Reference: http://www.cplusplus.com/forum/general/30929/  
int GetNumOfWords(const string searchText) {
  int wordCount = 1; //account for shift
  unsigned int i = 0;
  while (i < searchText.size()) {
    if (isspace(searchText[i])) {
      while (isspace(searchText[i])) //continues to evaluate if space is found, helps count one word
        i++;
      wordCount++;
    } else if (!isspace(searchText[i])) { //increments if a space is no longer found 
      i++;
    }
  }
  return wordCount;
}

//Reference: https://stackoverflow.com/questions/22489073/counting-the-number-of-occurrences-of-a-string-within-a-string
int FindText(string findThis, string searchText) {
  int foundCount = 0;
  string::size_type stringStart = 0;
  while ((stringStart = searchText.find(findThis, stringStart)) != string::npos) {
    foundCount++;
    stringStart += findThis.length();
  }
  return foundCount;
}

string ReplaceExclamation(string & replaceText) {
  string modifiedText = replaceText;
  unsigned int i = 0;
  while (i < replaceText.length()) {
    if (replaceText[i] == '!') {
      modifiedText[i] = '.';
    }
    replaceText = modifiedText;
    i++;
  }
  return modifiedText;
}

string ShortenSpace(string & searchText) {
  char modString[searchText.size() + 1];
  unsigned int b = 0;
  for (unsigned int a = 0; a < searchText.size(); b++) {
    modString[b] = searchText[a];
    if (isspace(searchText[a])) {
      while (isspace(searchText[a])) {
        a++;
      }
    } else {
      a++;
    }
  }
  return searchText = modString;
}

int main() {

  char usrChoice;
  string sampleText;
  string findThis;

  cout << "Enter a sample text:" << endl;
  getline(cin, sampleText);

  cout << "You entered: " << sampleText << endl;

  while (usrChoice != 'q') {
    PrintMenu(usrChoice);

    cout << "Choose an option:" << endl;
    cin >> usrChoice;

    if (usrChoice == 'c') { //non whitespace chars
      cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(sampleText) << endl;
    } else if (usrChoice == 'w') { //num words
      cout << "Number of words: " << GetNumOfWords(sampleText) << endl;
    } else if (usrChoice == 'f') { //find text
      cout << "Enter a word or phrase to be found:" << endl;
      cin >> findThis;
      cout << "\"" << findThis << "\"" << " instances: " << FindText(findThis, sampleText) << endl;
    } else if (usrChoice == 'r') { //Replace all !'s     
      cout << "Edited text: " << ReplaceExclamation(sampleText) << endl;
    } else if (usrChoice == 's') { //Shorten spaces
      cout << "Edited text: " << ShortenSpace(sampleText) << endl;
    }

  }

  return 0;
}