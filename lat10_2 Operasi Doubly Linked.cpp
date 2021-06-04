#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0
using namespace std;
typedef struct node *simpul;
struct node
{
  char Isi;
  simpul kanan;
  simpul kiri;
};
//======================
//==Prototype Function==
//======================
void Sisip_Depan(simpul &DL, char elemen);
void Sisip_Belakang(simpul &DL, char elemen);
void Sisip_Tengah1(simpul &DL, char elemen1, char elemen2);
void Sisip_Tengah2(simpul &DL, char elemen1, char elemen2);
void Hapus_Depan(simpul &DL);
void Hapus_Belakang(simpul &DL);
void Hapus_Tengah(simpul &DL, char elemen);
void Cetak(simpul DL);

//==================
//==Function Matin==
//==================
void program()
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
void Sisip_Depan(simpul &DL, char elemen)
{
  simpul baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
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
void Sisip_Tengah1(simpul &DL, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen1;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    cout<<"List Kosong ................"<<endl;
  else
    {
      bantu = DL;
      while(bantu->Isi != elemen2) bantu=bantu->kanan;
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
void Sisip_Tengah2(simpul &DL, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen1;
  baru->kanan = NULL;
  baru->kiri = NULL;
  if(DL == NULL)
    cout<<"List Kosong ............."<<endl;
  else
  {
    bantu = DL;
    while(bantu->kanan->Isi != elemen2) bantu=bantu->kanan;
    baru->kanan = bantu->kanan;
    baru->kiri = bantu;
    bantu->kanan->kiri = baru;
    bantu->kanan = baru;
  }
}

//*************************************
//**FUNCTION SISIP SIMPUL DI BELAKANG**
//*************************************
void Sisip_Belakang(simpul &DL, char elemen)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
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
void Cetak(simpul DL)
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
      cout<<bantu->Isi<<"<= =>";
      bantu=bantu->kanan;
    }
    cout<<bantu->Isi;
  }
}

//*******************************
//**FUNCTION HAPUS SIMPUL DEPAN**
//*******************************
void Hapus_Depan(simpul &DL)
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
void Hapus_Belakang(simpul &DL)
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
void Hapus_Tengah(simpul &DL, char elemen)
{
  simpul bantu, hapus;
  if(DL==NULL)
    cout<<"Linked List Kosong ................";
  else
  {
    bantu = DL;
    while(bantu->kanan->Isi != elemen)
      bantu=bantu->kanan;
    hapus = bantu->kanan;
    bantu->kanan->kanan->kiri=bantu;
    bantu->kanan = bantu->kanan->kanan;
    hapus->kanan = NULL;
    hapus->kiri = NULL;
    free(hapus);
  }
}