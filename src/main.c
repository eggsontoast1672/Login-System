/* Error: seg fault
 * username = jim
 * password = 1234
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    const char *username;
    const char *password;
} Account;

char *read_string(char *buffer, size_t length);

int main(void)
{
    char username[64];
    char password[64];

    Account accounts[] = {
        {"paul", "1234"},
    };

    size_t i;

    printf("Enter your username: ");
    if (read_string(username, sizeof(username)) == NULL) {
        fprintf(stderr, "Failed to get username\n");
        return 1;
    }
    printf("Enter your password: ");
    if (read_string(password, sizeof(password)) == NULL) {
        fprintf(stderr, "Failed to get password\n");
        return 1;
    }
    printf("Authenticated:\n");
    printf("==> Username '%s'\n", username);
    printf("==> Password '%s'\n", password);

    for (i = 0; i < sizeof(accounts); ++i) {
        Account account = accounts[i];
        if (strcmp(username, account.username) == 0) {
            if (strcmp(password, account.password) == 0) {
                printf("Welcome, %s!\n", username);
                return 0;
            }
            printf("Incorrect password!\n");
            return 0;
        }
    }
    printf("That user does not exist!\n");

    return 0;
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
