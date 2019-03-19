#include"abk.h"

abk_Status delete_contact(abk * abk_list)
{
    char name[30];
    c_detail * temp, * t ;
    char choice;

    /*search for a contact that need to be delete */
    puts("Enter the name that need to be delete :");
    fgets(name , 30 , stdin);
    name[strlen(name) - 1] = '\0';

    /*search for the name that contact need to delete*/

    if(strcmp(abk_list->head->name , name) == 0)
    {	
	
	printf("INFO : the name %s is found \n",name);
	puts("do you want to delete it permanently [y/n] :");
	scanf("%c%*c", &choice);
	if(choice == 'y')
	{	

	    temp =  abk_list->head->link;
	    free(abk_list->head);
	    return SUCCESS;
	}
	else
	{
	    puts("Not deleted");
	    return FAILURE;
	}
    }

    else
    {
	/*similar to delete after*/
	temp = abk_list->head;
	while(temp->link != NULL)
	{
	    if(strcmp(temp->link->name , name) == 0)
	    {
		printf("INFO : the name %s is found \n",name);
		puts("do you want to delete it permanently [y/n] :");
		scanf("%c%*c", &choice);
		if(choice == 'y')
		{	
		    t = temp->link;
		    temp->link = temp->link->link;

		    free(t);
		    puts("Deleted successfully");
		    return SUCCESS;
		}

		else{
		    puts("not deleted");
		    return FAILURE;
		}
	    }
	    temp = temp->link;
	}
    }

    printf("Data %s  that you are searching in not there\n", name);
    return FAILURE;
}
