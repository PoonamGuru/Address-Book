#include"abk.h"

void save_to_address_book(abk * abk_list, FILE * abk_fptr)
{
    char option;
    char file_name[30];
    puts("DO you want to use the default file or need to cearte new file ");
    puts("1 .Press [d] to use default file");
    puts("1. Press [n] to use new file ");
    puts("enter the option: ");
    scanf("%c%*c", &option);
    putchar(option);

    if(option == 'd')
    {
	/*open the default file in write mode*/
	if((abk_fptr =  open_file(DEFAULT_FILE_NAME ,"w")) != NULL)
	{

	    write_into_file(abk_list , abk_fptr);
	    fclose(abk_fptr);
	}


	else
	{
	    puts("The default file doesn't eixits");
	}

    }


    else if(option == 'n')
    {
	puts("Enter the file name with extension as .csv :");
	scanf("%s%*c",file_name);
	/*open the default file in write mode*/
	if((abk_fptr =  open_file(file_name ,"w")) != NULL)
	{

	    write_into_file(abk_list , abk_fptr);
	    fclose(abk_fptr);
	}


    }
}














void write_into_file(abk * abk_list , FILE * abk_fptr)
{
    int i = 0;
    char buf[5];
    c_detail * temp = abk_list->head;
    /*Go to the begining of the file */
    fseek(abk_fptr , 0, SEEK_CUR);

    /*store the total no of contact*/
    sprintf(buf , "#%d#\n",abk_list->count);
    fputs(buf,abk_fptr);

    /*store copying the contact detail from mem to file*/


    while(temp != NULL)
    {
	i = 0;
	fputs("NAME:",abk_fptr);
	fprintf(abk_fptr, "%s\n",temp->name);


	fputs("PHONE:",abk_fptr);
	while(temp->phone_no[i][0] != '\0')
	{
	    fprintf(abk_fptr , "%s", temp->phone_no[i]);

	    i++;
	    if(temp->phone_no[i][0] != '\0')

		fputc(',',abk_fptr);
	}



	fputs("\nEMAIL:",abk_fptr);

	i = 0; //reset to 0

	while(temp->phone_no[i][0] != '\0')
	{
	    fprintf(abk_fptr , "%s",temp->email[i]);
	    i++;


	    if(temp->phone_no[i][0] != '\0')

		fputc(',',abk_fptr);

	}
	fputc('\n' , abk_fptr);

	temp = temp->link;
    }

}

