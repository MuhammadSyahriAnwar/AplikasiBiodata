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

