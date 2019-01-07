#ifndef BIO_DATA_H
#define BIO_DATA_H
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;

class Bio_data
{
protected:
    char *seq;
    int sizes;
public:

    Bio_data();
    Bio_data(string,int );
    Bio_data(const Bio_data& );
    virtual~Bio_data();

    virtual void print() = 0 ;
    void setter(string,int);
    virtual int getchecker() = 0;

    friend char* Align(Bio_data *, Bio_data * );

    friend string operator+ (Bio_data & ,Bio_data & );
    friend bool operator== (Bio_data & ,Bio_data & );
    friend bool operator!= (Bio_data & ,Bio_data & );

    friend ostream& operator<< (ostream& ,Bio_data* );
    friend istream& operator>> (istream& ,Bio_data* );

    virtual void loadfromfile (char *) = 0;
    virtual void saveintofile (char *) = 0;



};

#endif // BIO_DATA_H
