/**
  Student Name: Alan Benitez
  File Name: LCSMulti.cpp
  Assignment number 5

  This class is where I have have all the methods that I need for part two of the project
**/

#include "LCSMulti.hpp"

//Overloaded constructor. Here I open the file multiStrings and do the main calls for the part two of the project
LCSMulti::LCSMulti(string fileName) {
    inputFile.open(fileName.c_str());
    if(inputFile.is_open()){
        cout << fileName << " opened succesfully!" << endl;
        inputFile >> numStringsInFile;
        inputs = new string[numStringsInFile];
        for(int i = 0; i < numStringsInFile; i++)
        {
            inputFile >> inputs[i];
            inputs[i].insert(0, " ");
        }
        table();
    }
    else{
        cout << "Could not open the file " << endl;
        exit(0);
    }
    inputFile.close();
}

//Here I am outputting the measures of similarity table needed for part 2
void LCSMulti::table(){
    cout << "Measures of similarity table:" << endl;
    for(int i = 0; i <= numStringsInFile; i++){
        if(i == 0) {
            cout << "  ";
        }
        else {
            //extra formatting for when an int is 2 digits long
            if(i >= 10) {
                cout << i ;
            }
            else {
                cout << " " << i;
            }
        }
        for(int j = 1; j <= numStringsInFile; j++){
            if(i == 0) {
                cout << "  " << j;
            }
            else {
                if(j <= i) {
                    //extra formatting for when an int is 2 digits long
                    if(j >= 10) {
                        cout << "   -";
                    }
                    else {
                        cout << "  -";
                    }
                }
                else {
                    //extra formatting for when an int is 2 digits long
                    if(j >= 10) {
                        cout << "   " << compareStrings(inputs[i-1], inputs[j-1]);
                    }
                    else {
                        cout << "  " << compareStrings(inputs[i-1], inputs[j-1]);
                    }
                }
            }
        }
        cout << endl;
    }
}

//This method compares the strings and returns the letter to print
char LCSMulti::compareStrings(string one, string two){

    int oneLength = one.length() - 1;
    int twoLength = two.length() - 1;
    double lcs = 0.0;

    double maxVal = max(oneLength, twoLength);
    double minVal = min(oneLength, twoLength);
    lcs = getLCSNum(one, two, oneLength, twoLength);
    
    return letterToPrint(maxVal, minVal, lcs);   
}

//This method will print the letter in the table
char LCSMulti::letterToPrint(double max, double min, double lcs){

    if(((min / max) >= 0.9) && ((lcs / min) >= 0.9)) { //10% and 90%  antes estaba 0.9 y 0.9
        return 'H';
    }
    else if(((min / max) >= 0.8) && ((lcs / min) >= 0.8)){  //20% and 80% antes estaba 0.8 y 0.8
        return 'M';
    }
    else if(((min / max) >= 0.6) && ((lcs / min) >= 0.5)) {  //40% and 50% antes estaba 0.6 y 0.5
        return 'L';
    }
    else{
        return 'D';
    }
}

//This method will get the LCS number and will return a number
int LCSMulti::getLCSNum(string X, string Y, int m, int n){
    int numToReturn[m + 1][n + 1];  

    for (int i = 0; i <= m; i++) {  
        for (int j = 0; j <= n; j++) {  
            if (i == 0 || j == 0) {
                numToReturn[i][j] = 0; 
            }
            else if (X[i - 1] == Y[j - 1]) {
                numToReturn[i][j] = numToReturn[i - 1][j - 1] + 1;
            }
            else {
                numToReturn[i][j] = max(numToReturn[i - 1][j], numToReturn[i][j - 1]); 
            }
        }  
    }  
    return numToReturn[m][n];  
}

//Destructor
LCSMulti::~LCSMulti() {
    delete[] inputs;
}
