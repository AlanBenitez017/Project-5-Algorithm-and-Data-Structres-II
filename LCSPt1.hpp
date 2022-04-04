/**
  Student Name: Alan Benitez
  File Name: LCSPt1.hpp
  Assignment number 5

  This class is the header file for the first part of the project
**/

#ifndef LCSPt1_HPP
#define LCSPt1_HPP
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

class LCSPt1{

  private:
    ifstream inputFile;
    string stringOne;
    string stringTwo;
    int LCSSize = 0;
    int** c;
   
  public:
    LCSPt1(string fileName);
    ~LCSPt1();
    void createArray(int oneSize, int twoSize);
    void LCSString(int i, int j);
    
};

#endif

