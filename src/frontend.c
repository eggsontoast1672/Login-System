#include <stdio.h>
#include <string.h>

#include "backend.h"
#include "frontend.h"

static char *read_line_internal(char *buffer, size_t length);
static void get_user_data_internal(const char *prompt, char *buffer, size_t length, const char *error);

void lg_get_password(char *buffer, size_t length)
{
    get_user_data_internal("Enter your password: ", buffer, length, "Failed to get password");
}

int lg_get_user_data(const char *username, const char *password, LgUserData *user)
{
    return backend_get_user_data(username, password, user);
}

void lg_get_username(char *buffer, size_t length)
{
    get_user_data_internal("Enter your username: ", buffer, length, "Failed to get username");
}

static void get_user_data_internal(const char *prompt, char *buffer, size_t length, const char *error)
{
    printf("%s", prompt);
    if (read_line_internal(buffer, length) == NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }
}

static char *read_line_internal(char *buffer, size_t length)
{
    char *nl;

    if (fgets(buffer, length, stdin) == NULL)
        return NULL;
    nl = strchr(buffer, '\n');
    if (nl != NULL)
        *nl = '\0';
    return buffer;
}
