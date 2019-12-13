#include <stdio.h>
 #include <string.h>
 #include "fonction.h"
#include <gtk/gtk.h>

enum
{
LOGIN,
MP,
NOMP,
EMAIL,
MOBILE,
ADRESSE,
COLUMNS
};

void ajouter(client cl)
{
FILE *f;
FILE *f1;
f=fopen("users.txt","a+");
f1=fopen("clients.txt","a+");
if(f!=NULL)
  {
   fprintf(f,"%s %s %d\n",cl.login,cl.mp,cl.role);  
   fclose(f);
  }
if(f1!=NULL)
  {
   fprintf(f1,"%s %s %s %s %s %s\n",cl.login,cl.mp,cl.Nomp,cl.email,cl.mobile,cl.adresse);  
   fclose(f1);
   }
}


int verifier(char login[20],char password[20])
{
FILE *f;
char log[20];
char psw[20];
int r;
f=fopen("users.txt","r");
if(f!=NULL)
  {
     
    while(fscanf(f,"%s %s %d\n",log,psw,&r)!=EOF)
        {
           if(strcmp(log,login)==0 && strcmp(psw,password)==0)
            {
              fclose(f);
              return (r);
             }             
        }
  }
else
return(-1);
}
//afficher un client
void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;//afficheur de cellule(cellule contient un texte,image..)
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char login[20];
char mp[20];
char nomp[20];
char email[20];
char mobile[10];
char adresse[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("login", renderer, "text",LOGIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mp", renderer, "text",MP, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nomp", renderer, "text",NOMP, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("email", renderer, "text",EMAIL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mobile", renderer, "text",MOBILE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",ADRESSE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

//la liste contient 6 colonnes de type chaine de caractères
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("clients.txt","r");
if(f==NULL)
{
  return;
}
else
{ 
 f=fopen("clients.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s\n" ,login,mp,nomp,email,mobile,adresse)!=EOF)
 {
   gtk_list_store_append(store,&iter);
   gtk_list_store_set(store,&iter,LOGIN,login,MP,mp,NOMP,nomp,EMAIL,email,MOBILE,mobile,ADRESSE,adresse,-1);
 }
  fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

int  supprimer(char login[20])
{
FILE *fu;//users.txt
FILE *f;//fichier auxiliaire
fu=fopen("users.txt","r");
f=fopen("auxuser.txt","w");
char log[20];
char psw[20];
int r;
int b=0;

    while(fscanf(fu,"%s %s %d\n",log,psw,&r)!=EOF && b==0)
        {
          if(strcmp(log,login)==0)
          b=1;
          else
          fprintf(f,"%s %s %d\n",log,psw,r);
         }
      if(b==0)
      {
      fclose(fu);
      fclose(f);
      remove("auxuser.txt");
      }
      else{
           fclose(f);
           f=fopen("auxuser.txt","a+");
           while(fscanf(fu,"%s %s %d\n",log,psw,&r)!=EOF)
           fprintf(f,"%s %s %d\n",log,psw,r);   
            fclose(fu);
            fclose(f);
            remove("users.txt");
            rename("auxuser.txt","users.txt");
            }

return(b);
}


void supprimer_2(char login[20])
{
FILE *fc;//clients.txt
FILE *f1;//fichier auxiliaire
fc=fopen("clients.txt","r");
f1=fopen("auxclients.txt","w");
char log[20];
char mp[20];
char Nomp[20];
char email[20];
char mobile[10];
char adresse[20];

    while(fscanf(fc,"%s %s %s %s %s %s\n" ,login,mp,Nomp,email,mobile,adresse)!=EOF && (strcmp(log,login)!=0))
       {
          fprintf(f1,"%s %s %s %s %s %s\n" ,login,mp,Nomp,email,mobile,adresse);
       }
           fclose(f1);
           f1=fopen("auxclients.txt","a+");
           while(fscanf(fc,"%s %s %s %s %s %s\n",login,mp,Nomp,email,mobile,adresse)!=EOF)
           { fprintf(f1,"%s %s %s %s %s %s\n" ,login,mp,Nomp,email,mobile,adresse);} 
            fclose(fc);
            fclose(f1);
            remove("clients.txt");
            rename("auxclients.txt","clients.txt");

}

int recherche(char login[20])
{
FILE *f;
f=fopen("users.txt","r");
char log[20];
char psw[20];
int r,b;
if(f!=NULL)
  {
   int b=0;
    
    while(fscanf(f,"%s %s %d\n",log,psw,&r)!=EOF )
        {
          if(strcmp(log,login)==0){
          b=1;
          return(b);}
         }
   }
fclose(f);
return(b);
}

void find(char login[20],char mp[20],char nom[20],char email[20],char mobile[20],char adresse[20])
{
char log[20];
FILE *f;
f=fopen("supprimer.txt","r");
fscanf(f,"%s",log);
fclose(f);
FILE *f1;
f1=fopen("clients.txt","r");
 while(fscanf(f1,"%s %s %s %s %s %s\n" ,login,mp,nom,email,mobile,adresse)!=EOF && (strcmp(log,login)!=0))
fclose(f1);
}

int verif(char login[20],char mp[20],char nom[20],char email[20],char mobile[20])
{
int b=1;
if(strcmp(login,"")==0 ||strcmp(mp,"")==0 || strcmp(nom,"")==0 || strcmp(email,"")==0 || strcmp(mobile,"")==0)
b=0;
return(b);
}

int verif_email(char email[20])
{
int b1=0;
int b2=0;
int i=0;
while(i<strlen(email) &&(!b1) && (!b2) )
{
if (email[i]=='@')
b1=1;
if (email[i]=='.')
b2=1;
i++;
}
return(b1*b2);
}

int verif_mobile(char mobile[20])
{
int b=1;
if(strlen(mobile)!=8)
return(0);
else{
int i=0;
while(i<strlen(mobile) && b==1 )
{
if(mobile[i]>='0' && mobile[i]<='9')
i++;
else b=0;
}
return(b);
}
}

