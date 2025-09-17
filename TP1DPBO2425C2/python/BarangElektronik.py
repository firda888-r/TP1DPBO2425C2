class BarangElektronik:
    #Atribut dari BarangElektronik
    def __init__(self, nama_barang="", harga=0, notel_toko="", alamat=""):
        self.nama_barang = nama_barang
        self.harga = harga
        self.notel_toko = notel_toko
        self.alamat = alamat

    # GET & SET
    def setNama(self, nama_barang):
        self.nama_barang = nama_barang

    def getNama(self):
        return self.nama_barang

    def setHargaBarang(self, harga):
        self.harga = harga

    def getHargaBarang(self):
        return self.harga

    def setNoTeleponToko(self, notel_toko):
        self.notel_toko = notel_toko

    def getNoTeleponToko(self):
        return self.notel_toko

    def setAlamatToko(self, alamat):
        self.alamat = alamat

    def getAlamatToko(self):
        return self.alamat
    

    # tambah barang #
    def addBarang(self, nama_barang, harga, notel_toko, alamat):
        self.nama_barang = nama_barang
        self.harga = harga
        self.notel_toko = notel_toko
        self.alamat = alamat

    # tampilkan barang
    def tampilkanDataBarang(self):
        print(f"Nama Barang : {self.nama_barang}")
        print(f"Harga Barang : {self.harga}")
        print(f"Nomor Tel Toko : {self.notel_toko}")
        print(f"Alamat Toko : {self.alamat}")
        print("\n---------------------------\n")

    # update barang
    def updateBarang(self, nama_barang, harga, notel_toko, alamat):
        self.nama_barang = nama_barang
        self.harga = harga
        self.notel_toko = notel_toko
        self.alamat = alamat


    def delete_barang(self, nama):
        for barang in self.barang_list:
            if barang["nama"] == nama:
                self.barang_list.remove(barang)
                print(f"Barang '{nama}' berhasil dihapus.")
                return
        print(f"Barang '{nama}' tidak ditemukan.")

    