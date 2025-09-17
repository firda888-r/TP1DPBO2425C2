import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BarangElektronik[] barang = new BarangElektronik[10];
        int n = 0;
        boolean running = true;

        while (running) {
            System.out.println("\n=== MENU TOKO ELEKTRONIK ===");
            System.out.println("1. Tambah Barang");
            System.out.println("2. Tampilkan Semua Barang");
            System.out.println("3. Hapus Barang");
            System.out.println("4. Cari Barang");
            System.out.println("5. Update Barang");
            System.out.println("6. Keluar");
            System.out.print("Pilih menu: ");
            int pilihan = sc.nextInt();
            sc.nextLine(); // buang newline

            if (pilihan == 1) {
                System.out.print("Masukkan Nama Barang: ");
                String nama = sc.nextLine();
                System.out.print("Masukkan Harga: ");
                int harga = sc.nextInt();
                sc.nextLine();
                System.out.print("Masukkan No Telp Toko: ");
                String notel = sc.nextLine();
                System.out.print("Masukkan Alamat Toko: ");
                String alamat = sc.nextLine();

                barang[n] = new BarangElektronik();
                barang[n].addBarang(nama, harga, notel, alamat);
                n++;
                System.out.println("Barang berhasil ditambahkan!");

            } else if (pilihan == 2) {
                System.out.println("\n=== Daftar Barang ===");
                for (int i = 0; i < n; i++) {
                    barang[i].tampilkanDataBarang();
                }

            } else if (pilihan == 3) {
                System.out.print("Masukkan nama barang yang akan dihapus: ");
                String target = sc.nextLine();
                if (n > 0) {
                    barang[0].deleteData(barang, n, target);
                    n--; // kurangi jumlah data
                } else {
                    System.out.println("Belum ada barang!");
                }

            } else if (pilihan == 4) {
                System.out.print("Masukkan nama barang yang dicari: ");
                String target = sc.nextLine();
                if (n > 0) {
                    barang[0].searchThing(barang, n, target);
                } else {
                    System.out.println("Belum ada barang!");
                }

            } else if (pilihan == 5) {
                System.out.print("Masukkan nama barang yang akan di-update: ");
                String target = sc.nextLine();
                boolean found = false;
                for (int i = 0; i < n; i++) {
                    if (barang[i].getNama().equals(target)) {
                        System.out.print("Masukkan Nama Baru: ");
                        String namaBaru = sc.nextLine();
                        System.out.print("Masukkan Harga Baru: ");
                        int hargaBaru = sc.nextInt();
                        sc.nextLine();
                        System.out.print("Masukkan No Telp Toko Baru: ");
                        String notelBaru = sc.nextLine();
                        System.out.print("Masukkan Alamat Toko Baru: ");
                        String alamatBaru = sc.nextLine();

                        barang[i].updateBarang(namaBaru, hargaBaru, notelBaru, alamatBaru);
                        System.out.println("Data berhasil diupdate!");
                        found = true;
                    }
                }
                if (!found) {
                    System.out.println("Barang dengan nama tersebut tidak ditemukan!");
                }

            } else if (pilihan == 6) {
                System.out.println("Terima kasih, program selesai.");
                running = false;
            }
        }

        sc.close();
    }
}
