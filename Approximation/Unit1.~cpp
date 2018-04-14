//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double fun1(double);
double fun2(double);
double fun3(double);

typedef double (*TFun)(double);

double Mn_Lagr(double*,double,int, TFun);
double Lin_Inter(double*,double,int, TFun);
double Kvadr_Inter(double*,double,int, TFun);


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Edit1->Text="-2";
 Edit2->Text="5";
 Edit3->Text="5";
 Edit4->Text="5";

 StringGrid1->Cells[0][2]="Линейная";
 StringGrid1->Cells[0][3]="Квадратичная";
 StringGrid1->Cells[0][1]="Лагранджа";

 RadioGroup1->ItemIndex=0;

 Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 double x,h,h1, a, b, *mas_x, **mas_y_t, mas_p[3], t;
 int i,n,m;
 TFun fun;

 if ( Edit1->Text=="" || Edit2->Text=="" || Edit3->Text=="" || Edit4->Text=="")
        {
         Memo1->Lines->Add("Заполните данные!");
         return;
        }

 a = StrToFloat(Edit1->Text);
 b = StrToFloat(Edit2->Text);

 Memo1->Lines->Clear();
 if (a>b)
        {
         Memo1->Lines->Add("Интервал введён некорректно и будет атоматически перевёрнут!");
         i=a;
         a=b;
         b=i;
         Edit1->Text=a;
         Edit1->Text=b;
        }
 if (a==b)
        {
         Memo1->Lines->Add("Интервал введён некорректно! А должно быть отлично от B. Программа остановлена.");
         return;
        }

 m = StrToInt(Edit3->Text);
 n = StrToInt(Edit4->Text);

 if (m>n)
        {
         Memo1->Lines->Add("Некоректные значения M и N! (M<N)");
         return;
        }

 StringGrid1->ColCount=n+1;
 StringGrid1->RowCount=4;
 for(i=1;i<=n;i++)
        StringGrid1->Cells[i][0]=i;

 switch(RadioGroup1->ItemIndex)
        {
         case 0:
                fun=fun1;
                Memo1->Lines->Add("Функция x^3-5*x^2");
                break;
         case 1:
                fun=fun2;
                Memo1->Lines->Add("Функция x*x-10*(sin(x))^2");
                break;
         case 2:
                fun=fun3;
                Memo1->Lines->Add("Функция ln(x)-5*cos(x)");
                break;
        }

 h = (b-a)/(m-1);
 h1 = (b-a)/(n-1);

 mas_x = new double[m+1];
 mas_y_t = new double* [n+1];

 for(i=0;i<n+1;i++)
        mas_y_t[i]=new double [3];

 for(x=a, i=0; i<m; i++)
        {
         mas_x[i] = x;
         x+=h;
        }

 for(i=0;i<4;i++)
        Chart1->Series[i]->Clear();

 for(x=a-0.1; x<b+0.1; x+=0.01)
        Chart1->Series[0]->AddXY(x,fun(x));
 for(int j=0;j<3; j++)
        mas_p[j]=0;
 for(x=a, i=0; i<n; i++, x+=h1)
        {

         mas_y_t[i][0] = Mn_Lagr(mas_x,x,m,fun);
         mas_y_t[i][1] = Lin_Inter(mas_x,x,m,fun);
         mas_y_t[i][2] = Kvadr_Inter(mas_x,x,m,fun);

         for(int j=1;j<=3; j++)
                {
                 Chart1->Series[j]->AddXY(x,mas_y_t[i][j-1]);
                 StringGrid1->Cells[i+1][j]=FloatToStrF(mas_y_t[i][j-1],ffFixed,8,2);
                 t=fabs(mas_y_t[i][j-1]-fun(x));
                 if (t>mas_p[j-1]) mas_p[j-1]=t;
                }
        }

 Memo1->Lines->Add("Максимальн погрешность (Лагранжа): "+FloatToStrF(mas_p[0],ffFixed,8,4));
 Memo1->Lines->Add("Максимальн погрешность (Линейная): "+FloatToStrF(mas_p[1],ffFixed,8,4));
 Memo1->Lines->Add("Максимальн погрешность (Квадратичная): "+FloatToStrF(mas_p[2],ffFixed,8,4));


 delete []mas_x;

  for(i=0;i<n+1;i++) delete mas_y_t[i];

 delete []mas_y_t;
}


double fun1(double x)
{
    	return x*x*x-5*x*x;
}

double fun2(double x)
{
        return x*x-10*sin(x)*sin(x);
}
double fun3(double x)
{
        return log(x)-5*cos(x)*cos(x);
}
double Mn_Lagr(double *x, double xt, int kol, TFun fun)
{
	int i, k;
	double e, p=0;
 	for(k=0; k<kol; k++) {
                e=1.;
                for (i=0;i<kol;i++)
                        if (i!=k)    e *= ((xt-x[i])/(x[k]-x[i]));
                p += e*fun(x[k]);
 	}
 return p;
}


double Lin_Inter(double* x,double xt,int kol, TFun fun)
        {
         int i;
         double n1, y, y1;
         for(i=0;i<kol;i++)
                if (x[i]>xt) break;
         if(fabs(x[i]-xt)>fabs(x[i-1]-xt)) i=i-1;

         y=fun(x[i]-1);
         y1=fun(x[i]);
         n1=y+(xt-x[i-1])*(y1-y)/(x[i]-x[i-1]);
         return n1;
        }
double Kvadr_Inter(double*x ,double xt ,int kol, TFun fun)
        {
         int i;
         double n1, n2, y, y1, y2;
         n1=Lin_Inter(x, xt, kol, fun);
         for(i=0;i<kol;i++)
                if (x[i]>xt) break;
         if(fabs(x[i]-xt)>fabs(x[i-1]-xt)) i=i-1;
         y=fun(x[i]-1);
         y1=fun(x[i]);
         y2=fun(x[i]+1);
         n2=n1+(xt-x[i-1])*(xt-x[i])*((y-y1)/(x[i-1]-x[i])-(y1-y2)/(x[i]-x[i+1]))/(x[i-1]-x[i+1]);
         return n2;
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
 int i, j;
 for(i=0;i<4;i++)
        Chart1->Series[i]->Clear();

 for(i=1; i<StringGrid1->ColCount; i++)
        for(j=1;j<=3; j++)
                StringGrid1->Cells[i][j]="";

 Edit1->Text="";
 Edit2->Text="";
 Edit3->Text="";
 Edit4->Text="";


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
 switch(RadioGroup1->ItemIndex)
        {
         case 0:
                Edit1->Text="-2";
                Edit2->Text="5";
                Edit3->Text="5";
                Edit4->Text="10";
                break;
         case 1:
                Edit1->Text="2";
                Edit2->Text="3";
                Edit3->Text="4";
                Edit4->Text="10";
                break;
         case 2:
                Edit1->Text="2";
                Edit2->Text="8";
                Edit3->Text="4";
                Edit4->Text="10";
                break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Close();       
}
//---------------------------------------------------------------------------

