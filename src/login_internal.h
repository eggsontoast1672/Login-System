#ifndef LOGIN_LOGIN_INTERNAL_H
#define LOGIN_LOGIN_INTERNAL_H

#include "login.h"

int backend_get_user_data(
    const char *username, const char *password, LgUserData *user);

#endif
