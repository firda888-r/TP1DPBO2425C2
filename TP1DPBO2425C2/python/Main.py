# MAIN
from BarangElektronik import BarangElektronik

def main():
    barang_list = []
    running = True

#selama pilihannya bukan 6 program akan terus berjalan running bernilai true
    while running:
        print("\n=== MENU TOKO ELEKTRONIK ===")
        print("1. Tambah Barang")
        print("2. Tampilkan Semua Barang")
        print("3. Hapus Barang")
        print("4. Cari Barang")
        print("5. Update Barang")
        print("6. Keluar")
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            nama = input("Masukkan Nama Barang: ")
            harga = int(input("Masukkan Harga: "))
            notel = input("Masukkan No Telp Toko: ")
            alamat = input("Masukkan Alamat Toko: ")
            barang = BarangElektronik()
            barang.addBarang(nama, harga, notel, alamat)
            barang_list.append(barang)
            print("Barang berhasil ditambahkan!")

        elif pilihan == "2":
            print("\n=== Daftar Barang ===")
            if not barang_list:
                print("Belum ada barang.")
            else:
                for b in barang_list:
                    b.tampilkanDataBarang()

        elif pilihan == "3":
            target = input("Masukkan nama barang yang akan dihapus: ")
            found = False
            for b in barang_list:
                if b.nama_barang == target:
                    barang_list.delete_barang(b)
                    print("Barang berhasil dihapus!")
                    found = True
                    break
            if not found:
                print("Barang tidak ditemukan!")

        elif pilihan == "4":
            target = input("Masukkan nama barang yang dicari: ")
            found = False
            for b in barang_list:
                if b.nama_barang == target:
                    print("Barang ditemukan:")
                    b.tampilkanDataBarang()
                    found = True
            if not found:
                print("Barang tidak ditemukan!")

        elif pilihan == "5":
            target = input("Masukkan nama barang yang akan di-update: ")
            found = False
            for b in barang_list:
                if b.nama_barang == target:
                    nama_baru = input("Masukkan Nama Baru: ")
                    harga_baru = int(input("Masukkan Harga Baru: "))
                    notel_baru = input("Masukkan No Telp Toko Baru: ")
                    alamat_baru = input("Masukkan Alamat Toko Baru: ")
                    b.update_barang(nama_baru, harga_baru, notel_baru, alamat_baru)
                    print("Data berhasil diupdate!")
                    found = True
            if not found:
                print("Barang tidak ditemukan!")

        elif pilihan == "6":
            print("Terima kasih, program selesai.")
            running = False

        else:
            print("Pilihan tidak valid!")

if __name__ == "__main__":
    main()
