#ifndef RNA_H
#define RNA_H
#include "Bio_data.h"
#include "CodonsTable.h"
#include "DNA.h"
#include "Protein.h"

class Protein;
class DNA;


enum RNA_Type {fat=0,mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Bio_data
{
private:
    RNA_Type type;
    string rnatype;
public:
    // constructors and destructor
    RNA();
    RNA(string,int, RNA_Type );
    RNA(const RNA& );
    ~RNA();

    int getchecker();
    char* getseq();
    int getsize();
    // function to be overridden to print all the RNA information
    void print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protein ConvertToProtein(CodonsTable & );
    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();

    void loadfromfile (char *)  ;
    void saveintofile (char *)  ;

};
#endif // RNA_H
