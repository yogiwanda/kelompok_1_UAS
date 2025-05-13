#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

Pasien daftarPasien[MAX_PASIEN];
int jumlahPasien = 0;

RiwayatMedis daftarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

int antrian[MAX_PASIEN];
int front = -1, rear = -1;

int validasiInputAngka(const char *teks) {
    char input[100];
    int angka;
    while (1) {
        printf("%s", teks);
        scanf("%s", input);
        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
        }
        if (valid) {
            angka = atoi(input);
            return angka;
        } else {
            printf(RED "Input harus berupa angka!\n" RESET);
        }
    }
}

// Input ID (hanya angka)
int inputAngka(const char *prompt) {
    char input[100];
    int hasil;
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &hasil) == 1) {
            return hasil;
        } else {
            printf("Input tidak valid! Harus berupa angka.\n");
        }
    }
}

// Input nama (tanpa angka)
void inputNama(const char *prompt, char *nama, int maxLen) {
    char input[100];
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i])) {
                valid = 0;
                printf("Input tidak valid! Nama tidak boleh mengandung angka.\n");
                break;
            }
        }
        if (valid) {
            strncpy(nama, input, maxLen);
            return;
        }
    }
}

// Input nomor telepon (hanya angka)
void inputTelepon(const char *prompt, char *telp, int maxLen) {
    char input[100];
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                printf("Input tidak valid! Nomor telepon hanya boleh angka.\n");
                break;
            }
        }
        if (valid) {
            strncpy(telp, input, maxLen);
            return;
        }
    }
}

// Input prioritas (angka 1-3)
int inputPrioritas(const char *prompt) {
    int nilai;
    while (1) {
        nilai = inputAngka(prompt);
        if (nilai >= 1 && nilai <= 3) {
            return nilai;
        } else {
            printf("Input tidak valid! Prioritas hanya boleh antara 1 sampai 3.\n");
        }
    }
}


// Fungsi untuk menambah pasien
void tambahPasien() {
    if (jumlahPasien >= MAX_PASIEN) {
        printf(RED"Daftar pasien penuh!\n"RESET);
        return;
    }

    Pasien pasienBaru;
    char input[100];
    int valid = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // ID Pasien
    while (!valid) {
        printf("Masukkan ID Pasien: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &pasienBaru.id) == 1) {
            valid = 1;
        } else {
            printf(RED"Input tidak valid! Harus angka.\n"RESET);
        }
    }

    // Nama Pasien
    valid = 0;
    while (!valid) {
        printf("Masukkan Nama Pasien: ");
        fgets(pasienBaru.nama, sizeof(pasienBaru.nama), stdin);
        pasienBaru.nama[strcspn(pasienBaru.nama, "\n")] = '\0';

        valid = 1;
        for (int i = 0; pasienBaru.nama[i] != '\0'; i++) {
            if (isdigit(pasienBaru.nama[i])) {
                valid = 0;
                printf(RED"Nama tidak boleh mengandung angka.\n"RESET);
                break;
            }
        }
    }

    // Alamat Pasien
    printf("Masukkan Alamat Pasien: ");
    fgets(pasienBaru.alamat, sizeof(pasienBaru.alamat), stdin);
    pasienBaru.alamat[strcspn(pasienBaru.alamat, "\n")] = '\0';

    // Telepon Pasien
    valid = 0;
    while (!valid) {
        printf("Masukkan Telepon Pasien: ");
        fgets(pasienBaru.telepon, sizeof(pasienBaru.telepon), stdin);
        pasienBaru.telepon[strcspn(pasienBaru.telepon, "\n")] = '\0';

        valid = 1;
        for (int i = 0; pasienBaru.telepon[i] != '\0'; i++) {
            if (!isdigit(pasienBaru.telepon[i])) {
                valid = 0;
                printf(RED"Nomor telepon hanya boleh angka.\n"RESET);
                break;
            }
        }
    }

    // Prioritas (1-3)
    valid = 0;
    while (!valid) {
        printf("Masukkan Prioritas (1=Ringan, 2=Sedang, 3=Darurat): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &pasienBaru.prioritas) == 1 && pasienBaru.prioritas >= 1 && pasienBaru.prioritas <= 3) {
            valid = 1;
        } else {
            printf(RED"Input tidak valid! Rentang prioritas hanya 1 sampai 3.\n"RESET);
        }
    }

    daftarPasien[jumlahPasien++] = pasienBaru;
        if (rear == MAX_PASIEN - 1)
            printf(RED "Antrian penuh!\n" RESET);
        else {
            if (front == -1) front = 0;

    antrian[++rear] = pasienBaru.id;
}


    printf(GREEN"Pasien berhasil ditambahkan!\n"RESET);
}

// Fungsi untuk menghapus pasien
void hapusPasien() {
    int id = validasiInputAngka("Masukkan ID pasien yang ingin dihapus: ");
    int index = -1;
    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf(RED "Pasien tidak ditemukan.\n" RESET);
        return;
    }
    for (int i = index; i < jumlahPasien - 1; i++) {
        daftarPasien[i] = daftarPasien[i + 1];
    }
    jumlahPasien--;
    printf(GREEN"Pasien dengan ID %d berhasil dihapus!\n"RESET, id);
}

// Fungsi untuk menampilkan semua pasien
void tampilkanSemuaPasien() {
    if (jumlahPasien == 0) {
        printf(RED "Tidak ada pasien yang terdaftar.\n" RESET);
        return;
    }

    printf(BLUE"\n==== Daftar Pasien ====\n"RESET);
    printf("+-----------------------------------------+\n");

    for (int i = 0; i < jumlahPasien; i++) {
        char *kategori;
        if (daftarPasien[i].prioritas == 1) kategori = "Ringan";
        else if (daftarPasien[i].prioritas == 2) kategori = "Sedang";
        else kategori = "Berat";

        printf("| ID      : %-29d |\n", daftarPasien[i].id);
        printf("| Nama    : %-29s |\n", daftarPasien[i].nama);
        printf("| Alamat  : %-29s |\n", daftarPasien[i].alamat);
        printf("| Telepon : %-29s |\n", daftarPasien[i].telepon);
        printf("+-----------------------------------------+\n");
    }
}

// Fungsi untuk mengedit data pasien
void editPasien() {
    int id = validasiInputAngka("Masukkan ID pasien yang ingin diubah: ");
    int index = -1;

    // Cari pasien berdasarkan ID
    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf(RED "Pasien tidak ditemukan.\n" RESET);
        return;
    }

    getchar(); 

    printf("Masukkan Nama Pasien Baru: ");
    fgets(daftarPasien[index].nama, sizeof(daftarPasien[index].nama), stdin);
    daftarPasien[index].nama[strcspn(daftarPasien[index].nama, "\n")] = '\0';

    printf("Masukkan Alamat Pasien Baru: ");
    fgets(daftarPasien[index].alamat, sizeof(daftarPasien[index].alamat), stdin);
    daftarPasien[index].alamat[strcspn(daftarPasien[index].alamat, "\n")] = '\0';

    printf("Masukkan Telepon Pasien Baru: ");
    fgets(daftarPasien[index].telepon, sizeof(daftarPasien[index].telepon), stdin);
    daftarPasien[index].telepon[strcspn(daftarPasien[index].telepon, "\n")] = '\0';

    printf(GREEN "Data pasien berhasil diubah!\n" RESET);
}

// Fungsi untuk menampilkan semua pasien
void tampilkanAntrian() {
    if (front == -1 || front > rear) {
        printf(RED "Antrian kosong.\n" RESET);
        return;
    }

    printf(BLUE"\n==== Daftar Pasien Berdasarkan Antrian ====\n"RESET);
    printf("+-----------------------------------------+\n");

    for (int i = front; i <= rear; i++) {
        int id = antrian[i];
        for (int j = 0; j < jumlahPasien; j++) {
            if (daftarPasien[j].id == id) {
                printf("| ID      : %-29d |\n", daftarPasien[i].id);
                printf("| Nama    : %-29s |\n", daftarPasien[i].nama);
                printf("| Alamat  : %-29s |\n", daftarPasien[i].alamat);
                printf("| Telepon : %-29s |\n", daftarPasien[i].telepon);
                printf("+-----------------------------------------+\n");
            }
        }
    }
}

// Fungsi untuk menambah riwayat medis
void tambahRiwayat() {
    if (jumlahRiwayat >= MAX_RIWAYAT) {
        printf(RED "Penyimpanan riwayat medis penuh!\n" RESET);
        return;
    }

    int id = validasiInputAngka("Masukkan ID pasien: ");
    int ditemukan = 0;
    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].id == id) {
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf(RED "Pasien dengan ID %d tidak ditemukan.\n" RESET, id);
        return;
    }

    RiwayatMedis riwayatBaru;
    riwayatBaru.id_pasien = id;

    getchar(); // bersihkan newline

    printf("Masukkan Tanggal (DD/MM/YYYY): ");
    fgets(riwayatBaru.tanggal, sizeof(riwayatBaru.tanggal), stdin);
    riwayatBaru.tanggal[strcspn(riwayatBaru.tanggal, "\n")] = '\0';

    printf("Masukkan Diagnosis           : ");
    fgets(riwayatBaru.diagnosis, sizeof(riwayatBaru.diagnosis), stdin);
    riwayatBaru.diagnosis[strcspn(riwayatBaru.diagnosis, "\n")] = '\0';

    printf("Masukkan Pengobatan          : ");
    fgets(riwayatBaru.pengobatan, sizeof(riwayatBaru.pengobatan), stdin);
    riwayatBaru.pengobatan[strcspn(riwayatBaru.pengobatan, "\n")] = '\0';

    printf("Masukkan Nama Dokter         : ");
    fgets(riwayatBaru.dokter, sizeof(riwayatBaru.dokter), stdin);
    riwayatBaru.dokter[strcspn(riwayatBaru.dokter, "\n")] = '\0';

    daftarRiwayat[jumlahRiwayat++] = riwayatBaru;

    printf(GREEN "Riwayat berhasil ditambahkan.\n" RESET);
}


// Fungsi untuk menampilkan semua riwayat medis
void tampilkanSemuaRiwayat() {
    if (jumlahRiwayat == 0) {
        printf(RED "Belum ada riwayat medis.\n" RESET);
        return;
    }

    printf(BLUE "\nSemua Riwayat Medis:\n" RESET);
    printf("+-----------------------------------------+\n");

    for (int i = 0; i < jumlahRiwayat; i++) {
        char namaPasien[50] = "Tidak Diketahui";
        for (int j = 0; j < jumlahPasien; j++) {
            if (daftarPasien[j].id == daftarRiwayat[i].id_pasien) {
                strcpy(namaPasien, daftarPasien[j].nama);
                break;
            }
        }

        printf("| ID Pasien     : %-19d     |\n", daftarRiwayat[i].id_pasien);
        printf("| Nama Pasien   : %-19s     |\n", namaPasien);
        printf("| Tanggal       : %-19s     |\n", daftarRiwayat[i].tanggal);
        printf("| Diagnosis     : %-19s     |\n", daftarRiwayat[i].diagnosis);
        printf("| Pengobatan    : %-19s     |\n", daftarRiwayat[i].pengobatan);
        printf("| Dokter        : %-19s     |\n", daftarRiwayat[i].dokter);
        printf("+-----------------------------------------+\n");
    }
}


// Fungsi untuk menampilkan riwayat medis untuk satu pasien
void tampilkanRiwayatTertentu() {
    int id = validasiInputAngka("Masukkan ID pasien: ");
    int ada = 0;

    char namaPasien[50] = "Tidak diketahui";
    for (int j = 0; j < jumlahPasien; j++) {
        if (daftarPasien[j].id == id) {
            strcpy(namaPasien, daftarPasien[j].nama);
            break;
        }
    }

    printf(BLUE "\nRiwayat Medis untuk Pasien: %s (ID: %d)\n" RESET, namaPasien, id);
    printf("+-----------------------------------------+\n");

    for (int i = 0; i < jumlahRiwayat; i++) {
        if (daftarRiwayat[i].id_pasien == id) {
            printf("| Tanggal   : %-27s |\n", daftarRiwayat[i].tanggal);
            printf("| Diagnosis : %-27s |\n", daftarRiwayat[i].diagnosis);
            printf("| Pengobatan: %-27s |\n", daftarRiwayat[i].pengobatan);
            printf("| Dokter    : %-27s |\n", daftarRiwayat[i].dokter);
            printf("+-----------------------------------------+\n");
            ada = 1;
        }
    }
    if (!ada)
        printf(RED "Tidak ada riwayat untuk ID tersebut.\n" RESET);
}


// Fungsi untuk mencari pasien berdasarkan nama
void cariPasienNama() {
    char keyword[MAX_NAMA];
    printf("Masukkan nama yang dicari: ");
    scanf(" %[^\n]", keyword);
    int ditemukan = 0;

    printf(BLUE "\nHasil pencarian untuk '%s':\n" RESET, keyword);
    printf("+-----------------------------------------+\n");

    for (int i = 0; i < jumlahPasien; i++) {
        if (strstr(daftarPasien[i].nama, keyword) != NULL) {
            printf("| ID      : %-29d |\n", daftarPasien[i].id);
            printf("| Nama    : %-29s |\n", daftarPasien[i].nama);
            printf("| Alamat  : %-29s |\n", daftarPasien[i].alamat);
            printf("| Telepon : %-29s |\n", daftarPasien[i].telepon);
            printf("+-----------------------------------------+\n");
            ditemukan = 1;
        }
    }
    if (!ditemukan)
        printf(RED "Pasien tidak ditemukan.\n" RESET);
}

int compareID(const void *a, const void *b) {
    Pasien *pa = (Pasien *)a;
    Pasien *pb = (Pasien *)b;
    return pa->id - pb->id;
}

// Fungsi untuk mencari pasien berdasarkan ID
void cariPasienID() {
    int id = validasiInputAngka("Masukkan ID yang dicari: ");
    qsort(daftarPasien, jumlahPasien, sizeof(Pasien), compareID);

    int left = 0, right = jumlahPasien - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (daftarPasien[mid].id == id) {
            printf(BLUE "\nData Pasien Ditemukan:\n" RESET);
            printf("+-----------------------------------------+\n");
            printf("| ID      : %-29d |\n", daftarPasien[mid].id);
            printf("| Nama    : %-29s |\n", daftarPasien[mid].nama);
            printf("| Alamat  : %-29s |\n", daftarPasien[mid].alamat);
            printf("| Telepon : %-29s |\n", daftarPasien[mid].telepon);
            printf("+-----------------------------------------+\n");
            return;
        } else if (daftarPasien[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf(RED "Pasien tidak ditemukan.\n" RESET);
}


void quickSort(int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    Pasien pivot = daftarPasien[(left + right) / 2];
    while (i <= j) {
        while (daftarPasien[i].prioritas > pivot.prioritas) i++;
        while (daftarPasien[j].prioritas < pivot.prioritas) j--;
        if (i <= j) {
            Pasien temp = daftarPasien[i];
            daftarPasien[i] = daftarPasien[j];
            daftarPasien[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(left, j);
    quickSort(i, right);
}

// Fungsi untuk mengurutkan pasien berdasarkan prioritas
void tampilkanPrioritas() {
    if (jumlahPasien == 0) {
        printf(RED "Tidak ada data pasien.\n" RESET);
        return;
    }

    quickSort(0, jumlahPasien - 1);

    printf(BLUE"\nDaftar Pasien Berdasarkan Prioritas:\n"RESET);
    printf("+----------------------------------------------------+\n");

    for (int i = 0; i < jumlahPasien; i++) {
        char *kategori;
        if (daftarPasien[i].prioritas == 1) kategori = "Ringan";
        else if (daftarPasien[i].prioritas == 2) kategori = "Sedang";
        else kategori = "Berat";

       printf("| ID: %-5d | Nama: %-10s | Prioritas: %-8d |\n",
            daftarPasien[i].id,
            daftarPasien[i].nama,
            daftarPasien[i].prioritas);
        printf("+----------------------------------------------------+\n");
    }
}
