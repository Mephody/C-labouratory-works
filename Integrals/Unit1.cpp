//---------------------------------------------------------------------------
#include<math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
typedef double (*type_f)(double);
typedef double (*met)(type_f, int);

double fun1(double);
double fun2(double);
double fun3(double);

double Simps(type_f, int);
double Srednih(type_f, int);
double Trapecii(type_f, int);

double a, b, eps;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
double x, h, Int1, Int2, pogr;
int n, n1;
a = StrToFloat(Edit1->Text);
b = StrToFloat(Edit2->Text);
eps = StrToFloat(Edit3->Text);
n = StrToInt(Edit4->Text);
h = (b - a)/100;
type_f f;
met metod;

switch(RadioGroup1->ItemIndex)
        {
         case 0:
                f=fun1;
                Memo1->Lines->Add("Функция 4x-7sinx");
                break;
         case 1:
                f=fun2;
                Memo1->Lines->Add("Функция x*x-10sinx*sinx");
                break;
         case 2:
                f=fun3;
                Memo1->Lines->Add("Функция lnx-5cosx");
                break;
        }

TChart->Series[0]->Clear();
for(x = a-h; x< b+h; x+=h)
                TChart->Series[0]->AddXY(x,f(x));

switch(RadioGroup2->ItemIndex)
        {
         case 0:
                metod=Srednih;
                break;

         case 1:
                metod=Trapecii;
                break;

         case 2:
                metod=Simps;
                break;
        }

switch(RadioGroup3->ItemIndex)
        {
        case 0:
                Memo1->Lines->Add("Расчет по разбиению на n = " + IntToStr(n));
                Int1 = metod(f,n);
        break;

        case 1:
                n1=2;

                Memo1->Lines->Add("Расчет по точности eps");
                Int1 = metod(f,n1);
                do
                {
                        Memo1->Lines->Add("При n = " +IntToStr(n1));
                        Memo1->Lines->Add(" Значение интеграла: "+FloatToStr(Int1));
                        n1*=2;
                        Int2 = metod(f,n1);
                        pogr = fabs(Int2-Int1);
                        Int1 = Int2;
                        
                }
                while(pogr > eps);
                Memo1->Lines->Add("При n = " +IntToStr(n1));
                Memo1->Lines->Add(" Значение интеграла: "+FloatToStr(Int1));

        break;
        }

    Memo1->Lines->Add("Значение интеграла = " + FloatToStr(Int1/*,ffFixed,8,6*/));

}
//---------------------------------------------------------------------------
double Simps(type_f p, int n)
{
    double s=0,h,x;
    h=(b-a)/n;
    x=a;
    for(int i=1; i<=n; i++)
        {
    	s=s+p(x)+4*p(x+h/2)+p(x+h);
    	x+=h;
        }
    return s*h/6;
}

double Srednih(type_f p, int n)
{
 double s=0, h, x;
 h=(b-a)/n;
 x=a+h/2;
 for(int i=1; i<=n; i++)
        {
         s+=p(x);
         x+=h;
        }
 return s*h;
}

double Trapecii(type_f p, int n)
{
 double s=0, h, x;
 h=(b-a)/n;
 x=a;
 for(int i=1; i<=n; i++)
        {
         s+=p(x)+p(x+h);

         x+=h;
        }
 return s*h/2;
}

double fun1(double x)
{
   return 4*x - 7*sin(x);
}

double fun2(double x)
{
   return x*x-10*sin(x)*sin(x);
}

double fun3(double x)
{
   return log(x)-5*cos(x);
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Memo1->Lines->Clear();
 Edit1->Text=-2;
 Edit2->Text=3;
 Edit3->Text=0.001;
 Edit4->Text=100;
 RadioGroup1->ItemIndex=0;
 RadioGroup2->ItemIndex=0;
 RadioGroup3->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Edit1->Text=-2;
 Edit2->Text=3;
 Edit3->Text=0.001;
 Edit4->Text=100;
 RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Edit1->Text=0;
 Edit2->Text=3;
 Edit3->Text=0.001;
 Edit4->Text=100;
 RadioGroup1->ItemIndex=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Edit1->Text=1;
 Edit2->Text=8;
 Edit3->Text=0.001;
 Edit4->Text=100;
 RadioGroup1->ItemIndex=2;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
 switch(RadioGroup1->ItemIndex)
        {
         case 0:
                Edit1->Text=-2;
                Edit2->Text=3;

                break;
         case 1:
                Edit1->Text=0;
                Edit2->Text=3;

                break;
         case 2:
                Edit1->Text=1;
                Edit2->Text=8;

                break;
        }
}
//---------------------------------------------------------------------------

