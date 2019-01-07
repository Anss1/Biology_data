#include "Bio_data.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include <cstring>

int n=1;

int main()
{
    CodonsTable cod;
    cod.LoadCodonsFromFile("codons2.txt"); //Load codons combinations and amino acids from file named codons2.txt into cod

    int choice,noseq,load,ns[2]; //AUCAAAAUUAAAAGCAGG
    char fn[50];
    /* choice to store the input of type of sequence

    noseq to store the input of number of sequence

    load to store the input of option of loading sequence or not

    */
    string str;//Store the input of sequence then send it as parameter to constructor

    cout<<"Enter number of sequences -> ";
    cin>>noseq;
    system("cls");

    Bio_data *b1[noseq+1];//array of pointer of objects to make polymorphism

    for(int i=1; i<= noseq; i++)
    {
types:
        try
        {
            cout<<"\t\t\t\t\t\t* List of types *\n\n";

            cout<<"1- DNA.\n2- RNA.\n3- Protein.\n\n";

            cout<<"Enter number of ("<<i<<") sequence type : ";
            cin>>choice;
            if(choice > 3 || choice < 1)
                throw 0;
            system("cls");

        }
        catch(int x)
        {
            cout<<endl<<"Error,,,choice does not in range,press any key to try again.\n"<<endl;
            system("pause");
            system("cls");
            goto types ;
        }


        if(choice == 1)
        {
            cout<<"\t\t\t\t\t\t* List of options *\n\n";
            cout<<"1- load sequence from file.\n2- Input sequence manually.\n\n";

            cout<<"Enter number of option : ";
            cin>>load;
            system("cls");
            if(load == 1)
            {
                char fn[50];
                b1[i] = new DNA;
                cout<<"Enter the file name with its extension : ";
                cin>>fn;
                b1[i]->loadfromfile(fn);
                ((DNA*)b1[i])->BuildComplementaryStrand();
                system("cls");
            }
            else
            {
again1:
                try
                {
                    cout<<"Enter the ("<<i<<") sequence ,NOTE(by default it is noncoding): ";
                    cin>>str;
                    for(unsigned int j=0; j<str.size(); j++)//****************
                    {
                        if(str[j] != 'A' && str[j] != 'C' && str[j] != 'G' && str[j] != 'T')
                            throw 0;
                        if(str.size() % 3 != 0)
                            throw 'a';
                    }
                }
                catch(int y)
                {
                    cout<<endl<<"Error,,,sequence have a strange alphabet... correct sequence consists of {A,T,C,G} ,press any key to try again.\n"<<endl;
                    system("pause");
                    system("cls");
                    goto again1 ;
                }
                catch(char x)
                {
                    cout<<endl<<"Error,,,sequence size should be from range [3 , 3*n] ,press any key to try again.\n"<<endl;
                    system("pause");
                    system("cls");
                    goto again1 ;
                }

                b1[i]= new DNA (str,str.size(),noncoding);
                ((DNA*)b1[i])->BuildComplementaryStrand();
                system("cls");
            }

        }
        else if(choice == 2)
        {
            cout<<"\t\t\t\t\t\t* List of options *\n\n";
            cout<<"1- load sequence from file.\n2- Input sequence manually.\n\n";

            cout<<"Enter number of option : ";
            cin>>load;
            system("cls");
            if(load == 1)
            {
                char fn[50];
                b1[i] = new RNA;
                cout<<"Enter the file name with its extension : ";
                cin>>fn;
                b1[i]->loadfromfile(fn);
                system("cls");
            }
            else
            {
again2:
                try
                {
                    cout<<"Enter the ("<<i<<") sequence ,NOTE(by default it is mRNA): ";
                    cin>>str;
                    for(unsigned int j=0; j<str.size(); j++)//****************
                    {
                        if(str[j] != 'A' && str[j] != 'C' && str[j] != 'G' && str[j] != 'U')
                            throw 0;
                        if(str.size() % 3 != 0)
                            throw 'a';
                    }
                }
                catch(int y)
                {
                    cout<<endl<<"Error,,,sequence have a strange alphabet... correct sequence consists of {A,U,C,G} ,press any key to try again.\n"<<endl;
                    system("pause");
                    system("cls");
                    goto again2 ;
                }
                catch(char x)
                {
                    cout<<endl<<"Error,,,sequence size should be from range [3 , 3*n] ,press any key to try again.\n"<<endl;
                    system("pause");
                    system("cls");
                    goto again2 ;
                }
                b1[i]= new RNA (str,str.size(),mRNA);
                system("cls");
            }
        }

        else if(choice == 3)
        {
            cout<<"\t\t\t\t\t\t* List of options *\n\n";
            cout<<"1- load sequence from file.\n2- Input sequence manually.\n\n";

            cout<<"Enter number of option : ";
            cin>>load;
            system("cls");
            if(load == 1)
            {
                char fn[50];
                b1[i] = new Protein;
                cout<<"Enter the file name with its extension : ";
                cin>>fn;
                b1[i]->loadfromfile(fn);
                system("cls");
            }
            else
            {
again3:
                try
                {
                    cout<<"Enter the ("<<i<<") sequence ,NOTE(by default it is Cellular_Function): ";
                    cin>>str;
                    for(unsigned int j=0; j<str.size(); j++)//****************
                    {
                        if(str[j] == 'B' || str[j] == 'O' || str[j] == 'Z' || str[j] == 'U' || str[j] == 'J' || str[j] == 'X' || islower(str[j]))
                            throw 0;
                    }
                }
                catch(int y)
                {
                    cout<<endl<<"Error,,,sequence have a strange alphabet... sequence should not consists of {B,U,O,Z,X,J} ,press any key to try again.\n"<<endl;
                    system("pause");
                    system("cls");
                    goto again3 ;
                }
                b1[i]= new Protein (str,str.size(),Cellular_Function);
                system("cls");
            }
        }
    }



    //List of operations----------------------------------------------------------
    int operation_num;
    while(1)
    {
        cout<<"\t\t\t\t\t\t* List of operation *\n\n";
        cout<<"1- Concatenate two sequences.\n2- Check if two sequences are equal."
            <<"\n3- Check if two sequences are not equal.\n4- Convert to DNA."
            <<"\n5- Convert to RNA.\n6- Convert to Protein.\n7- Check alignment by (LCS).\n8- Build Complementary Strand (DNA)."
            <<"\n9- Print sequence on screen.\n10- Save sequence in file.\n0- Exit.\n\n";

        cout<<"Enter number of operation : ";
        cin>>operation_num;

        system("cls");

        if(operation_num == 1)
        {
op1:
            try
            {
                cout<<"Enter number of first sequence : ";
                cin>>ns[0];
                cout<<endl<<"Enter number of second sequence : ";
                cin>>ns[1];
                if(b1[ns[0]]->getchecker() != b1[ns[1]]->getchecker())
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequences should be in the same type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op1 ;
            }
            string res = *b1[ns[0]] + *b1[ns[1]];
            cout<<res<<endl;
            system("pause");
            system("cls");

        }
        else if(operation_num == 2)
        {
op2:
            try
            {
                cout<<"Enter number of first sequence : ";
                cin>>ns[0];
                cout<<endl<<"Enter number of second sequence : ";
                cin>>ns[1];
                if(b1[ns[0]]->getchecker() != b1[ns[1]]->getchecker())
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequences should be in the same type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op2 ;
            }

            if(b1[ns[0]] == b1[ns[1]])
                cout<<"sequences are equal."<<endl;
            else
                cout<<"sequences are not equal."<<endl;
            system("pause");
            system("cls");
        }
        else if(operation_num == 3)
        {
op3:
            try
            {
                cout<<"Enter number of first sequence : ";
                cin>>ns[0];
                cout<<endl<<"Enter number of second sequence : ";
                cin>>ns[1];
                if(b1[ns[0]]->getchecker() != b1[ns[1]]->getchecker())
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequences should be in the same type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op3 ;
            }
            if(b1[ns[0]] != b1[ns[1]])
                cout<<"sequences are not equal."<<endl;
            else
                cout<<"sequences are equal."<<endl;
            system("pause");
            system("cls");
        }
        else if(operation_num == 4)
        {
op4:
            try
            {
                cout<<"Enter the number of (RNA) sequence to convert : ";
                cin>>ns[0];
                if(b1[ns[0]]->getchecker() != 2)
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequence should be in (RNA) type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op4 ;
            }
            //delete b1[ns];
            b1[ns[0]] = new DNA(((RNA*)b1[ns[0]])->ConvertToDNA());
            ((DNA*)b1[ns[0]])->BuildComplementaryStrand();
            b1[ns[0]]->print();
            system("pause");
            system("cls");
        }
        else if(operation_num == 5)
        {
op5:
            try
            {
                cout<<"Enter the number of (DNA) or (Protein) sequence to convert : ";
                cin>>ns[0];
                if(b1[ns[0]]->getchecker() != 1 && b1[ns[0]]->getchecker() != 3 )
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequence should be in (DNA) or (Protein) type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op5 ;
            }
            //delete b1[ns];
            system("cls");
            if(b1[ns[0]]->getchecker() == 1)
            {
                b1[ns[0]] = new RNA(((DNA*)b1[ns[0]])->ConvertToRNA());
            }
            else
            {
                int opt;
                cout<<"\t\t\t\t\t\t* List of options *\n\n";
                cout<<"1- Load (RNA) sequence from file.\n2- Enter (RNA) sequence manually.\n\nEnter your choice : ";
                cin>>opt;
                system("cls");
                if(opt == 1)
                {
                    cout<<"Enter the file name with its extension : ";
                    cin>>fn;
                    RNA r;
                    r.loadfromfile(fn);
                    b1[ns[0]] = new RNA(((Protein*)b1[ns[0]])->protein_to_rna(r));
                }
                else if(opt == 2)
                {
againop:
                    try
                    {
                        cout<<"Enter the sequence ,NOTE(by default it is mRNA): ";
                        cin>>str;
                        for(unsigned int j=0; j<str.size(); j++)//****************
                        {
                            if(str[j] != 'A' && str[j] != 'C' && str[j] != 'G' && str[j] != 'U')
                                throw 0;
                            if(str.size() % 3 != 0)
                                throw 'a';
                        }
                    }
                    catch(int y)
                    {
                        cout<<endl<<"Error,,,sequence have a strange alphabet... correct sequence consists of {A,U,C,G} ,press any key to try again.\n"<<endl;
                        system("pause");
                        system("cls");
                        goto againop ;
                    }
                    catch(char x)
                    {
                        cout<<endl<<"Error,,,sequence size should be from range [3 , 3 to power (n)] ,press any key to try again.\n"<<endl;
                        system("pause");
                        system("cls");
                        goto againop ;
                    }
                    RNA r(str,str.size(),mRNA);
                    b1[ns[0]] = new RNA(((Protein*)b1[ns[0]])->protein_to_rna(r));
                }

            }
            system("cls");
            b1[ns[0]]->print();
            system("pause");
            system("cls");
        }
        else if(operation_num == 6)
        {
op6:
            try
            {
                cout<<"Enter the number of (RNA) sequence to convert : ";
                cin>>ns[0];
                if(b1[ns[0]]->getchecker() != 2)
                    throw 0;
            }
            catch(int x)
            {
                cout<<endl<<"Error...sequence should be in (RNA)type ,press any key to try again.\n"<<endl;
                system("pause");
                system("cls");
                goto op6 ;
            }
            //delete b1[ns];
            b1[ns[0]] = new Protein(((RNA*)b1[ns[0]])->ConvertToProtein(cod));
            system("cls");
            b1[ns[0]]->print();
            system("pause");
            system("cls");
        }
        else if(operation_num == 7)
        {
            cout<<"Enter number of first sequence : ";
            cin>>ns[0];
            cout<<endl<<"Enter number of second sequence : ";
            cin>>ns[1];
            char *res = Align(b1[ns[0]],b1[ns[1]]);
            cout<<res<<endl;
            system("pause");
            system("cls");
        }
        else if(operation_num == 8)
        {
            cout<<"Enter the number of (DNA) sequence to build : ";
            cin>>ns[0];
            ((DNA*)b1[ns[0]])->printcomp();
            system("pause");
            system("cls");
        }
        else if(operation_num == 9)
        {
            cout<<"Enter number of sequence to print : ";
            cin>>ns[0];
            system("cls");
            b1[ns[0]]->print();
            cout<<endl;
            system("pause");
            system("cls");
        }
        else if(operation_num == 10)
        {
            cout<<"Enter the file name with its extension : ";
            cin>>fn;

            cout<<endl<<"Enter number of sequence to save : ";
            cin>>ns[0];
            b1[ns[0]]->saveintofile(fn);
            system("cls");
            cout<<"Successful operation."<<endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout<<"The program ended..."<<endl;
            break;
        }

    }

    for(int i=1; i<=noseq; i++)
        delete b1[i];




    return 0;
}
