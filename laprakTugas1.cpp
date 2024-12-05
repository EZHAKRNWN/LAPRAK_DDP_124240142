#include <iostream>
using namespace std;

int main()
{
    // Menampilkan pesan sambutan dan informasi login
    cout << "   	Selamat Datang		   " << endl;
    cout << "==============================" << endl;
    cout << "Silahkan Login Terlebih Dahulu" << endl;
    string nama, nim;
    int check = 0; // Variabel untuk menghitung percobaan login
    cout << "Masukan Nama dan Nim" << endl;
    
    do
    {
        // Meminta input nama dan NIM dari pengguna
        cout << "Silahkan Masukkan Nama : ";
        cin >> nama;
        cout << "Silahkan Masukkan NIM  : ";
        cin >> nim;
        
        
        // Memeriksa apakah nama dan NIM sesuai dengan yang diizinkan
        if (nama == "ezha" && nim == "142")
        {
            
            cout << "Login Berhasil" << endl;
            break; // Keluar dari perulangan jika login berhasil
        }
        check++; // Menambah jumlah percobaan
    } while (check < 3); // Maksimal 3 percobaan login

    if (check >= 3)
    {
      
       // Jika gagal 3 kali, menampilkan pesan dan keluar program
       cout << "Login Gagal" << endl;
        return 0;
    }

    string menu1, menu2; // Variabel tidak terpakai (dapat dihapus)
    int pilihanmenu;
    system ("pause");
    system ("cls");

    // Menampilkan menu utama
    cout << "	Menu		" << endl;
	cout << "===================" << endl;
    cout << "1. Game Tebak Angka" << endl;
    cout << "2. Keluar			" << endl;
    cout << "===================" << endl;
    cout << "Pilih menu di atas: ";
    cin >> pilihanmenu;

    // Menentukan pilihan menu pengguna
    if (pilihanmenu == 1)
    {
        system ("cls");
        int angka_tebak; // Variabel untuk menampung angka tebakan pengguna
        int angka_benar = 5; // Angka yang harus ditebak oleh pengguna
        cout << "Selamat Datang Di Permainan Angka " << endl;

        do
        {
            // Meminta pengguna menebak angka
            cout << "Tebak Angka dari (1-10) : ";
            cin >> angka_tebak;

            // Memberikan umpan balik berdasarkan tebakan pengguna
            if (angka_tebak > angka_benar)
            {
                system ("cls");
                cout << "Angka Terlalu Besar" << endl;
            }
            else if (angka_tebak < angka_benar)
            {
                system ("cls");
                cout << "Angka Terlalu Kecil" << endl;
            }
            else 
            {
                system ("cls");
                cout << "Selamat Anda Benar" << endl;
                break; // Keluar dari perulangan jika tebakan benar
            }
        } while (angka_tebak != angka_benar);

        return 0; // Program selesai setelah permainan
    }
    else if (pilihanmenu == 2)
    {
        // Jika pengguna memilih keluar, tampilkan pesan dan akhiri program
        system ("cls");
        cout << "Keluar Dari Program" << endl;
        return 0;
    }
    else
    {
        // Jika input menu tidak valid
        system ("cls");
        cout << "Menu Tidak Ada" << endl;
        return 0;
    }
}

