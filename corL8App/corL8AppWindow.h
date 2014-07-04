
#ifndef _CORL8_APP_WINDOW_H_
#define _CORL8_APP_WINDOW_H_

#include <gtk/gtk.h>

#include "corL8App.h"

#define CORL8_APP_WINDOW_TYPE (corl8_app_window_get_type())
#define CORL8_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), CORL8_APP_WINDOW_TYPE, corL8AppWindow))

typedef struct corL8AppWindow corL8AppWindow;
typedef struct corL8AppWindowClass corL8AppWindowClass;

GType corl8_app_window_get_type(void);
corL8AppWindow* corl8_app_window_new(corL8App *app);
void corl8_app_window_open(corL8AppWindow *window, GFile *file);


#endif // _CORL8_APP_WINDOW_H_
