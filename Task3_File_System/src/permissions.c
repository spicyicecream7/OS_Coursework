#include <stdio.h>
#include <sys/stat.h>

#include "../include/permissions.h"

#define MAX_FILENAME 100

/* Display file permissions */
void show_permissions()
{
    char filename[MAX_FILENAME];
    struct stat fileStat;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) != 0)
    {
        printf("Error: Cannot access file.\n");
        return;
    }

    printf("\n===== File Permissions =====\n");

    printf("Read    : %s\n",
           (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");

    printf("Write   : %s\n",
           (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");

    printf("Execute : %s\n",
           (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");

    printf("============================\n");
}

/* Display file information */
void show_file_info()
{
    char filename[MAX_FILENAME];
    struct stat fileStat;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) != 0)
    {
        printf("Error: Cannot access file.\n");
        return;
    }

    printf("\n===== File Information =====\n");

    printf("File Size : %ld bytes\n",
           fileStat.st_size);

    printf("Permissions : ");

    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");

    printf("\n");

    printf("============================\n");
}
