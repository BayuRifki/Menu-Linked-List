/*Author : Bayu Rifki Naisaburi
  NIM : 191011402633
  Kelas: 04TPLP011*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0
using namespace std;
typedef struct node *simpul;
struct node
{
  char isi;
  simpul Next;
  simpul kanan;
  simpul kiri;
};

//====Prototype Function====//
void Sisip_Depan(simpul &L, char elemen);
void Sisip_Belakang(simpul &L, char elemen);
void Sisip_Tengah1(simpul &L, char elemen1, char elemen2);
void Sisip_Tengah2(simpul &L, char elemen1, char elemen2);
void Hapus_Depan(simpul &L);
void Hapus_Belakang(simpul &L);
void Hapus_Tengah(simpul &L, char elemen);
void Cetak(simpul L);

//====Function Main====//
void singly()
{
  char huruf, huruf2;
  simpul L = NULL; //Pastikan L kosong
  cout<<"==OPERASI PADA SINGLE LINKED LIST=="<<endl<<endl;

  //====SISIP DEPAN====//
  cout<<"Penyisipan simpul di depan"<<endl<<endl;
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Depan(L, huruf);
  Cetak (L);

  //====SISIP BELAKANG====//

  cout<<"\n\nPenyisipan Simpul Belakang"<<endl<<endl;
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Belakang(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Belakang(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Belakang(L, huruf);
  cout<<"Masukkan Huruf: ";cin>>huruf;
  Sisip_Belakang(L, huruf);
  Cetak (L);

  //====SISIP SIMPUL SETELAH SIMPUL TERTENTU====//

  cout<<endl<<endl<<"Masukkan Huruf: ";cin>>huruf;
  cout<<"Disisip Setelah Huruf: ";cin>>huruf2;
  cout<<huruf<<" Disisip Setelah "<<huruf2<<endl;
  Sisip_Tengah1(L, huruf, huruf2);
  Cetak(L);

  //====SISIP SIMPUL SEBELUM SIMPUL TERTENTU====//

  cout<<endl<<endl<<"Masukkan Huruf: ";cin>>huruf;
  cout<<"Disisip Sebelum Huruf :";cin>>huruf2;
  cout<<huruf<<" Disisip Sebelum "<<huruf2<<endl;
  Sisip_Tengah2(L, huruf, huruf2);
  Cetak(L);

  //====HAPUS SIMPUL DEPAN====//

  cout<<endl<<endl<<"Setelah Hapus Simpul Depan "<<endl;
  Hapus_Depan(L);
  Cetak(L);

  //====HAPUS SIMPUL BELAKANG====//

  cout<<endl<<endl<<"Setelah Dihapus Simpul Belakang"<<endl;
  Hapus_Belakang(L);
  Cetak(L);

  //====HAPUS SIMPUL TENGAH====//

  cout<<"\n\nMasukkan Huruf Tengah Yang akan dihapus : ";cin>>huruf;
  Hapus_Tengah(L,huruf);
  Cetak(L);
  getch();
}

//======FUNCTION SISIP SIMPUL DI DEPAN=====//

void Sisip_Depan(simpul &L, char elemen)
{
  simpul baru; // = new simpul;
  baru = (simpul) malloc (sizeof(simpul));
  baru->isi = elemen;
  baru->Next = NULL;
  if(L == NULL)
    L=baru;
  else
  {
    baru->Next=L;
    L=baru;
  }
}
//=====FUNCTION SISIP SIMPUL SETELAH SIMPUL TERTENTU=====//
void Sisip_Tengah1(simpul &L, char elemen1, char elemen2)
{
  simpul bantu,baru;
  baru = (simpul) malloc (sizeof(simpul));
  baru->isi = elemen1;
  baru->Next = NULL;
  if(L == NULL)
    cout<<"List Kosong........."<<endl;
  else
  {
    bantu = L;
    while(bantu->isi != elemen2) bantu = bantu->Next;
    baru->Next=bantu->Next;
    bantu->Next=baru;
  }
}
//=====FUNCTION SISIP SIMPUL SEBELUM SIMPUL TERTENTU=====//

void Sisip_Tengah2(simpul &L, char elemen1, char elemen2)
{
  simpul bantu,baru;
  baru=(simpul) malloc (sizeof(simpul));
  baru->isi = elemen1;
  baru->Next = NULL;
  if(L == NULL)
    cout<<"List Kosong........."<<endl;
  else
  {
    bantu = L;
    while(bantu->Next->isi != elemen2) bantu=bantu->Next;
    baru->Next = bantu->Next;
    bantu->Next=baru;
  }
}
//=====FUNCTION SISIP SIMPUL BELAKANG====//
void Sisip_Belakang(simpul &L, char elemen)
{
  simpul bantu,baru;
  baru=(simpul) malloc (sizeof(simpul));
  baru->isi=elemen;
  baru->Next=NULL;
  if(L == NULL)
    L=baru;
  else
  {
    bantu = L;
    while(bantu->Next != NULL)
      bantu=bantu->Next;
    bantu->Next=baru;
  }
}
//=====FUNCTION MENCETAK ISI LINKED LIST=====//
void Cetak(simpul L)
{
  simpul bantu;
  if(L == NULL)
    cout<<"Linked List Kosong......"<<endl;
  else
  {
    bantu = L;
    cout<<"Isi Linked List: ";
    while(bantu->Next != NULL)
    {
      cout<<bantu->isi<<"-->";
      bantu=bantu->Next;
    }
    cout<<bantu->isi;
  }
}
//=====FUNCTION HAPUS SIMPUL DEPAN====//

void Hapus_Depan(simpul &L)
{
  simpul Hapus;
  if(L == NULL)
    cout<<"Linked List Kosong.......";
  else
  {
    Hapus = L;
    L = L->Next;
    Hapus->Next=NULL;
    free(Hapus);
  }
}
//======FUNCTION HAPUS SIMPUL BELAKANG=====//
void Hapus_Belakang(simpul &L)
{
  simpul bantu, hapus;
  if(L == NULL)
    cout<<"Linked List Kosong.......";
  else
  {
    bantu = L;
    while(bantu->Next->Next != NULL) bantu=bantu->Next;
    hapus = bantu->Next;
    bantu->Next=NULL;
    free(hapus);
  }
}
//=====FUNCTION HAPUS SIMPUL DITENGAH=====//
void Hapus_Tengah(simpul &L, char elemen)
{
  simpul bantu,hapus;
  if(L == NULL)
    cout<<"Linked List Kosong.......";
  else
  {
    bantu = L;
    while (bantu->Next->isi != elemen) bantu=bantu->Next;
    hapus = bantu->Next;
    bantu ->Next = bantu->Next->Next;
    hapus->Next=NULL;
    free(hapus);
  }
}
//======================
//==Prototype Function==
//======================
void Sisip_Depan2(simpul &DL, char elemen);
void Sisip_Belakang2(simpul &DL, char elemen);
void Sisip_Tengah12(simpul &DL, char elemen1, char elemen2);
void Sisip_Tengah123(simpul &DL, char elemen1, char elemen2);
void Hapus_Depan2(simpul &DL);
void Hapus_Belakang2(simpul &DL);
void Hapus_Tengah2(simpul &DL, char elemen);
void Cetak2(simpul DL);

//==================
//==Function Main==
//==================
void doubly()
{
  char huruf, huruf2;
  simpul DL = NULL; //Pastikan bahwa DL kosong
  int i;
  cout<<"\t\t=OPERASI PADA DOUBLE LINKED LIST==\n\n";
  //===============
  //==Sisip Depan==
  //===============
  cout<<"Penyisipan Simpul Di Deppan"<<endl<<endl;
  for(i=1; i<=4; i++)
  {
    cout<<"Masukkan Huruf :"; cin>>huruf;
    Sisip_Depan(DL, huruf);
  }
  Cetak(DL);
  //==================
  //==Sisip Belakang==
  //==================
  cout<<"\n\nPenyisipan Simpul Di Belakang \n\n";
  for(i=1; i<=4; i++)
  {
    cout<<"Masukkan Huruf :"; cin>>huruf;
    Sisip_Belakang(DL, huruf);
  }
  Cetak(DL);
  //========================================
  //==Sisip Simpul Setelah Simpul Tertentu==
  //========================================
  cout<<endl<<endl<<"Masukkan Huruf :";
  cin>>huruf;
  cout<<"Disisip Setelah Huruf:";cin>>huruf2;
  cout<<huruf<<" Disisip Setelah "<<huruf2<<endl;
  Sisip_Tengah1(DL, huruf, huruf2);
  Cetak(DL);
  //========================================
  //==Sisip Simpul Sebelum Simpul Tertentu==
  //========================================
  cout<<"\n\nMasukkan Huruf :";
  cin>>huruf;
  cout<<"Disisip Sebelum Huruf :";
  cin>>huruf2;
  cout<<huruf<<" Disisip Sebelum "<<huruf2<<endl;
  Sisip_Tengah2(DL, huruf, huruf2);
  Cetak(DL);
  //======================
  //==Hapus Simpul Depan==
  //======================
  cout<<"\n\nSetelah Hapus Simpul Depan \n";
  Hapus_Depan(DL);
  Cetak(DL);
  //=========================
  //==Hapus Simpul Belakang==
  //=========================
  cout<<"\n\nSetelah Hapus Simpul Belakang "<<endl;
  Hapus_Belakang(DL);
  Cetak(DL);
  //=======================
  //==Hapus Simpul Tengah==
  //=======================
  cout<<"\n\nMasukkan Huruf Tengah Yang Akan Dihapus :";
  cin>>huruf;
  Hapus_Tengah(DL,huruf);
  Cetak(DL);
  getch();
}

//**********************************
//**FUNCTION SISIP SIMPUL DI DEPAN**
//**********************************
void Sisip_Depan2(simpul &DL, char elemen)
{
  simpul baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->isi = elemen;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    DL=baru;
  else
  {
    baru->kanan = DL;
    DL->kiri = baru;
    DL=baru;
  }
}

//*************************************************
//**FUNCTION SISIP SIMPUL SETELAH SIMPUL TERTENTU**
//*************************************************
void Sisip_Tengah12(simpul &DL, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->isi = elemen1;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    cout<<"List Kosong ................"<<endl;
  else
    {
      bantu = DL;
      while(bantu->isi != elemen2) bantu=bantu->kanan;
      baru->kanan = bantu->kanan;
      baru->kiri = baru;
      baru->kiri = bantu;
      bantu->kanan->kiri = baru;
      bantu->kanan = baru;
    }
}

//*************************************************
//**FUNCTION SISIP SIMPUL SEBELUM SIMPUL TERTENTU**
//*************************************************
void Sisip_Tengah123(simpul &DL, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->isi = elemen1;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    cout<<"List Kosong ............."<<endl;
  else
  {
    bantu = DL;
    while(bantu->kanan->isi != elemen2) bantu=bantu->kanan;
    baru->kanan = bantu->kanan;
    baru->kiri = bantu;
    bantu->kanan->kiri = baru;
    bantu->kanan = baru;
  }
}

//*************************************
//**FUNCTION SISIP SIMPUL DI BELAKANG**
//*************************************
void Sisip_Belakang2(simpul &DL, char elemen)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->isi = elemen;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    DL=baru;
  else
  {
    bantu=DL;
    while(bantu->kanan != NULL)
      bantu=bantu->kanan;
    bantu->kanan=baru;
    baru->kiri = bantu;
  }
}

//*************************************
//**FUNCTION MENCETAK ISI LINKED LIST**
//*************************************
void Cetak2(simpul DL)
{
  simpul bantu;
  if(DL==NULL)
    cout<<"Linked List Kosong ........."<<endl;
  else
  {
    bantu=DL;
    cout<<"Isi Linked List : ";
    while (bantu->kanan != NULL)
    {
      cout<<bantu->isi<<"<= =>";
      bantu=bantu->kanan;
    }
    cout<<bantu->isi;
  }
}

//*******************************
//**FUNCTION HAPUS SIMPUL DEPAN**
//*******************************
void Hapus_Depan2(simpul &DL)
{
  simpul Hapus;
  if(DL==NULL)
    cout<<"Linked List Kosong ............";
  else
  {
    Hapus = DL;
    DL = DL->kanan;
    DL->kiri = NULL;
    Hapus->kanan = NULL;
    free(Hapus);
  }
}

//**********************************
//**FUNCTION HAPUS SIMPUL BELAKANG**
//**********************************
void Hapus_Belakang2(simpul &DL)
{
  simpul bantu, hapus;
  if(DL==NULL)
    cout<<"Linked List Kosong ...............";
  else
  {
    bantu = DL;
    while(bantu->kanan->kanan != NULL) bantu=bantu->kanan;
    hapus = bantu->kanan;
    bantu->kanan = NULL;
    hapus->kiri = NULL;
    free(hapus);
  }
}

//***********************************
//**FUNCTION HAPUS SIMPUL DI TENGAH**
//***********************************
void Hapus_Tengah2(simpul &DL, char elemen)
{
  simpul bantu, hapus;
  if(DL==NULL)
    cout<<"Linked List Kosong ................";
  else
  {
    bantu = DL;
    while(bantu->kanan->isi != elemen)
      bantu=bantu->kanan;
    hapus = bantu->kanan;
    bantu->kanan->kanan->kiri=bantu;
    bantu->kanan = bantu->kanan->kanan;
    hapus->kanan = NULL;
    hapus->kiri = NULL;
    free(hapus);
  }
}
int main(){
  int menu;
  char pertama;
  menu:
  cout<<"\n==========Daftar Metode Linked List=========="<<endl;
  cout<<"1. Singly Linked List"<<endl;
  cout<<"2. Doubly Linked List"<<endl;
  cout<<"==============================================="<<endl;

  cout<<"Masukkan Pilihan: ";
  cin>>menu;

  if(menu==1){
    singly();
  }else if(menu==2){
    doubly();
  }else{
    cout<<"Metode Tidak Ada"<<endl;
    cout<<endl;
  }
  {
  int jawab;
  cout<<"\n";
  cout<<"1. ya\n";
  cout<<"2. tidak\n";
  cout<<"Kembali ke menu ? \n";
  cin>>jawab;
  if(jawab==1){
    goto menu;
  }else if(jawab==2){
    goto exit;
  }else
  cout<<"Pilihan yang dimasukkan tidak ada\n";
  getch();
  goto exit;
}
exit:
{
  cout<<endl<<endl;
  return 0;
}
}