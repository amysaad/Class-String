#include "myString.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>

#include <cstring>

using namespace std;

/*  private:
       char  text[MAXLENGTH+1];
       short length; // number of chars in the text (doesn't include NULL)
*/

myString::myString()  // CTOR (default)
{
    this->pText = new char[1];
    this->pText[0] = '\0';
    this->length=0;
}

myString::myString(char newText[] )  // CTOR (with parameter)
{
    // you finish this CTOR
    long newLen = strlen(newText);
    this->pText = new char [newLen + 1];

    strcpy(this->pText, newText);
    this->length = newLen;
}

myString::myString(myString& copy){

    long NewLen = copy.length;

    this->pText = new char[copy.getLength() + 1];

    strcpy(this->pText, copy.pText);
    this->length = NewLen;

}

myString::~myString() // DTOR
{
    cout << "INSIDE DTOR: DIE OBJECT     (" << this->pText << ")" << endl;
    // you write the DTOR
    delete []pText; // FREE the memory for new to use again
}

long myString::getLength() const {
    if(pText)
        return strlen(pText);
    else
        return 0;
}

myString& myString::operator=(const char *newText) {

    long textLength = strlen(newText);

    if (this->length < textLength ) {
        // dang, not enough room, so clean up and make enough room
        delete []this->pText;
        this->pText = new char[textLength + 1];
    }
    strcpy(this->pText, newText);
    this->length = strlen(this->pText);

    return *this;

}

myString& myString::operator=(const myString& anotherStringObject){
    // A=B;
    // this->will point to the A object
    //anotherString is the B object
    if (this->length < anotherStringObject.length ) {
        // dang, not enough room, so clean up and make enough room
        delete []this->pText;
        this->pText = new char[ anotherStringObject.length + 1];
    }
    strcpy(this->pText, anotherStringObject.pText);
    this->length = strlen(this->pText);

    return *this;
}

myString myString::operator+(const myString& anotherString)const{
    myString temporary;
    char *oldPText = this->pText;

    long newLen = (this->length + anotherString.length);
    temporary = new char[newLen + 1];

    strcpy(this->pText, oldPText);            // start with original text
    strcat(this->pText, anotherString.pText); // concat on additional text
    temporary = pText;

    delete []oldPText;
    return temporary;
}

char myString::operator[](long i) {
    return pText[i];
}
//--------------RELATIONAL OPS-------------------//
bool myString::operator<(const myString& rhs)const{
    if(this->length < rhs.length)
        return true;
    else
        return false;
}
bool myString::operator>(const myString& rhs)const{
    if(this->length > rhs.length)
        return true;
    else
        return false;
}
bool myString::operator!=(const myString &rhs)const{
    if(this->length != rhs.length)
        return true;
    else
        return false;
}
bool myString::operator<=(const myString &rhs)const{
    if(this->length <= rhs.length)
        return true;
    else
        return false;
}
bool myString::operator>=(const myString &rhs) const {
    if(this->length >= rhs.length)
        return true;
    else
        return false;
}
bool myString::operator==(const myString &rhs) const {
    if(this->length == rhs.length)
        return true;
    else
        return false;
}

ostream& operator<<(/*Inout*/ ostream& output, /*In*/ const myString& someText)
{
    output << someText.pText << endl;

    return output;
}


