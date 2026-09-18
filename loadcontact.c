#include <stdio.h>
#include "contact.h"

// Function to load contacts from a file
void loadcontact(struct Addressbook *addressbook)
{
    // Open the file in read mode
    FILE *fptr = fopen("contact.csv", "r");
    int totalContacts;

    // Check whether the file exists
    if (fptr == NULL)
    {
        printf("No saved contacts found.\n");
        addressbook->count = 0;
        return;
    }

    // Read the total number of contacts from the file
    if (fscanf(fptr, "#%d\n", &totalContacts) != 1)
    {
        printf("Invalid contact file.\n");
        addressbook->count = 0;
        fclose(fptr);
        return;
    }

    // Do not allow a negative contact count
    if (totalContacts < 0)
    {
        totalContacts = 0;
    }

    // Limit contacts to the maximum array capacity
    if (totalContacts > 100)
    {
        totalContacts = 100;
    }

    // Initialize the contact count before loading contacts
    addressbook->count = 0;

    // Read every contact from the file
    for (int i = 0; i < totalContacts; i++)
    {
        if (fscanf(fptr, " %49[^,],%19[^,],%49[^\n]",
                   addressbook->contact[addressbook->count].name,
                   addressbook->contact[addressbook->count].mobile,
                   addressbook->contact[addressbook->count].email) == 3)
        {
            addressbook->count++;
        }
    }

    // Close the file after reading
    fclose(fptr);

    printf("%d contact(s) loaded successfully.\n", addressbook->count);
}
