//---------------------------------------------------------------------------
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

void vvod(char*);
char cvvod();
void svvod(char* s);
#pragma argsused
int main(int argc, char* argv[])
{
 char *s,a;
 int i,j,k,n,m,l;
 

 while(true)
 {
        s=new char [101];
        s[0]='\0';
        fflush(stdin);
        cout<<"Enter string consisting of 0, 1 and spaces. Thr program'll return the shotest group : "<<endl;

        svvod(s);


        j=0;
        while(s[0]==' ') strcpy(s,s+1);





        i=0;
        while(s[i]!=';')
                {

                 if (s[i]==' ' && s[i+1]==' ')
                        {
                         j=i;
                         while(s[j]!=';') s[j]=s[j+1], j++;
                         i--;
                        }
                 i++;
                }

        //cout<<"Corrected string: \n"<<s<<endl;

        j=n=i;
        k=0;
        for(i=0;i<=j;i++)

                {

                 if (s[i]!=' ' && s[i]!=';') k++;
                        else
                                {
                                 if (k<n) n=k;
                                 k=0;
                                }


                }


        l=0;
        for(i=0;i<=j;i++)

                {
                 if (s[i]!=' ' && s[i]!=';') k++;
                        else
                                {
                                 if (k==n)
                                        {
                                         l++;
                                         cout<<"The shortest gorup number "<<l<<"\t";
                                         for(m=i-k;m<=i;m++) cout<<s[m];
                                         cout<<endl;
                                        }
                                 k=0;
                                }


                }





        delete []s;
        //cout<<"Press any key for closing program...";
        //getch();
        cout<<"Do you want to repeat? Window'll be cleaned: y/n "<<endl;
        a=cvvod();
        fflush(stdin);
        if (a=='n') break;
        clrscr();
 }

       cout<<"Press any key for closing program...";
        //fflush(stdin);
        getch();
        return 0;
}

void svvod(char* s)
        {
                int i=0;
                do
                        {
                         s[i]=getch();
                         if (s[i]!='1' && s[i]!='0' && s[i]!=' ') continue;
                         cout<<s[i];
                         i++;
                        }
                while (s[i]!=';');
                cout<<endl;
                fflush(stdin);
        }

char cvvod()
        {
         char a;
         while (true)
                        {
                         a=getch();
                         if (a!='y' && a!='n')
                                {
                                 cout<<"Invalid value."<<endl;
                                 continue;
                                }
                         break;
                        }
         fflush(stdin);
         return a;
        }





//---------------------------------------------------------------------------
