#include <stdio.h>

#include "frontend.h"

#define PASSWORD_SIZE 64
#define USERNAME_SIZE 64

int main(void)
{
    char username[USERNAME_SIZE], password[PASSWORD_SIZE];
    LgUserData user;

    lg_get_username(username, USERNAME_SIZE);
    lg_get_password(password, PASSWORD_SIZE);
    if (lg_get_user_data(username, password, &user) != 0)
        printf("Invalid login information.\n");
    else
        printf("Hello, %s!\n", username);
    return 0;
}
