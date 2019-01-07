#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include <iostream>
#include <fstream>

using namespace std;


struct Codons
{
  	char value[3];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	protected:
        Codons codon[64];
   	public:
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);

        char getAminoAcid(string );

        void setCodon(string , int , char );
        void print_cod ();
};

#endif // CODONSTABLE_H
