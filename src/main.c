#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNTS_SIZE 1
#define PASSWORD_SIZE 64
#define USERNAME_SIZE 64

typedef struct {
    const char *username;
    const char *password;
} Account;

Account accounts[ACCOUNTS_SIZE] = {
    {"paul", "1234"},
};

void get_password(char *buffer, size_t length);
int get_user(Account *user, const char *username, const char *password);
void get_username(char *buffer, size_t length);
char *read_string(char *buffer, size_t length);

int main(void)
{
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];

    size_t i;

    get_username(username, USERNAME_SIZE);
    get_password(password, PASSWORD_SIZE);

    for (i = 0; i < ACCOUNTS_SIZE; ++i) {
        const Account *account = &accounts[i];

        if (strcmp(username, account->username) != 0) {
            continue;
        }

        if (strcmp(password, account->password) != 0) {
            printf("Incorrect password!\n");
            break;
        }

        printf("Welcome, %s!\n", username);
    }
    printf("That user does not exist!\n");

    return 0;
}

void get_password(char *buffer, size_t length)
{
    printf("Enter your password: ");
    if (read_string(buffer, length) == NULL) {
        fprintf(stderr, "Failed to get password\n");
        exit(1);
    }
}

int get_user(Account *user, const char *username, const char *password)
{
    // ...
}

void get_username(char *buffer, size_t length)
{
    printf("Enter your username: ");
    if (read_string(buffer, length) == NULL) {
        fprintf(stderr, "Failed to get username\n");
        exit(1);
    }
}


char *read_string(char *buffer, size_t length)
{
    char *nl;

    if (fgets(buffer, length, stdin) == NULL)
        return NULL;
    nl = strchr(buffer, '\n');
    if (nl != NULL)
        *nl = '\0';
    return buffer;
}
