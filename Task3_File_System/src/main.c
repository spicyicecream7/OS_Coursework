#include <stdio.h>

#include "../include/file_manager.h"
#include "../include/permissions.h"

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" Operating Systems Coursework\n");
        printf(" Task 3: File System Management\n");
        printf("=====================================\n");

        printf("1. Create File\n");
        printf("2. Write File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Show Permissions\n");
        printf("6. Show File Information\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_file();
                break;

            case 2:
                write_file();
                break;

            case 3:
                read_file();
                break;

            case 4:
                delete_file();
                break;

            case 5:
                show_permissions();
                break;

            case 6:
                show_file_info();
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}
