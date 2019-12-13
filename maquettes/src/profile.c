#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "profile.h"





void affiche_profile(char nom[],char prenom[],char sexe[],char date[],char tel[],char adresse[],char mdp[],char cin[])
{
	
FILE *f;
f=fopen("profileclient.txt","r");
if (f!=NULL)
	{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s\n",nom,prenom,sexe,date,tel,adresse,mdp,cin)!=EOF){

}
fclose(f); 
}
}
