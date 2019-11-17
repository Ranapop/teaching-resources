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

# Extra assignment 1: Save data to file (1p bonus)
# Extra assignmet 2: Load data from file (1p bonus)

# Extra assignment 3: Sign up (3p bonus)

You will add signing up functionality to the `food-ordering` application. First, the user will have to choose between siging in or signing up.

The required functionality can be visualized in the diagram below:

//TODO: put image here

If the user chooses to sign in, he will have to provide an existing username and associated password. If he:
* provides an existing username with the correct password, he will get to the food types choosing
* provides an invalid username (that doesn't exist), regardless the password, he will be promted with the message: "Username doesn't exist", then be redirected again to the step in which he is asked to sign up or sign in
* provides an existing username but with the incorrect password, he will pe promted with the message: "Incorrect password" and be asked again to provide the username and password

If the user chooses to sign up, he will have to provide a new (non-existing) username and password. If he:
* provides a non-existing username and valid password, he will get to the food types choosing
* provides an existing username, he will be prompted with the message "Please choose another username!" and repeat the step
* provides a non-existing username, but an invalid password, he will be prompted with an explanatory message and repeat the step


```
Welcome to Food Thingies!
Do you have an existing account?
>y
Please sign in to continue!
---Username
>ranap
---Password
>bad_pass123
Please choose the food you feel like eating today:
```

