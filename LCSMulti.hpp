/**
  Student Name: Alan Benitez
  File Name: LCSMulti.hpp
  Assignment number 5

  This class is the header file for the second part of the project
**/
#ifndef LCSMULTI_HPP
#define LCSMULTI_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class LCSMulti {
    private:
      ifstream inputFile;
      int numStringsInFile;
      string * inputs;
    public:
      LCSMulti(string fileName);
      ~LCSMulti();
      void table();
      char compareStrings(string one, string two);
      char letterToPrint(double max, double min, double lcs);
      int getLCSNum(string X, string Y, int m, int n);
};

#endif

