# Desired flow

The user can:
* sign in
* choose food type
* choose speciffic food (depends on food type)
* chose drink
* chose with/without cuttlery 
* add a comment (ENTER for no comment)
* go back at any point

This is an example of a flow (user input with `>`): 
```
Welcome to Food Thingies!
Please sign in to continue!
---Username
>ranap
---Password
>bad_password
Please choose the food you feel like eating today:
a) Pizza
b) Pasta
c) Salad
d) Go back
>a
Please choose the type of Pizza:
a) Pizza Carbonara: 21
b) Pizza Diavola: 23
c) Pizza Margherita: 19
d) Go back
>b
Please choose a drink to go with your Pizza:
a) Coca-cola: 5
b) Fanta: 5
c) Lipton: 5
d) Water: 4
e) No, tanks!
f) Go back
>b
Do you want cutlery?
a) Yes
b) No, thanks!
c) Go back
>b
Any additional info?
>Don't burn it pls :o3
This is your order:
-------------------
Name: ranap
Food items:
---Pizza Diavola: 23
---Fanta: 5
Cutlery: no
Additional info: Don't burn it pls :o3
Payment amount: 28
-------------------
a) Confirm order
b) Go back
>a
Order confirmed! Thank you for buying from us, ranap!
```
# Data
| Food type | 
| --------- |
| Pizza     | 
| Pasta     | 
| Salad     | 

| Pizza                 | Pasta                 | Salad                 |
| --------------------- | --------------------- | --------------------- |
| Pizza Carbonara  (21) | Chicken alfredo  (23) | Tuna Salad       (23) |
| Pizza Diavola    (23) | Mac&cheese       (21) | Chicken Salad    (22) |
| Pizza Margherita (19) |                       | Greek Salad      (19) |
|                       |                       | Cobb             (21) |

| Drink         | 
| ------------- |
| Coca-cola (5) | 
| Fanta     (5) |
| Lipton    (5) |
| Water     (4) |

# Grading

| Functionality            | Points |
| ------------------------ | ------ |
| Signing in               | 1 p    |
| Selecting food type      | 1 p    |
| Selecting speciffic food | 2 p    |
| Selecting drink          | 1 p    |
| Choosing cutlery         | 1 p    |
| Adding additional info   | 1 p    |
| Printing order           | 1 p    |
| Going back               | 2 p    |
