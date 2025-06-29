# Sistem Manajemen Pasien (SIMAPAN)

SIMAPAN adalah sistem manajemen pasien berbasis terminal yang dirancang untuk memudahkan pengelolaan data pasien, riwayat medis, antrian pasien, dan prioritas pengobatan di fasilitas kesehatan. Dengan antarmuka berbasis teks, SIMAPAN menyediakan cara yang sederhana namun efektif untuk mengelola berbagai informasi medis.

## Kelebihan SIMAPAN

- **Manajemen Data Pasien yang Efisien**: SIMAPAN memungkinkan pengguna untuk dengan mudah menambah, mengedit, dan menghapus data pasien.
- **Riwayat Medis Tersimpan dengan Rapi**: Sistem menyimpan riwayat medis setiap pasien, sehingga memudahkan pelacakan dan pemantauan kesehatan pasien.
- **Pencarian Pasien yang Cepat**: Pengguna dapat dengan mudah mencari pasien berdasarkan nama atau ID untuk akses yang lebih cepat.
- **Pengelolaan Antrian Pasien**: Sistem ini menyediakan fitur untuk menampilkan antrian pasien berdasarkan prioritas, memastikan pasien dengan tingkat urgensi yang lebih tinggi mendapatkan perhatian terlebih dahulu.
- **Prioritas Pasien yang Jelas**: Pasien dapat diprioritaskan berdasarkan tingkat urgensi pengobatan, memudahkan alur perawatan yang lebih terstruktur.

## Cara Penggunaan SIMAPAN

Disini kami akan menjelaskan cara menjalankan program SIMAPAN yang telah kami buat. Berikut petunjuk untuk menjalankan program SIMAPAN:

1. Buka Terminal (CMD/Powershell), pastikan direktori terminal saat ini berada di folder kelompok_1_UAS

2. Lakukan compile file main.c dengan menjalankan perintah berikut di terminal: gcc main.c fungsi.c -o simapan

3. Lakukan sign up dengan cara menjalankan hasil compile main.c. jalankan perintah berikut: ./simapan

Setelah Anda berhasil menjalankan SIMAPAN, Anda akan melihat menu utama yang menawarkan berbagai pilihan untuk mengelola data pasien dan riwayat medis. Berikut adalah cara menggunakan setiap fitur:

1. **Manajemen Pasien**  
   Anda dapat memilih opsi ini untuk menambah, mengedit, menghapus, atau melihat data pasien yang sudah ada.  
   - Tambah Pasien: Masukkan data pasien baru (nama, ID, alamat, dll.).
   - Edit Pasien: Ubah informasi pasien yang sudah ada.
   - Hapus Pasien: Hapus data pasien yang sudah tidak dibutuhkan.
   - Lihat Semua Pasien: Menampilkan daftar lengkap pasien yang terdaftar.

2. **Riwayat Medis Pasien**  
   Di submenu ini, Anda bisa mengelola riwayat medis pasien.  
   - Tambah Riwayat Medis: Masukkan informasi riwayat medis baru untuk pasien tertentu.
   - Lihat Semua Riwayat Medis: Menampilkan riwayat medis lengkap pasien yang terdaftar.
   - Lihat Riwayat Medis Pasien Tertentu: Cari dan tampilkan riwayat medis pasien berdasarkan ID atau nama.

3. **Cari Pasien**  
   Gunakan submenu ini untuk mencari pasien berdasarkan ID atau nama, sehingga Anda dapat dengan mudah menemukan data pasien yang diperlukan.

4. **Tampilkan Antrian Pasien**  
   Fitur ini menampilkan daftar pasien berdasarkan urutan antrian.

5. **Tampilkan Berdasarkan Prioritas**  
   Menampilkan daftar pasien dengan prioritas pengobatan (Ringan, Sedang, Berat), untuk membantu memudahkan penanganan pasien yang membutuhkan perawatan segera.

## Menu Utama

Setelah menjalankan program, Anda akan disajikan dengan menu berikut:

1. **Manajemen Pasien**
2. **Riwayat Medis Pasien**
3. **Cari Pasien**
4. **Tampilkan Antrian**
5. **Tampilkan Berdasarkan Prioritas**
0. **Keluar**

Setiap menu dapat diakses dengan memilih nomor yang sesuai, dan program akan memberi petunjuk lebih lanjut untuk setiap pilihan.

Dengan menggunakan SIMAPAN, pengelolaan data pasien menjadi lebih terstruktur dan efisien. Sistem ini sangat cocok untuk rumah sakit atau klinik yang ingin mempermudah manajemen data pasien secara digital.

