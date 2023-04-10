#include <stdio.h>
#include <string.h>
#define STOP_CODE "##"

int main() {
    char input[100];
    int unique[256] = {0}; // initialize all elements to 0
    int i, len;

    while (1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        if (strcmp(input, STOP_CODE) == 0) {
            break;
        }

        len = strlen(input);
        for (i = 0; i < len; i++) {
            unique[(int)input[i]] = 1; // mark character as seen
        }

        printf("Unique characters: ");
        for (i = 0; i < 256; i++) {
            if (unique[i] == 1) {
                printf("%c ", (char)i);
                unique[i] = 0; // reset for next input
            }
        }
        printf("\n");
    }

    return 0;
}