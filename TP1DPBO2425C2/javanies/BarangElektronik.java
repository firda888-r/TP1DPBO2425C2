class BarangElektronik {
    private String namaBarang;
    private int harga;
    private String noTelToko;
    private String alamat;

    // Konstruktor kosong
    public BarangElektronik() {
    }

    // Getter & Setter
    public void setNama(String namaBarang) {
        this.namaBarang = namaBarang;
    }

    public String getNama() {
        return this.namaBarang;
    }

    public void setHargaBarang(int harga) {
        this.harga = harga;
    }

    public int getHargaBarang() {
        return this.harga;
    }

    public void setNoTeleponToko(String noTelToko) {
        this.noTelToko = noTelToko;
    }

    public String getNoTeleponToko() {
        return this.noTelToko;
    }

    public void setAlamatToko(String alamat) {
        this.alamat = alamat;
    }

    public String getAlamatToko() {
        return this.alamat;
    }

    // Tambah barang
    public void addBarang(String namaBarang, int harga, String noTelToko, String alamat) {
        this.namaBarang = namaBarang;
        this.harga = harga;
        this.noTelToko = noTelToko;
        this.alamat = alamat;
    }

    // Tampilkan data barang
    public void tampilkanDataBarang() {
        System.out.println("Nama Barang : " + namaBarang);
        System.out.println("Harga Barang : " + harga);
        System.out.println("Nomor Tel Toko : " + noTelToko);
        System.out.println("Alamat Toko : " + alamat);
        System.out.println("\n..............................\n");
    }

    // Update barang
    public void updateBarang(String namaBarang, int harga, String noTelToko, String alamat) {
        this.namaBarang = namaBarang;
        this.harga = harga;
        this.noTelToko = noTelToko;
        this.alamat = alamat;
    }

    // Hapus data
    public void deleteData(BarangElektronik[] barang, int n, String target) {
        boolean found = false;

        for (int i = 0; i < n; i++) {
            if (barang[i].namaBarang != null && barang[i].namaBarang.equals(target)) {
                for (int j = i; j < n - 1; j++) {
                    barang[j] = barang[j + 1];
                }
                barang[n - 1] = null;
                System.out.println("Barang berhasil dihapus!");
                found = true;
            }
        }
        if (!found) {
            System.out.println("Barang dengan nama tersebut tidak ditemukan!");
        }
    }
    

    // Cari barang
    public void searchThing(BarangElektronik[] barang, int n, String target) {
        boolean found = false;

        for (int i = 0; i < n; i++) {
            if (barang[i].namaBarang != null && barang[i].namaBarang.equals(target)) {  //jika nama barang ada dan sama dengan target maka tampilkan pesan "Barang ditemukan"
                System.out.println("Barang ditemukan");
                barang[i].tampilkanDataBarang();  //tampilkan data barang
                found = true; //maka found menjadi true
            }
        }
        if (!found) {  //jika target tidak ketemu maka tampilkan pesan barang tidak tersedia
            System.out.println("Barang tidak tersedia");
        }
        
    }
}