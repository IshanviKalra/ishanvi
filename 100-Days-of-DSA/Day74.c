/* Problem:
Given votes (candidate names), find candidate with max votes.
If tie → print lexicographically smallest.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];

    for(int i = 0; i < n; i++)
        scanf("%s", names[i]);

    int count[n];
    for(int i = 0; i < n; i++) count[i] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0)
                count[i]++;
        }
    }

    int max = 0;
    char winner[50];

    for(int i = 0; i < n; i++) {
        if(count[i] > max || 
          (count[i] == max && strcmp(names[i], winner) < 0)) {
            max = count[i];
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);
    return 0;
}