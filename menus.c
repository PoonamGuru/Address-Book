#include"abk.h"

void main_menu()
{
    puts("***************************************MAIN MENU *************************************************");
    puts("1. Add contact [ A ]");
    puts("2. List contact [ L ]");
    puts("3. Search contact [ S ]");
    puts("4. Delete contact [ D ]");
    puts("5. Edit contact [ E ]");
    puts("6. Save contact [ S ]");
    puts("7. Exit the application [ X ]");
    puts("Select any one option:");
}


void add_contact_menu()
{
    puts("**********************************ADD CONTACT MENU ************************");
    puts("1. Add Detail [a]");
    puts("2. Exit to main menu [ x ]");
    puts("___________setect any option : _____________________");

}

void  add_detail_menu()
{
    system("clear");
    puts("************************************ ADD DETAIL MENU ******************************");
    puts("1. Add Phone Number [ p ]");
    puts("2. Add Email [ e ]");
    puts("3. Exit to add_contact_menu [ x ]");
    puts("Enter the option:"); 
}

void search_menu()
{
    system("clear");
    puts("*************************************SEARCH MENU*********************************");
    puts("1. Search by Name [ n ]");
    puts("2. Search by Phone no [ p ]");
    puts("3. Search by Email ID [ e ]");
    puts("4. Exit to main menu [ x ]");
    puts("Enter the option : ");
}


void edit_contact_menu()
{
    system("clear");
    puts("*********************************************EDIT MENU**********************************");
    printf("1. List all the contact [ l ]");
    search_menu();
}

void modification_menu()
{
    system("clear");
    puts("****************************************** MODIFICATION MENU ***********************************");
    puts("1. Edit contact name [n]");
    puts("2. Edit phone number [p]");
    puts("3. Edit email Id [e]");
    puts("4. Exit to main_menu");
    puts("Enter the option:");
}

void edit_phone_no_menu()
{
    system("clear");
    puts("1. Add Phone number[a]");
    puts("2. Modify Phone number[m]");
    puts("3. Delete Phone number[d]");
    puts("4. Exit to modification menu [x]");
}

void edit_email_menu()
{
    system("clear");
    puts("1. Add email ID [a]");
    puts("2. Modify email ID [m]");
    puts("3. Delete email ID [d]");
    puts("4. Exit to modification menu [x]");
}
