#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // Header untuk mkdir
#include <sys/types.h>
#include <errno.h>

// Fungsi untuk membuat direktori hierarkis
void createDirectories(const char *path) {
    char tempPath[1024];
    strcpy(tempPath, path);
    char *subPath = strtok(tempPath, "/");

    char currentPath[1024] = "";
    while (subPath != NULL) {
        strcat(currentPath, subPath);
        strcat(currentPath, "/");
        
        // Membuat direktori jika belum ada
        if (mkdir(currentPath, 0755) == 0) {
            printf("Direktori '%s' berhasil dibuat.\n", currentPath);
        } else if (errno != EEXIST) {
            perror("Gagal membuat direktori");
            exit(EXIT_FAILURE);
        }

        subPath = strtok(NULL, "/");
    }
}

int main() {
    char path[1024];

    // Meminta input path dari pengguna
    printf("Masukkan path direktori hierarkis yang ingin dibuat (contoh: dir1/dir2/dir3): ");
    scanf("%1023s", path);

    createDirectories(path);

    printf("Pembuatan direktori hierarkis selesai.\n");
    return 0;
}
