#include "Protein.h"

CodonsTable check_table;

string p_Type[] = {"a","Hormon","Enzyme","TF","Cellular_Function"};

Protein::Protein()
{
    proteintype = "";
}

Protein::Protein(string p,int s,Protein_Type atype):Bio_data(p,s)
{
    type = atype;
    proteintype = p_Type[atype];
}

Protein::~Protein()
{

}

int Protein::getchecker()
{
    return 3;
}

void Protein::print()
{
    cout<<"Sequence is : ";
    for(int i=0; i<sizes; i++)
        cout<<seq[i];
    cout<<endl<<"Type is : "<<proteintype<<endl;

}

RNA Protein::protein_to_rna(RNA &bigRna)
{
    check_table.LoadCodonsFromFile("codons2.txt");
    int sz = bigRna.getsize();
    string st = bigRna.getseq();

    string str = "", v = "";
    int j=0;

    for(int i=0; i<sz; i++)
    {
        v += st[i];
        v += st[i+1];
        v += st[i+2];
        if(seq[j] == check_table.getAminoAcid(v))
        {
            str.append(v);
            j++;
            v = "";
            for(int z=i+3; z<(3*sizes); z+=3)
            {
                v += st[z];
                v += st[z+1];
                v += st[z+2];
                if(seq[j] == check_table.getAminoAcid(v))
                {
                    str.append(v);
                    j++;
                }
                else
                {
                    str = "";
                    j = 0;
                    break;
                }
                v = "";
            }
        }
        v = "";
        if(str.size() == (3*sizes) || sz <= (3*sizes))
            break;
    }

    RNA res(str,str.size(),mRNA);
    return res;
}



void Protein::loadfromfile(char* filename)
{
    string st = "";
    char ch;
    ifstream in(filename);
    if(in.fail())
        cout<<"Error....file not exist!!!"<<endl;
    else
    {
        while(in.get(ch))
        {
            st += ch;
        }
        in.close();
    }
    bool val =true;
    sizes = st.size();
    seq = new char[st.size()];
    for(int i=0 ; i<sizes ; i++)
    {
       if(st[i] != '-' && val)
            seq[i] = st[i];
        else if(st[i] == '-')
            val = false;
        else if(!val)
        {
            if(i == st.size())
                break;
            else
                proteintype += st[i];
        }
    }
}
void Protein::saveintofile(char* filename)
{
    ofstream out(filename);
    out<<seq<<"-"<<proteintype;
    out.close();
}
