#ifndef MYSTRING
#define MYSTRING

#include <iostream>
using namespace std;


class myString
{
public:
    myString();                 // CTOR (default)
    myString( char newText[] ); // CTOR (when you know the text already)
    myString(myString& );       // Copy CTOR

    ~myString();                // DTOR

    // GETTERs
    long getLength() const;

    myString& operator=(const char newText[]);
    myString& operator=(const myString& anotherStringObject);

    myString  operator+(const myString& anotherString)const;

    char      operator[](long i);

    // relational expressions based on length of string
    bool      operator<(const myString& rhs)const;
    bool      operator<=(const myString& rhs)const;
    bool      operator>(const myString& rhs)const;
    bool      operator>=(const myString& rhs)const;
    bool      operator!=(const myString& rhs)const;
    bool      operator==(const myString& rhs)const;

    //IO operators
    friend ostream& operator<<(/*inout*/ostream& output_stream, /*in*/const myString& someText);

private:
    char  *pText; // memory for the array of chars will be on the HEAP
    long  length; // number of chars in the text (doesn't include NULL)
};

#endif