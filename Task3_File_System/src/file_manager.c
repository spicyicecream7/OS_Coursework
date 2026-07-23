#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/file_manager.h"

#define MAX_FILENAME 100
#define MAX_TEXT 1000

/* Create a new file */
void create_file()
{
    char filename[MAX_FILENAME];

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Unable to create file.\n");
        return;
    }

    fclose(file);

    printf("File '%s' created successfully.\n", filename);
}

/* Write data into a file */
void write_file()
{
    char filename[MAX_FILENAME];
    char text[MAX_TEXT];

    printf("Enter file name: ");
    scanf("%s", filename);

    getchar(); // Clear newline from input buffer

    printf("Enter text:\n");
    fgets(text, MAX_TEXT, stdin);

    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(file, "%s", text);

    fclose(file);

    printf("Data written successfully.\n");
}

/* Read data from a file */
void read_file()
{
    char filename[MAX_FILENAME];
    char text[MAX_TEXT];

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: File not found.\n");
        return;
    }

    printf("\n----- File Contents -----\n");

    while (fgets(text, MAX_TEXT, file))
    {
        printf("%s", text);
    }

    printf("\n-------------------------\n");

    fclose(file);
}

/* Delete a file */
void delete_file()
{
    char filename[MAX_FILENAME];

    printf("Enter file name: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Error deleting file.\n");
    }
}
