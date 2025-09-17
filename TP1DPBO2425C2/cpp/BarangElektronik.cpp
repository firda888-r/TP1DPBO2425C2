#include <string>
#include <iostream>
using namespace std;
class BarangElektronik{

    private:
        string nama_barang;
        int harga;
        string notel_toko;
        string alamat;

    public:
    BarangElektronik(){
    }

    /*GET and SET Atribut*/
    //nama barang
    void setNama(string nama_barang){
        this->nama_barang = nama_barang;
    }
    string getNama(){
        return this->nama_barang;
    }
    
    //harga barang
    void setHargaBarang(int harga){
        this->harga = harga;
    }
    int getHargaBarang(){
        return this->harga;
    }

    //nomor telepon toko
    void setNoTeleponToko(string notel_toko){
        this->notel_toko = notel_toko;
    }
    string getNoTeleponToko(){
        return this->notel_toko;
    }

    //alamat toko
    void setAlamatToko(string alamat){
        this->alamat = alamat;
    }
    string getAlamatToko(){
        return this->alamat;
    }


    /*buat method untuk menambahkan data*/
    void addBarang(string nama_barang, int harga, string notel_toko, string alamat) {
        this->nama_barang = nama_barang;
        this->harga = harga;
        this->notel_toko = notel_toko;
        this->alamat = alamat;
    }
    /*method menampilkan data barang ditoko elektronik*/
    void TampilkanDataBarang() {

        cout << "Nama Barang : " << nama_barang << endl;
        cout << "Harga Barang : " << harga << endl;
        cout << "Nomor Tel Toko : " << notel_toko << endl;
        cout << "Alamat Toko: " << alamat << endl;
        cout << "\n..............................\n" << endl;
    } 
    
     /*method update data setelah dihapus*/
    void updateBarang(string nama_barang, int harga, string notel_toko, string alamat) {
        this->nama_barang = nama_barang;
        this->harga = harga;
        this->notel_toko = notel_toko;
        this->alamat = alamat;
    }

    /*method for delete data*/
    void deleteData(BarangElektronik barang[], int &n, string target) {
        int index = -1;

        // cari index data yang mau dihapus
        for (int i = 0; i < n; i++) {
            if (barang[i].getNama() == target) {
                index = i;
            }
        }

        if (index == -1) {
            // cout << "Data dengan nama '" << target << "' tidak ditemukan.\n";
            return;
        }

        // geser data setelah index ke kiri
        for (int i = index; i < n - 1; i++) {
            barang[i] = barang[i + 1];
        }

        n--; // kurangi jumlah data
        cout << "Data '" << target << "' berhasil dihapus.\n";
    } 

    //method untuk mencari barang sesuai dengan nama barang
    void searchThing(BarangElektronik barang[], int n, string target) {
        bool stop = false;
         
        for(int i = 0; i < n; i++) {
            if (barang[i].getNama() == target) {
                cout << "Barang ditemukan:\n";
                stop = true;

                cout << "Nama Barang : " << nama_barang << endl;
                cout << "Harga Barang : " << harga << endl;
                cout << "Nomor Tel Toko : " << notel_toko << endl;
                cout << "Alamat Toko: " << alamat << endl;
                cout << "\n..............................\n" << endl;
            }
        }
        if(!stop) {
         cout << "Barang tidak tersedia\n";
        }

    }

    ~BarangElektronik() {

    }
};   

