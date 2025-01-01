#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_PAGES 20

void main() {
    int ms, ps, nop,np, rempages, i, j, x, y, pa, offset;
    int s[MAX_PROCESSES], fno[MAX_PROCESSES][MAX_PAGES];

    // Input ukuran memori
    printf("Enter the memory size (in bytes): ");
    scanf("%d", &ms);

    // Input ukuran halaman
    printf("Enter the page size (in bytes): ");
    scanf("%d", &ps);

    // Hitung jumlah halaman yang tersedia di memori
    nop = ms / ps;
    printf("\nThe number of pages available in memory are: %d", nop);

    // Input jumlah proses
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    rempages = nop; // Sisa halaman yang tersedia
    for (i = 0; i < np; i++) {
        // Input jumlah halaman yang dibutuhkan untuk proses i
        printf("\nEnter the number of pages required for process %d: ", i);
        scanf("%d", &s[i]);

        // Periksa apakah memori cukup untuk halaman yang dibutuhkan
        if (s[i] > rempages) {
            printf("\nMemory is Full");
            break;
        }

        rempages -= s[i];

        // Input tabel halaman untuk proses i
        printf("\nEnter the page table for process %d: ", i);
        for (j = 0; j < s[i]; j++) {
            scanf("%d", &fno[i][j]);
        }
    }

    // Input alamat logis untuk menemukan alamat fisik
    printf("\nEnter logical address to find physical address");
    printf("\nEnter process number, page number, and offset: ");
    scanf("%d %d %d", &x, &y, &offset);

    // Validasi input
    if (x >= nop || y >= s[x] || offset >= ps) {
        printf("\nInvalid Process Number, Page Number, or Offset");
    } else {
        // Hitung alamat fisik
        pa = (fno[x][y] * ps) + offset;
        printf("\nPhysical Address: %d", pa);
    }
}