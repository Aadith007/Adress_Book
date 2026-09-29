#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);

int is_valid_name(char name[]);
int is_valid_ph(char phone[]);
int is_valid_mail(char email[]);
void sort_name(AddressBook *addressBook);
void sort_email(AddressBook *addressBook);
void sort_phone(AddressBook *addressBook);
int search_name(AddressBook *addressBook);
int search_ph(AddressBook *addressBook);
int search_email(AddressBook *addressBook);
void delete_name(AddressBook *addressBook);
void delete_ph(AddressBook *addressBook);
void delete_email(AddressBook *addressBook);
int is_duplicate_em(AddressBook *addressbook,char email[]);
int is_duplicate_ph(AddressBook *addressBook,char phone[]);
void searchContact(AddressBook *addressBook);

void editContact(AddressBook *addressBook);
void edit_ph(AddressBook *addressBook);
void edit_name(AddressBook *addressBook);
void edit_email(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);
#endif
