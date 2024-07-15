#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;
    string jurusan;

    Mahasiswa(string n, string ni, string j) : nama(n), nim(ni), jurusan(j) {}
};

class BiodataMahasiswa {
private:
    vector<Mahasiswa> data_mahasiswa;

public:
    void tambah_mahasiswa(string nama, string nim, string jurusan) {
        Mahasiswa mahasiswa(nama, nim, jurusan);
        data_mahasiswa.push_back(mahasiswa);
        cout << "Biodata mahasiswa " << nama << " berhasil ditambahkan." << endl;
    }
void hapus_mahasiswa(string nim) {
        for (auto it = data_mahasiswa.begin(); it != data_mahasiswa.end(); ++it) {
            if (it->nim == nim) {
                data_mahasiswa.erase(it);
                cout << "Biodata mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
Mahasiswa* cari_mahasiswa(string nim) {
        for (auto& mahasiswa : data_mahasiswa) {
            if (mahasiswa.nim == nim) {
                return &mahasiswa;
            }
        }
        return nullptr;
    }
    void tampilkan_semua_mahasiswa() {
        if (data_mahasiswa.empty()) {
            cout << "Tidak ada data mahasiswa." << endl;
        } else {
            for (const auto& mahasiswa : data_mahasiswa) {
                cout << "Nama: " << mahasiswa.nama << ", NIM: " << mahasiswa.nim << ", Jurusan: " << mahasiswa.jurusan << endl;
            }
        }
    }
};
void menu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Hapus Mahasiswa\n";
    cout << "3. Cari Mahasiswa\n";
    cout << "4. Tampilkan Semua Mahasiswa\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}
int main() {
    BiodataMahasiswa biodata;
    int pilihan;
    string nama, nim, jurusan;

    do {
        menu();
        cin >> pilihan;
        cin.ignore();  // Membersihkan newline character dari buffer

        switch (pilihan) {
        case 1:
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            getline(cin, nim);
            cout << "Masukkan Jurusan: ";
            getline(cin, jurusan);
            biodata.tambah_mahasiswa(nama, nim, jurusan);
            break;
        case 2:
            cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
            getline(cin, nim);
            biodata.hapus_mahasiswa(nim);
            break;
        case 3:
            cout << "Masukkan NIM mahasiswa yang dicari: ";
            getline(cin, nim);
            Mahasiswa* mahasiswa;
            mahasiswa = biodata.cari_mahasiswa(nim);
            if (mahasiswa) {
                cout << "Biodata mahasiswa dengan NIM " << nim << ": " << mahasiswa->nama << ", " << mahasiswa->nim << ", " << mahasiswa->jurusan << endl;
            } else {
                cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
            }
            break;
        case 4:
            biodata.tampilkan_semua_mahasiswa();
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}
