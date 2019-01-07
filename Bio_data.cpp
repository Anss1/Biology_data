#include "Bio_data.h"

Bio_data::Bio_data() {}

Bio_data::Bio_data(string str,int s)
{
    sizes = s;
    seq = new char[s];
    seq[s] = '\0';
    for(int i=0; i<s; i++)
        seq[i] = str[i];
}
Bio_data::Bio_data(const Bio_data& b)//r2=r1
{
    sizes = b.sizes;
    seq = new char[b.sizes];
    seq[b.sizes] = '\0';

    for(int i=0; i<b.sizes; i++)
        seq[i] = b.seq[i];
}

Bio_data::~Bio_data()
{
    delete seq;
}

void Bio_data::setter(string str,int s)
{
    for(int i=0; i<s; i++)
        seq[i] = str[i];
}


char* Align(Bio_data* b1,Bio_data* b2)//LCS
{
    int m = b1->sizes, n = b2->sizes;
    int len[m+1][n+1];
    char *str1 = b1->seq, *str2 = b2->seq;

    /* Following steps build L[m+1][n+1] in bottom up fashion. */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                len[i][j] = 0;
            else if (str1[i-1] == str2[j-1])
                len[i][j] = len[i-1][j-1] + 1;
            else
                len[i][j] = max(len[i-1][j], len[i][j-1]);
        }
    }


    // Following code is used to return LCS------------------------------------
    int index = len[m][n];

    // Create a character array to store the lcs string
    char *lcs = new char[index+1];
    lcs[index] = '\0';     // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (str1[i-1] == str2[j-1])
        {
            lcs[--index] = str1[--i]; // Put current character in result
            j--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (len[i-1][j] > len[i][j-1])
            i--;
        else
            j--;
    }

    // Return the lcs
    return lcs;
    delete lcs;
}

string operator+ (Bio_data &b1,Bio_data &b2)
{
    string str1 =b1.seq, str2 = b2.seq;
    string res ;
    res += str1;
    res += str2;
    return res;
}
bool operator== (Bio_data &b1,Bio_data &b2)
{
    string str1 =b1.seq, str2 = b2.seq;
    if(b1.sizes != b2.sizes)
        return false;
    else
    {
        for(int i=0; i<b1.sizes; i++)
        {
            if(str1[i] != str2[i])
                return false;
        }
        return true;
    }
}
bool operator!= (Bio_data &b1,Bio_data &b2)
{
    string str1 =b1.seq, str2 = b2.seq;
    if(b1.sizes != b2.sizes)
        return true;
    else
    {
        for(int i=0; i<b1.sizes; i++)
        {
            if(str1[i] == str2[i])
                return false;
        }
        return true;
    }
}


ostream& operator<< (ostream& out,Bio_data *b)
{
    cout<<"Sequence is : ";
    for(int i=0; i< b->sizes; i++)
        out<<b->seq[i];
    cout<<endl;
    return out;
}

