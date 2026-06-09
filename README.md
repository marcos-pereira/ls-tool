# ls-tool
This repository will contain [tony's implementation](https://www.youtube.com/watch?v=GqEeOrDk5DI) of the `ls` linux command in C. Just for fun!

# Compilation
To compile the code, simply run the following command in the terminal:
```bash
gcc -Wall -Wextra -o ls_tool ls.c
```

# Usage
To run the compiled program, use the following command:
```bash
./ls_tool [path]
```
If no path is provided, it will default to the current directory.