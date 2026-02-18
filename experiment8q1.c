#include <stdio.h>

// Hash Function: digital root of last 3 digits
int hashFunction(int sapID) {
    int last3 = sapID % 1000;
    int sum = 0;

    // Step 1: sum of digits
    while (last3 > 0) {
        sum += last3 % 10;
        last3 /= 10;
    }

    // Step 2: convert to single digit (digital root)
    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }

    return sum;  // final family (0–9)
}

int main() {
    int sapID, family;

    printf("Enter SAP-ID: ");
    scanf("%d", &sapID);

    family = hashFunction(sapID);

    printf("Student belongs to family: %d\n", family);

    return 0;
}