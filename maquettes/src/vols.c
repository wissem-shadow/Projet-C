#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vols.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
   GtkWidget *espace_client;
  GtkWidget *Reclamation;
  GtkWidget *Vols;
  GtkWidget *Location_voitures;
  GtkWidget *payer_hotels;
  
  GtkWidget *Sejours;
  GtkWidget *Hotels;
  GtkWidget *Login;
  GtkWidget *treeview1;
  GtkWidget *treeview2;
  GtkWidget *treeview3;

  GtkWidget *treeview4;
GtkWidget *payer_vols;
GtkWidget *payer_sejours;
void affichage_vols (GtkWidget *treeview3) {

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

	char depart[30];
	char destination[30];
	char datedepart[30];
	char dateretour[30];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview3);
if (store == NULL)
{
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("depart",renderer,"text",DEPART,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("destination",renderer,"text",DESTINATION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("datedepart",renderer,"text",DATEDEPART,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("dateretour",renderer,"text",DATERETOUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);
}


store =gtk_list_store_new(NUM_COLL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );



            f=fopen("vols.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s",depart,destination,datedepart,dateretour)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,DEPART,depart,DESTINATION,destination,DATEDEPART,datedepart,DATERETOUR,dateretour,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview3),GTK_TREE_MODEL(store));
            g_object_unref(store);
	    
}
void recherchervols(char depart[300])
{
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
char depart1[300];
char destination1[300];
char datedepart1[300];
char dateretour1[300];


FILE *l;
l=fopen("vols.txt","r");
while (fscanf(l,"%s %s %s %s \n",depart1,destination1,datedepart1,dateretour1)!=EOF)
{
if (strcmp(depart,depart1)!=0)
{
payer_vols=create_payer_vols();
input2=lookup_widget(payer_hotels,"departv");
input3=lookup_widget(payer_hotels,"destinationv");
input4=lookup_widget(payer_hotels,"datedepartv");
input5=lookup_widget(payer_hotels,"dateretourv");




gtk_entry_set_text(GTK_ENTRY(input2),depart1);
gtk_entry_set_text(GTK_ENTRY(input3),destination1);
gtk_entry_set_text(GTK_ENTRY(input4),datedepart1);

gtk_entry_set_text(GTK_ENTRY(input5),dateretour1);


}

payer_vols = create_payer_vols();
gtk_widget_show (payer_vols);
}fclose(l);
}
