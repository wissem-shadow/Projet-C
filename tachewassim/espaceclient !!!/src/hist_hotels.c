#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hist_hotels.h"

void supprimer_hist_hotels (char nom1[] ){


hist a;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("paiementhotels.txt","r+") ;
f1=fopen("agents1.txt","a");
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",a.nom,a.pays,a.nbe,a.prixch,a.nbch,a.adultes,a.enfants,a.bebes)!=EOF) {
if (strcmp(nom1 ,a.nom)!=0)
{


fprintf(f1,"%s %s %s %s %s %s %s %s \n",a.nom,a.pays,a.nbe,a.prixch,a.nbch,a.adultes,a.enfants,a.bebes);

}
}
}


fclose(f);
fclose(f1);
remove("paiementhotels.txt");
rename("agents1.txt","paiementhotels.txt");

}
void afficher_hist_hotels (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char nom[20];
char pays [20];
char nbe [10] ;
char prixch[20];
char nbch[77];
char adultes[20];
char enfants[10] ;
char bebes[20];

store=NULL;

FILE *f1 ;

store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM111,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("pays",renderer,"text",PAYS111,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbe",renderer,"text",NBE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prixch",renderer,"text",PRIXCH,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbch",renderer,"text",NBCH,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	       renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("adultes",renderer,"text",ADULTES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("enfants",renderer,"text",ENFANTS,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("bebes",renderer,"text",BEBES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	     
}


	    store =gtk_list_store_new(NUM_COL111,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING );



            f1=fopen("paiementhotels.txt","r");
            if (f1!=NULL){
		while (fscanf(f1,"%s %s %s %s %s %s %s %s \n",nom,pays,nbe,prixch,nbch,adultes,enfants,bebes)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM111,nom,PAYS111,pays,NBE,nbe,PRIXCH,prixch,NBCH,nbch,ADULTES,adultes,ENFANTS,enfants,BEBES,bebes,-1);
		}
		}
		fclose(f1);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

/*
void modifier_hist_hotels (agents a1)
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
}*/
