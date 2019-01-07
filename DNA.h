#ifndef DNA_H
#define DNA_H

#include "Bio_data.h"
#include "RNA.h"

class RNA;

enum DNA_Type {sat=0,promoter, motif, tail, noncoding};

class DNA : public Bio_data
{
private:
    DNA_Type type;
    string dnatype;
    DNA * comp_str;//complementary_strand
public:
    // constructors and destructor
    DNA();
    DNA(string,int,DNA_Type );
    DNA(const DNA& );
    ~DNA();

    int getchecker ();
    // function printing DNA sequence information to user
    void print();
    void printcomp ();
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();

    //functions to load and save in and from file
    void loadfromfile (char *);
    void saveintofile (char *);

};

#endif // DNA_H
