// Name             : kousik c
// Date             : 27/07/2026
// Description      : The following functions are implemented in the Address Book project to manage contact information efficiently.

#include <stdio.h>
#include "contact.h"

int main()
{
    struct Addressbook addressbook;
    int choice;

    addressbook.count = 0;
    loadcontact(&addressbook);

    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Display all contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter a number from 1 to 6.\n");

            while (getchar() != '\n')
            {
            }

            continue;
        }

        getchar();

        switch (choice)
        {
            case 1:
                addContact(&addressbook);
                break;

            case 2:
                searchContact(&addressbook);
                break;

            case 3:
                editContact(&addressbook);
                break;

            case 4:
                deleteContact(&addressbook);
                break;

            case 5:
                displayallContacts(&addressbook);
                break;

            case 6:
                savecontact(&addressbook);
                printf("Contacts saved successfully.\n");
                printf("Thank you!!!\n");
                break;

            default:
                printf("Invalid choice. Choose between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}