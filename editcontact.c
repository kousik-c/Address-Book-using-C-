// createContact()      :->Adds a new contact to the address book by collecting name, mobile number, and email ID from the user.
//                       ->Validates the name, mobile number, and email ID before storing the contact.
//                       ->Does not allow duplicate mobile numbers or email IDs.

// searchContact()      :->Displays search options: name, mobile number, and email ID.
//                       ->Calls the required search function based on the user choice.

// search_name()        :->Searches for a contact by name.
//                       ->Displays the name, mobile number, and email ID when the contact is found.

// search_mobile()      :->Searches for a contact by mobile number.
//                       ->Displays the contact details when the mobile number is found.

// search_email()       :->Searches for a contact by email ID.
//                       ->Displays the contact details when the email ID is found.

// editContact()        :->Searches for a contact using the contact name.
//                       ->Allows the user to edit only the name, mobile number, or email ID.
//                       ->Validates updated values and does not allow duplicate mobile numbers or email IDs.

#include <stdio.h>
#include <string.h>
#include "contact.h"

// Check whether the mobile number belongs to another contact
int isMobileUniqueWhileEditing(struct Addressbook *addressbook, char *mobile, int currentIndex)
{
    for (int i = 0; i < addressbook->count; i++)
    {
        if (i != currentIndex &&
            strcmp(addressbook->contact[i].mobile, mobile) == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Check whether the email belongs to another contact
int isEmailUniqueWhileEditing(struct Addressbook *addressbook, char *email, int currentIndex)
{
    for (int i = 0; i < addressbook->count; i++)
    {
        if (i != currentIndex &&
            strcmp(addressbook->contact[i].email, email) == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Function to edit an existing contact
void editContact(struct Addressbook *addressbook)
{
    char edit_name[50];
    int choice;

    // Check whether the address book is empty
    if (addressbook->count == 0)
    {
        printf("Addressbook is empty.\n");
        return;
    }

    // Read the name of the contact to edit
    printf("Enter the name to edit: ");
    scanf(" %49[^\n]", edit_name);

    // Search for the contact by name
    for (int i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].name, edit_name) == 0)
        {
            // Display edit options
            printf("\nEdit Menu\n");
            printf("1. Edit name\n");
            printf("2. Edit mobile number\n");
            printf("3. Edit email\n");
            printf("4. Exit edit\n");
            printf("Enter your choice: ");

            if (scanf("%d", &choice) != 1)
            {
                printf("Invalid input.\n");

                while (getchar() != '\n')
                {
                }

                return;
            }

            // Edit only the name
            if (choice == 1)
            {
                do
                {
                    printf("Enter new name: ");
                    scanf(" %49[^\n]", addressbook->contact[i].name);

                    if (!isValid_name(addressbook->contact[i].name))
                    {
                        printf("Name should not contain special characters or digits.\n");
                    }

                } while (!isValid_name(addressbook->contact[i].name));

                printf("Name updated successfully.\n");
            }

            // Edit only the mobile number
            else if (choice == 2)
            {
                do
                {
                    printf("Enter new mobile number: ");
                    scanf(" %19[^\n]", addressbook->contact[i].mobile);

                    if (!isValid_mobile(addressbook->contact[i].mobile) ||
                        !isMobileUniqueWhileEditing(addressbook,
                                                     addressbook->contact[i].mobile, i))
                    {
                        printf("Mobile number must contain 10 digits, start with 6, 7, 8, or 9, and be unique.\n");
                    }

                } while (!isValid_mobile(addressbook->contact[i].mobile) ||
                         !isMobileUniqueWhileEditing(addressbook,
                                                      addressbook->contact[i].mobile, i));

                printf("Mobile number updated successfully.\n");
            }

            // Edit only the email address
            else if (choice == 3)
            {
                do
                {
                    printf("Enter new email: ");
                    scanf(" %49[^\n]", addressbook->contact[i].email);

                    if (!isValid_mail(addressbook->contact[i].email) ||
                        !isEmailUniqueWhileEditing(addressbook,
                                                    addressbook->contact[i].email, i))
                    {
                        printf("Enter a valid and unique email address.\n");
                    }

                } while (!isValid_mail(addressbook->contact[i].email) ||
                         !isEmailUniqueWhileEditing(addressbook,
                                                     addressbook->contact[i].email, i));

                printf("Email updated successfully.\n");
            }

            // Return to the main menu without editing
            else if (choice == 4)
            {
                printf("Returning to main menu.\n");
            }

            else
            {
                printf("Invalid choice.\n");
            }

            return;
        }
    }

    printf("Contact not found!\n");
}