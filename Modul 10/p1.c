#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir;

void main()
{
    int i, ch;
    char f[30];
    dir.fcnt = 0;
    // Masukkan nama direktori
    printf("\n\nEnter name of directory: ");
    scanf("%s", dir.dname);

    while (1)
    {
        // Menu pilihan
        printf("\n\n1. Create File\t2. Delete File\t3. Search File\n");
        printf("4. Display Files\tExit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // Membuat file baru
            printf("\n\nEnter file name: ");
            scanf("%s", dir.fname[dir.fcnt]);
            dir.fcnt++;
            break;
        case 2: // Menghapus file
            printf("\n\nEnter file name to delete: ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(dir.fname[i], f) == 0)
                {
                    printf("\n\nFile deleted...\n");
                    dir.fcnt--;
                    for (; i < dir.fcnt; i++)
                    {
                        strcpy(dir.fname[i], dir.fname[i + 1]);
                    }
                    dir.fcnt--; // Kurangi jumlah dir -1
                    break;
                }
            }
            if (i == dir.fcnt)
            {
                printf("\n\nFile not found.\n");
            }
            break;
        case 3: // Mencari file
            printf("\n\nEnter file name to search: ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(dir.fname[i], f) == 0)
                {
                    printf("\n\nFile found: %s\n", dir.fname[i]);
                    break;
                }
            }
            if (i == dir.fcnt)
            {
                printf("\n\nFile not found.\n");
            }
            break;
        case 4: // Menampilkan file
            if (dir.fcnt == 0)
            {
                printf("\n\nDirectory Empty.\n");
                break;
            }
            printf("\n\nThe Files are:\n");
            for (i = 0; i < dir.fcnt; i++)
            {
                printf("\t%s\n", dir.fname[i]);
            }
            break;
        case 5: // Keluar
            exit(0);
            break;
        default:
            printf("\n\nInvalid choice. Please try again.\n");
        }
    }
}