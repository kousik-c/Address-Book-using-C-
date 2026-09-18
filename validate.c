#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "contact.h"


/*
 * Function : isValid_mobile
 * Purpose  : Validate mobile number
 * Returns  : 1 -> Valid
 *            0 -> Invalid
 */
int isValid_mobile(char *mobile)
{
    int i;

    /* Check exactly 10 characters */
    if (strlen(mobile) != 10)
    {
        printf("Error: Mobile number must contain exactly 10 digits.\n");
        return 0;
    }

    /* First digit must be 6 to 9 */
    if (mobile[0] < '6' || mobile[0] > '9')
    {
        printf("Error: First digit must be between 6 and 9.\n");
        return 0;
    }

    /* Check only digits */
    for (i = 0; i < 10; i++)
    {
        if (!isdigit((unsigned char)mobile[i]))
        {
            printf("Error: Only digits are allowed in mobile number.\n");
            return 0;
        }
    }

    return 1;
}


/*
 * Function : isValid_name
 * Purpose  : Validate contact name
 * Returns  : 1 -> Valid
 *            0 -> Invalid
 */
int isValid_name(char *name)
{
    int length;
    int i;

    length = strlen(name);

    /* Minimum 3 characters */
    if (length < 3)
    {
        printf("Error: Name must contain at least 3 characters.\n");
        return 0;
    }

    /* Name should not start or end with space */
    if (name[0] == ' ' || name[length - 1] == ' ')
    {
        printf("Error: Name should not start or end with space.\n");
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        /* Only alphabets and spaces */
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
        {
            printf("Error: Name should contain only alphabets and spaces.\n");
            return 0;
        }

        /* No consecutive spaces */
        if (name[i] == ' ' && name[i + 1] == ' ')
        {
            printf("Error: Consecutive spaces are not allowed in name.\n");
            return 0;
        }
    }

    return 1;
}


/*
 * Function : isValid_mail
 * Purpose  : Validate email address
 * Returns  : 1 -> Valid
 *            0 -> Invalid
 */
int isValid_mail(char *email)
{
    int i;
    int atCount = 0;
    int dotCount = 0;
    int atPosition = -1;
    int dotPosition = -1;

    /* Email cannot be empty */
    if (strlen(email) == 0)
    {
        printf("Error: Email ID cannot be empty.\n");
        return 0;
    }

    /*
     * Check allowed characters.
     *
     * According to project requirement:
     * lowercase alphabets
     * digits
     * @
     * .
     */
    for (i = 0; email[i] != '\0'; i++)
    {
        if (islower((unsigned char)email[i]) ||
            isdigit((unsigned char)email[i]))
        {
            continue;
        }

        if (email[i] == '@')
        {
            atCount++;
            atPosition = i;
            continue;
        }

        if (email[i] == '.')
        {
            dotCount++;
            dotPosition = i;
            continue;
        }

        printf("Error: Invalid symbol in email ID.\n");
        return 0;
    }


    /* Exactly one @ */
    if (atCount == 0)
    {
        printf("Error: Missing @ symbol.\n");
        return 0;
    }

    if (atCount > 1)
    {
        printf("Error: Multiple @ symbols are not allowed.\n");
        return 0;
    }


    /* Exactly one dot */
    if (dotCount == 0)
    {
        printf("Error: Missing dot in email ID.\n");
        return 0;
    }

    if (dotCount > 1)
    {
        printf("Error: Email ID must contain exactly one dot.\n");
        return 0;
    }


    /*
     * Dot must be after @
     */
    if (dotPosition < atPosition)
    {
        printf("Error: Dot must appear after @ symbol.\n");
        return 0;
    }


    /*
     * At least one character between @ and .
     *
     * Example:
     * abc@.com -> invalid
     * abc@gmail.com -> valid
     */
    if (dotPosition == atPosition + 1)
    {
        printf("Error: At least one character is required between @ and dot.\n");
        return 0;
    }


    /*
     * Dot cannot be the last character
     */
    if (email[dotPosition + 1] == '\0')
    {
        printf("Error: Characters are required after dot.\n");
        return 0;
    }


    /*
     * Email must end exactly with .com
     *
     * abc@gmail.com  -> valid
     * abc@gmail.com1 -> invalid
     */
    if (strcmp(&email[dotPosition], ".com") != 0)
    {
        printf("Error: Email ID must end with .com.\n");
        return 0;
    }


    /*
     * There must be something before @
     */
    if (atPosition == 0)
    {
        printf("Error: Email ID cannot start with @.\n");
        return 0;
    }

    return 1;
}


/*
 * Function : isName_unique
 * Purpose  : Check duplicate name
 * Returns  : 1 -> Unique
 *            0 -> Duplicate
 */
int isName_unique(struct Addressbook *addressbook, char *name)
{
    int i;

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].name, name) == 0)
        {
            return 0;
        }
    }

    return 1;
}


/*
 * Function : isMobile_unique
 * Purpose  : Check duplicate mobile number
 * Returns  : 1 -> Unique
 *            0 -> Duplicate
 */
int isMobile_unique(struct Addressbook *addressbook, char *mobile)
{
    int i;

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].mobile, mobile) == 0)
        {
            return 0;
        }
    }

    return 1;
}


/*
 * Function : is_emailUnique
 * Purpose  : Check duplicate email
 * Returns  : 1 -> Unique
 *            0 -> Duplicate
 */
int is_emailUnique(struct Addressbook *addressbook, char *email)
{
    int i;

    for (i = 0; i < addressbook->count; i++)
    {
        if (strcmp(addressbook->contact[i].email, email) == 0)
        {
            return 0;
        }
    }

    return 1;
}