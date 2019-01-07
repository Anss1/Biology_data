#ifndef PROTEIN_H
#define PROTEIN_H
#include "Bio_data.h"
#include "RNA.h"
#include "CodonsTable.h"

class DNA;
class RNA;

enum Protein_Type {cat=0,Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Bio_data
{
private:
    Protein_Type type;
    string proteintype;
public:
    // constructors and destructor
    Protein();
    Protein(string,int,Protein_Type );
    ~Protein();

    int getchecker();
    void print();
    RNA protein_to_rna(RNA &);

    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    //DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);

    void loadfromfile (char *);
    void saveintofile (char *);

};

#endif // PROTEIN_H
