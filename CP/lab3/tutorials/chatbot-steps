
We want the following dialog between the computer and the user:
```
C: Let's chat
U: Hello there
```
For that we first need to print what the computer says. For that we can use ```printf``` with ```\n``` for new line:
```c
printf("Let's chat\n");
```
Now, we have to read what the computer says. For that, we can use gets, but this is [unsafe](https://blogcwi.wordpress.com/2015/04/27/gets-docx/) to use. We will use it for now:
```c
char userInput[100];
gets(userInput);
```
Now we want to get the name of the user. Sometething like:
```
C: Hello there to you too! I am HAL, what is your first name? (one word, please)
U: Marc
```
And we would also like to get back to the user using his/her name, to make the chatbot look more intelligent. Something like:
```
C: Oh hi, Marc. 
```
We would write something like this
```c
char name[20];
scanf("%s",name);
printf("Oh hi, %s.\n",name);
```
The computer could also ask for the user's age, and use that in the next line:
```
C: Oh hi, Marc. How old are you?
U: 20
C: Wow, 20 is quite something
```
We could modify the code as follows:
```c
char name[20];
scanf("%s",name);
printf("Oh hi, %s. How old are you?\n",name);
int age;
scanf("%d", &age);
printf("Wow. %d is quite something\n",age);
```

Let's say we want to wrap it up. We could end it with something like
```
U: I like bananas.
C: I'm sorry, not sure what this "I like bananas." means. Gotta go. Bby
```

We could try something like this:
```c
gets(userInput);
printf("I'm sorry, not sure what this \"%s\" means. Gotta go. Bby",userInput);
```
Unfortunately this doesn't work, as there seems to still be some characters in the stin which are read by ```gets``` instead of reading another line from the user. This is most likely due to our use of scanf above. We can quickly hack it by using this [solution](https://stackoverflow.com/questions/22226529/program-doesnt-execute-gets-after-scanf-even-using-fflushstdin):
```c
int c;
while((c= getchar()) != '\n' && c != EOF);
gets(userInput);
printf("I'm sorry, not sure what this \"%s\" means. Gotta go. Bby",userInput);
```

