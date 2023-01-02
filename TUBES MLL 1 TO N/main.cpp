#include "mll.h"

using namespace std;

int main()
{
    mll l;
    newList(l);
    adrFakultas x;

    int input = 1,n,i;

    inputFakultas(l, newFakultas("FIF"));

    x = findFakultas(l, "FIF");
    inputProdi(x, newProdi("Informatika", "A", "IF"));
    inputProdi(x, newProdi("Teknologi Informasi", "A", "IT"));
    inputProdi(x, newProdi("Rekayasa Perangkat Lunak", "B", "SE"));
    inputProdi(x, newProdi("Data Sains", "AB", "DS"));

    inputFakultas(l, newFakultas("FKB"));
    x = findFakultas(l, "FKB");
    inputProdi(x, newProdi("Administrasi Bisnis", "A", "AB"));
    inputProdi(x, newProdi("Ilmu Komunikasi", "A", "IK"));
    inputProdi(x, newProdi("Digital Public Relation", "B", "PR"));
    inputProdi(x, newProdi("Digital Content Broadcasting", "B", "DC"));

    inputFakultas(l, newFakultas("FEB"));
    x = findFakultas(l, "FEB");
    inputProdi(x, newProdi("Manajemen Bisnis Telekomunikasi & Informatika", "A", "MB"));
    inputProdi(x, newProdi("Akutansi", "A", "AK"));
    inputProdi(x, newProdi("Manajemen Bisnis Rekreasi", "C", "LM"));

    inputFakultas(l, newFakultas("FIT"));
    x = findFakultas(l, "FIT");
    inputProdi(x, newProdi("Teknik Telekomunikasi", "A", "TTI"));
    inputProdi(x, newProdi("Sistem Informatika", "A", "SIA"));
    inputProdi(x, newProdi("Sistem Komputer", "A", "SKR"));
    inputProdi(x, newProdi("Sistem Informasi", "A", "SII"));
    inputProdi(x, newProdi("Sistem Informasi Akuntansi", "A", "SIAI"));
    inputProdi(x, newProdi("Digital Marketing", "C", "DMG"));
    inputProdi(x, newProdi("Hospitality & Culinary Art", "C", "HCA"));
    inputProdi(x, newProdi("Terapan Digital Creative Multimedia", "C", "TDCM"));

    inputFakultas(l, newFakultas("FIK"));
    x = findFakultas(l, "FIK");
    inputProdi(x, newProdi("Desain Komunikasi Visual", "A", "DK"));
    inputProdi(x, newProdi("Desain Interior", "A", "DI"));
    inputProdi(x, newProdi("Seni Rupa", "A", "SR"));
    inputProdi(x, newProdi("Kriya Fashion", "A", "DC"));
    inputProdi(x, newProdi("Desain Produk", "A", "DP"));

    inputFakultas(l, newFakultas("FTE"));
    x = findFakultas(l, "FTE");
    inputProdi(x, newProdi("Teknik Telekomunikasi", "A", "TT"));
    inputProdi(x, newProdi("Teknik Elektro", "B", "TE"));
    inputProdi(x, newProdi("Smart Science & Technology", "C", "ST"));
    inputProdi(x, newProdi("Teknik Komputer", "AB", "TK"));
    inputProdi(x, newProdi("Teknik Biomedis", "B", "TB"));
    inputProdi(x, newProdi("Electrical Energy Engineering", "BC", "EE"));

    inputFakultas(l, newFakultas("FRI"));
    x = findFakultas(l, "FRI");
    inputProdi(x, newProdi("Teknik Industri", "A", "TI"));
    inputProdi(x, newProdi("Sistem Informasi", "A", "SI"));
    inputProdi(x, newProdi("Digital Supply Chain", "C", "DC"));

    adrFakultas cariF = findFakultas(l,"FTE");
    adrProdi cariP = findProdi(cariF,"Teknik Komputer");

    inputKelas(cariP,newKelas("TK-44-01",30));
    inputKelas(cariP,newKelas("TK-45-03",30));
    inputKelas(cariP,newKelas("TK-45-01",30));
    inputKelas(cariP,newKelas("TK-45-02",30));

    while (input != 0)
    {
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "           Selamat Datang di Your Telyu          " << endl;
        cout << "  program Kami dibuat untuk memudahkan Pengguna  " << endl;
        cout << " dalam menampilkan, menambahkan, mengurangi data " << endl;
        cout << "            Fakultas, Prodi, dan Kelas           " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "                     SE-45-02                    " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "               Fasya Raihan Maulana              " << endl;
        cout << "                   [1302213116]                  " << endl;
        cout << "              Muhammad Zaky Fathurahim           " << endl;
        cout << "                   [1302213067]                  " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1.  Input Fakultas" << endl;
        cout << "2.  Input Prodi" << endl;
        cout << "3.  Input Kelas" << endl;
        cout << "4.  Delete Fakultas" << endl;
        cout << "5.  Delete Prodi" << endl;
        cout << "6.  Delete Kelas" << endl;
        cout << "7.  Print Fakultas" << endl;
        cout << "8.  Print Prodi" << endl;
        cout << "9.  Print Kelas" << endl;
        cout << "10. Print Semua" << endl;
        cout << "11. Ubah Akreditasi" << endl;
        cout << "0.  Keluar" << endl;
        cout << "Masukkan Inputan : ";
        cin >> input;
        cout << endl;
        if (input == 1)
        {
            cout << "Total data fakultas yang ingin dimasukkan : ";
            cin >> n;
            i = 1;
            string nama;
            while (n > 0)
            {
                cout << "Masukkan data ke " << i << endl;
                cout << "Nama Fakultas : ";
                cin >> nama;
                cout << endl;
                inputFakultas(l, newFakultas(nama));
                n--;
                i++;
            }
        }
        else if (input == 2)
        {
            string f;
            adrFakultas pFakultas;
            printFakultas(l);
            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }

            cout << "Total data prodi yang ingin dimasukkan : ";
            cin >> n;
            i = 1;
            string nama, akreditasi, kodeKelas;
            while (n > 0)
            {
                cout << "Masukkan data ke " << i << endl;
                cout << "Nama Prodi : ";
                while(getline(cin, nama))
                {
                    if(nama != "")
                    {
                        break;
                    }
                };
                cout << "Akreditasi : ";
                cin >> akreditasi;
                cout << "Kode Kelas : ";
                cin >> kodeKelas;
                cout << endl;
                inputProdi(pFakultas, newProdi(nama, akreditasi, kodeKelas));
                n--;
                i++;
            }
        }
        else if (input == 3)
        {
            string p, f;

            printFakultas(l);
            adrFakultas pFakultas;
            adrProdi pProdi;

            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    printProdi(pFakultas);
                    while(true)
                    {
                        cout << "Pilih prodi di " << f << " : ";
                        while(getline(cin, p))
                        {
                            if(p != "")
                            {
                                break;
                            }
                        };
                        pProdi = findProdi(pFakultas, p);

                        if(pProdi != NULL)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Prodi tidak ditemukan" << endl;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }

            cout << "Total data kelas yang ingin dimasukkan : ";
            cin >> n;
            i = 1;

            string namaKelas;
            int kapasitas;
            string angkatan;
            string nomorUrut;
            while (n > 0)
            {
                cout << "Masukkan data ke " << i << endl;
                cout << "Angkatan : ";
                cin >> angkatan;
                cout << "Nomor Urut : ";
                cin >> nomorUrut;
                namaKelas = info(pProdi).kodeKelas + "-" + angkatan + "-" + nomorUrut;
                cout << "Kapasitas Kelas  : ";
                cin >> kapasitas;
                cout << endl;
                inputKelas(pProdi, newKelas(namaKelas, kapasitas));
                n--;
                i++;
            }
        }
        else if (input == 4)
        {
            printFakultas(l);
            adrFakultas pFakultas;
            string f;
            while(true)
            {
                cout << "Fakultas yang ingin dihapus : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }
            deleteFakultas(l,pFakultas);
            cout << "Fakultas " << info(pFakultas).nama << " telah dihapus" << endl;
            cout << endl;
            system("pause");

        }
        else if (input == 5)
        {

            string p, f;

            printFakultas(l);
            adrFakultas pFakultas;
            adrProdi pProdi;

            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    printProdi(pFakultas);
                    while(true)
                    {
                        cout << "Pilih prodi "<< f <<  " yang ingin dihapus : ";
                        while(getline(cin, p))
                        {
                            if(p != "")
                            {
                                break;
                            }
                        };
                        pProdi = findProdi(pFakultas, p);

                        if(pProdi != NULL)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Prodi tidak ditemukan" << endl;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }
            deleteProdi(pFakultas,pProdi);
            cout << "Prodi " << info(pProdi).nama << " telah dihapus" << endl;
            cout << endl;
            system("pause");

        }
        else if (input == 6)
        {
            string p, f;

            printFakultas(l);
            adrFakultas pFakultas;
            adrProdi pProdi;

            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    printProdi(pFakultas);
                    while(true)
                    {
                        cout << "Pilih prodi di " << f << " : ";
                        while(getline(cin, p))
                        {
                            if(p != "")
                            {
                                break;
                            }
                        };
                        pProdi = findProdi(pFakultas, p);

                        if(pProdi != NULL)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Prodi tidak ditemukan" << endl;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }

            string namakelas;
            adrKelas dicari;
            if (nextKelas(pProdi) != NULL)
            {
                printKelas(pProdi);
                while (true)
                {
                    cout << "Masukkan Kelas yang ingin dihapus : ";
                    cin >> namakelas;

                    dicari = findKelas(pProdi,namakelas);

                    if (dicari != NULL)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Kelas tidak ditemukan" << endl;
                    }
                }
                deleteKelas(pProdi,dicari);
                cout << "Kelas " << info(dicari).namaKelas << " telah dihapus" << endl;
                cout << endl;
                system("pause");
            }
            else
            {
                cout << "Prodi tidak memiliki kelas"<< endl;
                cout << endl;
                system("pause");
            }



        }
        else if (input == 7)
        {
            printFakultas(l);
            system("pause");
        }
        else if (input == 8)
        {
            printFakultas(l);
            adrFakultas pFakultas;
            string f;
            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }
            printProdi(pFakultas);
            cout << endl;
            system("pause");
        }
        else if (input == 9)
        {

            string p, f;

            printFakultas(l);
            adrFakultas pFakultas;
            adrProdi pProdi;

            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    printProdi(pFakultas);
                    while(true)
                    {
                        cout << "Pilih prodi di " << f << " : ";
                        while(getline(cin, p))
                        {
                            if(p != "")
                            {
                                break;
                            }
                        };
                        pProdi = findProdi(pFakultas, p);

                        if(pProdi != NULL)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Prodi tidak ditemukan" << endl;
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }

            printKelas(pProdi);
            system("pause");
        }
        else if (input == 10)
        {
            print(l);
            system("pause");
        }
        else if (input == 11)
        {
            string p, f;

            printFakultas(l);
            adrFakultas pFakultas;
            adrProdi pProdi;

            while(true)
            {
                cout << "Fakultas yang dipilih : ";
                cin >> f;
                pFakultas = findFakultas(l, f);
                if(pFakultas != NULL)
                {
                    printProdi(pFakultas);
                    while(true)
                    {
                        cout << "Pilih prodi "<< f <<  " yang ingin diubah akreditasinya : ";
                        while(getline(cin, p))
                        {
                            if(p != "")
                            {
                                break;
                            }
                        };
                        pProdi = findProdi(pFakultas, p);

                        if(pProdi != NULL)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Prodi tidak ditemukan" << endl;
                        }

                    }
                    break;
                }
                else
                {
                    cout << "Fakultas tidak ditemukan" << endl;
                }
            }
            if (next(pProdi)!= NULL)
            {
                string akreditasi;
                cout << "Masukkan akreditasi baru : ";
                cin >> akreditasi;
                info(pProdi).akreditasi = akreditasi;
                cout << "Perubahan akreditasi berhasil" << endl << endl;
                system("pause");
            }

        }
    }
}

