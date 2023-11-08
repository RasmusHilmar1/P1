#include "patient information.h"

void print_patient(const char *cpr_to_find) {
    // This code attempts to open the file "users.json" for reading.
    // If it fails to open the file (e.g., due to a file not found), it prints an error message and returns from the function.
    FILE *fp = fopen("users.json", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    // This code reads the contents of the opened file into a character buffer named buffer.
    char buffer[1024];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    // This part of the code extracts the "Users" array from the parsed JSON data.
    // If "Users" is an array, it proceeds to iterate through its elements using a for loop.
    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Error: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return;
    }

    // Find the JSON object with the specified "CPR"
    cJSON *users = cJSON_GetObjectItemCaseSensitive(json, "Users");
    if (cJSON_IsArray(users)) {
        for (int i = 0; i < cJSON_GetArraySize(users); i++) {
            cJSON *patient = cJSON_GetArrayItem(users, i);
            cJSON *cpr = cJSON_GetObjectItemCaseSensitive(patient, "CPR");

            if (cJSON_IsNumber(cpr) && (cpr->valueint == atoi(cpr_to_find))) {
                cJSON *name = cJSON_GetObjectItemCaseSensitive(patient, "Name");
                cJSON *age = cJSON_GetObjectItemCaseSensitive(patient, "Age");
                cJSON *gender = cJSON_GetObjectItemCaseSensitive(patient, "Gender");
                cJSON *diagnosis1 = cJSON_GetObjectItemCaseSensitive(patient, "Diagnosis1");
                cJSON *medicine1 = cJSON_GetObjectItemCaseSensitive(patient, "Medicine1");
                cJSON *diagnosis2 = cJSON_GetObjectItemCaseSensitive(patient, "Diagnosis2");
                cJSON *medicine2 = cJSON_GetObjectItemCaseSensitive(patient, "Medicine2");

                if (cJSON_IsString(name) && (name->valuestring != NULL)) {
                    printf("Name: %s\n", name->valuestring);
                }

                if (cJSON_IsNumber(age)) {
                    printf("Age: %d\n", age->valueint);
                }

                if (cJSON_IsString(gender) && (gender->valuestring != NULL)) {
                    printf("Gender: %s\n", gender->valuestring);
                }

                if (cJSON_IsString(diagnosis1) && (diagnosis1->valuestring != NULL)) {
                    printf("Diagnosis1: %s\n", diagnosis1->valuestring);
                }

                if (cJSON_IsString(medicine1) && (medicine1->valuestring != NULL)) {
                    printf("Medicine1: %s\n", medicine1->valuestring);
                }

                if (cJSON_IsString(diagnosis2) && (diagnosis2->valuestring != NULL)) {
                    printf("Diagnosis2: %s\n", diagnosis2->valuestring);
                }

                if (cJSON_IsString(medicine2) && (medicine2->valuestring != NULL)) {
                    printf("Medicine2: %s\n", medicine2->valuestring);
                }

                break;  // Exit the loop once the desired "CPR" is found
            }
        }
    } else {
        printf("Error: 'Users' is not an array in the JSON.\n");
    }

    // Delete the JSON object
    cJSON_Delete(json);
}