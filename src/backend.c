#include "login_internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#define USERS_SIZE 2

#define unused(x) (void)(x)

static const LgUserData users[USERS_SIZE] = {
    {"paul", "1234"},
    {"greg", "5678"},
};

static int callback(void *ptr, int argc, char **argv, char **colname);
static int get_user_data_array_internal(const char *username, const char *password, LgUserData *user);
static int get_user_data_sql_internal(const char *username, const char *password, LgUserData *user);

static int callback(void *ptr, int argc, char **argv, char **colname)
{
    int i;

    unused(ptr);
    for (i = 0; i < argc; ++i)
        printf("%s = %s\n", colname[i], argv[i] ? argv[i] : "NULL");
    printf("\n");
    return 0;
}

static int get_user_data_array_internal(
    const char *username, const char *password, LgUserData *user)
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

static int get_user_data_sqlite_internal(
    const char *username, const char *password, LgUserData *user)
{
    sqlite3 *db;
    char *log;

    /* TODO: Remove unused */
    unused(username);
    unused(password);
    unused(user);
    if (sqlite3_open("users.db", &db)) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    /* TODO: Add callback later */
    if (sqlite3_exec(db, "SELECT * FROM users", callback, NULL, &log) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", log);
        sqlite3_close(db);
        sqlite3_free(log);
        exit(1);
    }
    sqlite3_close(db);
    return 0;
}

int backend_get_user_data(
    const char *username, const char *password, LgUserData *user)
{
#ifdef LOGIN_USE_SQL
    return get_user_data_sqlite_internal(username, password, user);
#else
    return get_user_data_array_internal(username, password, user);
#endif
}
