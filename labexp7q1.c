#include <stdio.h>
int main() {
    int sap, last3, family;

    printf("Enter SAP ID: ");
    scanf("%d", &sap);

    last3 = sap % 1000;      // last 3 digits
    family = last3 % 10;     // family number

    printf("Last 3 digits = %d\n", last3);
    printf("Family = %d\n", family);

    return 0;
}