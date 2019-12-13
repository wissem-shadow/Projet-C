#include <gtk/gtk.h>
#include "users.h"
#include "string.h"
int verifier(char login[],char password[]){

char login1[50],password1[50];
int role,r=0;
FILE *f;


f=fopen("users.txt","r") ;
if (f!= NULL)
{

while (fscanf(f,"%s %s %d\n",login1,password1,&role)!=EOF) {

if (strcmp(login ,login1)==0 && strcmp (password,password1)==0)
{
	r=role;
        break;


}

}

fclose(f);
}

return r;

}
