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
struct Spis2
        {
                int info;
                Spis2 *next, *prev;
        } *begin, *end, *t, *begin2, *end2;



void Create_Spis2(Spis2**, Spis2**, int);
void Add_Spis2(int, Spis2**, Spis2**, int);
void View_Spis2(int, Spis2*);
void Del_All(Spis2**);


//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Edit1->Text="10";
 StringGrid1->ColCount=10;
 RadioGroup1->ItemIndex=0;
 Memo1->Clear();
 for(int i=1;i<=StrToInt(Edit1->Text);i++) StringGrid1->Cells[i][0]=i;
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
//---------------Очиcтить списки------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
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
        int i,max;

        for(i=1;i<StringGrid1->ColCount;i++)
                {
                if (StringGrid1->Cells[i][1]=="")
                        {
                         ShowMessage("Введите значения");
                         return;
                        }
                }


        int *a = new int [StringGrid1->ColCount];
        max=StrToInt(StringGrid1->Cells[1][1]);
        t=begin;
        Create_Spis2(&begin, &end, StrToInt(StringGrid1->Cells[1][1]));
        a[1]=StrToInt(StringGrid1->Cells[1][1]);
        for(i=2;i<StringGrid1->ColCount;i++)
                {
                 Add_Spis2(RadioGroup1->ItemIndex, &begin, &end, StrToInt(StringGrid1->Cells[i][1]));
                 a[i]=StrToInt(StringGrid1->Cells[i][1]);
                 if (a[i]>max) max=a[i];
                }
                

        Form1->Memo1->Lines->Add("\nMax="+IntToStr(max)+"\n");

        if (a[1]==max)
                {
                 ShowMessage("Максимальное стоит первым!");
                 if(begin != NULL) Del_All(&begin);
                 if(begin2 != NULL) Del_All(&begin2);
                 return;
                }

        Create_Spis2(&begin2, &end2, StrToInt(StringGrid1->Cells[1][1]));
        StringGrid1->Cells[1][2]=a[1];
        i=2;
        while(a[i]!=max)
                {
                 Add_Spis2(RadioGroup1->ItemIndex, &begin2, &end2, a[i]);
                 StringGrid1->Cells[i][2]=a[i];
                 i++;
                }
       Form1->Memo1->Lines->Add("Spis 1:\n");
       View_Spis2(0, begin);
       Form1->Memo1->Lines->Add("Spis 2:\n");
       View_Spis2(0, begin2);



        delete []a;
        if(begin != NULL) Del_All(&begin);
        if(begin2 != NULL) Del_All(&begin2);

}
//-----Добавим в список----------------------------------------------------------------------
void Add_Spis2(int kod, Spis2 **b, Spis2 **e, int in)  {
        t = new Spis2;
        t -> info = in;
        if(kod == 0){
                t -> prev = NULL;
                t -> next = *b;
                (*b) -> prev = t;
                *b = t;
        }
	        else {
                t -> next = NULL;
                t -> prev = *e;
                (*e) -> next = t;
                *e = t;
        }
}
//---------Просмотрим список------------------------------------------------------------------
void View_Spis2(int kod, Spis2 *t)  {
        while(t != NULL) {
                Form1->Memo1->Lines->Add(t->info);
                if(kod == 0) t = t->next;
                else  t = t->prev;
        }
}

//----------Создадим список-----------------------------------------------------------------
void Create_Spis2(Spis2 **b, Spis2 **e, int in)  {
        	t = new Spis2;
        	t -> info = in;
        	t -> next = t -> prev = NULL;
		*b = *e = t;
}

//------------Удалим список---------------------------------------------------------------
void Del_All(Spis2 **p)
{
while(*p != NULL)
        {
        t = *p;
        *p = (*p) -> next;
        delete t;
        }       
}
//---------------Рандом------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 randomize();
 for (int i=1;i<=StringGrid1->ColCount;i++)
        StringGrid1->Cells[i][1]=random(101)-50;
}
//--------------Проверка чисел-------------------------------------------------------------

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
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8) if ((Key < '0') || (Key > '9')) Key = NULL;

}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button7Click(TObject *Sender)
{

 int i, *a;
 for(i=1;i<StringGrid1->ColCount;i++)
        {
         if (StringGrid1->Cells[i][1]=="")
                {
                 ShowMessage("Введите значения");
                 return;
                }
        }
 a = new int[StringGrid1->ColCount];
 for(i=1;i<StringGrid1->ColCount;i++)
        {
         a[i]=StrToInt(StringGrid1->Cells[i][1]);
         StringGrid1->Cells[i][1]="";
         StringGrid1->Cells[i][2]="";
        }

 StringGrid1->ColCount++;
 for(i=2;i<StringGrid1->ColCount;i++)
        {
         StringGrid1->Cells[i][1]=a[i-1];
        }
 delete []a;
 StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount-1;
 Edit1->Text=StrToInt(Edit1->Text)+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 StringGrid1->ColCount++;
 StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount-1;
 Edit1->Text=StrToInt(Edit1->Text)+1;
}
//---------------------------------------------------------------------------


