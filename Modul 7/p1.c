#include <stdio.h>
#include <conio.h>

#define Max 25

void main(){
	int Frag[Max], B[Max], F[Max], i, j, NB, NF, temp;
	static int BF[Max], FF[Max];
	
	printf("\n\tMemory Management Scheme - First Fit");
	
	// Input Jumlah Blok Memori
	printf("\nEnter The Number of Blocks : ");
	scanf("%d", &NB);
	
	// Input Jumlah File
	printf("\nEnter The Number of Files : ");
	scanf("%d", &NF);
	
	// Input Ukuran Setiap Blok Memori
	printf("\nEnter The Size of The Blocks : -\n");
	for(i = 1; i <= NB; i++){
		printf("Block %d : ", i);
		scanf("%d", &B[i]);
	}
	
	// Input Ukuran Setiap File
	printf("\nEnter The Size of The Files : -\n");
	for(i = 1; i <= NF; i++) {
    	printf("File %d : ", i);
   		scanf("%d", &F[i]);
	}

	
	// Algoritma First Fit Untuk Memetakan File Ke Blok
	for(i = 1; i <= NF; i++){
		for(j = 1; j <= NB; j++){
			if (BF[j] != 1){ // Memeriksa Apakah Blok Belum Digunakan
				temp = B[j] - F[i]; // Menghitung Fragmentasi
				if (temp >= 0){ // Jika File Bisa Masuk Ke Blok
					FF[i] = j; // Mencatat Nomor Blok Yang Digunakan
					break;
				}
			}
		}
		Frag[i] = temp; // Menyimpan Fragmentasi
		BF[FF[i]] = 1; // Menandai Blok Sudah Terpakai
	}
	
	// Output Hasil Alokasi
	printf("\nFileNo \tFileSize \tBlockNO \tBlockSize \tFragment");
	for(i = 1; i <= NF; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, F[i], FF[i], B[FF[i]], Frag[i]);
	}
	getch();
	
}
