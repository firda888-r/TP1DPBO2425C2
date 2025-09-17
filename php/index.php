<?php
session_start();

if (isset($_POST['tambah'])) {
    $nama = $_POST['nama'];
    $harga = $_POST['harga'];
    $notel = $_POST['notel'];
    $alamat = $_POST['alamat'];

    //Bagian upload gambar
    $targetDir = "images/"; // folder penyimpanan yang bernama images
    if (!is_dir($targetDir)) {
        mkdir($targetDir); // jika belum buat folder baru
    }

    $gambar = "";
    if (!empty($_FILES["gambar"]["name"])) {
        $fileName = basename($_FILES["gambar"]["name"]);
        $targetFile = $targetDir . time() . "_" . $fileName; // biar unik

        if (move_uploaded_file($_FILES["gambar"]["tmp_name"], $targetFile)) { //untuk memindahkan gambar yang diupload user ke folder images
            $gambar = $targetFile;
        }
    }

    $barang = [
        'nama' => $nama,
        'harga' => $harga,
        'notel' => $notel,
        'alamat' => $alamat,
        'gambar' => $gambar
    ];

    $_SESSION['barang'][] = $barang;
}

// Proses hapus barang
if (isset($_GET['hapus'])) {
    $index = $_GET['hapus'];
    unset($_SESSION['barang'][$index]);
    $_SESSION['barang'] = array_values($_SESSION['barang']); // reset index array
}
//Bagian layouting ukuran type dll
?>
<!DOCTYPE html>
<html lang="id">
<head>  
    <meta charset="UTF-8">
    <title>Data Barang Elektronik</title>
    <style>
        body { font-family: Arial, sans-serif; padding: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        table, th, td { border: 1px solid black; }
        th, td { padding: 10px; text-align: center; }
        img { max-width: 100px; }
        form { margin-bottom: 20px; }
        input[type=text], input[type=number], input[type=file] { width: 100%; padding: 5px; margin: 5px 0; }
        input[type=submit] { padding: 8px 15px; }
    </style>
</head>
<body>
    <h2>Form Tambah Barang Elektronik</h2>
    <form method="post" enctype="multipart/form-data">
        <label>Nama Barang:</label><br>
        <input type="text" name="nama" required><br>

        <label>Harga Barang:</label><br>
        <input type="number" name="harga" required><br>

        <label>No. Telepon Toko:</label><br>
        <input type="text" name="notel" required><br>

        <label>Alamat Toko:</label><br>
        <input type="text" name="alamat" required><br>

        <label>Upload Gambar:</label><br>
        <input type="file" name="gambar" accept="image/*"><br><br>

        <input type="submit" name="tambah" value="Tambah Barang">
    </form>

    <h2>Daftar Barang Elektronik</h2>
    <table>
        <tr>
            <th>No</th>
            <th>Gambar</th>
            <th>Nama Barang</th>
            <th>Harga</th>
            <th>No. Telepon Toko</th>
            <th>Alamat</th>
            <th>Aksi</th>
        </tr>
        <?php if (empty($_SESSION['barang'])): ?>
            <tr>
                <td colspan="7">Belum ada data barang.</td>
            </tr>
        <?php else: ?>
            <?php foreach ($_SESSION['barang'] as $i => $b): ?>
                <tr>
                    <td><?= $i + 1 ?></td>
                    <td>
                        <?php if (!empty($b['gambar'])): ?>
                            <img src="<?= htmlspecialchars($b['gambar']) ?>" alt="Gambar">
                        <?php else: ?>
                            (Tidak ada gambar)
                        <?php endif; ?>
                    </td>
                    <td><?= htmlspecialchars($b['nama']) ?></td>
                    <td><?= htmlspecialchars($b['harga']) ?></td>
                    <td><?= htmlspecialchars($b['notel']) ?></td>
                    <td><?= htmlspecialchars($b['alamat']) ?></td>
                    <td><a href="?hapus=<?= $i ?>" onclick="return confirm('Hapus barang ini?')">Hapus</a></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </table>
</body>
</html>
