#include "dosagecalc.h"
#include<stdlib.h>
#include<stdio.h>

double dosage(){
    double patientWeight;
    double dosagePerKg;
    double maxDosage;
    double dosage;
    int unitChoice;
    printf("Enter the patient's weight in kilograms\n>");
    scanf("%lf", &patientWeight);
    printf("Input medicine dosage per kg\n>");
    scanf("%lf", &dosagePerKg);
    printf("Choose the unit (1 for g, 2 for mg, 3 for mcg)\n>");
    scanf("%d", &unitChoice);
    printf("Enter the maximum allowable dosage\n>");
    scanf("%lf", &maxDosage);

    if (unitChoice == 1) { // g
        dosage = patientWeight * dosagePerKg;
        printf("The calculated dosage is: %.2lf g.\n", dosage);
    } else if (unitChoice == 2) { // mg
        dosage = (patientWeight * dosagePerKg) * 1000;
        printf("The calculated dosage is: %.2lf mg.\n", dosage);
    } else if (unitChoice == 3) { // mcg
        dosage = (patientWeight * dosagePerKg) * 1000000;
        printf("The calculated dosage is: %.2lf mcg.\n", dosage);
    }

    if (dosage > maxDosage) {
        return maxDosage;
    } else {
        return dosage;
    }

    return dosage;
}