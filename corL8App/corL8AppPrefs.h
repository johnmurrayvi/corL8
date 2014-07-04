
#ifndef _CORL8_APP_PREFS_H_
#define _CORL8_APP_PREFS_H_

#include <gtk/gtk.h>

#include "corL8AppWindow.h"

#define CORL8_APP_PREFS_TYPE (corl8_app_prefs_get_type())
#define CORL8_APP_PREFS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), CORL8_APP_PREFS_TYPE, corL8AppPrefs))

typedef struct _corL8AppPrefs corL8AppPrefs;
typedef struct _corL8AppPrefsClass corL8AppPrefsClass;

GType corl8_app_prefs_get_type(void);
corL8AppPrefs* corl8_app_prefs_new(corL8AppWindow *corL8AppWindow);


#endif // _CORL8_APP_PREFS_H_
