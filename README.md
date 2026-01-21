*This project has been created as part of the 42 amman curriculum by bshbool.*

# Pipex

## Description

Pipex is a project from the 42 curriculum that reproduces the behavior of the Unix pipe (`|`) using low-level system calls.

The goal of the project is to learn how to manage processes, file descriptors, pipes, and command execution in Unix. The program executes commands in separate processes, redirects input from a file, pipes the output between commands, and writes the result to an output file.

With the bonus, Pipex can handle multiple commands and here_doc input, allowing behaviors like:

< infile cmd1 | cmd2 | ... | cmdn > outfile
cmd1 << LIMITER | cmd2 >> outfile

---

## Instructions

### Compilation

Compile the program using the provided Makefile:

make       # build executable
make clean # remove object files
make fclean# remove executable and objects
make re    # clean and rebuild

### Execution

Mandatory usage:

./pipex infile "cmd1" "cmd2" outfile

Bonus usage (multiple pipes / here_doc):

./pipex infile "cmd1" "cmd2" "cmd3" ... "cmdn" outfile
./pipex here_doc LIMITER cmd1 cmd2 outfile

---

## Resources

- Linux man pages: [pipe](https://man7.org/linux/man-pages/man2/pipe.2.html), [fork](https://man7.org/linux/man-pages/man2/fork.2.html), [dup2](https://man7.org/linux/man-pages/man2/dup2.2.html), [execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [42 Gitbook Guide](https://42-cursus.gitbook.io/guide/2-rank-02/pipex)
- [Article from Medium](https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103)
- [yt video about pipes](https://www.youtube.com/watch?v=NlFvGZoAgTs)

### AI Usage

AI tools were used to clarify project requirements, understand system calls, and structure this README.
All code, debugging, and implementation were done manually by me.