#ifndef LOGIN_BACKEND_H
#define LOGIN_BACKEND_H

#include "frontend.h"

int backend_get_user_data(const char *username, const char *password, LgUserData *user);

#endif
