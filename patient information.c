#include "patient information.h"

//Skriv indholdet af din funktion her.
int print_patient() {
    FILE *fileptr;
    char *buffer;
    long filelen;

    // Open file, print error if fail
    fileptr = fopen("/Users/lassemacbookair/CLionProjects/P1/users.json", "rb");
    if (fileptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);

    // allocate memory for file
    buffer = (char *)malloc((filelen + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating memory for file content");
        fclose(fileptr);
        return -1;
    }
    fread(buffer, filelen, 1, fileptr);
    fclose(fileptr);

    buffer[filelen] = '\0';

    // parse the file
    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        free(buffer);
        return -1;
    }

    // access the JSON data
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "Name");
    if (cJSON_IsString(name) && (name->valuestring != NULL)) {
        printf("Name: %s\n", name->valuestring);
    }



    /*
    // find data from file
    int found = 0;
    cJSON *users = cJSON_GetObjectItemCaseSensitive(json, "users");
    cJSON *user;
    */

    // clear file & clear memory
    cJSON_Delete(json);
    free(buffer);

    return 0;
}