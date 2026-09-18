// isValid_name()       :->Checks whether a name contains only letters and spaces.
//                       ->Does not allow empty names, special characters, digits, or consecutive spaces.

// isValid_mobile()     :->Checks whether a mobile number contains exactly 10 digits.

// isValid_mail()       :->Checks whether an email ID contains a valid @ symbol and a dot after @.
//                       ->Does not allow spaces or more than one @ symbol.

// isMobile_unique()    :->Checks whether a mobile number already exists in the address book.

// is_emailUnique()     :->Checks whether an email ID already exists in the address book.

#include<stdio.h>    
#include"contact.h"  
#include<string.h>   

// Function to save all contacts into a file
void savecontact(struct Addressbook *addressbook)
{
    // Open the file in write mode
    FILE *fptr=fopen("contact.csv","w");
    // Check if the file is opened successfully
    if(fptr==NULL)
    {
        printf("File Not Found\n");
        return;
    }
    // Save the total number of contacts in the first line
    fprintf(fptr, "#%d\n", addressbook->count);
    // Write each contact's details into the file
    for(int i=0;i<addressbook->count;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact[i].name,
                                addressbook->contact[i].mobile,
                                addressbook->contact[i].email);
    }
    // Close the file
    fclose(fptr);
    // Display success message
    printf("Contacts saved successfully\n");
}