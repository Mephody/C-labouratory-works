//---------------------------------------------------------------------------
#include <math.h>
#include <stdlib.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct Stack
{
	char info;
        Stack *next;
} *begin;

int Prior (char);
Stack* InStack( Stack*,char);
Stack* OutStack( Stack*,char*);
double Rezult(String);
double mas[201];   				// Массив для вычисления
Set  <char, 0, 255> znak;			// Множество символов-знаков
int Kol = 8;
        
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  StringGrid1->ColCount=2;
  Edit1->Text = "a+b*(c-d)/e";
  Edit2->Text = "";
  Memo1->Lines->Clear();
  StringGrid1->Cells[0][0] ="Имя"; StringGrid1->Cells[1][0] ="Значение";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if (Edit1->Text=="")
                {
                 Memo1->Lines->Add("Данные не заполнены!");
                 return;
                }
	Stack *t;
	begin = NULL; 		                	// Стек операций пуст
	char ss, a;
        String InStr, OutStr; 			// Входная и выходная строки
        OutStr = "";  Edit2->Text = "";
        InStr = Edit1->Text;
        int kol1=0, kol2=0, kol3=0, kol4=0;
        for(int i=1;i<= InStr.Length();i++)
                {
                 if (InStr[i]=='(') kol1++;
                 if (InStr[i]==')') kol2++;
                 if (InStr[i]>='a' && InStr<='z') kol3++;
                 if (InStr.Length()-i>1)
                        {
                        if (InStr[i]=='('&& (InStr[i+1]=='+' || InStr[i+1]=='-' || InStr[i+1]=='*' || InStr[i+1]=='/' || InStr[i+1]=='^'))
                                {
                                Memo1->Lines->Add("Баланс знаков нарушен!");
                                return;
                                }

                        if (InStr[i+1]==')' && (InStr[i]=='+' || InStr[i]=='-' || InStr[i]=='*' || InStr[i]=='/' || InStr[i]=='^'))
                                {
                                Memo1->Lines->Add("Баланс знаков нарушен!");
                                return;
                                }
                        }
                 switch(InStr[i])
                        {
                         case '^': case '*': 	case '/': case '-': 	case '+': kol4++;
                        }
                 if (kol2>kol1)
                        {
                         Memo1->Lines->Add("Баланс скобок нарушен!");
                         return;
                        }
                }
                if (kol2!=kol1)
                        {
                         Memo1->Lines->Add("Баланс скобок нарушен!");
                         return;
                        }
                if (kol4+1!=kol3)
                        {
                         Memo1->Lines->Add("Ошибка в количестве знаков или переменных!");
                         return;
                        }


        znak << '*' << '/' << '+' << '-' << '^';
	int len = InStr.Length(), k;
	for (k = 1; k <= len; k++)
                {
		ss = InStr[k];
// Открывающую скобку записываем в стек
		if ( ss == '(' ) begin = InStack(begin, ss);
		if ( ss == ')' )
                        {
// Выталкиваем из стека все знаки операций до открывающей скобки
                        while ( (begin -> info) != '(' )
                                {
                                begin = OutStack(begin,&a);	// Считываем элемент из стека
                                OutStr += a;      			// Записываем в строку
                                }
                        begin = OutStack(begin,&a);	// Удаляем из стека '(' скобку
	                }
// Букву (операнд) заносим в выходную строку
	        if (ss >=  'a' && ss <= 'z' )  OutStr += ss;
/* Если знак операции, то переписываем из стека в выходную строку все опе-ра-ции с большим или равным приоритетом */
                if (znak.Contains(ss))
                        {
                        while ( begin != NULL && Prior (begin -> info) >= Prior (ss) )
                                {
                                begin = OutStack(begin, &a);
                                OutStr += a;
                                }
                        begin = InStack(begin, ss);
                        }
                }
// Если стек не пуст, переписываем все операции в выходную строку
	while ( begin != NULL)
        {
                begin = OutStack(begin, &a);
                OutStr += a;
        }
  Edit2->Text = OutStr;		// Выводим полученную строку
}
        

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
char ch;
if (Edit2->Text=="")
        {
         Memo1->Lines->Add("Данные не заполнены!");
         return;
        }
for(int i=1;i<StringGrid1->RowCount;i++)
         if (StringGrid1->Cells[1][i]=="")
                {
                 Memo1->Lines->Add("Данные не заполнены!");
                 return;
                }


String OutStr = Edit2->Text;


for (int i=1; i<StringGrid1->RowCount; i++) {
        ch = StringGrid1->Cells[0][i][1];
        mas[int(ch)]=StrToFloat(StringGrid1->Cells[1][i]);
}
Edit3->Text=FloatToStr(Rezult(OutStr));

}
//---------------------------------------------------------------------------
int Prior ( char a ){
	switch ( a ) {
                case '^': 			return 4;
                case '*': 	case '/': 	return 3;
                case '-': 	case '+': 	return 2;
                case '(': 			return 1;
}
	return 0;
}
double Rezult(String Str) {
   char ch, ch1, ch2;
   double op1, op2, rez;
   znak << '*' << '/' << '+' << '-' << '^';
   char chr = 'z'+1;
   for (int i=1; i <= Str.Length(); i++){
     	ch=Str[i];
     	if (! znak.Contains(ch)) begin = InStack(begin, ch);
     	else {
        		begin = OutStack(begin,&ch1);
        		begin = OutStack(begin,&ch2);
        		op1 = mas[int (ch1)];
        		op2 = mas[int (ch2)];
        		switch (ch){
                		case '+' : 	rez=op2+op1;  		break;
                		case '-' : 	rez=op2-op1;  		break;
                		case '*' : 	rez=op2*op1;  		break;
                		case '/' : 	rez=op2/op1;   		break;
                		case '^' : 	rez=pow(op2,op1); 	break;
        		}
        	mas[int (chr)] = rez;
        	begin = InStack(begin,chr);
        	chr++;
     	}
   }
   return rez;
}

Stack* OutStack(Stack* p, char *out)
{
        Stack *t = p;
        *out = p -> info;
        p = p -> next;
        delete t;
        return p;
}

Stack* InStack(Stack *p, char in)
{
        Stack *t = new Stack;
	t -> info = in;
        t -> next = p;
        return t;
}


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 String str=Edit1->Text;
 for(int i=1;i<StringGrid1->RowCount;i++)
        StringGrid1->Cells[1][i]=="";
 char s[80];
 strcpy(s, str.c_str());
 int k=1;
 for(int i=0;i<str.Length();i++)
        {
         if(s[i]>='a' && s[i]<='z')
                {
                 StringGrid1->Cells[0][k]=s[i];
                 k++;
                }
        }

 StringGrid1->RowCount=k;
 
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
 Key=NULL;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
 randomize();
 for(int i = 1; i<StringGrid1->RowCount; i++)
        StringGrid1->Cells[1][i] = random(20);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Memo1->Lines->Clear();
 Edit1->Text="";
 Edit2->Text="";
 Edit3->Text="";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Close();       
}
//---------------------------------------------------------------------------

