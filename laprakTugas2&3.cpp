#include <iostream>
using namespace std;

// Konstanta untuk jumlah maksimum mahasiswa
const int MAX_MAHASISWA = 100;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
    float nilai;
};

// Array untuk menyimpan daftar mahasiswa
Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0; // Variabel untuk menghitung jumlah mahasiswa yang telah ditambahkan

// Deklarasi fungsi menu
void menu();

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa() {
    // Memeriksa apakah jumlah mahasiswa masih di bawah batas maksimum
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        Mahasiswa mahasiswaBaru;

        // Input data mahasiswa baru
        cout << "Masukkan nama mahasiswa: ";
        cin.ignore(); // Membersihkan buffer input
        getline(cin, mahasiswaBaru.nama);
        cout << "Masukkan NIM mahasiswa: ";
        cin >> mahasiswaBaru.nim;
        cout << "Masukkan nilai mahasiswa: ";
        cin >> mahasiswaBaru.nilai;

        // Menyimpan data mahasiswa baru ke dalam array
        daftarMahasiswa[jumlahMahasiswa] = mahasiswaBaru;
        jumlahMahasiswa++; // Increment jumlah mahasiswa
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    } else {
        // Jika kapasitas maksimum tercapai
        cout << "Kapasitas maksimum mahasiswa telah tercapai!" << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menampilkan daftar mahasiswa
void tampilkanDaftarMahasiswa() {
    // Memeriksa apakah ada data mahasiswa yang disimpan
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
    } else {
        cout << "Daftar Mahasiswa: " << endl;
        // Menampilkan data mahasiswa satu per satu
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << i + 1 << ". Nama: " << daftarMahasiswa[i].nama 
                 << ", NIM: " << daftarMahasiswa[i].nim 
                 << ", Nilai: " << daftarMahasiswa[i].nilai << endl;
        }
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menghitung rata-rata nilai mahasiswa
void hitungRataRataNilai() {
    // Memeriksa apakah ada data mahasiswa yang disimpan
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
    } else {
        float totalNilai = 0;

        // Menghitung total nilai mahasiswa
        for (int i = 0; i < jumlahMahasiswa; i++) {
            totalNilai += daftarMahasiswa[i].nilai;
        }

        // Menghitung rata-rata
        float rataRata = totalNilai / jumlahMahasiswa;
        cout << "Rata-rata nilai mahasiswa: " << rataRata << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menampilkan mahasiswa dengan nilai tertinggi
void tampilkanNilaiTertinggi() {
    // Memeriksa apakah ada data mahasiswa yang disimpan
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
    } else {
        // Menentukan mahasiswa dengan nilai tertinggi
        Mahasiswa *mahasiswaTerbaik = &daftarMahasiswa[0];
        for (int i = 1; i < jumlahMahasiswa; i++) {
            if (daftarMahasiswa[i].nilai > mahasiswaTerbaik->nilai) {
                mahasiswaTerbaik = &daftarMahasiswa[i];
            }
        }

        // Menampilkan data mahasiswa dengan nilai tertinggi
        cout << "Mahasiswa dengan nilai tertinggi: " << endl;
        cout << "Nama: " << mahasiswaTerbaik->nama 
             << ", NIM: " << mahasiswaTerbaik->nim 
             << ", Nilai: " << mahasiswaTerbaik->nilai << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menampilkan menu utama
void menu() {
    int pilihan;

    // Menampilkan pilihan menu
    cout << "=== Menu Manajemen Nilai Mahasiswa ===" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tampilkan Daftar Mahasiswa" << endl;
    cout << "3. Hitung Rata-rata Nilai" << endl;
    cout << "4. Tampilkan Mahasiswa dengan Nilai Tertinggi" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

    // Menentukan aksi berdasarkan pilihan menu
    switch (pilihan) {
        case 1: tambahMahasiswa(); break;
        case 2: tampilkanDaftarMahasiswa(); break;
        case 3: hitungRataRataNilai(); break;
        case 4: tampilkanNilaiTertinggi(); break;
        case 5: cout << "Terima kasih! Program selesai." << endl; break;
        default: cout << "Pilihan Tidak Ada." << endl; break;
    }
}

// Fungsi utama program
int main() {
    menu(); // Memanggil fungsi menu utama
    return 0; // Menandakan program selesai
}

