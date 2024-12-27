#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10
#define MAX_FILES 10

// Fungsi untuk menampilkan alokasi memori
void displayMemoryAllocation(int memory[MAX_BLOCKS], int numBlocks, int blockSize[MAX_BLOCKS]) {
    printf("\nMemory Allocation:\n");
    for (int i = 0; i < numBlocks; i++) {
        if (memory[i] == -1)
            printf("Block %d: Empty\n", i + 1);
        else
            printf("Block %d: File %d (Size: %d)\n", i + 1, memory[i], blockSize[i]);
    }
}

// Fungsi untuk melakukan pemadatan (compaction) memori
void compaction(int memory[MAX_BLOCKS], int numBlocks, int blockSize[MAX_BLOCKS]) {
    int nextFreeBlock = 0;  // Menyimpan indeks blok memori kosong berikutnya

    // Pindahkan file-file yang sudah dialokasikan ke awal blok memori
    for (int i = 0; i < numBlocks; i++) {
        if (memory[i] != -1) {
            memory[nextFreeBlock] = memory[i];
            blockSize[nextFreeBlock] = blockSize[i];
            if (nextFreeBlock != i) {
                memory[i] = -1;  // Mengosongkan blok lama
                blockSize[i] = 0; // Menyreset ukuran blok
            }
            nextFreeBlock++;
        }
    }

    // Menandai blok sisanya sebagai kosong
    for (int i = nextFreeBlock; i < numBlocks; i++) {
        memory[i] = -1;
        blockSize[i] = 0;
    }
}

int main() {
    int memory[MAX_BLOCKS], blockSize[MAX_BLOCKS], fileSize[MAX_FILES];
    int numBlocks, numFiles;

    // Inisialisasi array memori
    for (int i = 0; i < MAX_BLOCKS; i++) {
        memory[i] = -1; // Menandakan bahwa blok kosong
        blockSize[i] = 0; // Ukuran blok adalah 0 saat kosong
    }

    // Input jumlah blok memori
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    // Input ukuran blok memori
    for (int i = 0; i < numBlocks; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input jumlah file
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    // Input ukuran file
    for (int i = 0; i < numFiles; i++) {
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    // Alokasi file ke blok memori
    for (int i = 0; i < numFiles; i++) {
        int placed = 0;
        for (int j = 0; j < numBlocks; j++) {
            if (memory[j] == -1 && blockSize[j] >= fileSize[i]) {
                memory[j] = i + 1; // Menandakan file ke-i dialokasikan ke blok j
                blockSize[j] = fileSize[i]; // Menyimpan ukuran file
                placed = 1;
                break;
            }
        }

        if (!placed) {
            printf("File %d could not be allocated to any block.\n", i + 1);
        }
    }

    // Tampilkan alokasi memori sebelum pemadatan
    printf("\nMemory Allocation before Compaction:\n");
    displayMemoryAllocation(memory, numBlocks, blockSize);

    // Lakukan pemadatan
    compaction(memory, numBlocks, blockSize);

    // Tampilkan alokasi memori setelah pemadatan
    printf("\nMemory Allocation after Compaction:\n");
    displayMemoryAllocation(memory, numBlocks, blockSize);

    return 0;
}
