# Compulsory assignment 

We will add a new functionality to the `food-ordering` application: 'Loading the data'.

For now, the data will be loaded from the console (you will have to change this either in the extra assignment or in the lab 8 assignment to load the data from a file).
The flow will be modified to first load the data. The message `Please load the data` will be displayed. An example:

```
Please load the data
>3:
>Pizza: (Pizza Carbonara - 21.00) (Pizza Diavola - 23.00) (Pizza Margherita - 19.00)
>Pasta: (Chicken alfredo - 23.00) (Mac&cheese - 21.00)
>Salad: (Tuna Salad - 23.00) (Chicken Salad - 22.00) (Greek Salad - 19.00) (Cobb - 21.00)
>4:
>(Coca-cola - 5), (Fanta -5), (Lipton - 5), (Water - 4)
Welcome to Food Thingies!
```
The user will have to input:
* on the first line the number of food types (noOfFoodTypes)
* on the next noOfFoodTypes lines the user inputs the food type, ":" and the speciffic foods with prices for that food type
* the number of drinks (noOfDrinks)
* on the last line, the drinks with their prices

!!! Please note that the user doesn't have to go back from signing in to this step.

For parsing the input, please read one line at the time and use appropiate strings functions to extract the relavant information. Also, please notice patterns in the input and where functions can be extracted.

Please define the "Please load the data" as a constant:

| Message key  | Value                   |
| ------------ | ----------------------- |
| LOAD_DATA    | "Please load the data"  |

| Functionality                | Points |
| ---------------------------- | ------ |
| Parse food data              | 2.5 p  |
| Allocate memory food data    | 2 p    |
| Free memory food data        | 1 p    |
| Parse drinks data            | 2 p    |
| Allocate memory drinks data  | 1.5 p  |
| Free memory drinks data      | 0.5 p  |
| Define message               | 0.5 p  |

You may be panalized for:
* bugs 
* long functions, duplicate code, magic numbers, badly named variables

