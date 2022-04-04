/**
  Student Name: Alan Benitez
  File Name: main.cpp
  Assignment number 5

  This is the main class
**/
#include <iostream>
#include <cstdlib>
#include "LCSPt1.hpp"
#include "LCSMulti.hpp"

using namespace std;

int main() {
  
    cout << "######## PART ONE ########" << endl;
    LCSPt1 * work = new LCSPt1("twoStrings.txt");
    
    cout << endl;

    cout << "######## PART TWO ########" << endl;
    LCSMulti * multi = new LCSMulti("multiStrings.txt");
    
    return 0;
}

