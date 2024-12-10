#include <stdio.h>
#include <stdbool.h>

#define P 5  // Jumlah proses
#define R 3  // Jumlah jenis sumber daya

// Fungsi untuk mendeteksi deadlock
bool isSafe(int alloc[][R], int max[][R], int avail[], int n, int m) {
    int need[n][m];
    bool finish[n];
    int safeSeq[n];

    // Menghitung matriks need
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }

    int work[m];
    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[p][j];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("Deadlock detected!\n");
            return false; // Deadlock terdeteksi
        }
    }

    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return true; // Sistem aman
}

int main() {
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int max[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int avail[3] = {3, 3, 2}; // Sumber daya yang tersedia

    isSafe(alloc, max, avail, P, R);
    return 0;
}
