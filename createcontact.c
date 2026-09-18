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
#include <ctype.h>
#include <string.h>
#include "contact.h"

// Function to create a new contact
void createContact(struct Addressbook *addressbook)
{
    int nameFlag = 1;
    int mobileFlag = 1;
    int emailFlag = 1;

    // Check whether the address book is full
    if (addressbook->count >= 100)
    {
        printf("Addressbook is full.\n");
        return;
    }

    // Read and validate the contact name
    do
    {
        printf("Enter your name: ");
        scanf(" %49[^\n]", addressbook->contact[addressbook->count].name);

        if (isValid_name(addressbook->contact[addressbook->count].name))
        {
            nameFlag = 0;
        }
        else
        {
            printf("Name should not contain special characters or digits.\n");
        }

    } while (nameFlag);

    // Read, validate, and check uniqueness of the mobile number
    do
    {
        printf("Enter your mobile number: ");
        scanf(" %19[^\n]", addressbook->contact[addressbook->count].mobile);

        if (isValid_mobile(addressbook->contact[addressbook->count].mobile) &&
            isMobile_unique(addressbook,
                            addressbook->contact[addressbook->count].mobile))
        {
            mobileFlag = 0;
        }
        else
        {
            printf("Mobile number must contain 10 digits, start with 6, 7, 8, or 9, and be unique.\n");
        }

    } while (mobileFlag);

    // Read, validate, and check uniqueness of the email address
    do
    {
        printf("Enter your email: ");
        scanf(" %49[^\n]", addressbook->contact[addressbook->count].email);

        if (isValid_mail(addressbook->contact[addressbook->count].email) &&
            is_emailUnique(addressbook,
                           addressbook->contact[addressbook->count].email))
        {
            emailFlag = 0;
        }
        else
        {
            printf("Enter a valid and unique email address.\n");
        }

    } while (emailFlag);

    // Increase the contact count after successful creation
    addressbook->count++;

    printf("Contact created successfully.\n");
}