
# Submission

Please create a repository called `food-data-provider`, add `Ranapop` as a collaborator and work on a dev branch. You can create a pull request (reviewer:`Ranapop`) after implementing a few functionalities, or after implementing everthing, but please create your final pull request by Saturday, 8am.

# Desired flow

The user can:
* enter food types
* enter speciffic foods (with their prices)
* enter drinks

This is an example of a flow (user input with `>`):
```
Please input number of food types
>3
Please food types (each on a new line, may contain spaces)
>Pizza
>Pasta
>Salad

Please input no of speciffic foods for food "Pizza"
>3
Please input "Pizza" speciffic foods &prices: each line in the format <speciffic food> (price):
>Pizza Carbonara (21)
>Pizza Diavola (23)
>Pizza Margherita (19)

Please input no of speciffic foods for food "Pasta"
>2
Please input "Pasta" speciffic foods &prices: each line in the format <speciffic food> (price):
>Chicken alfredo (23)
>Mac&cheese (21)

Please input no of speciffic foods for food "Salad"
>2
Please input "Salad" speciffic foods &prices: each line in the format <speciffic food> (price):
>Tuna Salad (23)
>Chicken Salad (22)
>Greek Salad (19)
>Cobb (21)

Please input no of drinks
>4
Please input the drinks: each line in the format <drink> (price):
>Coca-cola (5)
>Fanta (5)
>Lipton (5)
>Water (4)

The food data is:
Pizza: (Pizza Carbonara - 21.00) (Pizza Diavola - 23.00) (Pizza Margherita - 19.00)
Pasta: (Chicken alfredo - 23.00) (Mac&cheese - 21.00)
Salad: (Tuna Salad - 23.00) (Chicken Salad - 22.00) (Greek Salad - 19.00) (Cobb - 21.00)
The drinks data is:
drinks: Coca-cola, Fanta, Lipton, Water
prices: 5, 5, 5, 4
```

# Grading

The flow given as an example should be 100% reflected in the execution of the program on the same data:
* same messages for input
* same input formatting
* same output formatting
You may be penalized for moving away from the requirements.

Functionalities:

| Functionality                          | Points |
| -------------------------------------- | ------ |
| Creating food-data-provider repo       | 1 p    |
| Add Ranapop as collaborator&reviewer   | 1 p    |
| Read and store foods no & food types   | 1 p    |
| Read and store speciffic foods nos     | 0.5 p  |
| Read and store speciffic foods         | 1 p    |
| Read and store speciffic foods prices  | 1 p    |
| Read and store drinks                  | 1 p    |
| Display data                           | 1 p    |
| Free speciffic foood memory            | 1.5 p  |
| Free drinks memory                     | 1 p    |

Code requirements:
* no static allocation
* foods stored in an array of strings (char**)
* speciffic foods stored in an array of array of strings (char***)
* speciffic foods prices stored in an array of array of doubles (double**)
* drinks stored in array of strings (char**)
* drinks prices stored in array of doubles (double*)
* all allocated memory should be deallocated

You may be penalized for not respecting the code requirements.




