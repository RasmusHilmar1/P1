#include <stdio.h>
#include "cJSON.h"
#include "login.h"
#include "dosagecalc.h"
#include "patient information.h"

int main() {

    login(); // LOGIN FUNCTION
    dosage(); // DOSAGE CALCULATOR
    const char *cpr_to_find = "308031234";  // Replace with the desired CPR value
    print_patient(cpr_to_find);

    /* // open the file
    FILE *fp = fopen("users.json", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    // read the file contents into a string
    char buffer[1024];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    // parse the JSON data
    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Error: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return 1;
    }

    // access the JSON data
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "Name");
    if (cJSON_IsString(name) && (name->valuestring != NULL)) {
        printf("Name: %s\n", name->valuestring);
    }

    // delete the JSON object
    cJSON_Delete(json); */

    return 0;
}
