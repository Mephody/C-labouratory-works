//---------------------------------------------------------------------------
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

int vvod();
void obrabotchick(int**, int*, int, int);
void ran( int**, int, int);
char cvvod();


#pragma argsused
int main(int argc, char* argv[])
{int **massiv, *vector, l=1, i, j, kod, n, m;
 char a, s[100];

while (l!=0)
        {

                cout<<"Hello. Program number 2. This program displays lines sorted descendingly. All numbers are integer."<<endl;
                //������ ������ �������
                kod=1;
                while (kod!=0)
                        {
                         cout<<"Enter the number of strings (N) (size>=2): ";
                         n=vvod();
                         cout<<"Enter the number of column(M) (size>=2): ";
                         m=vvod();
                         if (n<2 || m<2)
                                 {
                                  cout<<"Invalid value."<<endl;
                                  continue;
                                 }
                         kod=0;
                        }

                //������������� ���������� ������� � ���������� ��� ��������� ���������� �������
                kod=1;
                cout<<"Do you want to enter the data array from the keyboard? Otherwise the array will be filled with random numbers from -10 to 10. y/n :"<<endl;
                a=cvvod();

                //�������� ������������� �������
                massiv=new int *[n];
                for(i=0;i<n;i++) massiv[i]=new int[m];
                vector=new int [n];



                //��������� ������
                switch(a)
                        {
                         case 'y':
                                  cout<<"Enter the data of array:"<<endl;
                                  

                                  for(i=0;i<n;i++)
                                        {
                                         for(j=0;j<m;j++)
                                                {
                                                 cout<<"a["<<i<<"]["<<j<<"]=";
                                                 massiv[i][j]=vvod();
                                                 //cout<<b[i][j]<<endl;
                                                }
                                        }

                                  cout<<"Matrix: "<<endl;
                                  for(i=0;i<n;i++)
                                        {
                                         for(j=0;j<m;j++)
                                                 cout<<massiv[i][j]<<"\t";
                                         cout<<endl;
                                        }
                                  break;

                         case 'n': ran(massiv,n,m);
                                   break;

                        }

                //������������ ������
                obrabotchick(massiv,vector,n,m);

                //�������� ������������� �������
                for(i=0;i<n;i++)
                        delete []massiv[i];
                delete []massiv;
                delete []vector;

                //��������� ������������� ���������� ���������
                kod=1;
                cout<<"Do you want to exit? Otherwise program'll be repeated."<<endl;
                a=cvvod();
                if (a=='y') break;

                cout<<"Press any key for clear the window and continue.";
                getch();
                clrscr();
        }        


        cout<<"Press any key to exit the program...";
        getch();
        return 0;
}

//---------------------------------------------------------------------------

int vvod()
        {int i,n;
         char s[100];

                while(true)
                        {
                                gets(s);

                                i=0;
                                while (i<=strlen(s)-1)
                                        {
                                        //cout<<s[i];
                                        //���������, �������� �� ������ ������
                                        if (s[i]<'0' || s[i]>'9' && s[i]!='-')
                                                {
                                                 cout<<"Invalid value. Enter the correct value."<<endl;
                                                 break;
                                                }
                                        i++;
                                        }
                                if (i==strlen(s)) break;
                        }
         n=atoi(s);
         return n;
        }


char cvvod()
        { char a;
          int kod=1;
                while (kod!=0)
                        {
                         a=getch();
                         if (a!='y' && a!='n')
                                {
                                 cout<<"Invalid value."<<endl;
                                 continue;
                                }
                         kod=0;
                        }
          return a;
        }

void ran( int** massiv1, int n, int m)
        {
         int i,j;
         randomize();
         cout<<"Matrix: "<<endl;

         for(i=0;i<n;i++)
                {
                        for(j=0;j<m;j++)
                        {
                         massiv1[i][j]=random(21)-10;
                         cout<<massiv1[i][j]<<"\t";
                        }
                 cout<<endl;
                }
         
        }






void obrabotchick(int **massiv,int *vector,int n, int m)
        {
         int i,j;
         vector=new int [n];
         for(i=0;i<n;i++)
                {
                        for(j=0;j<m-1;j++)
                        {
                         if (massiv[i][j]>massiv[i][j+1]) vector[i]=1;
                         else
                                {
                                 vector[i]=0;
                                 break;
                                }
                        }
                }

         cout<<"Vector : "<<endl;
         for(i=0;i<n;i++) cout<<vector[i]<<endl;
         delete []vector;
        }

