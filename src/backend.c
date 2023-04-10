#include "backend.h"

#include <string.h>

#define USERS_SIZE 2

static const LgUserData users[USERS_SIZE] = {
     /* username, password */
    {"paul", "1234"},
    {"greg", "5678"},
};

int backend_get_user_data(const char *username, const char *password, LgUserData *user)
{
    size_t i;

    for (i = 0; i < USERS_SIZE; ++i) {
        if (strcmp(username, users[i].username) != 0)
            continue;
        if (strcmp(password, users[i].password) != 0)
            return 1; /* passwords do not match */
        *user = users[i];
        return 0;
    }
    return 1; /* user not found */
}
