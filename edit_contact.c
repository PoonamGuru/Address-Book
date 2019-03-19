#include"abk.h"
void edit_contact(abk * abk_list)
{
    char option, choice;
    do
    {
	/*display the modification menu*/
	modification_menu();

	scanf("%c%*c", &option);

	switch(option)
	{
	    case 'n':
		edit_name(abk_list);
		break;

	    case 'p':
		edit_phone(abk_list);
		break;
	    case 'e':
		edit_email(abk_list);
		break;
	    case 'x':
		return;
		break;
	}

	puts("Do you want to continue to edit [y/n] :");
	scanf("%c%*c", &choice);

    }   while(choice == 'y');
}



abk_Status edit_name(abk * abk_list)
{
    char name[30];
    char choice;
    c_detail * temp;
    abk_Status status;

    /*prompt user to enter the name*/
    puts("Enter the name to be edited:");
    fgets(name , 30 , stdin);
    name[strlen(name) - 1] = '\0';


    /*search whether that name is present or not*/

    if(search_by_name(abk_list , name, &temp) == FOUND)
    {
	printf("INFO : %s is found\n", name);
	printf("INFO : Would you like to modify it [y/n] :");
	scanf("%c%*c", &choice);

	/*if user is ready to modify allow*/
	if(choice == 'y')
	{

	    do
	    {

		puts("Enter the name :");
		fgets(name , 30 , stdin);
		name[strlen(name) - 1] = '\0';
		status = search_by_name(abk_list , name , NULL);


		/*name is already present */
		if(status  == FOUND)
		{
		    puts("this name is present already , Enter other name:");
		}
	    }while(status == FOUND);

	    strcpy(temp->name , name);
	    printf("The name is modified to %s successfully\n",  temp->name);
	    return SUCCESS;
	}
	else
	{
	    printf("%s name remains same \n", name);
	    return FAILURE;
	}
    }

    else
    {
	printf("%s is not found\n", name);
	return FAILURE;
    }
}



void edit_phone(abk * abk_list)
{
    char phone[11], option, choice;
    c_detail * temp;
    int index, len , i = 0;
    abk_Status status;

    /*prompt the user to enter the phone number*/

    puts("Enter the phone number to edit : ");
    scanf("%s%*c",phone);


    temp = search_phone_no(abk_list , phone , &index);

    /*if thephone no is found*/
    if(temp != NULL)
    {
	/*display the edit_phone_no_menu*/
	edit_phone_no_menu();
	scanf("%c%*c", &option);

	switch(option)
	{
	    case 'a':

		e_add_phone_no(index , phone , temp);
		break;
		//---------------------------------------------------------------------------------------------------------------------------------------------
	    case 'm':
		e_modify_phone_no(phone , index , temp);

		break;
		//------------------------------------------------------------------------------------------------------------------------------------------------		    
	    case 'd':

		e_delete_phone_no( index ,  phone ,  temp);
		break;
		//-------------------------------------------------------------------------------------------------------------------------------------------		    
	    case 'x':
		return ;
		break;
	}
    }
}

void e_add_phone_no(int index , char * phone , c_detail * temp)
{
    int i = 0;
    char choice;
    int len;
    if(index == 3)
	printf("Only 4 phone numbers can be entered \n");
    else 
	/*prompt the user to enter the phone no*/
	puts("Enter the phone number to be added : ");
    scanf("%s%*c", phone);

    len  = strlen(phone);
    /*check the size of phone number*/
    if(len > 10)
	printf("%s is greater than 10 digits \n", phone);
    else if(len < 10)
	printf("%s is less than 10 digits\n",phone);


    else
    {
	/*add the phone no to contact*/
	while(i < 4)
	{
	    if(temp->phone_no[i][0] == ' ')
	    {
		strcpy(temp->phone_no[i] , phone);
		break;
	    }

	    else if(temp->phone_no[i][0] == '\0')
	    {
		strcpy(temp->phone_no[i] , phone);
		break;
	    }
	    i++;
	}
    }

}

void e_modify_phone_no(char * phone , int index , c_detail * temp)
{
    char choice;
    abk_Status status;
    printf("%s number is found\n",phone);
    puts("Do you want to modify it [y/n] :");
    choice = getchar();
    getchar();
    if(choice == 'y')
    {
	do
	{
	    puts("Enter the phone number to edit :");
	    scanf("%s%*c", phone);

	    /*search the phone is already present or not*/
	    status = search_by_phone_no(temp, phone , NULL);
	    if(status == FOUND)
		printf("ERROR :%s is already present\n",phone);

	}while(status == FOUND);

	strcpy(temp->phone_no[index] , phone);
	printf("INFO : %s is modified successfully\n",phone);
    }

    else

	printf("ERROR :%s is not modified\n",phone);

}
void e_delete_phone_no(int index , char * phone , c_detail * temp)
{
    char choice;
    printf("%s is found\n",phone);
    puts("Do you want to delete it [y/n] :");
    choice = getchar(); getchar();

    int i = 0;
    if(choice == 'y')
    {
//	printf("indx = %d\n", index);
	while(temp->phone_no[index][i] != '\0')
	{
	    temp->phone_no[index][i] = ' ';
//	    printf("%d\n",temp->phone_no[index][i]);
	    i++;
	}



	printf("INFO : %s phone no is deleted successfully\n", phone);
    }
    else
    {
	printf("ERROR : %s is not modified \n" , phone);
    }

}


void edit_email(abk * abk_list)
{
    char email[30], option, choice;
    c_detail * temp;
    int index, len , i = 0;
    abk_Status status;

    /*prompt the user to enter the phone number*/

    puts("Enter the email id to edit : ");
    scanf("%s%*c",email);


    temp = search_email(abk_list , email , &index);

    /*if email  found*/
    if(temp != NULL)
    {
	/*display the edit_phone_no_menu*/
	edit_email_menu();
	scanf("%c%*c", &option);

	switch(option)
	{
	    case 'a': e_add_email( index ,  email ,  temp);

		      break;
		      //---------------------------------------------------------------------------------------------------------------------------------------------
	    case 'm':
		      e_modify_email(index , email , temp);

			  break;
		      //------------------------------------------------------------------------------------------------------------------------------------------------		    
	    case 'd':
		      e_delete_email(index, email , temp);
		      break;
		      //-------------------------------------------------------------------------------------------------------------------------------------------		    
	    case 'x':
		      return ;
		      break;
	}
    }
}

void e_add_email(int index , char * email , c_detail * temp)
{
    int i = 0;

    if(index == 3)
	printf("Only 4 email can be entered \n");
    else
    {	
	/*prompt the user to enter the phone no*/
	puts("Enter the email to be added : ");
	scanf("%s%*c", email);



	/*add the email to contact*/
	while(i < 4)
	{
	    if(temp->email[i][0] == ' ')
	    {
		strcpy(temp->email[i] , email);
		break;
	    }

	    else if(temp->email[i][0] == '\0')
	    {
		strcpy(temp->email[i] , email);
		break;
	    }
	    i++;
	}
    }

}
void e_modify_email(int index , char * email , c_detail * temp)
{
    char choice;
    abk_Status status;
    printf("%s email  found\n",email);
    puts("Do you want to modify it [y/n] :");
    choice = getchar();
    getchar();
    if(choice == 'y')
    {
	do
	{
	    puts("Enter the email to edit :");
	    scanf("%s%*c", email);

	    /*search the email is already present or not*/
	    status = search_by_email(temp, email , NULL);
	    if(status == FOUND)
		printf("ERROR :%s is already present\n",email);

	}while(status == FOUND);

	strcpy(temp->email[index] , email);
	printf("INFO : %s is modified successfully\n",email);
    }

    else

	printf("ERROR :%s is not modified\n",email);

}


void e_delete_email(int index, char * email , c_detail * temp)
{
    int i = 0;
    char choice;
    printf("%s is found\n",email);
    puts("Do you want to delete it [y/n] :");
    choice = getchar(); getchar();


    if(choice == 'y')
    {
//	printf("indx = %d\n", index);
	while(temp->email[index][i] != '\0')
	{
	    temp->email[index][i] = ' ';
//	    printf("%d\n",temp->email[index][i]);
	    i++;
	}



	printf("INFO : %s  is deleted successfully\n", email);
    }
    else
    {
	printf("ERROR : %s is not modified \n" , email);
    }

}
