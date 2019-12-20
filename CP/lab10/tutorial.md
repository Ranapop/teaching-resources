
## Factorial

```c
int fact(int n) {
  if(n==0) {
    return 1;
  }
  return n * fact(n-1);
}
```

## Fibbonaci 

```c
int fib(int n) {
  if(n==0 || n==1) {
     return 1;
  }
  return fib(n-1) + fib(n-2);
}
```

## Tower of Hanoi

We have 3 rods and on the first of them there are _n_ disks, put in increasing size.

### Objective

Move _n_ disks to the third rod.

### Rules

* Move only one disk at a time
* A disk can only be moved if it's at the top
* No disk can be placed on a smaller disk

### Idea

* if we consider we can move the top n-1 disks to the middle rod, then we simply take the remaining disk and move it to the final rod
* then, we move the n-1 disks from the middle to the first rod, and we have the same problem for a smaller size (n-1)
* when our problem is of size 0, we are done

### Implementation

```c
void moveDisk(int src, int target, int disk) {
    printf("Move disk %d from tower %d to tower %d\n",disk, src, target);
}

void move(int src, int target, int aux, int n) {
    if(n==0) {
        return;
    }
    move(src, aux, target, n-1);
    moveDisk(src, target, n);
    move(aux, src, target, n-1);
}

void hanoiExample(int n) {
    move(0,2,1, n);
}
```

## N Queen problem

### Objective 

Place N queens on the chessboard so that no two queens attack eachother.

### Idea

Try to place a queen on each column:
* go from top to bottom trying to find a row:
  * if there is no attack with the already placed queens, place queen on the current square and also place following queens
  * if there is no placement for the following queens, move down to the next square 
  * if there is a placement, return true
  * if after traversing the rows top down, there is no valid placement, we return false

### Implementation

```c
int isAttack(int ** board, int n, int row, int col) {
    int i, j;
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 1;
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 1;
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 1;
    return 0;
}

int placeQueens(int ** board, int n, int col) {
    if(col==n) {
        return 1;
    }
    // try all rows
    for(int i=0;i<n;i++) {
        if(!isAttack(board, n, i, col)) {
            board[i][col] = 1;
            int canPlaceRest = placeQueens(board, n, col+1);
            if(canPlaceRest) {
                return 1;
            } else {
                // clean up this queen
                board[i][col] = 0;
            }
        }
    }
    return 0;
}

void printBoard(int ** board, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0; j<n;j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int ** initializeBoard(int n) {
    int ** board = (int**)malloc(n* sizeof(int*));
    for(int i=0;i<n;i++) {
        board[i] = (int*)malloc(n* sizeof(int));
        for(int j=0;j<n;j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

void queenExample(int n) {
    int ** board = initializeBoard(n);
    placeQueens(board, n, 0);
    printBoard(board, n);
}
```
