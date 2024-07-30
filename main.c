#include "contact.h"

int main()
{
    int choice;
    AddressBook book;
    initialize(&book);

    int displayMenu = 1; // Flag to control whether to display the menu

    do
    {
	if (displayMenu)
       	{
	    printf("Address Book Menu:\n");
	    printf("1.Create contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.List all contacts\n6.Exit\n");
	    printf("Edit choice:");
	}

	scanf("%d", &choice);
	displayMenu = 1; // Reset the flag

	switch (choice)
	{
	    case 1:
		printf("Create contact\n");
		createContact(&book);
		break;
	    case 2:
		printf("Search contact\n");
		searchContact(&book);
		break;
	    case 3:
		printf("Edit contact\n");
		editContact(&book);
		break;
	    case 4:
		printf("Delete contact\n");
		deleteContact(&book);
		break;
	    case 5:
		printf("List all contacts\n");
		listContacts(&book);
		break;
	    case 6:
		printf("Exit\n");
		return 0; // Exit the program
	    default:
		printf("Invalid choice. Please enter between 1 and 6\n");
		displayMenu = 0; // Don't display the menu again if the choice is invalid
		break;
	}
    } while (choice != 6);

    return 0;
}



