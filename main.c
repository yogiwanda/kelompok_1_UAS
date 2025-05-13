// main.c

#include <stdio.h>
#include "pasien.h"

void tampilkanSubmenuManajemen() {
    int pilih;
    do {
        printf(BLUE "\n-- SUBMENU MANAJEMEN PASIEN --\n" RESET);
        printf("1. Tambah Pasien\n");
        printf("2. Hapus Pasien\n");
        printf("3. Edit Pasien\n");
        printf("4. Lihat Semua Pasien\n");
        printf("0. Kembali\n");
        pilih = validasiInputAngka("Pilih: ");

        switch (pilih) {
            case 1: tambahPasien(); break;
            case 2: hapusPasien(); break;
            case 3: editPasien(); break;
            case 4: tampilkanSemuaPasien(); break;
            case 0: break;
            default: printf(RED "Pilihan tidak valid.\n" RESET);
        }
    } while (pilih != 0);
}

void tampilkanSubmenuRiwayat() {
    int pilih;
    do {
        printf(BLUE "\n=== SUBMENU RIWAYAT MEDIS ===\n" RESET);
        printf("1. Tambah Riwayat Medis\n");
        printf("2. Lihat Semua Riwayat Medis\n");
        printf("3. Lihat Riwayat Medis Pasien Tertentu\n");
        printf("0. Kembali\n");
        pilih = validasiInputAngka("Pilih: ");

        switch (pilih) {
            case 1: tambahRiwayat(); break;
            case 2: tampilkanSemuaRiwayat(); break;
            case 3: tampilkanRiwayatTertentu(); break;
            case 0: break;
            default: printf(RED "Pilihan tidak valid.\n" RESET);
        }
    } while (pilih != 0);
}

void tampilkanSubmenuCari() {
    int pilih;
    do {
        printf(BLUE "\n=== SUBMENU CARI PASIEN ===\n" RESET);
        printf("1. Berdasarkan Nama\n");
        printf("2. Berdasarkan ID\n");
        printf("0. Kembali\n");
        pilih = validasiInputAngka("Pilih: ");

        switch (pilih) {
            case 1: cariPasienNama(); break;
            case 2: cariPasienID(); break;
            case 0: break;
            default: printf(RED "Pilihan tidak valid.\n" RESET);
        }
    } while (pilih != 0);
}

int main() {
    int pilihan;
    do {
        printf(BLUE"\n Selamat Datang di SIMAPAN!"RESET);
        printf("\n========== Menu  ==========\n");
        printf("1. Manajemen Pasien\n");
        printf("2. Riwayat Medis Pasien\n");
        printf("3. Cari Pasien\n");
        printf("4. Tampilkan Antrian\n");
        printf("5. Tampilkan Berdasarkan Prioritas\n");
        printf("0. Keluar\n");

        pilihan = validasiInputAngka("Pilih menu: ");

        switch (pilihan) {
            case 1: tampilkanSubmenuManajemen(); break;
            case 2: tampilkanSubmenuRiwayat(); break;
            case 3: tampilkanSubmenuCari(); break;
            case 4: tampilkanAntrian(); break;
            case 5: tampilkanPrioritas(); break;
            case 0: printf(GREEN "Program selesai.\n" RESET); break;
            default: printf(RED "Pilihan tidak valid.\n" RESET);
        }
    } while (pilihan != 0);

    return 0;
}
