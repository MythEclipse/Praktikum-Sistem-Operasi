#include <stdio.h>

#define MAX_PAGES 3
#define PAGE_SIZE 100  // Ukuran setiap halaman dalam byte
#define MAX_FRAMES 3

// Tabel halaman untuk dua tingkat
int pageTable1[MAX_PAGES];   // Tabel halaman tingkat pertama
int pageTable2[MAX_PAGES];   // Tabel halaman tingkat kedua
int frameTable[MAX_FRAMES];  // Tabel frame fisik

// Fungsi untuk menginisialisasi tabel frame
void initializeFrameTable() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frameTable[i] = -1;  // -1 menunjukkan frame kosong
    }
    for (int i = 0; i < MAX_PAGES; i++) {
        pageTable1[i] = -1;  // -1 menunjukkan halaman kosong
        pageTable2[i] = -1;  // -1 menunjukkan halaman kosong
    }
}

// Fungsi untuk menerjemahkan alamat virtual menjadi alamat fisik
void translateAddress(int virtualAddress) {
    int page1Index, page2Index, offset;

    // Pembagian alamat virtual menjadi 3 bagian
    // Misalkan kita menggunakan 2 bit untuk page directory index
    // 2 bit untuk page table index
    // Dan 7 bit untuk offset (untuk ukuran halaman 100 byte)
    page1Index = (virtualAddress >> 7) & 0x03;  // Indeks untuk page directory (2 bit pertama)
    page2Index = (virtualAddress >> 2) & 0x03;  // Indeks untuk page table (2 bit berikutnya)
    offset = virtualAddress & 0x7F;  // Offset (7 bit terakhir)

    // Cek apakah halaman tingkat pertama valid
    if (pageTable1[page1Index] == -1) {
        printf("Page 1 not found in memory.\n");
        return;
    }

    // Cek apakah halaman tingkat kedua valid
    if (pageTable2[page2Index] == -1) {
        printf("Page 2 not found in memory.\n");
        return;
    }

    // Dapatkan nomor frame dari frameTable
    int frameNumber = frameTable[pageTable2[page2Index]];

    // Hitung alamat fisik
    int physicalAddress = frameNumber * PAGE_SIZE + offset;
    printf("Physical address: %d\n", physicalAddress);
}

int main() {
    int numPages;

    // Inisialisasi tabel frame
    initializeFrameTable();

    // Input jumlah halaman
    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    // Input halaman tingkat pertama
    printf("Enter page table 1 (frame numbers):\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page 1 entry %d: ", i);
        scanf("%d", &pageTable1[i]);
    }

    // Input halaman tingkat kedua
    printf("Enter page table 2 (frame numbers):\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page 2 entry %d: ", i);
        scanf("%d", &pageTable2[i]);
    }

    // Input frame yang terkait
    printf("Enter physical frames (for frame table):\n");
    for (int i = 0; i < numPages; i++) {
        printf("Frame entry %d: ", i);
        scanf("%d", &frameTable[i]);
    }

    // Input alamat virtual untuk diterjemahkan
    int virtualAddress;
    printf("Enter virtual address to translate: ");
    scanf("%d", &virtualAddress);

    // Terjemahkan alamat virtual ke alamat fisik
    translateAddress(virtualAddress);

    return 0;
}
