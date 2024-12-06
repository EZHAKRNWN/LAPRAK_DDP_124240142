#include <iostream>
using namespace std;

// Konstanta untuk jumlah maksimum buku yang dapat disimpan
const int MAX_BUKU = 100;

// Struktur data untuk menyimpan informasi penulis
struct penulis {
    string Nama;
} namaPenulis;

// Struktur data untuk menyimpan informasi buku
struct Buku {
    int ID_Buku, Harga_Buku;     // ID buku dan harga buku
    string Judul_Buku, namaPenulis; // Judul buku dan nama penulis
};

// Array untuk menyimpan daftar buku
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0; // Variabel untuk menghitung jumlah buku yang telah ditambahkan

// Deklarasi fungsi menu
void menu();

// Fungsi untuk menambahkan buku ke dalam daftar
void tambahBuku() {
    int jumlah_buku_yang_di_input;

    // Memeriksa apakah masih ada ruang untuk menambah buku
    if (jumlahBuku < MAX_BUKU) {
        cout << "Silahkan masukkan jumlah buku yang mau di input: ";
        cin >> jumlah_buku_yang_di_input;

        // Input data untuk setiap buku yang ingin ditambahkan
        for (int i = 0; i < jumlah_buku_yang_di_input; i++) {
            Buku bukuBaru;
            cout << "Masukkan ID Buku: ";
            cin >> bukuBaru.ID_Buku;
            cin.ignore();
            cout << "Masukkan Judul Buku: ";
            getline(cin, bukuBaru.Judul_Buku);
            cout << "Masukkan Nama Pengarang: ";
            getline(cin, bukuBaru.namaPenulis);
            cout << "Masukkan Harga Buku: ";
            cin >> bukuBaru.Harga_Buku;
            cout << endl;

            daftarBuku[jumlahBuku] = bukuBaru;
            jumlahBuku++;
        }
        cout << "Buku Berhasil Ditambahkan!" << endl;
    } else {
        // Jika kapasitas maksimum tercapai
        cout << "Kapasitas Maksimum Buku Telah Tercapai!" << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada data buku." << endl;
    } else {
        cout << "Daftar Buku: " << endl;
        for (int i = 0; i < jumlahBuku; i++) {
            cout << i + 1 << ". ID Buku : " << daftarBuku[i].ID_Buku << endl;
            cout << "Judul Buku: " << daftarBuku[i].Judul_Buku << endl;
            cout << "Penulis: " << daftarBuku[i].namaPenulis << endl;
            cout << "Harga: " << daftarBuku[i].Harga_Buku << endl;
            cout << endl;
        }
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk mengubah data buku berdasarkan ID
void ubahDataBuku() {
    int ID;
    cout << "Masukkan ID buku yang ingin diubah: ";
    cin >> ID;

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].ID_Buku == ID) {
            ditemukan = true;
            cout << "Masukkan Judul Buku Baru: ";
            cin.ignore();
            getline(cin, daftarBuku[i].Judul_Buku);
            cout << "Masukkan Nama Pengarang Baru: ";
            getline(cin, daftarBuku[i].namaPenulis);
            cout << "Masukkan Harga Buku Baru: ";
            cin >> daftarBuku[i].Harga_Buku;
            break;
        }
    }
    if (!ditemukan) {
        cout << "ID Tidak Di Temukan" << endl;
    } else {
        cout << "Data buku berhasil diubah!" << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku() {
    int ID;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> ID;

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].ID_Buku == ID) {
            for (int j = i; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "ID Buku Tidak Di Temukan" << endl;
    } else {
        cout << "Buku Telah Di Hapus!" << endl;
    }
    system("pause");
    system("cls");
    menu();
}

// Fungsi untuk menghitung total harga pembelian dengan diskon
void hitungTotalDiskon() {
    int totalHarga = 0;
    int jumlahBukuDipilih;
    bool diskon5Persen = false;
    string kodeVoucher;

    cout << "Masukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlahBukuDipilih;

    string penulisTerpilih = "";
    int jumlahBukuPenulis = 0;

    for (int i = 0; i < jumlahBukuDipilih; i++) {
        int idBuku;
        cout << "Masukkan ID Buku yang ingin dibeli: ";
        cin >> idBuku;

        bool bukuDitemukan = false;
        for (int j = 0; j < jumlahBuku; j++) {
            if (daftarBuku[j].ID_Buku == idBuku) {
                totalHarga += daftarBuku[j].Harga_Buku;
                if (penulisTerpilih == "") {
                    penulisTerpilih = daftarBuku[j].namaPenulis;
                }

                if (daftarBuku[j].namaPenulis == penulisTerpilih) {
                    jumlahBukuPenulis++;
                }

                bukuDitemukan = true;
                break;
            }
        }

        if (!bukuDitemukan) {
            cout << "Buku dengan ID tersebut tidak ditemukan!" << endl;
        }
    }

    if (jumlahBukuPenulis >= 2) {
        diskon5Persen = true;
    }

    cout << "Masukkan kode voucher (jika ada): ";
    cin >> kodeVoucher;

    if (kodeVoucher == "JPYUM") {
        totalHarga -= totalHarga * 0.1;
        cout << "Diskon 10% dengan voucher JPYUM diterapkan!" << endl;
    }

    if (diskon5Persen) {
        totalHarga -= totalHarga * 0.05;
        cout << "Diskon 5% diterapkan untuk buku-buku dari penulis yang sama!" << endl;
    }

    cout << "Total harga setelah diskon: " << totalHarga << endl;
    system("pause");
    system("cls");
}

// Fungsi menu utama
void menu() {
    int pilihan;
    cout << "=== Menu ===" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Tampilkan Daftar Buku" << endl;
    cout << "3. Ubah Data Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Hitung Total Harga Pembelian Dengan Diskon" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih Menu: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: tambahBuku(); break;
        case 2: tampilkanDaftarBuku(); break;
        case 3: ubahDataBuku(); break;
        case 4: hapusBuku(); break;
        case 5: hitungTotalDiskon(); break;
        case 6: cout << "Terima Kasih, Silahkan Datang Kembali" << endl; break;
        default: cout << "Pilihan Tidak Tersedia" << endl; break;
    }
}

int main() {
    menu(); // Memanggil fungsi menu utama
    return 0; // Menandakan program selesai
}

