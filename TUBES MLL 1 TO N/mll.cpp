#include "mll.h"

void newList(mll &l)
{
    first(l) = NULL;
}

bool alphabetIsSmaller(string kata1, string kata2)
{
    int i = 0;

    while (kata1[i] == kata2[i])
    {
        i++;
    }

    if (int(kata1[i]) < int(kata2[i]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

adrFakultas newFakultas(string nama)
{
    adrFakultas p = new elmFakultas;
    info(p).nama = nama;
    next(p) = NULL;
    nextProdi(p) = NULL;
    return p;
}

adrProdi newProdi(string nama, string akreditasi, string kodeKelas)
{
    adrProdi p = new elmProdi;
    info(p).nama = nama;
    info(p).akreditasi = akreditasi;
    info(p).kodeKelas  = kodeKelas;
    next(p) = NULL;
    nextKelas(p) = NULL;
    return p;
}

adrKelas newKelas(string namaKelas, int jumlahMahasiswa)
{
    adrKelas p = new elmKelas;
    info(p).namaKelas = namaKelas;
    info(p).jumlahMahasiswa = jumlahMahasiswa;
    next(p) = NULL;
}


void inputFakultas(mll &l, adrFakultas pFakultas)
{
    if (first(l) == NULL)
    {
        first(l) = pFakultas; //insert ketika kosong
    }
    else
    {
        adrFakultas p = first(l), prec = NULL;

        while (p != NULL)
        {
            if (alphabetIsSmaller(info(pFakultas).nama, info(p).nama))
            {
                if (p == first(l)) //insert first
                {
                    next(pFakultas) = p;
                    first(l) = pFakultas;
                }
                else //insert after
                {
                    next(prec) = pFakultas;
                    next(pFakultas) = p;
                }
                return;
            }
            prec = p;
            p = next(p);
        }
        next(prec) = pFakultas; //insert last
    }
}

void inputProdi(adrFakultas &pFakultas, adrProdi pProdi)
{
    if (nextProdi(pFakultas) == NULL)
    {
        nextProdi(pFakultas) = pProdi; //insert child jika kosong
    }
    else
    {
        adrProdi p = nextProdi(pFakultas), prec = NULL;

        while (p != NULL)
        {
            if (alphabetIsSmaller(info(pProdi).nama, info(p).nama))
            {
                if (p == nextProdi(pFakultas)) //insert first
                {
                    next(pProdi) = p;
                    nextProdi(pFakultas) = pProdi;
                }
                else //insert after
                {
                    next(prec) = pProdi;
                    next(pProdi) = p;
                }
                return;
            }
            prec = p;
            p = next(p);
        }
        next(prec) = pProdi; //inse
    }
}

void inputKelas(adrProdi &pProdi, adrKelas pKelas)
{
    if (nextKelas(pProdi) == NULL)
    {
        nextKelas(pProdi) = pKelas;
    }
    else
    {
        adrKelas p = nextKelas(pProdi), prec = NULL;

        while (p != NULL)
        {
            if (alphabetIsSmaller(info(pKelas).namaKelas, info(p).namaKelas))
            {
                if (p == nextKelas(pProdi))
                {
                    next(pKelas) = p;
                    nextKelas(pProdi) = pKelas;
                }
                else
                {
                    next(prec) = pKelas;
                    next(pKelas) = p;
                }
                return;
            }
            prec = p;
            p = next(p);
        }
        next(prec) = pKelas;
    }
}

adrFakultas findFakultas(mll l, string x)
{
    adrFakultas f = first(l);
    while (f != NULL)
    {
        if (info(f).nama == x)
        {
            return f;
        }
        f = next(f);
    }
    return NULL;
}

adrProdi findProdi(adrFakultas pFakultas, string x)
{
    adrProdi p = nextProdi(pFakultas);
    while (p != NULL)
    {
        if (info(p).nama == x)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

adrKelas findKelas(adrProdi pProdi, string x)
{
    adrKelas k = nextKelas(pProdi);
    while (k != NULL)
    {
        if (info(k).namaKelas == x)
        {
            return k;
        }
        k = next(k);
    }
    return k;
}
void deleteFakultas(mll &l, adrFakultas pFakultas)
{
    adrFakultas temp;
    adrFakultas f = first(l);
    if (first(l) == pFakultas)
    {
        temp = first(l);
        first(l) = next(first(l));
        next(temp) = NULL;
    }
    else
    {
        while (next(next(f)) != NULL)
        {
            if (next(f) == pFakultas)
            {
                temp = next(f);
                next(f) = next(next(f));
                next(temp) = NULL;
                break;
            }
            f = next(f);
        }
        if (next(f) == pFakultas)
        {
            next(f) = NULL;
        }
    }
}
void deleteProdi(adrFakultas &pFakultas, adrProdi pProdi)
{
    adrProdi p = nextProdi(pFakultas);
    adrProdi deletedP;
    if (nextProdi(pFakultas) == pProdi)
    {
        deletedP = nextProdi(pFakultas);
        nextProdi(pFakultas) = next(nextProdi(pFakultas));
        next(deletedP) = NULL;
    }
    else
    {
        while (next(next(p)) != NULL)
        {
            if (next(p) == pProdi)
            {
                deletedP = next(p);
                next(p) = next(next(p));
                next(deletedP) = NULL;
                break;
            }
            p = next(p);
        }
        if (next(p) == pProdi)
        {
            next(p) = NULL;
        }
    }
}

void deleteKelas(adrProdi &pProdi, adrKelas pKelas)
{
    adrKelas p = nextKelas(pProdi);
    adrKelas deletedK;
    if (nextKelas(pProdi) == pKelas)
    {
        deletedK = nextKelas(pProdi);
        nextKelas(pProdi) = next(nextKelas(pProdi));
        next(deletedK) = NULL;
    }
    else
    {
        while (next(next(p)) != NULL)
        {
            if (next(p)==pKelas)
            {
                deletedK = pKelas;
                next(p) = next(next(p));
                next(deletedK) = NULL;
                break;
            }
            p = next(p);
        }
        if (next(p) == pKelas)
        {
            next(p) = NULL;
        }
    }
}
void print(mll l)
{
    adrFakultas pFakultas = first(l);
    adrProdi pProdi;
    adrKelas pKelas;


    if (pFakultas == NULL)
    {
        cout << "Fakultas Kosong" << endl;
    }

    while (pFakultas != NULL)
    {
        cout << "=================" << info(pFakultas).nama
             << "=================" << endl;
        pProdi = nextProdi(pFakultas);
        while (pProdi != NULL)
        {
            cout << "~ " << info(pProdi).nama << " (" << info(pProdi).akreditasi << ") " <<": ";
            pKelas = nextKelas(pProdi);
            while (pKelas != NULL)
            {
                cout << info(pKelas).namaKelas << " ";
                pKelas = next(pKelas);
            }
            cout << endl;
            pProdi = next(pProdi);
        }
        cout << endl;
        pFakultas = next(pFakultas);
    }

}

void printFakultas(mll l)
{

    if (first(l) == NULL)
    {
        cout << "Fakultas Kosong" << endl;
    }
    adrFakultas pFakultas = first(l);
    if (first(l) != NULL)
    {
        cout << "=================Daftar Fakultas=================" << endl;
    }
    int i = 1;
    while (pFakultas != NULL)
    {
        cout <<"~ " << info(pFakultas).nama << endl;
        i++;
        pFakultas = next(pFakultas);
    }


}

void printProdi(adrFakultas p)
{
    adrProdi pProdi;
    adrKelas pKelas;

    if (pProdi == NULL)
    {
        cout << "Prodi Kosong" << endl;
    }
    if (pProdi != NULL)
    {
        cout << "=================Daftar Prodi "<< info(p).nama << "=================" << endl;
    }
    pProdi = nextProdi(p);
    while (pProdi != NULL)
    {
        cout << "~ " << info(pProdi).nama << " (" << info(pProdi).akreditasi << ") " << endl;
        pProdi = next(pProdi);
    }

}

void printKelas(adrProdi p)
{
    int i = 1;
    adrKelas pKelas = nextKelas(p);
    if (pKelas == NULL)
    {
        cout << "Kelas Kosong";
        cout << endl;
    }
    if (pKelas != NULL)
    {
        cout << "=================Daftar Kelas " << info(p).nama << " =================" << endl;
    }
    while (pKelas != NULL)
    {
        cout << "~ " << info(pKelas).namaKelas << endl;
        i++;
        pKelas = next(pKelas);
    }
    cout << endl;
}

int hitungFakultas(mll l){
    int tot = 0;
    adrFakultas p = first(l);
    while (p != NULL){
        tot++;
        p = next(p);
    }
    return tot;
}
int hitungProdi(adrFakultas pFakultas){
    int tot = 0;
    adrProdi p = nextProdi(pFakultas);
    while (p != NULL){
        tot++;
        p = next(p);
    }
    return tot;
}
int hitungKelas(adrProdi pProdi){
    int tot = 0;
    adrKelas p = nextKelas(pProdi);
    while (p != NULL){
        tot++;
        p = next(p);
    }
    return tot;
}


