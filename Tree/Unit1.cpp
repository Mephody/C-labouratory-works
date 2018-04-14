//---------------------------------------------------------------------------
#include <string.h>
#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


String srandom();
struct TInfo
                        {
                         int key;
                         char text[81];
                        } *mas;
struct Tree {

                TInfo info;
		Tree *left, *right;
	} *root;



//--------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 randomize();
 for (int i=1;i<StringGrid1->ColCount;i++)
        {
         StringGrid1->Cells[i][1]=random(101)-50;
         StringGrid1->Cells[i][2]=srandom();
        }


}
//-------------------chisla/bykvi stringgrid--------------------------------------------------------

int Row=1, Col;
void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{

//---------------------------------------------------------------------------
 if (Row==1) if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
void __fastcall TForm1::StringGrid1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
 Row=ARow;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
 Row=ARow;
 if (ARow==0) return;
 if (ACol==0) return;
}


//-------------------------tolko chisla edit--------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
  if (Key!=8 && Key!='-') if ((Key < '0') || (Key > '9')) Key = NULL;
}

//--------------------edit change-------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 if (Edit1->Text=="" || Edit1->Text=='0' || Edit1->Text=='1') return;
        else
                {
                 StringGrid1->ColCount=StrToInt(Edit1->Text)+1;
                 StringGrid2->ColCount=StrToInt(Edit1->Text)+1;
                }
 
 for(int i=1;i<=StrToInt(Edit1->Text)+1;i++)
        {
         StringGrid1->Cells[i][0]=i;
         StringGrid2->Cells[i][0]=i;
        }
 }




void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Memo1->Lines->Clear();
 
 Edit1->Text=10;
 Edit2->Text="";

 StringGrid1->ColCount=11;
 StringGrid1->RowCount=3;
 StringGrid2->ColCount=11;
 StringGrid2->RowCount=3;

 StringGrid1->Cells[0][0]="�����";
 StringGrid1->Cells[0][1]="����";
 StringGrid1->Cells[0][2]="�����";

 StringGrid2->Cells[0][0]="�����";
 StringGrid2->Cells[0][1]="����";
 StringGrid2->Cells[0][2]="�����";


 for(int i=1;i<=StrToInt(Edit1->Text)+1;i++)
        {
         StringGrid1->Cells[i][0]=i;
         StringGrid2->Cells[i][0]=i;
        }
}
//---------------------------------------------------------------------------



Tree* List(TInfo in)
{
	Tree *t = new Tree;
        t->info=in;
	t -> left = t -> right = NULL;
        return t;
}
//---------------------------------------------------------------------------


void Add_List(Tree *root, TInfo in)
{
 Tree *prev, *t;
 bool find = true;
		t = root;				
		while ( t && find) {
		  	prev = t;
		  	if( in.key == t->info.key) {
                                find = false;
                                ShowMessage("Dublucate Key!");
			}
		   	else
				if ( in.key < t->info.key) t = t -> left;
				else   t = t -> right;
		}
		if (find) {
			t = List(in);
			if ( in.key < prev->info.key ) prev -> left = t;
			else    prev -> right = t;		
		}
}



  //peredelat
void View_Tree(Tree *p, int level )
{
  String str;
  if ( p )
        {
	   	View_Tree (p -> right , level+1);
	   	for ( int i=0; i<level; i++) str = str + "    ";
				Form1->Memo1->Lines->Add(str + IntToStr(p->info.key));

	   	View_Tree(p -> left , level+1);
        }
}


int x=0;
void Kol_Uzlov(Tree *p)
{
if ( p )
        {
        if(p->right==NULL && p->left==NULL) x++;
        Kol_Uzlov(p -> right);
        Kol_Uzlov(p -> left);
        }
}




Tree* Del_Info(Tree *root, int key)  {
	Tree *Del, *Prev_Del, *R, *Prev_R;
// Del, Prev_Del - ��������� ���� � ��� ���������� (������); 
// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ������;
	Del = root; 
	Prev_Del = NULL;
//-------- ����� ���������� �������� � ��� ������ �� ����� key ---------
while (Del != NULL && Del ->info.key != key) {
		Prev_Del = Del;
		if (Del->info.key > key)  Del = Del->left;
			else Del = Del->right;
		}
	if (Del == NULL)	{				// ������� �� ������
   	ShowMessage ( "NOT Key!");
			return root;
	}
//-------------------- ����� �������� R ��� ������ --------------------------------
	if (Del -> right == NULL) R = Del->left;
	else
		if (Del -> left == NULL) R = Del->right;
		else {
//---------------- ���� ����� ������ ���� � ����� ��������� -----------------
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {  
				Prev_R = R;
				R = R->right;
			}
//----------- ����� ������� ��� ������ R � ��� ������ Prev_R -------------
			if( Prev_R == Del)  R->right = Del->right;
			else {		
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
	 }
	if (Del== root) root = R;			// ������ ������, �������� ��� �� R
	else
//------- ��������� R ������������ � ������ ���������� ���� -----------
	if (Del->info.key < Prev_Del->info.key)
			Prev_Del->left = R;				// �� ����� �����
		else	Prev_Del->right = R;				// �� ������ �����
	delete Del;
	return root;
}



void Make_Blns(Tree **p, int n, int k, TInfo *mas)
{
   if (n == k)
        {
         *p = NULL;
         return;
        }
   else
        {
            int m=(n+k)/2;
            *p = new Tree;
            (*p)->info=mas[m];


            Make_Blns( &(*p)->left, n, m, mas);
            Make_Blns( &(*p)->right, m+1, k, mas);
        }
}




void Del_Tree(Tree *t) {
  	if ( t != NULL)  {
    		Del_Tree ( t -> left); 			// �� ����� �����
    		Del_Tree ( t -> right); 			// �� ������ �����
      	delete t;
   	}
}


String srandom()
{
 int k;
 String s;
 for(int j=0; j<3;j++)
                {
                k=random(26);
                s=s+(char)(k+97);
                }
 return s;
}
//----------------------Sozdat derevo------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,k;
 for(i=1;i<StringGrid1->ColCount;i++)
        if (StringGrid1->Cells[i][1]=="" || StringGrid1->Cells[i][2]=="")
                {
                 Memo1->Lines->Add("��������� ������!");
                 MessageBeep(0xFFFFFFFF);
                 return;
                }
 char *b;
  if (root!=NULL)
         {
         Memo1->Lines->Add("���������� ������!");
         MessageBeep(0xFFFFFFFF);
         return;
         }
 mas = new TInfo [StringGrid1->ColCount];
 bool find=true;
 String s="";
 for(i=1;i<StringGrid1->ColCount;i++)
        {
         mas[i].key=StrToInt(StringGrid1->Cells[i][1]);
         strcpy(mas[i].text, StringGrid1->Cells[i][2].c_str());
         for(k=1; k<i;k++)
                {
                 if (mas[i].key==mas[k].key)
                        {
                         s=s+"  "+i;
                         find=false;
                         break;
                        }
                }
        }

 if (!find)
        {

         Memo1->Lines->Add("����� �� ���������! ");
         MessageBeep(0xFFFFFFFF);
         Memo1->Lines->Add("���������� �������� �������� � ��������: ");
         Memo1->Lines->Add(s);
         return;
        }

 root=List(mas[1]);
 for(i=2;i<StringGrid1->ColCount; i++)
        {
         Add_List(root, mas[i]);
        }
 Memo1->Lines->Add("---������---");
 View_Tree(root, 0);

 delete []mas;
}
//--------------------Sbalasir derevo-------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int i, k, min, q;
 int *a;
 char *b;
 if (root!=NULL)
         {
         Memo1->Lines->Add("���������� ������!");
         MessageBeep(0xFFFFFFFF);
         return;
         }
  for(i=1;i<StringGrid1->ColCount;i++)
        if (StringGrid1->Cells[i][1]=="" || StringGrid1->Cells[i][2]=="")
                {
                 Memo1->Lines->Add("��������� ������!");
                 MessageBeep(0xFFFFFFFF);
                 return;
                }
 mas= new TInfo [StringGrid1->ColCount-1];

 bool find=true;
 String s="";
 for(i=0;i<StringGrid1->ColCount-1;i++)
        {
         mas[i].key=StrToInt(StringGrid1->Cells[i+1][1]);
         strcpy(mas[i].text, StringGrid1->Cells[i+1][2].c_str());
         for(k=1; k<i;k++)
                {
                 if (mas[i].key==mas[k].key)
                        {
                         s=s+"  "+i;
                         find=false;
                         break;

                        }
                }
        }

if (!find)
        {

         Memo1->Lines->Add("����� �� ���������! ");
         MessageBeep(0xFFFFFFFF);
         Memo1->Lines->Add("���������� �������� �������� � ��������: ");
         Memo1->Lines->Add(s);
         return;
        }


 TInfo T;
 for(i=0;i<StringGrid1->ColCount-1;i++)
        {

                 min  = i;
                 for(k=i+1;k<StringGrid1->ColCount-1;k++)
                        if (mas[k].key<mas[min].key) min = k;

                 T = mas[i];
                 mas[i] = mas[min];
                 mas[min] = T;



        }

 for(i=0;i<StringGrid1->ColCount-1;i++)
        {
         StringGrid2->Cells[i+1][1]=mas[i].key;
         StringGrid2->Cells[i+1][2]=mas[i].text;
        }
 Make_Blns(&root, 0, StringGrid1->ColCount-1, mas);


 Memo1->Lines->Add("---���������������� ������---");
 View_Tree(root, 0);

 delete []mas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{

 Del_Tree(root);
 root=NULL;
 Memo1->Lines->Add("---������ �������---");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
 StringGrid1->ColCount++;
 StringGrid2->ColCount++;
 StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount-1;
 StringGrid2->Cells[StringGrid2->ColCount-1][0]=StringGrid2->ColCount-1;
 Edit1->Text=StrToInt(Edit1->Text)+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 if (Edit2->Text=="")
        {
         Memo1->Lines->Add("��������� ���� ��� ������!");
         MessageBeep(0xFFFFFFFF);
         return;
        }
 if (root==NULL)
        {
         Memo1->Lines->Add("�������� ������!");
         MessageBeep(0xFFFFFFFF);
         return;
        }
 int n=StrToInt(Edit2->Text);
 bool k=true;
 Tree *t=root;
 while(t!=NULL)
        {
        if (t->info.key==n)
                {
                 Memo1->Lines->Add("---������� ������---");
                 Memo1->Lines->Add("���: "+IntToStr(t->info.key)+" �����: "+t->info.text);
                 k=false;
                 break;
                }
        if (n<t->info.key) t=t->left;
                else t=t->right;

        }

 if (k) Memo1->Lines->Add("---������� �� ������---");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 if (mas!=NULL) delete []mas;
 if (root!=NULL) Del_Tree(root);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
 Memo1->Lines->Clear();
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 for(int i=1;i<StringGrid1->ColCount;i++)
        {
         for(int j=1;j<3;j++)
                {
                 StringGrid1->Cells[i][j]="";
                 StringGrid2->Cells[i][j]="";
                }
        }
 Edit2->Clear();
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button10Click(TObject *Sender)
{
 if (Edit2->Text=="")
        {
         Memo1->Lines->Add("��������� ���� ��� ������!");
         MessageBeep(0xFFFFFFFF);
         return;
        }
 if (root==NULL)
        {
        Memo1->Lines->Add("�������� ������!");
        MessageBeep(0xFFFFFFFF);
        return;
        }

 int n=StrToInt(Edit2->Text);



 bool find=true;
 for(int i=0;i<StringGrid1->ColCount-1;i++)
        if (mas[i].key==n)
                {
                 find=false;
                 break;
                }
 if (find)
        {
         Memo1->Lines->Add("������ �������� ���!");
         return;
        }
  for(int i=1;i<StringGrid1->ColCount-1;i++)
        {
         if (StrToInt(StringGrid1->Cells[i][1])==n)
                {
                 for(int j=i; j<StringGrid1->ColCount-1;j++)
                        {
                         for(int k=1; k<StringGrid1->RowCount-1;k++)
                                {
                                 StringGrid1->Cells[j][k]=StringGrid1->Cells[j+1][k];
                                 StringGrid2->Cells[j][k]=StringGrid2->Cells[j+1][k];
                                }
                        }
                }
        }

 StringGrid1->ColCount--;
 Edit1->Text=StrToInt(Edit1->Text)-1;
 StringGrid1->Cells[StringGrid1->ColCount][1]="";
 StringGrid1->Cells[StringGrid1->ColCount][2]="";
 StringGrid2->Cells[StringGrid1->ColCount][1]="";
 StringGrid2->Cells[StringGrid1->ColCount][2]="";


 root=Del_Info(root, n);
 Memo1->Lines->Add("---����� ������---");
 View_Tree(root, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
  if (root==NULL)
        {
        Memo1->Lines->Add("�������� ������!");
        return;
        }
 Kol_Uzlov(root);
 Memo1->Lines->Add("���������� �������: ");
 Memo1->Lines->Add(x);
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button12Click(TObject *Sender)
{
 if (root!=NULL)
        {
         Memo1->Lines->Add("---������---");
         View_Tree(root, 0);

        }
        else Memo1->Lines->Add("�������� ������!");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
 StringGrid1->ColCount=11;
 StringGrid2->ColCount=11;
 Edit1->Text=10;


 randomize();
 for (int i=1;i<StringGrid1->ColCount;i++)
        {
         StringGrid1->Cells[i][1]=random(101)-50;
         StringGrid1->Cells[i][2]=srandom();
        }


 StringGrid1->Cells[3][1]=25;
 StringGrid1->Cells[5][1]=25;
 StringGrid1->Cells[6][1]=7;
 StringGrid1->Cells[2][1]=7;
 StringGrid1->Cells[8][1]=7;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button14Click(TObject *Sender)
{
  for (int i=1;i<StringGrid1->ColCount;i++)
        {
         StringGrid1->Cells[i][1]=i;
         StringGrid1->Cells[i][2]=srandom();
        }
}
//---------------------------------------------------------------------------

