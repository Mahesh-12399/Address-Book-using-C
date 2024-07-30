#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
       printf("---------------------------------------------------------------------------------\n");
       printf("Name\t\t\tphone number\t\t\tEmail id\n");
       printf("---------------------------------------------------------------------------------\n");
       for(int i=0;i<addressBook->contactCount;i++)
       {
	   printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       }
}

void createContact(AddressBook *addressBook) 
{
    // Check if the address book is full
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }

    // Prompt the user to input the contact details
    printf("Enter name:");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);

    printf("Enter email: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);

    // Increment the contact count
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /*
    char search[100];
    printf("enter name to search:");
    scanf(" %[^\n]",search);
    getchar();
    for(int i=0;i<addressBook->contactCount;i++)
    {
	if(!strcmp(search,addressBook->contacts[i].name))
	{
	    printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	    break;
	}
    }
    */
    int choice;
    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline left by scanf

    char search[100];
    printf("Enter search name: ");
    scanf("%[^\n]", search);
    getchar(); // consume newline left by scanf

    int found = 0; // Flag to indicate if any matching contact is found

    switch (choice)
    {
        case 1:
            printf("Search Results by Name:\n");
            for (int i = 0; i < addressBook->contactCount; i++) 
	    {
                if (strcmp(search, addressBook->contacts[i].name)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressBook->contacts[i].name,
                           addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    found = 1; // Set the flag to indicate a match is found
                }
            }
            break;
        case 2:
            printf("Search Results by Phone:\n");
            for (int i = 0; i < addressBook->contactCount; i++)
	    {
                if (strcmp(search, addressBook->contacts[i].phone)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressBook->contacts[i].name,
                           addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    found = 1; // Set the flag to indicate a match is found
                }
            }
            break;
        case 3:
            printf("Search Results by Email:\n");
            for (int i = 0; i < addressBook->contactCount; i++)
	    {
                if (strcmp(search, addressBook->contacts[i].email)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressBook->contacts[i].name,
                           addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    found = 1; // Set the flag to indicate a match is found
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    if (!found)
    {
        printf("No contacts found matching the search criteria.\n");
    }
}


void editContact(AddressBook *addressBook)
{
   /*
    char edit[50];
    printf("enter the name to edit:");
    scanf(" %[^\n]",edit);
    
    int found=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
	if(strcmp(addressBook->contacts[i].name,edit)==0)
	{
	    found=1;
	    printf("contact found......\n");
	    printf("enter new name:");
	    scanf(" %[^\n]",addressBook->contacts[i].name);
	    printf("enter new phone:");
	    scanf(" %[^\n]",addressBook->contacts[i].phone);
	    printf("enter new email:");
	    scanf(" %[^\n]",addressBook->contacts[i].email);
	    printf("contact edited successfully.\n");
	    return;
	}
    }
    if(!found)
      {
	  printf("contact not found\n");
      }
      */
    int choice;
    printf("edit by:\n");
    printf("1.Name\n");
    printf("2.phone\n");
    printf("3.email\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    getchar();

    char edit[100];
    printf("enter edit to name:");
    scanf(" %[^\n]",edit);
    getchar();

    int flag=0;
    switch(choice)
    {
	case 1:
	    printf("edit the name:\n");
	    for(int i=0;i<addressBook->contactCount;i++)
	    {
		if(strcmp(edit,addressBook->contacts[i].name)==0)
		{
		    printf("contact found....\n");
		    printf("enter new name:");
		    scanf(" %[^\n]",addressBook->contacts[i].name);
		    flag=1;
		}
	    }
	    break;
	case 2:
	    printf("edit the phone\n");
	    for(int i=0;i<addressBook->contactCount;i++)
	    {
	      if(strcmp(edit,addressBook->contacts[i].phone)==0)
	      {
		  
		  printf("contact found...\n");
		  printf("enter new phone:");
		  scanf(" %[^\n]",addressBook->contacts[i].phone);
		  flag=1;
	      }
	    }
	    break;
	case 3:
	    printf("edit the email\n");
	    for(int i=0;i<addressBook->contactCount;i++)
	    {
	      if(strcmp(edit,addressBook->contacts[i].email)==0)
	      {
	       
		printf("contact found...\n");
		printf("enter new email:");
		scanf(" %[^\n]",addressBook->contacts[i].email);
		flag=1;
	      }
	    }
            break;
	default:
             printf("Invalid choice!\n");
    }
    if(!flag)
    {
	printf("contact not found\n");
    }
    	     


}

void deleteContact(AddressBook *addressBook) 
{
      char delete[100];
      printf("enter the name:");
      scanf(" %[^\n]",delete);
      int flag=0;
      for(int i=0;i<addressBook->contactCount;i++)
      {
	 if(strcmp(delete,addressBook->contacts[i].name)==0)
	 {
	    flag=1;
	    for(int j=i;j<addressBook->contactCount-1;j++)
	    {
	     addressBook->contacts[j]=addressBook->contacts[j+1];
             addressBook->contactCount--;
	    }
	 }
      }
      if(!flag)
      {
       printf("it is not found\n");
      }

}
