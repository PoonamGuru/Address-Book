#include"abk.h"
void search_contact(abk * abk_list)
{
    char option , choice;
    char buf[30];
    int index = 0;
    do
    {
	/*display the search menu*/
	search_menu();

	scanf("%c%*c",&option);

	switch(option)
	{
	    case 'n':
		puts("Enter the name to be search:");
		scanf("%s%*c" , buf);

		if(search_by_name(abk_list , buf, NULL) == FOUND)
		{
		    printf("%s is FOUND\n", buf);
		}

		else
		{
		    printf("%s is NOT FOUND\n",buf);
		}
		break;
	    case 'p':
		puts("Enter the phone_no to be search :");
		scanf("%s%*c", buf);
		if(search_phone_no(abk_list , buf, &index) == NULL)
		{
		    printf("ERROR : Address book does not contain this %s number\n",buf);
		}
		else
		{

		    printf("INFO : Address book does  contain this %s number\n",buf);
		}

		break;
	    case 'e':
		puts("Enter the email ID  to be search :");
		scanf("%s%*c", buf);
		if(search_email(abk_list , buf, &index) == NULL)
		{
		    printf("ERROR : Address book does not contain this %s email\n",buf);
		}
		else
		{

		    printf("INFO : Address book does  contain this %s email\n",buf);
		}

		break;
	    case 'x':
		return ;
		break;
	}

	puts("do you want to continue the search [y/n]: ");
	scanf("%c%*c",&choice);
    }while(choice == 'y');
}
c_detail * search_phone_no(abk * abk_list , char * phone , int * index)
{
    c_detail * temp = abk_list->head;
    while(temp != NULL)
    {
	if(search_by_phone_no(temp , phone, index) == FOUND)
	{
	    printf("INFO : %s contain this %s email\n", temp->name , temp->phone_no[*index]);
	    return temp;
	}
	temp = temp->link;
    }
    return NULL;
}


c_detail * search_email(abk * abk_list , char * email, int * index)
{
    c_detail * temp = abk_list->head;
    while(temp != NULL)
    {
	if(search_by_email(temp , email , index) == FOUND)
	{
	    printf("INFO : %s contain this %s email\n", temp->name , temp->email[*index]);
	    return temp;
	}
	temp = temp->link;
    }
    return NULL;
}


abk_Status search_by_name(abk * abk_list, char * name, c_detail ** tmp)
{
    c_detail * temp = abk_list->head;

    /*loop till the end of list*/
    while(temp != NULL)
    {
	/*compare with each name*/
	if(strcmp(temp->name , name) == 0)
	{
	    if(tmp != NULL)
	    {
		*tmp = temp;
	    }
		


	    /*if matched retuen FOUND*/
	    return FOUND;
	}

	temp = temp->link;
    }


    /*else return NOT_FOUND */
    return NOT_FOUND;
}


abk_Status search_by_phone_no(c_detail * tmp , char * phone, int * index)
{

    int i = 0;
   // if(index != NULL)
    //*index= 0;
    while(tmp->phone_no[i][0] != '\0')
    {
	if(strcmp(tmp->phone_no[i] , phone ) == 0)
	{ 
	    if(index != NULL)
	    {
		*index = i;
	    }
	    return FOUND;
	}
	i++;
    }


    return NOT_FOUND;
}

abk_Status search_by_email(c_detail * tmp , char * email, int * index)
{

    int i = 0;
    //if(index != NULL)
    //*index = 0;
    while(tmp->email[i][0] != '\0')
    {
	if(strcmp(tmp->email[i] , email) == 0)
	{
	    if(index != NULL)
	    {
		*index = i;
	    }
	    return FOUND;
	}
	i++;
    }


    return NOT_FOUND;
}
