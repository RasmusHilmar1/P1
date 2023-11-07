#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "Enter CPR .h"

int EnterCPR() {
    FILE *fileptr;

    //input and scan for CPR-number
    printf("Please enter patients CPR-number:\n>");
    scanf("" CPRnr);

    //open json file
    fileptr = fopen(//json document location,---);

}