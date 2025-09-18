# TP1DPBO2425C2
#Saya Firda Ridzki Utami dengan NIM 2401626 mengerjakan TP1 dalam Praktikum mata kuliah DPBO 
untuk keberkahannya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan

Kode Flow
Dalam empat kode bahasa ini terdapat 1 class sesuai spesifikasi soal bernama'BendaElektronik' (public) yang berisi 4 atribut yaitu :
1. 'string nama_barang' untuk menyimpan nama barang yang tersedia di toko elektronik tersebut
2. 'int harga' untuk harga dibuat integer karena harga umumnya berupa bilangan bulat
3. 'string notel_toko' menggunakan string untuk menghindari error karena nomor telepon bisa saja panjang
4. 'string alamat' untuk menyimpan alamat dari toko elektronik

Setiap atribut dilegkapi dengan GET dan SET agar penyimpanan serta pengambilan data dapat terkontrol.

Class ini juga memiliki lima method utama yaitu  :
1. Method addData, yang digunakan untuk menambah data barang ke dalam daftar dengan menerima input user
2. Method TampilkanDataBarang, yang digunakan untuk menampilkan seluruh data barang yang tersimpan, sehingga user dapat melihat data barang dengan mudah dan terstruktur
3. Method UpdateBarang untuk memudahkan mengupdate data barang bila ada kesalahan input ataupun update stok barang baru
4. Method DeleteData untuk menghapus data barang dengan mencari barang berdasarkan nama lalu menggeser isi array agar data tetap rapat dan tidak ada celah kosong. Dengan begitu, jumlah barang (n) akan berkurang satu dan daftar barang tetap teratur.
5. Method seachThing, untuk memudahkan pencarian barang berdasarkan nama. Program akan mengecek dari indeks ke 0 sampai terakhir jika getNama dan target nya sama maka barang yang dicari ditemukan

untuk melihat hasil compile dari keempat kode, telah disimpan di folder dokumentasi
