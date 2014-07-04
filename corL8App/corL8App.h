
#ifndef _CORL8_APP_H_
#define _CORL8_APP_H_

#include <gtk/gtk.h>

#define CORL8_APP_TYPE (corl8_app_get_type())
#define CORL8_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), CORL8_APP_TYPE, corL8App))

typedef struct corL8App corL8App;
typedef struct corL8AppClass corL8AppClass;

GType corl8_app_get_type(void);
corL8App* corl8_app_new(void);


#endif // _CORL8_APP_H_
