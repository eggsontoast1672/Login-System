#ifndef LOGIN_LOGIN_H
#define LOGIN_LOGIN_H

#include <stdlib.h>

typedef struct {
    const char *username;
    const char *password;
} LgUserData;

void lg_get_password(char *buffer, size_t length);
int lg_get_user_data(
    const char *username, const char *password, LgUserData *user);
void lg_get_username(char *buffer, size_t length);

#endif
