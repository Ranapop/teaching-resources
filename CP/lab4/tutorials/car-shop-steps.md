
```c
#include <stdio.h>

#define EXIT_KEY 'q'
#define TRUE 1

int main() {
    printf("Welcome to our car shop. Press 'ESC' to exit\n");
    int c;

    do {
        c = getchar();
        ungetc(c ,stdout);
    } while(c!=EXIT_KEY);

    return 0;
}
```
