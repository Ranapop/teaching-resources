
In our `car-shop` project right now we rely on the convention that each state has a number, and make a `switch` statement to choose the actions for the current state.

We can make our code a lot more readable by creating an enum to hold those numeric values:

```c
enum State {INPUT_BUYER_DATA, CHOOSE_BRAND, CHOOSE_MODEL, CHOOSE_ADDITIONAL_ITEM, SIGN_CONTRACT};
```
The `switch` thus becomes:
```c
switch (state) {
  case INPUT_BUYER_DATA: {
      ...
  }
  case CHOOSE_BRAND: {
      ...
  }
  case CHOOSE_MODEL: {
      ...
  }
  case CHOOSE_ADDITIONAL_ITEM: {
      ...
  }
  case SIGN_CONTRACT: {
      ...
  }
```
