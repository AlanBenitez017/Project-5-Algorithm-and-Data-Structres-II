/**
  Student Name: Alan Benitez
  File Name: LCSPt1.cpp
  Assignment number 5

  This class is where I have have all the methods that I need for part one of the project
**/

#include "LCSPt1.hpp"

using namespace std;

//Overloaded constructor. Here I open the file twoStrings and do the main calls for the part one of the project
LCSPt1::LCSPt1(string fileName){

    inputFile.open(fileName.c_str());
    if(inputFile.is_open()){
        cout << fileName << " opened successfully!" << endl;
        getline(inputFile, stringOne);
        getline(inputFile, stringTwo);
        stringOne.insert(0, " ");
        stringTwo.insert(0, " ");
    }
    else{
        cout << "The file did not open correctly" << endl;
        exit(0);
    }
    cout << "\t" << "String 1: " << endl;
    cout << stringOne << endl;
    cout << "\t" << "String 2: " << endl;
    cout << stringTwo << endl;
    
    int size = stringOne.length();
    int sizer = stringTwo.length();
    createArray(size,sizer);
    cout << "\t" << "LCS is " << endl;
    LCSString(size, sizer);
    cout << endl;
    cout << "\t" << "Size " << endl;
    cout << "\t" << LCSSize - 1;
    
    inputFile.close();
}

//Here I create the array
void LCSPt1::createArray(int oneSize, int twoSize){
    
    c = new int*[oneSize + 1];

    for(int i = 0; i < oneSize; i++){
        c[i] = new int[twoSize + 1];
    }
    for(int i = 1; i < oneSize; i++){
        c[i][0] = 0;
    }
    for(int i = 0; i < oneSize; i++){
        c[0][i] = 0;
    }
    for(int m = 1; m < oneSize; m++){
        for(int n = 1; n < twoSize; n++){
            if(stringOne[m] == stringTwo[n]){
                c[m][n] = c[m-1][n-1] + 1;
            }
            else {
                if(c[m-1][n] >= c[m][n-1]){
                    c[m][n] = c[m-1][n];
                }
                else{
                    c[m][n] = c[m][n-1];
                }
            }
	      }
    } 
}

//This function will make the LCS recursively
void LCSPt1::LCSString(int i, int j){
    if(i == 0 || j == 0) {
        return;
    }
    else {
        if(stringOne[i] == stringTwo[j]) {
            LCSString(i-1, j-1);
            cout << stringOne[i];
            LCSSize++;
        }
        else if(c[i-1][j] >= c[i][j-1]) {
            LCSString(i-1, j);
        }
        else {
            LCSString(i, j-1);
        }
    }
}

//Destructor
LCSPt1::~LCSPt1() {
    delete []c;
}

