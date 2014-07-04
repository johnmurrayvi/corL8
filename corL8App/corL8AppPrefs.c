
#include <gtk/gtk.h>

#include "corL8App.h"
#include "corL8AppWindow.h"
#include "corL8AppPrefs.h"


struct _corL8AppPrefs
{
  GtkDialog parent;
};

struct _corL8AppPrefsClass
{
  GtkDialogClass parent_class;
};

typedef struct _corL8AppPrefsPrivate corL8AppPrefsPrivate;

struct _corL8AppPrefsPrivate
{
  GSettings *settings;
  GtkWidget *font;
  GtkWidget *transition;
};

G_DEFINE_TYPE_WITH_PRIVATE(corL8AppPrefs, corl8_app_prefs, GTK_TYPE_DIALOG);

static void preferences_closed(GtkWidget *button)
{
  gtk_widget_destroy(gtk_widget_get_toplevel(button));
}

static void corl8_app_prefs_init(corL8AppPrefs *prefs)
{
  corL8AppPrefsPrivate *priv;

  priv = corl8_app_prefs_get_instance_private(prefs);
  gtk_widget_init_template(GTK_WIDGET(prefs));

  priv->settings = g_settings_new("com.johnmurrayvi.corl8app");
  g_settings_bind(priv->settings, "font",
                  priv->font, "font",
                  G_SETTINGS_BIND_DEFAULT);
  g_settings_bind(priv->settings, "transition",
                  priv->transition, "active-id",
                  G_SETTINGS_BIND_DEFAULT);
}

static void corl8_app_prefs_dispose(GObject *object)
{
  corL8AppPrefsPrivate *priv;
  priv = corl8_app_prefs_get_instance_private(CORL8_APP_PREFS(object));
  g_clear_object(&priv->settings);

  G_OBJECT_CLASS(corl8_app_prefs_parent_class)->dispose(object);
}

static void corl8_app_prefs_class_init (corL8AppPrefsClass *class)
{
  G_OBJECT_CLASS(class)->dispose = corl8_app_prefs_dispose;

  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "/com/johnmurrayvi/corl8app/prefs.ui");

  gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class),
                                               corL8AppPrefs,
                                               font);
  gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class),
                                               corL8AppPrefs,
                                               transition);

  gtk_widget_class_bind_template_callback(GTK_WIDGET_CLASS(class),
                                          preferences_closed);
}

corL8AppPrefs* corl8_app_prefs_new(corL8AppWindow *win)
{
  // return g_object_new(corL8_APP_PREFS_TYPE,
  //                     "transition-for", win,
  //                     "use-header-bar", TRUE,
  //                     NULL);
  return g_object_new(CORL8_APP_PREFS_TYPE,
                      "transition", win,
                      NULL);
}
