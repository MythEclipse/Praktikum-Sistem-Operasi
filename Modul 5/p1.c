#include <stdio.h>

struct file {
    int all[10];  // Alokasi Array
    int max[10];  // Maximum Array
    int need[10]; // Need Array
    int flag;     // Flag Untuk Tanda Proses Dikunjungi
};

int main() {
    struct file f[10];
    int fl = 0, i, j, k, p, b, n, r, g, cnt = 0, id, newr;
    int avail[10], seq[10];

    // Input jumlah proses
    printf("Enter number of processes -- ");
    scanf("%d", &n);

    // Input jumlah sumber daya
    printf("Enter number of resources -- ");
    scanf("%d", &r);

    // Input alokasi dan maksimum
    for (i = 0; i < n; i++) {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for (j = 0; j < r; j++) {
            scanf("%d", &f[i].all[j]);
        }

        printf("Enter Max -- ");
        for (j = 0; j < r; j++) {
            scanf("%d", &f[i].max[j]);
        }
        f[i].flag = 0; // Set flag ke 0 (belum dikunjungi)
    }

    // Input sumber daya yang tersedia
    printf("\nEnter Available Resources -- ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    // Input permintaan baru
    printf("\nEnter New Request Details\n");
    printf("Enter process ID -- ");
    scanf("%d", &id);

    printf("Enter Request For Resources -- ");
    for (i = 0; i < r; i++) {
        scanf("%d", &newr);
        f[id].all[i] += newr;
        avail[i] -= newr;
    }

    // Hitung matriks Need
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            f[i].need[j] = f[i].max[j] - f[i].all[j];
            if (f[i].need[j] < 0) {
                f[i].need[j] = 0;
            }
        }
    }

    // Algoritma Bankir
    cnt = 0;
    while (cnt != n) {
        g = 0;
        for (j = 0; j < n; j++) {
            if (f[j].flag == 0) { // Jika proses belum dikunjungi
                b = 0;
                for (p = 0; p < r; p++) {
                    if (avail[p] >= f[j].need[p]) {
                        b++;
                    }
                }
                if (b == r) { // Semua sumber daya mencukupi
                    printf("\nP%d is visited", j);
                    seq[fl++] = j;
                    f[j].flag = 1; // Tandai proses sebagai dikunjungi
                    for (k = 0; k < r; k++) {
                        avail[k] += f[j].all[k];
                    }
                    cnt++;
                    g = 1;
                }
            }
        }
        if (g == 0) {
            printf("\nREQUEST NOT GRANTED -- DEADLOCK OCCURRED");
            printf("\nSYSTEM IN UNSAFE STATE");
            return 1;
        }
    }

    // Sistem dalam keadaan aman
    printf("\nSYSTEM IS IN SAFE STATE");
    printf("\nThe safe sequence is: ");
    for (i = 0; i < fl; i++) {
        printf("P%d ", seq[i]);
    }
    printf("\n");

    // Tampilkan detail proses
    printf("\nProcess\t\tAllocation\t\tMax\t\tNeed\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t", i);
        for (j = 0; j < r; j++) {
            printf("%3d ", f[i].all[j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%3d ", f[i].max[j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%3d ", f[i].need[j]);
        }
        printf("\n");
    }

    return 0;
}
