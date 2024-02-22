
#include <iostream>
#include "myString.h"

#include <cstring>
#include <cassert>
using namespace std;

// if you don't have the C++ string class, then
// we'll have to use our own arrays of chars

int main()
{
    //-------------------- Default CTOR() ---------
    myString A;
    cout << "(1). Default CTOR  ---------------" << endl;
    cout << A << endl;

    //-------------------- CTOR() with argument/parameter ---------
    char word[10];
    strcpy(word, "helloMyO");
    myString B(word);
    cout << "(2). CTOR with arg ---------------" << endl;
    cout << B << endl;

    //-------------------- Copy CTOR() ---------
    myString C(B);
    cout << "(3). Copy CTOR ---------------" << endl;
    cout << C << endl;

    //-------------------- operator= "an array of chars" ---------
    char junk[10];
    strcpy(junk, "foobar");

    A = junk;
    cout << "------------------------------" << endl;
    cout << "(4). A = (array of chars) " << endl;
    cout << A << endl;

    //-------------------- operator= "another myString object ---------
    B = A;
    cout << "------------------------------" << endl;
    cout << "(5). B = A" << endl;
    cout << B << endl;

    //-------------------- operator+ ---------

    myString F;

    cout << "------------------------------" << endl;
    cout << "(6). F = A + B (concat)" << endl;

    F = A + B;
    cout << "\tAfter concat: " << F << endl;
//-------------------- operator[] ---------

    cout << "(7): oneLetter = D[i]" << endl;
    char oneLetter;
    oneLetter = F[0];                 // initial letter
    assert(oneLetter == 'f');

    oneLetter = F[ F.getLength()-1 ];  // last letter
    assert(oneLetter == 'r');

    //--------------------  <,<=,>,>=,!=,==  ---------
    // RELATIONAL ops
    cout << "(8): Testing all relational operators" << endl;

    assert (F > B);  cout << "> ";
    assert (A >= B); cout << ">= ";
    assert (A == B); cout << "== ";
    assert (F != A); cout << "!= ";
    assert (B < F);  cout << "< ";
    assert (A <= B); cout << "<= " << endl;

    cout << endl << "------------------------------------------" << endl;
    cout << "(N): Testing DTORs" << endl;
    return 0;
}
