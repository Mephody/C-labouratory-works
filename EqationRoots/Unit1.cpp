//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
typedef double (*type_f)(double);

double function1(double);
double function2(double);
double function3(double);

double MetodVegsteyna(type_f, double, double);
double Metod_Del_2(type_f, double, double);
typedef double (*met)(type_f, double, double);

int i;
double a,b,eps,h;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if (Edit1->Text=="" || Edit2->Text=="" || Edit3->Text=="" || Edit4->Text=="")
                {
                ShowMessage("Данные не заполнены!");
                return;
                }


        double x, y, r, xn, xk;
	int nom1=0, nom2=0;
        met metod;
        type_f f;

	a = StrToFloat(Edit1->Text);
        b = StrToFloat(Edit2->Text);
	eps = StrToFloat(Edit3->Text);     
	h = StrToFloat(Edit4->Text);

        if(b<=a)
                {
                 ShowMessage("A>=B!");
                 return;
                }





switch(RadioGroup1->ItemIndex)
        {
         case 0:
                f=&function1;
                Memo1->Lines->Add("Функция x - 5*sin(x)*sin(x)-5");
                break;
         case 1:
                f=&function2;
                Memo1->Lines->Add("Функция x*x*x - 10*x*x - 50");
                break;
         case 2:
                f=&function3;
                Memo1->Lines->Add("Функция sin(x)*sin(x) - 3*cos(x)");
                break;
        }

switch(RadioGroup2->ItemIndex)
        {
        case 0:
                metod=&MetodVegsteyna;
                Memo1->Lines->Add("Метод Вегстейна");
                break;
        case 1:
                metod=&Metod_Del_2;
                Memo1->Lines->Add("Метод деления пополам");
                break;
        }

	Chart1->Series[0]->Clear();
        for(x = a-h; x< b+h; x+=h)
			Chart1->Series[0]->AddXY(x,f(x));




Memo1->Lines->Add("------ Корни ------");
for(x = a; x<=b; x+=h)
        {
         if(f(x)*f(x+h)<0)
                {
                        nom1++;
                        i=0;
                        y = metod(f,x,x+h);
                        Memo1->Lines->Add(IntToStr(nom1)+"-й = "+FloatToStrF(y,ffFixed,8,6)+" Количество итераций: "+IntToStr(i));

                }

         if(fabs(f(x))<eps && f(x)*f(x+h)>=0) xn=x;
         if(fabs(f(x))>eps && xk==0 && xn!=0)
                {
                        nom2++;
                        i=0;
                        Memo1->Lines->Add(IntToStr(nom2)+"-й интервал особых корней: "+FloatToStr(xn)+"    "+FloatToStr(xk));
                        xn=0;
                        xk=0;

                }

        }




        if(nom1==0) Memo1->Lines->Add("На отрезке простых корней НЕТ!");
        if(nom2==0) Memo1->Lines->Add("На отрезке особых корней НЕТ!");
        Memo1->Lines->Add("");


}
//---------------------------------------------------------------------------
double MetodVegsteyna(type_f p,double x0,double x1)
{
    double y0,y1,x2,de;
        y0=p(x0);
        y1=p(x1);

        do
        {

                x2=x1-y1*(x1-x0)/(y1-y0);
                de=fabs(x1-x2);
                x0=x1;
                x1=x2;
                y0=y1;
                y1=p(x2);
                i++;
                if (i>200) break;
        }   while (de>eps);

    return x2;
}


double Metod_Del_2(type_f p,double x0,double x1)
{
    double x2,y0,y2;
    y0=p(x0);
    do
    {
	x2=(x0+x1)/2;
        y2=p(x2);
	if(y0*y2 > 0)
                {
                 x0 = x2;
                 y0 = y2;
	        }
	else x1 = x2;
        i++;
        if(i>200) break;
    }
    while (fabs(x1-x0)>eps);
    return (x0+x1)/2;
}




double function1(double x)
{
        return x - 5*sin(x)*sin(x)-5;
}

double function2(double x)
{
        return x*x*x + 10*x*x - 50;
}

double function3(double x)
{
        return sin(x)*sin(x) - 3*cos(x);
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 RadioGroup1->ItemIndex=0;
 RadioGroup2->ItemIndex=0;
 Memo1->Lines->Clear();
 Edit1->Text=3;
 Edit2->Text=9;
 Edit3->Text=0.001;
 Edit4->Text=0.001;
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Memo1->Lines->Clear();
 Chart1->Series[0]->Clear();
 Edit1->Text="";
 Edit2->Text="";
 Edit3->Text="";
 Edit4->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Edit1->Text=3;
 Edit2->Text=9;
 Edit3->Text=0.001;
 Edit4->Text=0.001;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Edit1->Text=-7;
 Edit2->Text=3;
 Edit3->Text=0.001;
 Edit4->Text=0.001;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 Edit1->Text=-12;
 Edit2->Text=5;
 Edit3->Text=0.001;
 Edit4->Text=0.001;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
 switch(RadioGroup1->ItemIndex)
        {
         case 0:
                Edit1->Text=3;
                Edit2->Text=9;

                break;
         case 1:
                Edit1->Text=-7;
                Edit2->Text=3;

                break;
         case 2:
                Edit1->Text=-12;
                Edit2->Text=5;

                break;
        }
}
//---------------------------------------------------------------------------

