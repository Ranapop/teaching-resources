# Fork

## Download
Go here to install it:
https://git-fork.com/?fbclid=IwAR3Yy9PVuL_rdPtUoJjZRmS7U4f2IAsyD3dEtcLKdQeYHcd3S5mvuJGZP24

## Open car-shop repository in __Fork__

You should have your car-shop repository cloned locally. Once you have that, you can open the local repo (folder) from the __Fork__ git client by clicking "File > Open Repository" and selecting the car-shop folder.

![open_repository](images/gitclient/1_open_repository.png)
![open_repository_car_shop](images/gitclient/2_open_car_shop_repo.png)

## Create a C project in the car-shop folder (local repo)
We will do the development from __CLion__. If the car-shop repo is empty, create a C project in __CLion__ in your local repository. If you already created a C project in the repository, you may skip this step.
![3_create_c_project_in_car_shop_repo.png](images/gitclient/3_create_c_project_in_car_shop_repo.png)

## Visualize commits in __Fork__

Now we will play around with __CLion___ and __Fork__. You have already created commits and pushed them from __CLion__. We can do that from __Fork__ as well, or we can use both tools. If we create commits from __CLion__ we should see them in Fork as well.

## Create a hello world commit
If you commit your changes after creating the C project from __CLion__  under the message `created hello world project`:
![4_commit_clion.png](images/gitclient/4_commit_clion.png)

You can see the `created hello world project` commit in __Fork__. What's more, you can see what you have on your local repo (`master`) and what you have on your remote repo (`origin master`).
![5_fork_client_after_commit.png](images/gitclient/5_fork_client_after_commit.png)
## Create a second commit
Now change the hello world message
```c
printf("Hello, world!\n");
```
to the following message:
```c
printf("Welcome to our car shop. Press 'ESC' to exit\n");
```
Create a commit named `add welcome message` from __CLion__
![6_modify_print_commit.png](images/gitclient/6_modify_print_commit.png)

From Fork you should now see the second commit (`add welcome message`) stacked on top of the previous commit (`created hello world project`)
![6_fork_client_2_commits.png](images/gitclient/6_fork_client_2_commits.png)

## Push from __CLion__ and visualize in __Fork__

If you push your changes from __CLion__ that means your commits in the local repo will reach the remote repo.
![7_push_commits_clion.png](images/gitclient/7_push_commits_clion.png)
That is, the `master` branch and the `origin master` branch will be at the same commit, which can be visualized in __Fork__
![8_fork_after_push.png](images/gitclient/8_fork_after_push.png)


