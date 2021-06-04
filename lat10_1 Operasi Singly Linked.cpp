#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
typedef struct node *simpul;
struct node
{
	char isi;
	simpul Next;
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
main()
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