#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 1024
#define STR 128

#define FILENAME "data.csv"

int read_with_format() {
    int result, line = 0, id, age;
    char header_id[STR], header_age[STR], firstName[STR], lastName[STR], email[STR], type[STR];

    FILE* f = fopen(FILENAME, "r");
    if (f == NULL) {
        return 0;
    }

    while (!feof(f)) {
        if (line++ == 0) {
            // read header
            result = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", header_id, firstName, lastName, email, header_age, type);
            printf("%s %s %s %s %s %s\n", header_id, firstName, lastName, email, header_age, type);
        } else {
            // read data
            result = fscanf(f, "%d,%[^,],%[^,],%[^,],%d,%[^\n]", &id, firstName, lastName, email, &age, type);
            printf("%d %s %s %s %d %s\n", id, firstName, lastName, email, age, type);
        }

        if (result != 6) {
            // missing data
            return 0;
        }
    }

    fclose(f);

    return 1;
}

int read_with_token() {
    int line = 0, id, age;
    char *token, row[STR], firstName[STR], lastName[STR], email[STR], type[STR];

    FILE* f = fopen(FILENAME, "r");
    if (f == NULL) {
        return 0;
    }

    while (fgets(row, LINE, f)) {
        if (line++) {
            strtok(row, "\n");
            token = strtok(row, ",");

            id = atoi(token);
            token = strtok(NULL, ",");

            strcpy(firstName, token);
            token = strtok(NULL, ",");

            strcpy(lastName, token);
            token = strtok(NULL, ",");

            strcpy(email, token);
            token = strtok(NULL, ",");

            age = atoi(token);
            token = strtok(NULL, ",");

            strcpy(type, token);
            token = strtok(NULL, ",");

            printf("%d, %s, %s, %s, %d, %s\n", id, firstName, lastName, email, age, type);
        }
    }

    fclose(f);

    return 1;
}

int main() {

    read_with_format() ? puts("\nsuccess") : printf("\nError");

    read_with_token() ? puts("\nsuccess") : printf("\nError");

    return (EXIT_SUCCESS);
}

