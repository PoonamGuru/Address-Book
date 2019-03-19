#include"abk.h"

abk_Status load_file(FILE * abk_fptr,abk * abk_list)
{
    char ch;
    int i , j;
    c_detail * temp;
    abk_list->count = 0;
    abk_list->head = NULL;
    printf("h = %p\n",abk_list->head);
    /*check default file is exist or not */

    /*if present---->check empty or not ----> read the count---> read the name , phone no and email ----->store it in memory*/


    if((abk_fptr =  open_file(DEFAULT_FILE_NAME ,"r")) != NULL)
    {
	/*check file is empty or not*/
	if (check_emptyness(abk_fptr , DEFAULT_FILE_NAME) == FAILURE)
	    return FAILURE;

	else
	{
	    /*read the no of contacts*/
	    read_no_contact(abk_fptr, abk_list);
	    /*check count is zero or not */
	    if(abk_list->count == 0) return FAILURE;

	    else
	    {
		printf("count %d\n",abk_list->count);
		i = 0;
		j = 0;
		while(j < abk_list->count)
		{
		    temp = insert_at_last(abk_list);
		    memset(temp , '\0', sizeof(temp->phone_no));
		    memset(temp , '\0', sizeof(temp->email));
		    /*read the name*/
		    fseek(abk_fptr , 5, SEEK_CUR);
		    strcpy(temp->name, read_name(abk_fptr));
//		    puts(temp->name);
		    


		    /*read phone no*/
		    fseek(abk_fptr , 6 , SEEK_CUR);
		    do{

			strcpy(temp->phone_no[i] , read_phone_no(abk_fptr,&ch));
//			puts(temp->phone_no[i]);
			i++;
		    }while (ch  != '\n');

		    i = 0;
		    /*read email*/
		    fseek(abk_fptr , 6 , SEEK_CUR);
		    do{
			
				strcpy(temp->email[i] , read_email(abk_fptr,&ch));
//				puts(temp->email[i]);
				i++;
		    }while (ch  != '\n');


                    i = 0;
		    j++;
		}

	    }


	}



    }


    else
    {
	fprintf(stderr , "ERROR : %s file is not available\n", DEFAULT_FILE_NAME);
	return FAILURE;
    }



}

char * read_phone_no(FILE * abk_fptr, char * ch)
{
    char * buf = malloc(11);
    fgets(buf , 11 , abk_fptr);
    //    puts(buf);
    *ch = fgetc(abk_fptr);
    //    printf("%c\n",*ch);
    return buf;
}

char * read_email(FILE * abk_fptr, char * ch)
{
    int i = 0;
    char * buf = malloc(30);
    while((*ch = fgetc(abk_fptr)) != '\n')
    {
	if(*ch == ',')
	    break;
	buf[i] = *ch;
	i++;
    }

    buf[i] = '\0';
    //  puts(buf);
    return buf;
}
char * read_name(FILE * abk_fptr)
{
    char * buf = malloc(30);
    fgets(buf , 30 , abk_fptr);
    buf[strlen(buf) - 1] = '\0';
    //puts(buf);
    return buf;
}
/*name        : read_no_contact
 *input       : abk_list
 *output      : char *pointer
 *discription : read the count which stored at the begining of the file
 start with # so skip that .
 read from the 2nd position
 return the count address

 */

void read_no_contact(FILE * abk_file ,abk * abk_list )
{   
    char count[3];
    int i = 0;
    /*point at the begining of the file */
    fseek(abk_file , 0 , SEEK_SET);
    fseek(abk_file,  1 ,SEEK_CUR);

    while((count[i]= fgetc(abk_file)) != '#')
    {
	i++;
    }
    count[i] = '\0';

    fseek(abk_file , 1 , SEEK_CUR); 
    abk_list->count = atoi(count);
}



/*name        : open_file
 *input       : file_name , mode
 *output      : fptr
 *discription : open the file in the specified mode and do the erorr handling
 */


FILE * open_file(const char * file_name,const char * mode)
{
    FILE * fptr1 = fopen(file_name, mode);

    if(fptr1 == NULL)
    {
	perror("fopen");
	printf("ERROR : %s is not openned successfully\n",file_name);
	return NULL;
    }

    else
    {
	printf("INFO : %s is opened successfully\n", file_name);
	return fptr1;
    }

}
/*name          :check_emptyness
 *input         : fptr , file_name
 *output        : SUCCESS , FAILURE
 *discription   : check the empty file or not
 */
int check_emptyness(FILE *fptr, char * file_name)
{
    rewind(fptr);

    /* check file is empty or not*/
    fseek(fptr,0L,2);
    if(ftell(fptr)  != 0)
    {
	printf("INFO : \"%s\" is not empty\n",file_name);
	rewind(fptr);
	return SUCCESS;
    }
    else
    {
	printf("ERROR : \"%s\" is Empty\n",file_name);

	rewind(fptr);
	return FAILURE;
    }

}


