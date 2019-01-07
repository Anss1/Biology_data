#include "DNA.h"

string d_Type[] = {"a","promoter","motif","tail","noncoding"};

DNA::DNA()
{
    dnatype = "";
}

DNA::DNA(string st,int s,DNA_Type atype):Bio_data(st,s)
{
    type = atype;
    dnatype = d_Type[atype];
}

DNA::DNA(const DNA &rhs)
{
    sizes = rhs.sizes;
    type = rhs.type;
    dnatype = rhs.dnatype;
    seq = new char[rhs.sizes];
    for(int i=0; i<rhs.sizes; i++)
        seq[i] = rhs.seq[i];
}

int DNA::getchecker()
{
    return 1;
}

RNA DNA::ConvertToRNA()
{
    string str = seq;
    for(int i=0; i<sizes; i++)
    {
        if(str[i] == 'T' )
            str[i] = 'U';
    }
    RNA r (str,sizes,mRNA);
    return r;
}

void DNA::BuildComplementaryStrand()
{
    string str = "";
    for(int i=0; i<sizes; i++)
    {
        if(seq[i] == 'T' )
            str += 'A';
        else if(seq[i] == 'A' )
            str += 'T';
        else if(seq[i] == 'C' )
            str += 'G';
        else if(seq[i] == 'G' )
            str += 'C';
    }
    comp_str = new DNA(str,sizes,noncoding);
}
void DNA::printcomp()
{
    cout<<"Complementary sequence is : ";
    for(int i=0; i<sizes; i++)
        cout<<comp_str->seq[i];
    cout<<endl<<"Type is : "<<comp_str->dnatype<<endl;
}


DNA::~DNA()
{
    delete comp_str;
}

void DNA:: print()
{
    cout<<"Sequence is : ";
    for(int i=0; i<sizes; i++)
        cout<<seq[i];
    cout<<endl<<" Type is : "<<dnatype<<endl;
}

void DNA::loadfromfile(char* filename)
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
                dnatype += st[i];
        }
    }
}

void DNA::saveintofile(char* filename)
{
    ofstream out(filename);
    out<<seq<<"-"<<dnatype;
    out.close();
}

