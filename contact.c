#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include<ctype.h>

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("Sort based on : \n1.Name\n2.phone\n3.email\n");
    scanf("%d",&criteria);
    switch(criteria){
        case 1:sort_name(addressBook);
        break;
        case 2:sort_phone(addressBook);
        break;
        case 3:sort_email(addressBook);
        break;
        default: printf("Invalid input\n");
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    while(1){
 int i;
    int saved=0;
	printf("Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    if(is_valid_name(addressBook->contacts[addressBook->contactCount].name)){
        
        break;
    }
        else{
        printf("Enter valid name\n");
        
    }
    
}
while(1){
     
    
        printf("Enter mobile number: ");
        scanf("%s", addressBook->contacts[addressBook->contactCount].phone);

        if(!(is_valid_ph(addressBook->contacts[addressBook->contactCount].phone)))
         {
            printf("Invalid number\n");
            
         }
         else if(is_duplicate_ph(addressBook,addressBook->contacts[addressBook->contactCount].phone)){
            printf("Number aldresy existing\n");
         }
         else{
            
            break;
         }
       
    }
while(1){
    printf("Enter mail id : ");
    scanf("%s",addressBook->contacts[addressBook->contactCount].email);
    if(!(is_valid_mail(addressBook->contacts[addressBook->contactCount].email))){
        printf("Invalid\n");
    }
    else if(is_duplicate_em(addressBook,addressBook->contacts[addressBook->contactCount].email)){
        printf("Mail adredy existing\n");
    }
    else{
        
        break;
    }
    
    

}

int c=addressBook->contactCount++;

printf("Contact %d created",c+1);
printf("\n");
    
}
void sort_name(AddressBook *addressBook){
    int i;
    int j;
    for(i=0;i<addressBook->contactCount-1;i++){ 
        for(j=0;j<addressBook->contactCount-i-1;j++){
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0){
            Contact temp;
            temp = addressBook->contacts[j];
            addressBook->contacts[j] = addressBook->contacts[j+1];
            addressBook->contacts[j+1] = temp;
            }

    }
}
     printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    
     for(i=0;i<addressBook->contactCount;i++){
        printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void sort_email(AddressBook *addressBook){
    int i,j;
    for(i=0;i<addressBook->contactCount-1;i++){
        for(j=0;j<addressBook->contactCount-i-1;j++){
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0){
                Contact temp;
                temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;

            }
        }
    }
   printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
   printf("--------------------------------------------------\n");
    
     for(i=0;i<addressBook->contactCount;i++){
        printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

}

void sort_phone(AddressBook *addressBook){
    int i,j;
    for(i=0;i<addressBook->contactCount-1;i++){
        for(j=0;j<addressBook->contactCount-i-1;j++){
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0){
                Contact temp;
                temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;

            }
        }
    }
    printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    
     for(i=0;i<addressBook->contactCount;i++){
        printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

}






int is_valid_name(char name[]){
    int i;
    if(strlen(name)<2){
        return 0;
    } 
    
    for(i=0;name[i]!='\0';i++){
        if(!isalnum(name[i]) && name[i]!=' '){
            return 0;
        }
    }
    return 1;
}
int is_valid_ph(char phone[]){
    int i;
    if(strlen(phone)!=10){
        return 0;
    }
    if(phone[0]<'6' || phone[0]>'9'){
        return 0;
    }
    for(i=0;phone[i]!='\0';i++){
        if(!isdigit(phone[i])){
            return 0;
        }
    }
    return 1;
}
int is_duplicate_ph(AddressBook *addressBook, char phone[]){
    int i;
    for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,phone)==0){
            return 1;
        }
    }
    return 0;
}
int is_duplicate_em(AddressBook *addressBook, char mail[]){
    int i;  
    for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].email,mail)==0){
            return 1;
        }
    }
    return 0;
    
}
int is_valid_mail(char mail[]){
    int i;
    int count_m=0;
    for(i=0;mail[i]!='\0';i++){
        if(mail[i]>='A' && mail[i]<='Z'){
            return 0;
        }
        if((mail[i]=='.'&&mail[i+1]=='.') || (mail[i]=='@' && mail[i+1]=='.') || (mail[i]=='.'&&mail[i+1]=='@')){
            return 0;
        }
        
        
        
        
        if(mail[i]== '@' ){
            count_m++;
            if(!isalpha(mail[i+1])){
                return 0;
            }
        }
        
    
    
   
}
     if(count_m!=1){
        return 0;
    }
    if(mail[0]=='@'){
        return 0;
    }

    int len=strlen(mail);
    if(len<4){
        return 0;
    }
    if(mail[len-4]!='.' || mail[len-3]!='c' || mail[len-2]!='o' || mail[len-1]!='m'){
        return 0;
    }
    
    return 1;
}
void searchContact(AddressBook *addressBook){
    int criteria;
    printf("Search based on: \n");
    printf("1.Name\n2.phone\n3.email\n");
    printf("Enter your choice: \n");
    scanf("%d",&criteria);
    switch(criteria){
        case 1:search_name(addressBook);
        break;
        case 2:search_ph(addressBook);
        break;
        case 3:search_email(addressBook);
        break;
        default:printf("Invalid operation\n");
        
    }
}
void search_name(AddressBook *addressBook){
    char key[20];
    int i;
    int found=0;
    printf("Enter name to search: \n");
    scanf(" %[^\n]",key);
   
    for(i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].name,key)!=NULL){
             found=1;
        }
    }
        if(found==0){
             printf("No search results\n");
            return;
        }
        printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++){
         if(strcasestr(addressBook->contacts[i].name,key)!=NULL){
             printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    
}

void search_ph(AddressBook *addressBook){
    char key[20];
    int i;
    int found=0;
    printf("Enter phone number to search: \n");
    scanf("%s",key);
     
    for(i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].phone,key)!=NULL){
         
            found=1;
        }

    }
    if(found==0){
        printf("No search results\n");
        return;
    }
     printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++){
         if(strcasestr(addressBook->contacts[i].phone,key)!=NULL){
             printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }


}
void search_email(AddressBook *addressBook){
    char key[20];
    int i;
    int found=0;
    printf("Enter mail id to search: \n");
    scanf("%s",key);
    
    for(i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].email,key)!=NULL){
            found=1;
        }
    }
    if(found==0){
        printf("No search results\n");
        return;
    }
    printf("             CONTACT LIST\n");
    printf("%-15s %-12s %-30s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++){
         if(strcasestr(addressBook->contacts[i].email,key)!=NULL){
             printf("%-15s %-12s %-30s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }

}






void editContact(AddressBook *addressBook)
{   

	/* Define the logic for Editcontact */

}

void deleteContact(AddressBook *addressBook)
{
	delete_name(addressBook);

    
}
void delete_name(Address *addressBook){
    char key[20];
    printf("Enter name to be deleted: ");
    scanf(" %[^\n]",key);
    if(strcasestr(adressBook->contacts[i].name,key)!=NULL){
    for(int i=0;i<adressBook->contactCount;i++){
        
            adressBook->contacts[i]=addressBook->contacts[i+1];

    }
    adressBook->contactCount-1;
    
    }
}
