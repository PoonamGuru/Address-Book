#include"abk.h"

void main_menu_fun(abk * abk_list)
{
    FILE *abk_fptr;
    char option, choice;
    do{
	sleep(1);
	system("clear");
	main_menu();
	scanf("%c%*c",&option);
	switch(option)
	{
	    case 'A':
		add_contact(abk_list);
		break;
	    case 'L':
		list_contact(abk_list);
		break;
	    case 'S':
		search_contact(abk_list);
		break;
	    case 'E':
		edit_contact(abk_list);
		break;
	    case 'D':
		 delete_contact(abk_list);

		break;
	    case 'V':
		save_to_address_book(abk_list ,abk_fptr);
		break;
	    case 'X':
		return;
		break;
	}
	puts("Do you want to continue with the application:");
	scanf("%c%*c",&choice);
    }while(choice == 'y');


}

