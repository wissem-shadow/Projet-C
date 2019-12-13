#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rec.h"

void supprimer_reclamation (char num_CIN1 [] ){


agents a;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("reclamation.txt","r") ;
f1=fopen("agents1.txt","a");
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s \n",a.nom,a.prenom,a.num_CIN,a.date,a.mes)!=EOF) {
if (strcmp(num_CIN1 ,a.num_CIN)!=0)
{


fprintf(f1,"%s %s %s %s %s \n",a.nom,a.prenom,a.num_CIN,a.date,a.mes);

}
}
}


fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("agents1.txt","reclamation.txt");

}
void afficher_reclamation (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char nom[20];
char prenom [20];
char num_CIN [10] ;
char date[20];
char mes[77];
store=NULL;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM11,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_CIN",renderer,"text",NUMERO_CIN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("date",renderer,"text",DATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("mes",renderer,"text",MES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	     
}


	    store =gtk_list_store_new(NUM_COL11,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING );



            f=fopen("reclamation.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s \n",nom,prenom,num_CIN,date,mes)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM11,nom,PRENOM,prenom,NUMERO_CIN,num_CIN,DATE,date,MES,mes,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}
void modifier_reclamation (agents a1)
{
agents a;
FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("reclamation.txt","r");
f1=fopen("reclamation.tmp","w");
if (f!= NULL)
{
while (fscanf(f,"%s %s %s %s %s \n",a.nom,a.prenom,a.num_CIN,a.date,a.mes)!=EOF) {
if (strcmp(a1.num_CIN ,a.num_CIN)==0)
{
fprintf(f1,"%s %s %s %s %s \n",a1.nom,a1.prenom,a1.num_CIN,a1.date,a1.mes) ;
}
else
fprintf(f1,"%s %s %s %s %s \n",a.nom,a.prenom,a.num_CIN,a.date,a.mes) ;
}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename ("reclamation.tmp","reclamation.txt");
}
}
