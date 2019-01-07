#include "RNA.h"

string r_Type[] = {"a","mRNA","pre_mRNA","mRNA_exon","mRNA_intron"};
RNA::RNA() {rnatype = "";}

RNA::RNA(string st,int siz,RNA_Type atype):Bio_data(st,siz)
{
    type = atype;
    rnatype = r_Type[atype];
}
RNA::RNA(const RNA &rhs)
{
    sizes = rhs.sizes;
    type = rhs.type;
    rnatype = rhs.rnatype;
    seq = new char[rhs.sizes];
    for(int i=0; i<rhs.sizes; i++)
        seq[i] = rhs.seq[i];
}
RNA::~RNA()
{

}

int RNA::getchecker()
{
    return 2;
}

DNA RNA::ConvertToDNA()//acuu    actt
{
    string str = seq;
    for(int i=0; i<sizes; i++)
    {
        if(str[i] == 'U' )
            str[i] = 'T';
    }
    DNA d(str,sizes,noncoding);
    return d;
}

Protein RNA::ConvertToProtein(CodonsTable& table)
{
    string str = "", v = "";
    for(int i=0; i<sizes; i+=3)
    {
        v += seq[i];
        v += seq[i+1];
        v += seq[i+2];
        str += table.getAminoAcid(v);
        v = "";
    }
    Protein p(str,str.size(),Cellular_Function);
    return p;
}


void RNA::print()
{
    cout<<"Sequence is : ";
    for(int i=0; i<sizes; i++)
        cout<<seq[i];
    cout<<endl<<"Type is : "<<rnatype<<endl;

}

void RNA::loadfromfile(char* filename)
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
    sizes = st.size();//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
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
                rnatype += st[i];
        }
    }
}
void RNA::saveintofile(char* filename)
{
    ofstream out(filename);
    out<<seq<<"-"<<rnatype;
    out.close();
}


char* RNA::getseq()
{
    return seq;
}
int RNA::getsize()
{
    return sizes;
}
