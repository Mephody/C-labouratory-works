//---------------------------------------------------------------------------
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h>
#include <io.h>

#pragma hdrstop
//Zadanie nomer 10
struct TZap
        {
        char FIO[30];
        double s_b;
        int ngr, godr, massotm[3];
        } Zap;
int size = sizeof(TZap);
FILE *Fz, *Ft;

int proverka(char*, int);
TZap structvvod(TZap, int);
void out(TZap);
void shortout(TZap);
void halfofoutfile(TZap);
void halfofout(TZap);
double dvvod();
double ivvod();

char File_Zap[] = "zapisi.dat";
char File_Rez[] = "rezult.txt";
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
 int i, kod=0, len, kol, number, m;
 TZap *mas_Z;
 Ft=fopen(File_Rez, "w");
 while(true)
        {
         puts("Choose operation: \n1-Create new database \n2-Enter the data of student \n3-Individual task (click info for detail information) \n4-Information \n5-Correct the data of students \n6-View the data of students \n7-Delete the data of students \n8-Clean screan \n9-Exit");
         kod=ivvod();
         printf("\n");
         switch(kod)
                {

                case 1: //Create   file
                        if ((Fz=fopen(File_Zap,"wb"))==NULL)
                                        {
                        		        printf("\nCreate ERROR!");
                        		        return 0;
                		        }
            		        fclose(Fz);
            		        printf("New database has been created succecful!\n\n",File_Zap);
                 break;
                 
                  case 2:  //------Vvod
                                Fz = fopen(File_Zap,"ab");
                		Zap=structvvod(Zap, 0);
                                //printf("Name: %s", Zap.FIO);
                                halfofoutfile(Zap);
                		fwrite(&Zap, size, 1, Fz);
                		fclose(Fz);
                 break;

                case 3:  //Zadanie
                                if ((Fz=fopen(File_Zap,"rb"))==NULL)
                                        {
                        		printf("Open ERROR! \n");
                                        getch();
                        		return 0;
                		        }
                                len = filelength(fileno(Fz));
				kol = len/size;
				mas_Z = new TZap[kol];

                                printf("Students, who have scores below 4:\n\n");
                                fprintf(Ft,"----------Students, who have scores below 4:--------------\n\n");
                                m=0;
                                for (i=0; i < kol; i++)
                                        {
                			if (!fread((mas_Z+i), size, 1, Fz)) break;
                                        if (mas_Z[i].massotm[0]<4 || mas_Z[i].massotm[1]<4 || mas_Z[i].massotm[2]<4 || mas_Z[i].massotm[3]<4) out(mas_Z[i]), m++;
                                        }
                                if (m==0) printf("There is no bad students!\n\n"), fprintf(Ft,"There is no bad students!\n\n");
                                delete []mas_Z;
                                fclose(Fz);
                 break;





                 case 4: printf("Info. The Individual task is to show information of students, who have 1 or more marks below 4.\n\n"); break;//Informaciya

                 case 5:  //Korrekciya
                                if ((Fz=fopen(File_Zap,"rb"))==NULL)
                                        {
                        		printf("Open ERROR! \n");
                        		return 0;
                		        }

				len = filelength(fileno(Fz));
				kol = len/size;
                                if (kol==0)
                                        {
                                         printf("There's no students!\n\n");
                                         break;
                                        }
				mas_Z = new TZap[kol];

                                
        			for (i=0; i < kol; i++)
                                        {
                			fread((mas_Z+i), size, 1, Fz);
                                        printf("Number=%i\n",i);
                                        shortout(mas_Z[i]);
                                        }
                                fclose(Fz);
                                
                                while(true)
                                        {
                                        printf("Enter the number of student, whose data you want to change (-1 for exit): ");
                                        
                                        number=ivvod();
                                        if (number>=kol)
                                                {
                                                printf("Wrong number!\n");
                                                continue;
                                                }
                                        if (number<=-1) break;
                                        printf("If you dont want to change one of parameters press - \n\n");
                                        printf("Number=%i\n",number);

                                        mas_Z[number]=structvvod(mas_Z[number], 1);
                                        }
                                Fz=fopen(File_Zap,"w");
                                fprintf(Ft,"--------- Corrected data ---------\n");
                                printf("\n--------- Corrected data ---------\n");
                                for (i=0; i < kol; i++)
                                        fwrite(&mas_Z[i], size, 1, Fz), out(mas_Z[i]);
                                delete []mas_Z;
                		fclose(Fz);
                 break;













                 case 6:   //Prosmotr
                                if ((Fz=fopen(File_Zap,"rb"))==NULL)
                                        {
                        		printf("Open ERROR! \n");
                        		return 0;
                		        }

                		printf("--------- Informations ---------\n");

                		while(true)
                                        {
   	                		 if(!fread(&Zap,size,1,Fz)) break;
                                         halfofout(Zap);
                		        }
                		fclose(Fz);
                 break;









                 case 7:        //Udalit' studenta
                                if ((Fz=fopen(File_Zap,"r+b"))==NULL)
                                        {
                        		printf("Open ERROR! \n");
                        		return 0;
                		        }

				len = filelength(fileno(Fz));
				kol = len/size;
                                if (kol==0)
                                        {
                                         printf("There's no students!\n\n");
                                         break;
                                        }
				mas_Z = new TZap[kol];
                                printf("--------- Informations ---------\n");
        			for (i=0; i < kol; i++)
                                        {
                			fread((mas_Z+i), size, 1, Fz);
                                        printf("Number=%i\n",i);
                                        shortout(mas_Z[i]);
                                        }
                                fclose(Fz);

                                m=kol;
                                while(true)
                                        {
                                        printf("Enter the number of student, whose data you want to delete (-1 for exit): ");
                                        number=ivvod();
                                        if (number>=kol)
                                                {
                                                printf("Wrong number!\n");
                                                continue;
                                                }
                                        if (number<=-1) break;


                                        mas_Z[number].godr=0;
                                        m--;
                                        if (m==0)
                                                {
                                                 printf("There's no students for deleteing!\n\n");
                                                 break;
                                                }
                                        }
                                Fz=fopen(File_Zap,"w");
                                printf("--------- Corrected (Without deleted) data ---------\n");
                                for (i=0; i < kol; i++)
                                        if (mas_Z[i].godr!=0)
                                                {
                                                 fwrite(&mas_Z[i], size, 1, Fz);
                                                 out(mas_Z[i]);
                                                }

                                delete []mas_Z;
                		fclose(Fz);

                                break;


                 case 8: clrscr(); break;



                 case 9://Vihod
                        if ((Fz=fopen(File_Zap,"rb"))==NULL)
                                {
                                printf("Open ERROR! \n");

                                return 0;
                                }


                        fprintf(Ft,"--------- Informations of the whole file ---------\n");

                        while(true)
                                {
                                if(!fread(&Zap,size,1,Fz)) break;
                                halfofoutfile(Zap);
                                }
                        fclose(Fz);
                        return 0;
                 default: printf("Enter the right value!\n");
                }






        }
        fclose(Ft);
        return 0;
        getch();
}

void shortout(TZap a)
        {
         printf(" Name: %s\n Number of the group: %i\n\n",a.FIO, a.ngr);
        }

void out(TZap a)
        {
         printf(" Name: %s\n Number of the group: %i\n Year of birth: %i\n Marks: \n Mathematics: %i\n Physics: %i\n Chemistry %i\n Informatics: %i\n GPA: %f\n\n", a.FIO, a.ngr, a.godr,  a.massotm[0],a.massotm[1],a.massotm[2],a.massotm[3], a.s_b);
         fprintf(Ft, " Name: %s\n Number of the group: %i\n Year of birth: %i\n Marks: \n Mathematics: %i\n Physics: %i\n Chemistry %i\n Informatics: %i\n GPA: %f\n\n", a.FIO, a.ngr, a.godr,  a.massotm[0],a.massotm[1],a.massotm[2],a.massotm[3], a.s_b);
        }

void halfofoutfile(TZap a)
        {
         fprintf(Ft, " Name: %s\n Number of the group: %i\n Year of birth: %i\n Marks: \n Mathematics: %i\n Physics: %i\n Chemistry %i\n Informatics: %i\n GPA: %f\n\n", a.FIO, a.ngr, a.godr,  a.massotm[0],a.massotm[1],a.massotm[2],a.massotm[3], a.s_b);
        }

void halfofout(TZap a)
        {
         printf(" Name: %s\n Number of the group: %i\n Year of birth: %i\n Marks: \n Mathematics: %i\n Physics: %i\n Chemistry %i\n Informatics: %i\n GPA: %f\n\n", a.FIO, a.ngr, a.godr,  a.massotm[0],a.massotm[1],a.massotm[2],a.massotm[3], a.s_b);
        }

TZap structvvod(TZap izn, int x)
        {
         char b[30];
         int c,i;
         double d;
         TZap a;

         printf(" Name: ");
         fflush(stdin);

         gets(b);
         if (b[0]=='-' && x==1) strcpy(a.FIO,izn.FIO);
                else strcpy(a.FIO, b);


         printf(" Number of the group: ");
         c=proverka(b, x);
         if (c==-1) a.ngr=izn.ngr;
                else a.ngr=c;

         printf(" Year of birth: ");
         c=proverka(b, x);
         if (c==-1) a.godr=izn.godr;
                else a.godr=c;

         printf(" Marks: \n");
         for (i=0; i<=3;i++)
                {
                 switch(i)
                        {
                         case 0: printf(" Mathematics: "); break;
                         case 1: printf(" Physics: "); break;
                         case 2: printf(" Chemistry: "); break;
                         case 3: printf(" Informatics: "); break;
                        }
                 c=proverka(b, x);
                 if (c==-1) a.massotm[i]=izn.massotm[i];
                        else a.massotm[i]=c;
                }


         a.s_b=(a.massotm[0]+a.massotm[1]+a.massotm[2]+a.massotm[3]);
         a.s_b=a.s_b/4;


         printf(" GPA: %lf\n\n", a.s_b);
         return a;
        }



int proverka(char* b, int x)
        {
          int i;
          while(true)
                        {
                                gets(b);
                                if (b[0]=='-' && x==1) return -1;
                                i=0;
                                while (i<=strlen(b)-1)
                                        {
                                        //cout<<s[i];
                                        //���������, �������� �� ������ ������
                                        if (b[i]<'0' || b[i]>'9' && b[i]!='-')
                                                {
                                                 printf("Invalid value. Enter the correct value. \n");
                                                 break;
                                                }
                                        i++;
                                        }
                                if (i==strlen(b)) break;
                        }
          return atoi(b);
        }



double ivvod()
        {
         int i,n;
         char s[100];

                while(true)
                        {
                                fflush(stdin);
                                gets(s);

                                i=0;
                                while (i<=strlen(s)-1)
                                        {
                                        //cout<<s[i];
                                        //���������, �������� �� ������ ������
                                        if ((s[i]<'0' || s[i]>'9') && (s[i]!='-'))
                                                {
                                                 printf("Invalid value. Enter the correct value. \n");
                                                 break;
                                                }
                                        i++;
                                        }
                                if (i==strlen(s)) break;
                        }
         n=atoi(s);
         return n;
        }


//---------------------------------------------------------------------------
