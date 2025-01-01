#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 10

// Struktur untuk mendefinisikan segmen dalam memori
typedef struct {
    int segment_id;
    int size;
    int *base_address;
} Segment;

// Fungsi untuk membuat segmen
void createSegment(Segment *segment, int id, int size) {
    segment->segment_id = id;
    segment->size = size;
    segment->base_address = (int *)malloc(size * sizeof(int)); // Alokasi memori untuk segmen
    if (segment->base_address == NULL) {
        printf("Gagal mengalokasikan memori untuk segmen %d\n", id);
        exit(1);
    }
    printf("Segmen %d dibuat dengan ukuran %d\n", id, size);
}

// Fungsi untuk mengakses data dalam segmen
void accessSegment(Segment *segment, int offset, int value) {
    if (offset < 0 || offset >= segment->size) {
        printf("Kesalahan: Offset di luar batas segmen %d\n", segment->segment_id);
        return;
    }
    segment->base_address[offset] = value;
    printf("Nilai %d disimpan pada offset %d di segmen %d\n", value, offset, segment->segment_id);
}

// Fungsi untuk menghapus segmen
void deleteSegment(Segment *segment) {
    free(segment->base_address);
    segment->base_address = NULL;
    printf("Segmen %d dihapus\n", segment->segment_id);
}

// Fungsi untuk menampilkan semua segmen
void displaySegments(Segment *segments, int count) {
    for (int i = 0; i < count; i++) {
        printf("Segmen %d: Ukuran = %d\n", segments[i].segment_id, segments[i].size);
    }
}

int main() {
    Segment segments[MAX_SEGMENTS];
    int segmentCount, size, offset, value;

    // Meminta jumlah segmen dari pengguna
    printf("Masukkan jumlah segmen (maksimum %d): ", MAX_SEGMENTS);
    scanf("%d", &segmentCount);

    // Mengecek apakah jumlah segmen valid
    if (segmentCount <= 0 || segmentCount > MAX_SEGMENTS) {
        printf("Jumlah segmen tidak valid.\n");
        return 1;
    }

    // Membuat segmen sesuai input
    for (int i = 0; i < segmentCount; i++) {
        printf("Masukkan ukuran segmen %d: ", i + 1);
        scanf("%d", &size);
        createSegment(&segments[i], i + 1, size);
    }

    // Mengakses dan menyimpan data dalam segmen
    for (int i = 0; i < segmentCount; i++) {
        printf("Masukkan offset untuk segmen %d: ", i + 1);
        scanf("%d", &offset);
        printf("Masukkan nilai untuk offset %d pada segmen %d: ", offset, i + 1);
        scanf("%d", &value);
        accessSegment(&segments[i], offset, value);
    }

    // Menampilkan informasi segmen
    displaySegments(segments, segmentCount);

    // Menghapus segmen
    for (int i = 0; i < segmentCount; i++) {
        deleteSegment(&segments[i]);
    }

    return 0;
}
