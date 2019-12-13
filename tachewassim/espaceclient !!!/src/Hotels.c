#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Hotels.h"
 
void affichage_Hotels (GtkWidget *treeview3) {

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


char nom [100];
char pays[100] ;
char nbr_etoiles [10];

char prix [10];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview3);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("pays",renderer,"text",PAYS,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

           renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbr_etoiles",renderer,"text",NBRETOILE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prix",renderer,"text",PRIXCHAMBRE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

 

          ;
}


store =gtk_list_store_new(NUM_COL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING );



            f=fopen("hotel.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s",nom,pays,nbr_etoiles,prix)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM,nom,PAYS,pays,PRIXCHAMBRE,prix,NBRETOILE,nbr_etoiles,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview3),GTK_TREE_MODEL(store));
            g_object_unref(store);
	    
}

void ajouter_Hotel(hotel h) {

FILE * f; 

f=fopen("hotel.txt","a+") ;
if(f!=NULL) {


fprintf(f,"%s %s %s %s \n ",h.nomHotel,h.nbrEtoiles,h.pays,h.prix);
}

fclose(f); 
}

/*

void modifier_hotel (hotel h1)
{
hotel h;
FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("hotel.txt","r+");
f1=fopen("hotel1.txt","w");
if (f!= NULL)
{
while (fscanf(f," %s %s %s %s %s",h.nomHotel,h.nbrEtoiles,h.pays,h.nbrChambres,h.prix)!=EOF) {
if (strcmp(h1.nomHotel ,h.nomHotel)==0)
{
fprintf(f1,"%s %s %s %s %s\n",h1.nomHotel,h1.nbrEtoiles,h1.pays,h1.nbrChambres,h1.prix) ;
}
else
fprintf(f1,"%s %s %s %s %s\n",h.nomHotel,h.nbrEtoiles,h.pays,h.nbrChambres,h.prix) ;
}
fclose(f1);
fclose(f);
remove("hotel.txt");
rename ("hotel1.txt","hotel.txt");
}
}




void supprimer_hotel (char nomHotel1[]){


hotel h;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("hotel.txt","r") ;
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s\n",h.nomHotel,h.nbrEtoiles,h.pays,h.nbrChambres,h.prix)!=EOF) {
if (strcmp(nomHotel1 ,h.nomHotel))
{
f1=fopen("hotel1.txt","a");

fprintf(f1,"%s %s %s %s %s\n",h.nomHotel,h.nbrEtoiles,h.pays,h.nbrChambres,h.prix) ;
fclose(f1);
}
}
}


fclose(f);
remove("hotel.txt");
rename("hotel1.txt","hotel.txt");

}




*/
