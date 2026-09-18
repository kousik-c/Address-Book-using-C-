#ifndef VALIDATE_H
#define VALIDATE_H

#include "contact.h"

int validateName(char name[]);
int validatePhone(char phone[]);
int validateEmail(char email[]);

int isNameUnique(AddressBook *addressBook, char name[]);
int isPhoneUnique(AddressBook *addressBook, char phone[]);
int isEmailUnique(AddressBook *addressBook, char email[]);

#endif