#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include<ctype.h>
int matching_contact[100];

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("List based on : \n1.Name\n2.phone\n3.email\n");
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
            printf("Number Aldredy Exist\n");
         }
         else{
            
            break;
         }
       
    }
while(1){
    printf("Enter Mail id : ");
    scanf("%s",addressBook->contacts[addressBook->contactCount].email);
    if(!(is_valid_mail(addressBook->contacts[addressBook->contactCount].email))){
        printf("Invalid Mail ID\n");
    }
    else if(is_duplicate_em(addressBook,addressBook->contacts[addressBook->contactCount].email)){
        printf("Mail Aldredy Exist\n");
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
            if(strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0){
            Contact temp;
            temp = addressBook->contacts[j];
            addressBook->contacts[j] = addressBook->contacts[j+1];
            addressBook->contacts[j+1] = temp;
            }

    }
}
     printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("------------------------------------------------------------\n");
    int c=1;
     for(i=0;i<addressBook->contactCount;i++){
        printf(" %d. %-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
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
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
   printf("--------------------------------------------------\n");
    int c=1;
     for(i=0;i<addressBook->contactCount;i++){
        printf("%d.%-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
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
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
     for(i=0;i<addressBook->contactCount;i++){
        printf("%d.%-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
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
int search_name(AddressBook *addressBook){
    char key[20];
    int i;
    
    printf("Enter name to search: \n");
    scanf(" %[^\n]",key);
    int matching_count=0;
    
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].name,key)!=NULL){
            
            matching_contact[matching_count]=i;
            matching_count++;
            

    }

}
        if(matching_count==0){
             printf("No search results\n");
             return -1;
        }
        printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(i=0;i<matching_count;i++){
        int index=matching_contact[i];
        
             printf("%d.%-20s %-15s %-30s \n",c++,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
        }
        int selec;
        printf("Select a contact: ");
        scanf("%d",&selec);
        if(selec<1 || selec>matching_count){
            return -1;
        }

        return matching_contact[selec-1];

    
}

int search_ph(AddressBook *addressBook){
    char key[20];
    int i;
    int matching_count=0;
    printf("Enter phone number to search: \n");
    scanf("%s",key);
     
    for(i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].phone,key)!=NULL){
            matching_contact[matching_count]=i;
            matching_count++;
        }
       
    }
     if(matching_count==0){
            printf("No search results\n");
            return -1;
        }
    
     printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(i=0;i<matching_count;i++){
            int index=matching_contact[i];
             printf("%d.%-20s %-15s %-30s \n",c++,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
        }
         int selec;
        printf("Select a contact: ");
        scanf("%d",&selec);
        if(selec<1 || selec>matching_count){
            return -1;
        }

        return matching_contact[selec-1];

    


}
int search_email(AddressBook *addressBook){
    char key[20];
    int i;
    int matching_count=0;
    printf("Enter mail id to search: \n");
    scanf("%s",key);
    
    for(i=0;i<addressBook->contactCount;i++){
        if(strcasestr(addressBook->contacts[i].email,key)!=NULL){
            matching_contact[matching_count]=i;
            matching_count++;
        }
    }
    if(matching_count==0){
            printf("No search results\n");
            return -1;
        }
   
    printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(i=0;i<matching_count;i++){
            int index=matching_contact[i];
             printf("%d.%-20s %-15s %-30s \n",c++,addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
        }
         int selec;
        printf("Select a contact: ");
        scanf("%d",&selec);
        if(selec<1 || selec>matching_count){
            return -1;
        }

        return matching_contact[selec-1];


}






void editContact(AddressBook *addressBook)
{   

	int criteria;
    int index;
    int edit;
    printf("Search based on: \n");
    printf("1.Name\n2.phone\n3.email\n");
    printf("Enter your choice: \n");
    scanf("%d",&criteria);
    switch(criteria){
        case 1:index=search_name(addressBook);
        break;
        case 2:index=search_ph(addressBook);
        break;
        case 3:index=search_email(addressBook);
        break;
        default:printf("Invalid operation\n");
        return;
        
    }
    if(index==-1){
        return;
    }

    
    printf("Edit based on\n");
    printf("1.Name\n2.Phone\n3.Email\n");
    printf("Enter your choice\n: ");
    scanf("%d",&edit);
    switch(edit){
        case 1:edit_name(addressBook,index);
        break;
        case 2:edit_ph(addressBook,index);
        break;
        case 3:edit_email(addressBook,index);
        break;
        default:printf("Invalid operation\n");

    }
}

void edit_name(AddressBook *addressBook,int index){
    
    char new_name[20];

printf("Enter new name: \n");
scanf(" %[^\n]", new_name);

if(is_valid_name(new_name))
{
    strcpy(addressBook->contacts[index].name, new_name);
    printf("Name changed\n");
    return;
}
else
{
    printf("Invalid name\n");
    return;
}
}


void edit_ph(AddressBook *addressBook,int index){

    char new_ph[20];
   


printf("Enter new phone number : \n");
scanf("%s", new_ph);

if(is_valid_ph(new_ph))
{   
    if(!is_duplicate_ph(addressBook,new_ph)){
    strcpy(addressBook->contacts[index].phone, new_ph);
    printf("Phone number changed\n");
    return;
}
else{
    printf("Number Aldredy Exist\n");
    return ;
}
}
else
{
    printf("Invalid Phone Number\n");
    return;
}
}


void edit_email(AddressBook *addressBook,int index){
    char new_mail[20];
   
  


printf("Enter new mail id : \n");
scanf("%s", new_mail);

if(is_valid_mail(new_mail))
{   
    if(!is_duplicate_em(addressBook,new_mail)){
    strcpy(addressBook->contacts[index].email, new_mail);
    printf("email id number changed\n");
    return;
}
else{
    printf("Mail ID Aldresy Exist\n");
    return ;
}
}
else
{
    printf("Invalid Mail ID\n");
    return;
}
}


void deleteContact(AddressBook *addressBook)
{    int criteria;
    printf("Delete based on: \n");
    printf("1.Name\n2.phone\n3.email\n");
    printf("Enter your choice: \n");
    scanf("%d",&criteria);
    switch(criteria){
        case 1:delete_name(addressBook);
        break;
        case 2:delete_ph(addressBook);
        break;
       case 3:delete_email(addressBook);
        break;
        default:printf("Invalid operation\n");
        
    }
}
	
void delete_name(AddressBook *addressBook){
   int index;
   index=search_name(addressBook);
   if(index==-1){
    return;
   }
   for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact deleted\n");
    printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(int i=0;i<addressBook->contactCount;i++){
        
         printf(" %d. %-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
         
        }

}
    
void delete_ph(AddressBook *addressBook){
   int index;
   index=search_ph(addressBook);
   if(index==-1){
    return;
   }
   for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact deleted\n");
    printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(int i=0;i<addressBook->contactCount;i++){
        
         printf(" %d. %-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
         
        }

}

void delete_email(AddressBook *addressBook){
   int index;
   index=search_email(addressBook);
   if(index==-1){
    return;
   }
   for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact deleted\n");
    printf("             CONTACT LIST\n");
    printf("%-25s %-20s %-35s\n","NAME" , "PHONE", "MAIL ID");
    printf("--------------------------------------------------\n");
    int c=1;
    for(int i=0;i<addressBook->contactCount;i++){
        
         printf(" %d. %-20s %-15s %-30s \n",c++,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
         
        }

}

   
   
   
    
    


   
    
    

