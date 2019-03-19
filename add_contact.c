#include"abk.h"
void add_contact(abk * abk_list)
{
    char * buf = malloc(30);
    char choice;
    c_detail * temp;
    do
    {
	/*prompt the user to enter the name*/
	puts("\nEnter the user name :");
	fgets(buf , 30 , stdin);
	buf[strlen(buf) - 1] = '\0';


	/*search name is already present*/
	if(search_by_name(abk_list, buf, NULL) == FOUND)
	    /*if present*/

	    /*diplay error message*/
	    printf("ERROR : the %s is already present in the address book\n",buf);


	else
	    /*store it in memory*/
	{
	    /*create a memory*/
	    temp = insert_at_last(abk_list);
	    strcpy(temp->name , buf);
	    puts(temp->name);
	    abk_list->count += 1;
	    /*add the detail info */

	    add_contact_detail(temp);


	}

	puts("\n\n............................Do you want to enter another name again :................................");
	scanf("%c%*c",&choice);
    }while(choice == 'y');


}

void add_contact_detail( c_detail * tmp)
{
    char option , choice;
    do
    {
	add_contact_menu();
	scanf("%c%*c",&option);

	switch(option)
	{
	    case 'a' :
		add_detail_info(tmp);
		break;
	    case 'x':
		return ;
		break;
	}

	puts("\n\n.......................................do you want to enter further details :...........................");
	scanf("%c%*c", &choice);

    }while(choice == 'y');

}

void add_detail_info(c_detail * tmp)
{
    char option, choice;
    do
    {
	add_detail_menu();
	scanf("%c%*c", &option);

	switch(option)
	{
	    case 'p':
		add_phone_no(tmp);
		break;
	    case 'e':
		add_email(tmp);
		break;
	    case 'x':
		return ;
		break;
	}

	puts("\n\n......................do you want to other details :...................................");
	scanf("%c%*c",&choice);
    }while(choice == 'y');

}


void add_phone_no(c_detail * tmp)
{
    memset(tmp->phone_no , '\0', sizeof(tmp->phone_no));
    char * buf = malloc(11);
    int count = 0;
    char choice;
    do
    {
	if(count == 4)
	{
	    printf("ERROR : You are allowed to enter only 4 phone numbers");
	    break;
	}
	puts("Enter the phone number:");
	scanf("%s%*c",buf);

	int len = strlen(buf);
	if(len < 10)
	    printf("ERROR : %s is less then 10 digits\n", buf);

	else if( len > 10)
	    printf("ERROR : %s is greter than 10 digits\n", buf);

	/*first time the phone number is storing*/
	else if(tmp->phone_no[0][0] == '\0')
	{
	    strcpy(tmp->phone_no[0] , buf);
	    count++;
	}

	/*search for the phone number*/
	else if(search_by_phone_no(tmp, buf, NULL) == FOUND)
	{
	    printf("ERROR : %s is already present in the address book\n", buf);
	}

	else
	{
	    /*store it in a memory*/
	    strcpy(tmp->phone_no[count] , buf);
	    printf("%d %s\n", count , tmp->phone_no[count] );
	    printf("INFO : %s is stored SUCCESSFULLY\n", buf);
	    count++;
	}
	puts("\n\n....................................Do you want to enter the new phone no :.............................");
	scanf("%c%*c",&choice);
    }while(choice == 'y');


}

void add_email(c_detail * tmp)
{
    memset(tmp->email , '\0', sizeof(tmp->email));
    char * buf = malloc(30);
    int count = 0;
    char choice;
    do
    {
	if(count == 4)
	{
	    puts("ERROR : you are allowed to enter only 4 email id's");
	    break;
	}
	puts("Enter the email ID:");
	scanf("%s%*c",buf);

	int len = strlen(buf);
	

	/*first time the phone number is storing*/
	 if(tmp->email[0][0] == '\0')
	{
	    strcpy(tmp->email[0] , buf);
	    count++;
	}

	/*search for the phone number*/
	else if(search_by_email(tmp, buf, NULL) == FOUND)
	{
	    printf("ERROR : %s is already present in the address book\n", buf);
	}

	else
	{
	    /*store it in a memory*/
	    strcpy(tmp->email[count] , buf);
	    printf("%d %s\n", count , tmp->email[count] );
	    printf("INFO : %s is stored SUCCESSFULLY\n", buf);
	    count++;
	}
	puts("\n\n...........................................Do you want to enter the new email ID :..............................");
	scanf("%c%*c",&choice);
    }while(choice == 'y');


}


