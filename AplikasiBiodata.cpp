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
