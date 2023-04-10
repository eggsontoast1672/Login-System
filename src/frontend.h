#ifndef LOGIN_FRONTEND_H
#define LOGIN_FRONTEND_H

#include <stdlib.h>

typedef struct {
    const char *username;
    const char *password;
} LgUserData;

void lg_get_password(char *buffer, size_t length);
int lg_get_user_data(const char *username, const char *password, LgUserData *user);
void lg_get_username(char *buffer, size_t length);

#endif
