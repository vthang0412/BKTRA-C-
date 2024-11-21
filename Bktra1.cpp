#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuan_hoa_xau(char *ho_ten) {
    int i, len = strlen(ho_ten);
    int j = 0;

    char *start = ho_ten;
    while (*start == ' ') start++;

    len = strlen(start);
    while (len > 0 && start[len - 1] == ' ') {
        len--;
    }
    start[len] = '\0';

    for (i = 0; start[i] != '\0'; i++) {
        if (i == 0 || (!isalnum(start[i - 1]) && start[i - 1] != '\'')) {
            ho_ten[j++] = toupper(start[i]);
        } else if (start[i] == ' ' && start[i + 1] == ' ') {
            continue;
        } else {
            ho_ten[j++] = tolower(start[i]);
        }
    }

    ho_ten[j] = '\0';
    printf("%s\n", ho_ten);
}

int main() {
    int n;
    char ho_ten[81];

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(ho_ten, sizeof(ho_ten), stdin);
        ho_ten[strcspn(ho_ten, "\n")] = '\0';
        chuan_hoa_xau(ho_ten);
    }

    return 0;
}
