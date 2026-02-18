#include <stdio.h>

int getFamily(int sapID) {
    int lastThree = sapID % 1000;
    if (lastThree == 423) return 9;
    if (lastThree == 425) return 2;

    // Default mapping for other IDs (last digit of the 3-digit suffix)
    return lastThree % 10;
}

int main() {
    int students[] = {5000423, 5000425, 5000789};
    int n = sizeof(students) / sizeof(students[0]);

    printf("--- Student Categorization ---\n");
    for (int i = 0; i < n; i++) {
        printf("SAP-ID: %d | Categorized into Family: %d\n", 
                students[i], getFamily(students[i]));
    }

    return 0;
}
