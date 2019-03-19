#ifndef ABK_H
#define ABK_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define  PHONE_COUNT 5 
#define  EMAIL_COUNT 5
#define  PHONE_SIZE  13
#define  EMAIL_SIZE  30
#define  NAME_SIZE   30
#define DEFAULT_FILE_NAME "address_book.csv"

typedef enum status
{
    SUCCESS ,
    FAILURE, 
    FOUND,
    NOT_FOUND
}abk_Status;


typedef struct contact_detail
{
    char name[NAME_SIZE];
    char phone_no[PHONE_COUNT][PHONE_SIZE];
    char email[EMAIL_COUNT][EMAIL_SIZE];
    struct contact_detail * link;
}c_detail;
typedef struct abk_detail_t
{
    c_detail * head;
    int count;
}abk;


/*file related function prototypes*/
abk_Status load_file(FILE * abk_fptr,abk * abk_list);
FILE * open_file(const char * file_name,const char * mode);
int check_emptyness(FILE *fptr, char * file_name);
void read_no_contact(FILE * abk_file , abk * abk_list);
char * read_name(FILE * abk_fptr);
char * read_phone_no(FILE * abk_fptr,char * ch);
char * read_email(FILE * abk_fptr, char * ch);
c_detail * insert_at_last(abk * abk_list);


/*menu functions prototype*/
void main_menu();
void add_contact_menu();
void add_detail_menu();

void edit_menu();
void modification_menu();
void edit_phone_no_menu();
void edit_email_menu();

void search_menu();
/*main menu function prototype*/
void main_menu_fun(abk * abk_list);


/*add contact functions prototypes*/
void add_contact(abk * abk_list);
void add_contact_detail( c_detail * tmp);
void add_detail_info(c_detail * tmp);
void add_phone_no(c_detail * tmp);
void add_email(c_detail * tmp);


/*edit contact function prototypes*/
void edit_contact(abk * abk_list);
abk_Status edit_name(abk * abk_list);
void edit_phone(abk * abk_list);
void edit_email(abk * abk_list);
void e_delete_phone_no(int index , char * phone , c_detail * temp);
void e_modify_phone_no(char * phone , int index , c_detail * temp);
void e_add_phone_no(int index , char * phone , c_detail * temp);
void e_add_email(int index , char * email , c_detail * temp);
void e_modify_email(int indx , char * email , c_detail * temp);
void e_delete_email(int index, char * email , c_detail * temp);





/*list the contact*/
void list_contact(abk * abk_list);


/*delete the contact*/
abk_Status delete_contact(abk * abk_list);

/*search function prototypes*/
void search_contact(abk * abk_list);
c_detail * search_email(abk * abk_list , char * email, int * index);
c_detail * search_phone_no(abk * abk_list , char * phone, int * index);
abk_Status search_by_name(abk * abk_list, char * name, c_detail ** tmp);
abk_Status search_by_phone_no(c_detail * tmp , char * phone, int * indx);
abk_Status search_by_email(c_detail * tmp , char * email, int * index);

/*save to .cvs file*/
void save_to_address_book(abk * abk_list, FILE * abk_fptr);
void write_into_file(abk * abk_list , FILE * abk_fptr);

#endif

