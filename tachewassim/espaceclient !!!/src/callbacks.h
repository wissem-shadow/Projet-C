#include <gtk/gtk.h>


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

gboolean
on_Hotels_button_press_event           (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_envoyer_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_mon_profil_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);
void
on_se_deconnecter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_payerhotels_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_login_button_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_payervols_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_payerlocationvoitures_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget      *button,
                                        gpointer         user_data);

void
on_payervols_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_payervols_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_payer_sejours_clicked        (GtkButton       *button1,
                                        gpointer         user_data);

void
on_vols_button_enter                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_hotels_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_voitures_button_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_sejours_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourprofile_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_sejours_button_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_payer_sejours_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_profil_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_profil_activate                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_reclamation_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_reclamation_clicked       (GtkButton       *widget,
                                        gpointer         user_data);

void
on_modifier_reclamation_clicked        (GtkWidget      *button,
                                        gpointer         user_data);

void
on_valider_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_hist_payer_hotels_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_payer_hotels_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_payer_hotels_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_payer_hotels_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_vols_client_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_hotels_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_location_voiture_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_sejours_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_valider_modifier_payer_hotels_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
