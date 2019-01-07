#include "CodonsTable.h"

CodonsTable::CodonsTable() {}

CodonsTable::~CodonsTable() {}

void CodonsTable::LoadCodonsFromFile(string filename)
{
    int i=0;
    char ch;
    string str = "";
    ifstream file(filename);
    if(file.fail())
    {
        cerr<<"File is not exist!\n"<<endl;
    }
    else
    {
        while(!file.eof())
        {
            file>>str;
            for(int j=0;j<3;j++)
                codon[i].value[j] = str[j];
            codon[i].AminoAcid = str[3];
            i++;
        }
    }
    file.close();
}

char CodonsTable::getAminoAcid(string val)
{
    for(int i=0; i<64; i++)
    {
        if(codon[i].value[0] == val[0] && codon[i].value[1] == val[1] && codon[i].value[2] == val[2])
        {
            return codon[i].AminoAcid;
            break;
        }
    }
}

void CodonsTable::setCodon(string val,int index,char amino)
{
    for(int i=0; i<3; i++)
        codon[index].value[i] = val[i];
    codon[index].AminoAcid = amino;
}


void CodonsTable::print_cod()
{
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<3; j++)
            cout<<codon[i].value[j];
        cout<<" "<<codon[i].AminoAcid<<endl;
    }
}

