# SELAMAT DATANG DI PROJEK SIMAPAN (SISTEM MANAJEMEN PASIEN)

Proyek ini adalah aplikasi manajemen data pasien yang dibuat menggunakan bahasa pemrograman C.  
Aplikasi ini memiliki fitur untuk menambah, mengedit, menghapus, dan menampilkan data pasien serta riwayat medis mereka.

Berikut petunjuk untuk menjalankan program:

---

### 1. Buka Terminal (CMD/PowerShell)
Pastikan direktori terminal saat ini berada di folder yang berisi file program (`simapan`).

### 2. Compile file dengan perintah berikut:
```bash
gcc pasien.c main.c simapan.c -o simapan
```

### 3. Jalankan hasil compile dengan perintah:
```bash
./simapan
```

---

### 4. Menu utama akan tampil seperti berikut:
```
Selamat Datang di SIMAPAN!
========= Menu =========
1. Tambah Pasien
2. Hapus Pasien
3. Tampilkan Pasien
4. Edit Pasien
5. Cari Pasien
6. Tambah Riwayat Medis
7. Tampilkan Semua Riwayat Medis
8. Tampilkan Riwayat Pasien Tertentu
9. Tampilkan Pasien Berdasarkan Prioritas
0. Keluar
```

---

### 5. Penjelasan Setiap Menu:

- **1. Tambah Pasien**  
  Digunakan untuk menambahkan data pasien baru ke dalam sistem, seperti nama, umur, jenis kelamin, dan lain-lain.

- **2. Hapus Pasien**  
  Menghapus data pasien berdasarkan ID atau kriteria tertentu.

- **3. Tampilkan Pasien**  
  Menampilkan semua data pasien yang telah tersimpan dalam sistem.

- **4. Edit Pasien**  
  Mengubah atau memperbarui data pasien yang sudah ada.

- **5. Cari Pasien**  
  Mencari pasien berdasarkan nama atau ID untuk melihat data secara spesifik.

- **6. Tambah Riwayat Medis**  
  Menambahkan catatan riwayat medis baru ke data pasien yang sudah ada.

- **7. Tampilkan Semua Riwayat Medis**  
  Menampilkan seluruh riwayat medis dari semua pasien dalam sistem.

- **8. Tampilkan Riwayat Pasien Tertentu**  
  Menampilkan riwayat medis hanya dari satu pasien tertentu yang dicari.

- **9. Tampilkan Pasien Berdasarkan Prioritas**  
  Menampilkan daftar pasien berdasarkan tingkat prioritas tertentu (misalnya kondisi darurat, penyakit kronis, dsb).

- **0. Keluar**  
  Keluar dari program SIMAPAN.

---

### 6. Cara Menggunakan:

Masukkan angka sesuai menu yang ingin dijalankan, lalu tekan **ENTER**.  
**Contoh:**  
Untuk menambah pasien, ketik `1` lalu ikuti petunjuk pengisian data di layar.

---

### Spesifikasi yang dibutuhkan:
- Program ini dijalankan di terminal yang mendukung **ANSI escape sequence** agar tampilan warna dan teks lebih jelas.
