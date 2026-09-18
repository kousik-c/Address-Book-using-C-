#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100


/* Contact structure */
typedef struct
{
    char name[50];
    char mobile[11];
    char email[50];

} Contact;


/* Address Book structure */
typedef struct Addressbook
{
    Contact contact[MAX_CONTACTS];
    int count;

} AddressBook;


/*------------------------------------------------
                  ADD / DISPLAY
------------------------------------------------*/

void addContact(AddressBook *addressbook);

void displayallContacts(AddressBook *addressbook);


/*------------------------------------------------
                     SEARCH
------------------------------------------------*/

void searchContact(AddressBook *addressbook);

void search_name(AddressBook *addressbook);

void search_mobile(AddressBook *addressbook);

void search_email(AddressBook *addressbook);


/*------------------------------------------------
                    VALIDATION
------------------------------------------------*/

int isValid_mobile(char *mobile);

int isValid_name(char *name);

int isValid_mail(char *email);


/*------------------------------------------------
                DUPLICATE CHECK
------------------------------------------------*/

int isName_unique(AddressBook *addressbook, char *name);

int isMobile_unique(AddressBook *addressbook, char *mobile);

int is_emailUnique(AddressBook *addressbook, char *email);


/*------------------------------------------------
               EDIT / DELETE
------------------------------------------------*/

void editContact(AddressBook *addressbook);

void deleteContact(AddressBook *addressbook);


/*------------------------------------------------
                  FILE HANDLING
------------------------------------------------*/

void loadcontact(AddressBook *addressbook);

void savecontact(AddressBook *addressbook);

#endif