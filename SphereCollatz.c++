//
//  SpereCollatz.cpp
//  
//
//  Created by Drew Zoellner on 2/5/15.
//
//

#include <stdio.h>
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

//#include "Collatz.h"

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
    assert (i >= 0);
    int count = 1;
    int largestCount = 1;
    int max = j;
    int min = i;
    if (j < i){
        max = i;
        min = j;
    }if (min == 0) {
        min++;
    }
    for (int k = min; k <= max; k++){
        int theNum = k;
        while (theNum != 1){
            if (theNum % 2 == 0){
                theNum = theNum / 2;
                count++;
            }else{
                theNum = theNum * (3) + 1;
                count += 1;
            }
        }
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



// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif


// ----
// main
// ----

int main () {
    //using namespace std;
    collatz_solve(cin, cout);
    return 0;}