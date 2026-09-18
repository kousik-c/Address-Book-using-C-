#include<stdio.h>     
#include"contact.h"   

// Function to display all contacts in the address book
void displayallContacts(struct Addressbook *addressbook)
{
    // Check if the address book is empty
    if(addressbook->count==0)
    {
        printf("Addressbook is Empty\n");
        return;
    }
 
    printf("----------------------------------------------------------------\n");

    for(int i=0;i<addressbook->count;i++)
    {
        printf("Name: %s\n",addressbook->contact[i].name);
        printf("Mobile: %s\n",addressbook->contact[i].mobile);
        printf("Email: %s\n",addressbook->contact[i].email);
       
        printf("----------------------------------------------------------------\n");

    }
    
}
void addContact(AddressBook *addressbook)
{
    Contact temp;

    /* NAME */
    printf("Enter Name: ");
    scanf(" %[^\n]", temp.name);

    if (!isValid_name(temp.name))
    {
        return;
    }

    if (!isName_unique(addressbook, temp.name))
    {
        printf("Error: Name already exists.\n");
        return;
    }


    /* MOBILE */
    printf("Enter Mobile Number: ");
    scanf("%10s", temp.mobile);

    if (!isValid_mobile(temp.mobile))
    {
        return;
    }

    if (!isMobile_unique(addressbook, temp.mobile))
    {
        printf("Error: Mobile number already exists.\n");
        return;
    }


    /* EMAIL */
    printf("Enter Email ID: ");
    scanf("%49s", temp.email);

    if (!isValid_mail(temp.email))
    {
        return;
    }

    if (!is_emailUnique(addressbook, temp.email))
    {
        printf("Error: Email ID already exists.\n");
        return;
    }


    /* Store contact */
    addressbook->contact[addressbook->count] = temp;

    addressbook->count++;

    printf("\nContact added successfully.\n");
}