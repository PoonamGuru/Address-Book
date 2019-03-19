#include"abk.h"

c_detail * insert_at_last(abk * abk_list)
{

    c_detail * temp = abk_list->head;
    /*if head is null*/
    if(abk_list->head == NULL)
    {
	abk_list->head = malloc(sizeof(c_detail));
	if(abk_list->head == NULL)
	    return NULL;

	else
	{
	    abk_list->head->link = NULL;
	    return abk_list->head;
	}

    }

    else
    {
	temp = abk_list->head;

	while(temp->link != NULL)
	    temp = temp->link;


	temp->link = malloc(sizeof(c_detail));
	if(temp->link == NULL)
	    return NULL;
	else
	{
	    temp->link->link = NULL;
	    return temp->link;
	}
    }
}
