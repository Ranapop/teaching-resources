### Problem statement
N-1 numbers from the interval [1,n] are read from the console. Find the missing number. First n is read, then the n-1 numbers.

### Example
```
Input:
5
1 5 2 4
Output
3
```

### Idea
Bitwise operators can be used to solve this problem efficiently. The xor operator has the property of resulting 0 when applied to two equal numbers. For example, 7 xor 7 = 0.

That means that if we apply xor to the numbers in the input, and to the numbers in interval [1,n], and make the xor between those, the equal numbers cancel eachother out, and the missing number remains.

### Solution
```c
#include <stdio.h>

int main() {

    // read n
    int n;
    printf("Input n\n");
    scanf("%d",&n);
    // read a string of n-1 numbers & calculate their xor
    printf("Input n-1 numbers in the interval [1,n]\n");
    int xorInput = 0;
    for(int i=0; i<n-1; i++) {
        int nr;
        scanf("%d", &nr);
        xorInput = xorInput ^ nr;
    }

    // calculate xorN - xor of the numbers from 1 to n
    int xorN = 0;
    for(int i=1;i<=n;i++) {
        xorN = xorN ^ i;
    }

    // find missing number by xor
    int missingNumber = xorInput ^ xorN;

    // print missing number
    printf("Missing number is %d\n", missingNumber);

    return 0;
}
```
