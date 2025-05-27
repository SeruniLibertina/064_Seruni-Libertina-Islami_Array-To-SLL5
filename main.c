#include "kota.h"

int main(void) {
    int pilihan;
    char kota[MAX_STR], orang[MAX_STR];

    initKota();
    do {
        puts("\n=== MENU ===");
        puts("1. Tambah Kota");
        puts("2. Tambah Nama pada Kota");
        puts("3. Hapus Kota");
        puts("4. Hapus Orang dari Kota");
        puts("5. Tampilkan Semua");
        puts("6. Tampilkan per Kota");
        puts("0. Keluar");
        printf("Pilihan: "); scanf("%d", &pilihan); getchar();

        switch (pilihan) {
            case 1:
                printf("Nama kota: ");
                fgets(kota, sizeof kota, stdin);
                kota[strcspn(kota, "\n")] = 0;
                tambahKota(kota);
                break;
            case 2:
                printf("Nama kota: ");
                fgets(kota, sizeof kota, stdin);
                kota[strcspn(kota, "\n")] = 0;
                printf("Nama orang: ");
                fgets(orang, sizeof orang, stdin);
                orang[strcspn(orang, "\n")] = 0;
                tambahOrang(kota, orang);
                break;
            case 3:
                printf("Nama kota: ");
                fgets(kota, sizeof kota, stdin);
                kota[strcspn(kota, "\n")] = 0;
                if (hapusKota(kota)) printf("Kota dihapus.\n");
                else printf("Kota tidak ditemukan.\n");
                break;
            case 4:
                printf("Nama kota: ");
                fgets(kota, sizeof kota, stdin);
                kota[strcspn(kota, "\n")] = 0;
                printf("Nama orang: ");
                fgets(orang, sizeof orang, stdin);
                orang[strcspn(orang, "\n")] = 0;
                if (hapusOrang(kota, orang)) printf("Orang dihapus.\n");
                else printf("Orang atau kota tidak ditemukan.\n");
                break;
            case 5:
                tampilkanSemua();
                break;
            case 6:
                printf("Nama kota: ");
                fgets(kota, sizeof kota, stdin);
                kota[strcspn(kota, "\n")] = 0;
                tampilkanPerKota(kota);
                break;
            case 0:
                puts("Keluar.");
                break;
            default:
                puts("Pilihan tidak valid.");
        }
    } while (pilihan != 0);

    return 0;
}
