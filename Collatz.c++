// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    //no negative values!
    assert (i >= 0);
    assert (j >= 0);
    int* cache = new int[100000000];
    int count = 1;
    int largestCount = 1;
    int max = j;
    int min = i;
    //put numbers in correct order / check for error cases
    if (j < i){
        max = i;
        min = j;
    }if (min == 0) {
        if(max == 0){
            return 0;
        }
        min++;
    }
    //loop through all numbers in the range
    for (int k = min; k <= max; k++){
        int theNum = k;
        bool haventFound = true;
        //keep going until you found cachedValue or get to 1
        while (theNum != 1 && haventFound){
            //did you find a cached value?
            if(theNum > 0 && theNum < 100000000 && cache[theNum] != 0){
                count += cache[theNum];
                haventFound = true;
            }
            else if (theNum % 2 == 0){
                theNum = theNum / 2;
                count++;
            }else{
                theNum = theNum * (3) + 1;
                count++;
            }
        }
        //update cache table and largest cycle
        cache[theNum] = count;
        if (count > largestCount) {
            largestCount = count;
        }
        count = 1;
    }
    assert(largestCount >= 1);
    return largestCount;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
