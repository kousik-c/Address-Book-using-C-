// deleteContact()      :->Removes a contact from the address book based on the contact name entered by the user.
//                       ->Shifts the remaining contacts to maintain the correct order.

// displayallContacts() :->Displays all saved contacts with name, mobile number, and email ID.
//                       ->Displays an appropriate message when the address book is empty.

// savecontact()        :->Saves all contacts from memory into the contact.csv file.
//                       ->Stores the contact count in the first line and contact details in the following lines.

// loadcontact()        :->Loads previously saved contacts from contact.csv when the program starts.
//                       ->Allows the user to continue working with saved contacts without data loss.

#include <stdio.h>
#include <string.h>
#include "contact.h"


/* Function to display a single contact */
static void printContact(Contact *contact)
{
    printf("\n----------------------------------------\n");
    printf("Name   : %s\n", contact->name);
    printf("Mobile : %s\n", contact->mobile);
    printf("Email  : %s\n", contact->email);
    printf("----------------------------------------\n");
}


/* Search by name */
void search_name(AddressBook *addressbook)
{
    char name[50];
    int found = 0;
    int i;

    printf("\nEnter name to search: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].name, name) == 0)
        {
            printContact(&addressbook->contact[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}


/* Search by mobile number */
void search_mobile(AddressBook *addressbook)
{
    char mobile[11];
    int found = 0;
    int i;

    printf("\nEnter mobile number to search: ");
    scanf("%10s", mobile);

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].mobile, mobile) == 0)
        {
            printContact(&addressbook->contact[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}


/* Search by email */
void search_email(AddressBook *addressbook)
{
    char email[50];
    int found = 0;
    int i;

    printf("\nEnter email ID to search: ");
    scanf("%49s", email);

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].email, email) == 0)
        {
            printContact(&addressbook->contact[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}


/* Search menu */
void searchContact(AddressBook *addressbook)
{
    int choice;

    printf("\n========== SEARCH CONTACT ==========\n");
    printf("1. Search by Name\n");
    printf("2. Search by Mobile\n");
    printf("3. Search by Email\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            search_name(addressbook);
            break;

        case 2:
            search_mobile(addressbook);
            break;

        case 3:
            search_email(addressbook);
            break;

        case 4:
            return;

        default:
            printf("Invalid choice.\n");
    }
}