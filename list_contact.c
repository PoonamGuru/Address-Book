#include"abk.h"

void list_contact(abk * abk_list)
{
    c_detail * temp = abk_list->head;

    int i = 0;
    while(temp != NULL)
    {
	printf("\nNAME : %s\n", temp->name);
         puts("PHONE:");

	while(temp->phone_no[i][0] != '\0')
	{
//	    if(temp->phone_no[i][0] != ' ')
	    printf("%s ", temp->phone_no[i]);
	    i++;
	}
	i = 0;
	printf("\nEMAIL : \n");
	while(temp->email[i][0] != '\0')
	{
	    printf("%s ", temp->email[i]);
	    i++;
	}
puts("\n***************************************************************************");

	temp = temp->link;
	i = 0;
    }
}
