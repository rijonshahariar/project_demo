#include<stdio.h>
#include<string.h>
#include<process.h>

struct User
{
    char id[20], pass[100], route[100], role[10];
};
struct User u[100];

int n; //global variable for count users

//using this for password encryption
//char key[70] = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
//char org[70] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


void getData()
{
    FILE *fp;
    fp = fopen("userDB.txt", "r");

    for(int i = 0; ; i++)
    {
        if(feof(fp))
        {
            break;
        }
        fscanf(fp,"%s", u[i].id);
        fscanf(fp,"%s", u[i].pass);
        fscanf(fp,"%s", u[i].role);
        fscanf(fp,"%s", u[i].route);
        n=i;
    }
    fclose(fp);

}

void writeData()
{
    FILE *fr;
    fr = fopen("userDB.txt", "w");

    for(int i = 0; i<n; i++)
    {
        fprintf(fr, "%s\n", u[i].id);
        fprintf(fr, "%s\n", u[i].pass);
        fprintf(fr, "%s\n", u[i].role);
        fprintf(fr, "%s\n", u[i].route);
    }
    fclose(fr);
}

void signup()
{
    int x;
    char uid[10], key[100], route[100];
    printf("  Enter UID: _");
    scanf("%s", uid);
    printf("  Enter Password: _");
    scanf("%s", key);
    printf("  Routes Available:\n");
    printf("  1. IIUC - Chawkbazar\n");
    printf("  2. IIUC - Bahaddarhat\n");
    printf("  Enter Your Route: ");
    scanf("%d", &x);

    strcpy(u[n].id, uid);
    strcpy(u[n].pass,key);
    strcpy(u[n].role, "user");
    if(x == 1)
    {
        strcpy(u[n].route, "Chawkbazar");
    }
    else if(x == 2)
    {
        strcpy(u[n].route, "Bahaddarhat");
    }

    n++;

}

void login()
{
    char str[100], password[100];
    int checkingIfUserfound = 0;
    printf("  Enter ID: ");
    scanf("%s", str);
    printf("  Enter Password: ");
    scanf("%s", password);

    for(int i = 0; i<n; i++)
    {
        if(strcmp(str,u[i].id) == 0 && strcmp(password, u[i].pass) == 0)
        {
            checkingIfUserfound = 1;
            if(strcmp("admin",u[i].role) == 0){
                system("cls");
                adminPanel();
                break;
            }
            else{
            system("cls");
            homepage();
            break;
            }

        }
    }

    if(checkingIfUserfound == 0){
        printf("\n\nWrong Username or Password\n\n");
    }

}

void homepage()
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  User Panel                       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

}

void adminPanel(){
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  Admin Panel                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
}

int main()
{
    int q;
    getData();
    printf("  1. Login\n");
    printf("  2. Register\n");
    printf("  Enter Number: ");
    scanf("%d", &q);

    switch(q)
    {
    case(1):
        login();
        break;


    case(2):
        signup();
        writeData();
        break;
    }
}
