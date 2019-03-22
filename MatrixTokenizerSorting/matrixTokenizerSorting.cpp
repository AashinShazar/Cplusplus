

#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include <algorithm>
using namespace std;

struct TokenFreq{
   string token;
   int freq;
};

//Reference below: https://martin-thoma.com/cpp-operator-overloading/
bool operator<=(const TokenFreq& t1, const TokenFreq& t2){
        return t1.freq <= t2.freq;
}
        
TokenFreq operator+(const TokenFreq& t1, const TokenFreq& t2){
      TokenFreq t3;
        t3.freq = t1.freq + t2.freq;
        t3.token = t1.token + " or " + t2.token;
        return t3;
}

std::ostream& operator<<(std::ostream &strm, const TokenFreq &t1) {
  return strm << "(token, freq)=(" << t1.token << ", " << t1.freq << ")" << endl;
}

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols);
void getTokenFreqVec(string& istr, vector<TokenFreq> & tfVec);
void selectionSort( vector<TokenFreq> & tokFreqVector ); 
void insertionSort( vector<TokenFreq> & tokFreqVector ); 
void displayVector(vector<TokenFreq> & tfVec); //for debugging
//string ShortenSpace(string & searchText);


int main(){
   vector<vector<int> > matrix;
   matrixInit(matrix, 3, 4);
      
   //string istr = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
   //string istr = "And    no, I'm not a    walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I   do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
   string istr = "Writing   in C or C++ is    like running a chain   saw with all the safety guards removed. In C++, reinvention is    its own reward.";
   vector<TokenFreq> tfVec;
   getTokenFreqVec(istr, tfVec);
   //selectionSort(tfVec);
   displayVector(tfVec);
   
}

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols){
   
   int a, b;
   matrix.resize(numRows, vector<int>(numCols));
   
   for (a = 0; a < numRows; a++){
      for (b = 0; b < numCols; b++){
         matrix[a][b] = a*b;
      }
   }
   
   cout << "Size of matrix is: " << numRows << "x" << numCols << endl;
   for (a = 0; a < numRows; a++){
      for (b = 0; b < numCols; b++){
         cout << "matrix[" << a << "][" << b << "]=" << matrix[a][b] << endl;
      }
   }
}
   
/*References: 
* https://stackoverflow.com/questions/20073312/how-to-remove-multiple-spaces-from-a-c-program-and-put-one-space-instead-it
*/
string shortenSpaces(string& istr, string & newstr){
	int j;
	int i = 0;

	while (i < int(istr.length())){ 
		istr[i] = tolower(istr[i]); //lower case conversion 
		if (isspace(istr[i])){ //check space

			j = i+1;
			while(true){ //while space is true 
			if (istr[j] == '\342'){
			istr[j]=' '; //reduce to one whitespace
				}
			if (istr[j] == '\200'){
			istr[j]=' '; //reduce to one whitespace
				}
			if (istr[j] == '\224'){ //octal conversions of whitespace characters?
				istr[j]=' '; //reduce to one whitespace
				}
			if(isspace(istr[j])){
				j++; //increment as long as it is a space
			}
			else {
				break; //not break
			}
			}
			i=j-1;
			newstr = newstr + istr[i]; //append to our newstr
			}
			else if ((!isspace(istr[i]))){ //as long as it's not a space
			newstr = newstr + istr[i];
			}
				++i;
			}
			return newstr;
}

/*References:
* https://stackoverflow.com/questions/6444842/efficient-way-to-check-if-stdstring-has-only-spaces
* https://linustechtips.com/main/topic/765821-find-the-most-frequent-value-in-a-sorted-vector-c/
* https://stackoverflow.com/questions/20820672/efficient-way-to-find-frequencies-of-each-unique-value-in-the-stdvector
* http://www.cplusplus.com/forum/beginner/77801/
* https://stackoverflow.com/questions/18671315/record-number-of-occurrences-of-specific-substring-in-vector-of-strings
* and plenty others, this really threw me for a doozy
*/
void getTokenFreqVec( string& istr, vector<TokenFreq> & tfVec){
	
	string safeCopy, tempCopy;
	int indexStart, indexEnd;
	int index = 0;
	TokenFreq newToken;
	string foundWord;
	bool checkToken;
	int i = 0;
	
	//int totalSize = int(safeCopy.length()); does not work, fix?
	  
	safeCopy = shortenSpaces(istr, safeCopy); //call on that function we referenced
	tempCopy = safeCopy; //assign it to a tempcopy
  
	if(safeCopy.find_first_not_of(' ') != std::string::npos) //cool way of checking not whitespace
	{
	 tfVec.push_back(newToken);
	}

	while (i < int(safeCopy.length())){
		if(isspace(safeCopy[i])){
			checkToken = false;
			indexEnd = i;
			foundWord = tempCopy.substr(indexStart, indexEnd - indexStart); //use substring to isolate for
			indexStart = i + 1;
  
			for (int j = 0; j < int(tfVec.size()); j++){
			if (tfVec[j].token == foundWord){
				tfVec[j].freq++; //increment
				checkToken = true; //trigger
				
				if (checkToken == true){ //break
					break;
				}
				}
			}
			if (i!=(int(safeCopy.length())-1)){
				if (checkToken != 1){ //double check for trigger
				tfVec[index].token=foundWord;
				tfVec[index].freq=1;
				index++;
				tfVec.push_back(newToken);
				}
			}
			foundWord = ""; //reset found word 
			}
			++i;
}
  
	if(!isspace(safeCopy[int(safeCopy.length())-1])){
		foundWord = tempCopy.substr(indexStart, indexEnd - (int(safeCopy.length())-1));
		tfVec[index].token=foundWord;
		tfVec[index].freq=1;
	}
}
   
//Reference: http://www.algolist.net/Algorithms/Sorting/Selection_sort
void selectionSort( vector<TokenFreq> & tokFreqVector ){
      int minIndex;
      int totalSize = int(tokFreqVector.size());
      TokenFreq useToken;
      for ( int i = 0; i < totalSize -1; i++) {
            minIndex = i;
            for (int j = i + 1; j < totalSize; j++)
                  if (tokFreqVector[j].freq < tokFreqVector[minIndex].freq)
                        minIndex = j;
            if (minIndex != i) {
                  useToken = tokFreqVector[i];
                  tokFreqVector[i] = tokFreqVector[minIndex];
                  tokFreqVector[minIndex] = useToken;

            }
      }
}


//Reference: http://www.algolist.net/Algorithms/Sorting/Insertion_sort
void insertionSort( vector<TokenFreq> & tokFreqVector ){
      int maxIndex;
      int totalSize = int(tokFreqVector.size());
      TokenFreq useToken;
      for ( int i = 0; i < totalSize -1; i++) {
            maxIndex = i;
            for (int j = i + 1; j < totalSize; j++)
                  if (tokFreqVector[j].freq > tokFreqVector[maxIndex].freq)
                        maxIndex = j;
            if (maxIndex != i) {
                  useToken = tokFreqVector[i];
                  tokFreqVector[i] = tokFreqVector[maxIndex];
                  tokFreqVector[maxIndex] = useToken;

            }
      }
}


void displayVector(vector<TokenFreq> & tfVec){
cout << "size= {" << tfVec.size() << endl;
for (int i = 0; i < int(tfVec.size()); i++){
cout << " [" << i << "] = (token = \""<< tfVec[i].token <<"\", freq = " << tfVec[i].freq << ")" << endl;
}
cout << endl;
}