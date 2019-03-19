#include"abk.h"

int main()
{
    FILE * abk_fptr;
    abk  abk_list;

    /*load the file*/
    load_file(abk_fptr , &abk_list);

    /*main_menu*/
    main_menu_fun(&abk_list);
    return 0;
}
