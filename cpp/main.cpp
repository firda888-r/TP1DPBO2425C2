#include <iostream> 
using namespace std;
#include "BarangElektronik.cpp"

int main() {
    BarangElektronik barang[10];
    int n = 0;
    bool running = true;
    int pilihan;

    // selama bukan pilihan 6 yang dipilih maka status running akan run terus
    //program akan selesai jika status running false
    while (running) {
        cout << "\n=== MENU TOKO ELEKTRONIK ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Cari Barang\n";
        cout << "5. Update Barang\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        // 1 ADD DATA BARANG
        if (pilihan == 1) {
            string nama, notel, alamat;
            int harga;

            cout << "Masukkan Nama Barang: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Harga: ";
            cin >> harga;
            cout << "Masukkan No Telp Toko: ";
            cin.ignore();
            getline(cin, notel);
            cout << "Masukkan Alamat Toko: ";
            getline(cin, alamat);

            barang[n].addBarang(nama, harga, notel, alamat);
            n++;
            cout << "Barang berhasil ditambahkan!\n";
        }
        // 2 SHOW DATA
        else if (pilihan == 2) {
            cout << "\n=== Daftar Barang ===\n";
            for (int i = 0; i < n; i++) {
                barang[i].TampilkanDataBarang();
            }
        }
        // jika perintah nya 3  maka barang target akan didelete (DELETE DATA BARANG)
        else if (pilihan == 3) {
            string target;
            cout << "Masukkan nama barang yang akan dihapus: ";
            cin.ignore();
            getline(cin, target);
            barang[0].deleteData(barang, n, target);
        }
        // jika pilihan nya 4 maka mencari barang target dengan memanggil method seachthing
        else if (pilihan == 4) {
            string target;
            cout << "Masukkan nama barang yang dicari: ";
            cin.ignore();
            getline(cin, target);
            barang[0].searchThing(barang, n, target);
        }
        // 5 Update DATA BARANG
        else if (pilihan == 5) {
            string target;
            cout << "Masukkan nama barang yang akan di-update: ";
            cin.ignore();
            getline(cin, target);

            bool found = false;
            for (int i = 0; i < n; i++) {
                if (barang[i].getNama() == target) { //jika target sama dengan nama yang ada di data
                    string namaBaru, notelBaru, alamatBaru; //buat string nama, notel, alamat dll baru
                    int hargaBaru;

                    cout << "Masukkan Nama Baru: "; //lalu masukan
                    getline(cin, namaBaru);
                    cout << "Masukkan Harga Baru: ";
                    cin >> hargaBaru;
                    cout << "Masukkan No Telp Toko Baru: ";
                    cin.ignore();
                    getline(cin, notelBaru);
                    cout << "Masukkan Alamat Toko Baru: ";
                    getline(cin, alamatBaru);

                    barang[i].updateBarang(namaBaru, hargaBaru, notelBaru, alamatBaru);
                    cout << "Data berhasil diupdate!\n";
                    found = true;
                }
            }
            if (!found) {
                cout << "Barang dengan nama tersebut tidak ditemukan!\n";
            }
        }
        else if (pilihan == 6) {
            cout << "Terima kasih, program selesai.\n";
            running = false;
        }
        
    }

    return 0;
}
