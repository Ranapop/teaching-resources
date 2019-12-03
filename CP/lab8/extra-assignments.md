# Requirements

You will work on the extra assignment from https://github.com/Ranapop/teaching-resources/blob/master/CP/lab7/extra-assignments/sign-up.md.
For the previous extra assignment, you should have saved a list of (username, password) in memeory. 

Now, it's time to store that data into a file, so that accounts can be created across different executions of the program (that means you will have to append in the file, not rewrite).

But it's not a good idea to store the passwords in plain text. You will have to encrypt the passwords, using an algorithm of your choosing, but an algorithm that uses one key.

For encryption algorithms, you can look here: https://crypto.interactive-maths.com/. The algorithms here are exemplified on letters of the alphabet, but most should be easily extandable for your character set.

You should store on the first line the encryption/decreption key, then on the second line the number of users, then on each line the username with its password (think about how you could modify the number of users in the file without rewriting all the content after the number of users - maybe involving `fseek`).

# Grading (3p)

| Functionality                                                  | Points |
| -------------------------------------------------------------- | ------ |
| Store the no of users and the users in a file                  | 1 p    |
| Rewrite the no of users without rewriting all data afterwards  | 1 p    |
| Encrypt passwords on save, decrypt passwords on load           | 1 p    |

# Due data
14.01.2019
