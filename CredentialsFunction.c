#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define USER_P "<user>_P"
#define MAX_NUM_CREDS 30


struct logins /*fix logins to login*/
{
    char appName[100];
    char email[100];
    char password[100];
};

typedef struct logins login_t;

void save_credential(); /* Anjali */
void view_credential(); /* Anjali */

int main(void){
int choice = 0;
    /* ENTRY TO PROGRAM */
    while(choice != 5)
    {
        /* prints functionality menu for program
            1. create_login()
            2. show_logins()
            3. create_secure_note()
            4. show_secure_notes()
        */
        printf("Main Menu: \n");
        printf("1. Save Credential\n");
        printf("2. View Credential\n");
        printf("3. Create Secure Note\n");
        printf("4. View Secure Note\n");
        printf("5. Log Out\n");
        printf("> ");

        scanf("%d", &choice);
        printf("\n");
        /* switch case for menu options */
        switch(choice)
        {
            case 1: save_credential();
                    break;
            case 2: view_credential();
                    break;
            /*case 3: create_secure_note();
                    break;
            case 4: show_secure_notes();
                    break; */
            case 5: break;
            default: printf("Invalid option\n");
        }
    }
    return 0;
}

void save_credential(){
    login_t credential;
    
    printf("------Save new credentials------\n");
    printf("Application Name: ");
    scanf("%s", credential.appName);
    printf("Username/Email: ");
    scanf("%s", credential.email);
    printf("Password: ");
    scanf("%s", credential.password);
    printf("-------Password encrypted-------\n");
    printf("\n");

    FILE *file_p = NULL;
    file_p = fopen(USER_P, "ab"); 
    if (file_p != NULL)
    {
        /* at the EOF -> MAKE SURE TO GO THROUGH THE FILE TO GET EOF*/
            fwrite(&credential, sizeof(login_t), 1, file_p);
    }
    else
    {
        printf("Read error\n");
    }
    fclose(file_p);

    main();
}



void view_credential(){
    login_t saved_creds[MAX_NUM_CREDS];
    int saved_creds_arr_length = 0;

    FILE *file_p = NULL;
    int items_read = 0;

    file_p = fopen(USER_P, "rb");
    if (file_p != NULL)
    {
        int i;
        for (i = 0; i < MAX_NUM_CREDS-1; i++)
        {
            items_read = fread(&saved_creds[i], sizeof(login_t), 1, file_p);
            if (items_read == 1)
            {
                saved_creds_arr_length++;
            }
        }
        fclose(file_p); 
    }
    else
    {
        printf("Read error\n");
    }

    /*printf("saved_creds_arr_length: %d \n", saved_creds_arr_length);*/

    login_t cred;
    printf("Enter the app name: ");
    scanf("%s", cred.appName);

            /*printf("%s \n", saved_creds[0].appName);
            printf("%s \n", cred.appName);*/

    int i;
    for (i = 0; i < saved_creds_arr_length ; i++)
    {
        if(strcmp(saved_creds[i].appName,cred.appName)==0){
            printf("------Credentials for: %s------\n", saved_creds[i].appName);
            printf("Username/Email: %s \n", saved_creds[i].email);
            printf("Password: %s \n", saved_creds[i].password);
        }
    }
    printf("There are no credentials saved under that application name.\n");
    printf("\n");

    main();
}