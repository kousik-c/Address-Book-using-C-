#include <stdio.h>
#include <string.h>
#include "contact.h"

// Function to delete a contact from the address book
void deleteContact(struct Addressbook *addressbook)
{
    char delete_name[50];

    // Check whether the address book is empty
    if (addressbook->count == 0)
    {
        printf("Addressbook is empty.\n");
        return;
    }

    // Read the name of the contact to delete
    printf("Enter the name to delete: ");
    scanf(" %49[^\n]", delete_name);

    // Search for the contact by name
    for (int i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].name, delete_name) == 0)
        {
            // Shift the remaining contacts one position to the left
            for (int j = i; j < addressbook->count - 1; j++)
            {
                addressbook->contact[j] = addressbook->contact[j + 1];
            }

            // Reduce the contact count
            addressbook->count--;

            printf("Contact deleted successfully.\n");
            return;
        }
    }

    // Display a message if the contact is not found
    printf("Contact not found!\n");
}