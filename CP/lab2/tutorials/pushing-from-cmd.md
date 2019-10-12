### Create a .gitignore file in your repo folder with the following content
```
/cmake-build-debug/
.idea
```

### Use `git add` to select which files you want to be in the commit (the .gitignore file, the cmake and source files)
```
git add .gitignore CMakeLists.txt main.c 
```

### Use `git commit` to create the commit. If you use `-m` you can give the commit message:
```
git commit -m "push from cmd"
```

### Use `git push` to push your changes:
```
git push origin master
```
