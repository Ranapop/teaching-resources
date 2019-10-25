
```c
#include <stdio.h>

#define EXIT_KEY 'q'
#define TRUE 1

int main() {
    printf("Welcome to our car shop. Press 'q' to exit\n");
    int c = getchar();
    while(c!=EXIT_KEY){
        c = getchar();
        ungetc(c ,stdout);
    }

    return 0;
}
```
