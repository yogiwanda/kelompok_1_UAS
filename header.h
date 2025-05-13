#ifndef PASIEN_H
#define PASIEN_H

#define MAX_PASIEN 100
#define MAX_NAMA 50
#define MAX_ALAMAT 100
#define MAX_TELEPON 20
#define MAX_PENYAKIT 100
#define MAX_DOKTER 50
#define MAX_TANGGAL 15
#define MAX_RIWAYAT 100

// ANSI WARNA
#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define BLUE   "\033[1;34m"

typedef struct {
    int id;
    char nama[MAX_NAMA];
    char alamat[MAX_ALAMAT];
    char telepon[MAX_TELEPON];
    int prioritas;
} Pasien;

typedef struct {
    int id_pasien;
    char tanggal[MAX_TANGGAL];
    char diagnosis[MAX_PENYAKIT];
    char pengobatan[MAX_PENYAKIT];
    char dokter[MAX_DOKTER];
} RiwayatMedis;

// Variabel Global
extern Pasien daftarPasien[MAX_PASIEN];
extern int jumlahPasien;

extern RiwayatMedis daftarRiwayat[MAX_RIWAYAT];
extern int jumlahRiwayat;

extern int antrian[MAX_PASIEN];
extern int front, rear;

// Fungsi
void tampilkanMenuUtama();
void tampilkanSubmenuManajemen();
void tampilkanSubmenuRiwayat();
void tampilkanSubmenuCari();

void tambahPasien();
void hapusPasien();
void editPasien();
void tampilkanSemuaPasien();

void tambahRiwayat();
void tampilkanSemuaRiwayat();
void tampilkanRiwayatTertentu();

void cariPasienNama();    
void cariPasienID();      

void tampilkanAntrian();  
void tampilkanPrioritas(); 

int validasiInputAngka(const char *teks);

#endif
