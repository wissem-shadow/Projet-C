#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include<fonction.h>
#include "interface.h"
#include "support.h"
#include  <string.h>
#include "interfaceClient.h"

//Retour de authentification au page d'acceuil
void
on_retour1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Authentification;
Authentification=lookup_widget(objet,"Authentification");
gtk_widget_destroy(Authentification);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}

//Permet de faire l'authentification
void
on_connecter_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_vols_client;
  GtkWidget *treeview_location_voiture_client;
  GtkWidget *treeview_hotels_client;
  GtkWidget *treeview_reclamation_client;

GtkWidget *treeview_payer_hotels;
  GtkWidget *EspaceAgent;
  GtkWidget *treeview_sejours_client;
  GtkWidget *payer_vols;
  GtkWidget *payer_sejours;
  GtkWidget *payer_location_voitures;
  GtkWidget *profile;
  GtkWidget *Modification_des_informations;
  GtkWidget *historique_payer_hotels;

GtkWidget *Authentification;
GtkWidget *espace_admin;
GtkWidget *espace_client;
GtkWidget *espace_agent;
GtkWidget *erreur;
GtkWidget *input1;
GtkWidget *input2;
char mp[20];
char login[20];
input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");
strcpy(mp,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
int res=verifier(login,mp);
Authentification=lookup_widget(objet,"Authentification");
if (res==1)  {  gtk_widget_destroy(Authentification);
                espace_admin = create_espace_admin ();
                gtk_widget_show (espace_admin);}
/*else if (res==2) {
		  gtk_widget_destroy(Authentification);
                  espace_agent = create_espace_agent ();
                  gtk_widget_show (espace_agent);}*/
             
else if(res==3) {
                 gtk_widget_destroy(Authentification);
                 espace_client = create_espace_client ();
		treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
  treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);
  //gtk_widget_hide (loginn);  
  gtk_widget_show (espace_client);
  
}
             
else {
       gtk_widget_destroy(Authentification);
       erreur=create_erreur();
       gtk_widget_show(erreur);}
}



//Aller à la fenetre de gestion des clients
void
on_gestion_c_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *gestion_client;
GtkWidget *treeview1;
lookup_widget(objet,"espace_admin");
gtk_widget_destroy(espace_admin);
lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
treeview1=lookup_widget(gestion_client,"treeview1");
afficher_personne(treeview1);
}





void
on_gestion_a_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}

//Aller vers la fenetre d'ajout
void
on_ajouter_c_clicked                   (GtkWidget       *object,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *Inscription_client;
gestion_client=lookup_widget(object,"gestion_client");
gtk_widget_destroy(gestion_client);
Inscription_client=lookup_widget(object,"Inscription_client");
Inscription_client=create_Inscription_client();
gtk_widget_show(Inscription_client);
}

//Supprimer un client à partir d'un login donnée 
void
on_supprimer_c_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
gestion_client=lookup_widget(objet,"gestion_client");
GtkWidget *input1;
GtkWidget *sortie;
char login[20];
input1=lookup_widget(objet,"entry_log");
sortie=lookup_widget(objet,"label");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
int b=supprimer(login);
if (b==1) 
{
supprimer_2(login);
gtk_label_set_text(GTK_LABEL(sortie),"Suppression faite !");
}
else 
{
gtk_label_set_text(GTK_LABEL(sortie),"Client inexistant !");
}
}
//Aller à la fenetre modifier_c
void
on_modifier_c_clicked                  (GtkWidget       *objet,
                                       gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *modifier_c;
GtkWidget *input1;
GtkWidget *sortie;
char login[20];
FILE *f;
gestion_client=lookup_widget(objet,"gestion_client");
input1=lookup_widget(gestion_client,"entrylogin");
sortie=lookup_widget(gestion_client,"label");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
//modifier_c=create_modifier_c();
modifier_c=lookup_widget(objet,"modifier_c");
//if(recherche(login)==1)
//{

gtk_widget_show(modifier_c);
f=fopen("supprimer.txt","w");
fprintf(f,"%s",login);
fclose(f);
//}
/*else
gtk_label_set_text(GTK_LABEL(sortie),"Client inexistant!");
*/
}




//Valider l'ajout d'un nouveau client au fichier
void
on_valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Inscription_client;
Inscription_client=lookup_widget(objet,"Inscription_client");
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *sortie;
input1=lookup_widget(Inscription_client,"entrylogin");
input2=lookup_widget(Inscription_client,"entrymp");
input3=lookup_widget(Inscription_client,"entrynom");
input4=lookup_widget(Inscription_client,"entryemail");
input5=lookup_widget(Inscription_client,"entrymobile");
input6=lookup_widget(Inscription_client,"entryadresse");
sortie=lookup_widget(Inscription_client,"labelverif");
client cl;
char login[20];
char mp[20];
char nom[20];
char email[20];
char mobile[20];
char adresse[20];
//strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
//strcpy(mp,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input3)));
//strcpy(email,gtk_entry_get_text(GTK_ENTRY(input4)));
//strcpy(mobile,gtk_entry_get_text(GTK_ENTRY(input5)));
//strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
cl.role=3;
//if(verif(login,mp,nom,email,mobile)&& verif_email(email)&& verif_mobile(mobile))
//{
strcpy(cl.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(cl.mp,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cl.Nomp,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cl.email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(cl.mobile,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(cl.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
ajouter(cl);
//}
//else
//gtk_label_set_text(GTK_LABEL(sortie),"Erreur de saisie");
}
//Retour de inscription_client au Gestion_client
void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inscription_client, *gestion_client;
inscription_client=lookup_widget(objet,"inscription_client");
gtk_widget_destroy(inscription_client);
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


//Valider la modification des champs
void
on_valider_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_c;
GtkWidget *gestion_client;
ajouter_c=lookup_widget(objet,"ajouter_c");
gestion_client=lookup_widget(objet,"gestion_client");
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
input1=lookup_widget(objet,"login");
input2=lookup_widget(objet,"mp");
input3=lookup_widget(objet,"nomp");
input4=lookup_widget(objet,"email");
input5=lookup_widget(objet,"mobile");
input6=lookup_widget(objet,"adresse"); 
char login[20];
char mp[20];
char nom[20];
char email[20];
char mobile[20];
char adresse[20];
client cl;
find(login,mp,nom,email,mobile,adresse);
gtk_entry_set_text(GTK_ENTRY(input1),login);
gtk_entry_set_text(GTK_ENTRY(input2),mp);
gtk_entry_set_text(GTK_ENTRY(input3),nom);
gtk_entry_set_text(GTK_ENTRY(input4),email);
gtk_entry_set_text(GTK_ENTRY(input5),mobile);
gtk_entry_set_text(GTK_ENTRY(input1),adresse);
strcpy(cl.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(cl.mp,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cl.Nomp,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cl.email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(cl.mobile,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(cl.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
cl.role=3;
int b=supprimer(cl.role);
if (b) 
supprimer_2(cl.login);
ajouter(cl);
}

//Retour au fenetre Gestion client
void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_c , *gestion_client;
modifier_c=lookup_widget(objet,"modifier_c");
gtk_widget_destroy(modifier_c);
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}



//Aller vers la fenetre Inscription_client
void
on_inscrire_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Inscription_client;
Acceuil=lookup_widget(objet,"Acceuil");
gtk_widget_destroy(Acceuil);
Inscription_client=lookup_widget(objet,"Inscription_client");
Inscription_client=create_Inscription_client();
gtk_widget_show(Inscription_client);
}


//Aller vers l'espace d'authentification
void
on_connect_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Authentification;
Acceuil=lookup_widget(objet,"Acceuil");
gtk_widget_destroy(Acceuil);
Authentification=lookup_widget(objet,"Authentification");
Authentification=create_Authentification();
gtk_widget_show(Authentification);
}

void
on_retoura_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Inscription_client;
Inscription_client=lookup_widget(objet,"Inscription_client");
gtk_widget_destroy(Inscription_client);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}

