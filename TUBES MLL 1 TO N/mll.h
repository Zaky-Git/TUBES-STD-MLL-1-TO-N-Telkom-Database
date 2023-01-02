#include <iostream>

#define next(x) x->next
#define first(l) l.first
#define info(q) q->info
#define nextProdi(p) p->nextProdi
#define nextKelas(p) p->nextKelas

using namespace std;


struct fakultas
{
    string nama;
};

struct prodi
{
    string nama;
    string akreditasi;
    string kodeKelas;
};

struct kelas
{
    string namaKelas;
    int jumlahMahasiswa;
};

typedef fakultas infofakultas;
typedef prodi infoprodi;
typedef kelas infokelas;
typedef struct elmFakultas *adrFakultas;
typedef struct elmProdi *adrProdi;
typedef struct elmKelas *adrKelas;

struct elmFakultas
{
    infofakultas info;
    adrFakultas next;
    adrProdi nextProdi;
};

struct elmProdi
{
    infoprodi info;
    adrProdi next;
    adrKelas nextKelas;
};

struct elmKelas
{
    infokelas info;
    adrKelas next;
};

struct mll
{
    adrFakultas first;
};

void newList(mll &l);
bool alphabetIsSmaller(string kata1, string kata2);
adrFakultas newFakultas(string nama);
adrProdi newProdi(string nama, string akreditasi, string kodeKelas);
adrKelas newKelas(string namaKelas, int jumlahMahasiswa);
void inputFakultas(mll &l, adrFakultas pFakultas);
void inputProdi(adrFakultas &pFakultas, adrProdi pProdi);
void inputKelas(adrProdi &pProdi, adrKelas pKelas);
adrFakultas findFakultas(mll l, string x);
adrProdi findProdi(adrFakultas pFakultas, string x);
adrKelas findKelas(adrProdi pProdi, string x);
void deleteFakultas(mll &l, adrFakultas pFakultas);
void deleteProdi(adrFakultas &pFakultas, adrProdi pProdi);
void deleteKelas(adrProdi &pProdi, adrKelas pKelas);
void print(mll l);
void printFakultas(mll l);
void printProdi(adrFakultas p);
void printKelas(adrProdi p);
