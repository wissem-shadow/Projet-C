#include <gtk/gtk.h>
typedef struct{
char login[20];
char mp[20];
char Nomp[20];
char email[20];
char mobile[10];
char adresse[20];
int role;
}client;

int verifier(char login[],char password[]);
void afficher_personne(GtkWidget *liste);
int supprimer(char login[]);
void supprimer_2(char login[]);
int recherche(char login[]);
void find(char login[],char mp[],char nom[],char email[],char mobile[],char adresse[]);
int verif(char login[],char mp[],char nom[],char email[],char mobile[]); 
int verif_email(char email[]); 
int verif_mobile(char mobile[]);

