//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
struct Stack
        {
                int info;
                Stack * next;
        } *begin, *t, *begin2;

int k;

Stack* InStack(Stack*, int);
void Del_All(Stack **);

void View(Stack *p)
        {
        Stack *t = p;
        while( t != NULL)
                {
                Form1->Memo1->Lines->Add(IntToStr(t->info));
                t = t -> next;
                }
	}




void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8) if ((Key < '0') || (Key > '9')) Key = NULL;

}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Edit1->Text="10";
 StringGrid1->ColCount=11;
 Memo1->Clear();
 k=StrToInt(Edit1->Text)+1;
 for(int i=1;i<=StrToInt(Edit1->Text)+1;i++) StringGrid1->Cells[i][0]=i;
 StringGrid1->Cells[0][1]=1;
 StringGrid1->Cells[0][2]=2;

}



//------------------Очистить всё---------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        for (int i=1;i<=StringGrid1->ColCount;i++)
                {

                StringGrid1->Cells[i][1]="";
                StringGrid1->Cells[i][2]="";

                }
        Form1->Memo1->Clear();
        if(begin != NULL) Del_All(&begin);
        if(begin2 != NULL) Del_All(&begin2);
        ShowMessage("Память освобождена!");

}
//-------------------Выход--------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Close();
}
//------------Индивид задание---------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{

        if((begin != NULL) || (begin2 != NULL))
                {
                ShowMessage("Освободите память!");
                return;
                }

        for(int i=1;i<=StringGrid1->ColCount;i++)
                if (StringGrid1->Cells[i][1]=="")
                        {
                         ShowMessage("Введите данные!");
                         return;
                        };
        int i,max;

        //for(i=1;i<=StringGrid1->ColCount-1;i++)


        int *a = new int [StringGrid1->ColCount-1];
        max=StrToInt(StringGrid1->Cells[1][1]);
        t=begin;
        for(i=1;i<StringGrid1->ColCount;i++)
                {
                 begin=InStack(begin, StrToInt(StringGrid1->Cells[i][1]));
                 a[i]=StrToInt(StringGrid1->Cells[i][1]);
                 if (a[i]>max) max=a[i];
                }

        Form1->Memo1->Lines->Add("Stek 1:\n");
        View(begin);
        Form1->Memo1->Lines->Add("\nMax="+IntToStr(max)+"\n");

        i=1;
        while(a[i]!=max)
                {
                 begin2=InStack(begin2, a[i]);
                 StringGrid1->Cells[i][2]=a[i];
                 i++;
                }
       Form1->Memo1->Lines->Add("Stek 2:\n");
       View(begin2);



        delete []a;
        //if(begin != NULL) Del_All(&begin);
        //if(begin2 != NULL) Del_All(&begin2);

}
//---------------------------------------------------------------------------
Stack* InStack(Stack *p, int in)
{
        Stack *t = new Stack;

        t -> info = in;
        t -> next = p;
        return t;
}

//---------------------------------------------------------------------------
void Del_All(Stack **p)
{
        while(*p != NULL)
                {
                t = *p;
                *p = (*p) -> next;
                delete t;
                }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 randomize();
 for (int i=1;i<=StringGrid1->ColCount;i++)
        StringGrid1->Cells[i][1]=random(101)-50;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
  if (Key!=8) if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{

 if (Edit1->Text=="" || Edit1->Text=='0' || Edit1->Text=='1') return;
        else StringGrid1->ColCount=StrToInt(Edit1->Text)+1;

 for(int i=1;i<=StrToInt(Edit1->Text)+1;i++) StringGrid1->Cells[i][0]=i;



 }
//---------------Очичтить стэки------------------------------------------------------------





void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(begin != NULL) Del_All(&begin);
 if(begin2 != NULL) Del_All(&begin2);
 ShowMessage("Память освобождена!");
}
//-----------Инфо----------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 ShowMessage("Программа формирует 2 стэка: 1-полный список данных из строки, 2-список от вершины до максиимального");
}
//-----------Стек 1----------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 Form1->Memo1->Lines->Add("Stek 1:");
 if (begin!=NULL) View(begin);
        else ShowMessage("Стек пуст");
}
//----------Стек 2-----------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  Form1->Memo1->Lines->Add("Stek 2:");
  if (begin2!=NULL) View(begin2);
        else ShowMessage("Стек пуст");
}
//-------------Очитсить мемо--------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
 Form1->Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{

        for(int i=1;i<=StringGrid1->ColCount;i++)
                if (StringGrid1->Cells[i][1]=="")
                        {
                         ShowMessage("Введите данные!");
                         return;
                        };

        if((begin != NULL))
                {
                ShowMessage("Освободите память!");
                return;
                }

        double *a = new double [StringGrid1->ColCount];
        int i, index;
        for(i=1;i<StringGrid1->ColCount;i++)
                {
                 a[i]=StrToInt(StringGrid1->Cells[i][1]);
                 begin=InStack(begin, a[i]);
                }
        double q;
        int min;




        /*
        int *a, i=0;
        a=new int [n];
        t=begin;
        while(t!=NULL)
        {
         t=OutStack(t, a[i]);
         t=t->next;
         i++;
        }
        */





        for(i=1;i<StringGrid1->ColCount-1;i++)
        {
                 min  = i;
                 for(k=i+1;k<StringGrid1->ColCount;k++)
                        if (a[k]<a[min])
                                min = k;
                 q = a[i];
                 a[i] = a[min];
                 a[min] = q;
        }
                for(i=1;i<StringGrid1->ColCount;i++)
                        {
                         StringGrid1->Cells[i][2]=a[i];
                         begin2=InStack(begin2, a[i]);
                        }
        delete []a;
        //if(begin != NULL) Del_All(&begin);
        //if(begin2 != NULL) Del_All(&begin2);
}
//---------------------------------------------------------------------------

