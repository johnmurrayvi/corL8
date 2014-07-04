
#include <gtk/gtk.h>

#include "corL8App.h"
#include "corL8AppWindow.h"
#include "corL8AppPrefs.h"


struct corL8App
{
  GtkApplication parent;
};

struct corL8AppClass
{
  GtkApplicationClass parent_class;
};

G_DEFINE_TYPE(corL8App, corl8_app, GTK_TYPE_APPLICATION);

static void corl8_app_init(corL8App *app)
{

}

static void preferences_activated(GSimpleAction *action,
                                  GVariant      *parameter,
                                  gpointer      app)
{
  corL8AppPrefs *prefs;
  GtkWindow *win;

  win = gtk_application_get_active_window(GTK_APPLICATION(app));
  prefs = corl8_app_prefs_new(CORL8_APP_WINDOW(win));

  gtk_window_present(GTK_WINDOW(prefs));
}

static void quit_activated(GSimpleAction *action,
                           GVariant      *parameter,
                           gpointer      app)
{
  g_application_quit(G_APPLICATION(app));
}

static GActionEntry app_entries[] = 
{
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};


static void corl8_app_startup(GApplication *app)
{
  GtkBuilder *builder;
  GMenuModel *app_menu;
  // const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS(corl8_app_parent_class)->startup(app);

  g_action_map_add_action_entries(G_ACTION_MAP(app),
                                  app_entries,
                                  G_N_ELEMENTS(app_entries),
                                  app);

  // gtk_application_set_accels_for_action(GTK_APPLICATION(app),
  //                                       "app.quit",
  //                                       quit_accels);

  builder = gtk_builder_new_from_resource("/com/johnmurrayvi/corl8app/app-menu.ui");
  app_menu = G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu"));
  gtk_application_set_app_menu(GTK_APPLICATION(app), app_menu);

  g_object_unref(builder);
}

static void corl8_app_activate(GApplication *app)
{
  corL8AppWindow *win;
  win = corl8_app_window_new(CORL8_APP(app));

  gtk_window_present(GTK_WINDOW(win));
}

static void corl8_app_open(GApplication *app,
                           GFile        **files,
                           gint         n_files,
                          const gchar  *hint)
{
  GList *windows;
  corL8AppWindow *win;
  int i;

  windows = gtk_application_get_windows(GTK_APPLICATION(app));
  if (windows) 
    win = CORL8_APP_WINDOW(windows->data);
  else
    win = corl8_app_window_new(CORL8_APP(app));

//  win = (windows) ? L8_APP_WINDOW(windows->data) : corl8_app_window_new(L8_APP(app));

  for (i = 0; i < n_files; i++)
    corl8_app_window_open(win, files[i]);

  gtk_window_present(GTK_WINDOW(win));
}

static void corl8_app_class_init(corL8AppClass *class)
{
  G_APPLICATION_CLASS(class)->startup = corl8_app_startup;
  G_APPLICATION_CLASS(class)->activate = corl8_app_activate;
  G_APPLICATION_CLASS(class)->open = corl8_app_open;
}

corL8App* corl8_app_new(void)
{
  return g_object_new(CORL8_APP_TYPE,
                      "application-id",
                      "com.johnmurrayvi.corl8app",
                      "flags",
                      G_APPLICATION_HANDLES_OPEN,
                      NULL);
}
