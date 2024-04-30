# Minishell

Minishell is a compact and educational shell program designed to provide a practical understanding of shell programming fundamentals. 
It emulates basic functionalities of a typical shell, allowing users to execute commands, navigate the directory structure, 
and manage simple input/output operations.

## Features

- **Command Execution:** Minishell facilitates the execution of various built-in commands and external programs.
- **Directory Navigation:** Users can seamlessly navigate the file system using commands like cd (change directory) and pwd (print working directory).
- **Input/Output Redirection:** The shell supports input and output redirection through the > and >> operators, enabling control over how commands
- interact with files.
- **Environment Variables:** Minishell provides the ability to set and manipulate environment variables, enhancing customization and configuration.
- **Error Handling:** The shell incorporates basic error handling mechanisms to gracefully manage issues such as invalid commands or nonexistent files.
  
## Running the Project
- clone repository
  ```
  git clone https://github.com/Alaire1/MiniShell_42.git
  ```
- compile program
  ```
  make
  ```
- now you can run
  ```
  ./minishell
  ```
  ## Built-in Commands:

- **cd (change directory):** Navigates to a specified directory.
- **pwd (print working directory):** Displays the current working directory path.
- **echo:** Prints arguments to the console.
- **exit:** Terminates the minishell session.
- **export:** Sets or modifies environment variables.
- **unset:** Unsets an environment variable.
- **env:** Prints enviromental variables.

Our minishell goes beyond basic built-in commands and offers a range of features to create a more powerful and user-friendly experience:

### Advanced Parsing:
It avoids interpreting unnecessary characters like backslashes (\) and semicolons (;) that aren't crucial for understanding commands.
### Quoting:
It handles both single (') and double (") quotes effectively. Single quotes prevent any interpretation within the quoted sequence, while double quotes allow variable expansion ($) but not other shell metacharacters.
### Redirectional Magic
- **<:** Redirects input from a specified file.
- **>:** Redirects output to a designated file, overwriting existing content.
- **<<:** Enables here-strings, where input is read until a specific delimiter line is encountered (history update is not implemented).
- **>>:** Redirects output in append mode, adding to the existing content in a file.
### Pipe Power
It supports pipes (|), allowing the output of one command to be directly fed as input to the next, enabling powerful command combinations.
### Variable Savvy
It understands environment variables, expanding $ followed by a sequence of characters to their corresponding values.
Exit Status Awareness: It recognizes $? as a special token, expanding it to the exit status of the most recent foreground command executed.
## Signal Handling in Interactive Mode:
Ctrl-C: Displays a new prompt on a new line, essentially continuing execution after interruption.
Ctrl-D: Exits the shell gracefully.
Ctrl-\: Currently has no effect in our minishell.


