# Pipex - 42 Project

Pipex is a project that aims to reproduce the behavior of the shell pipe `|` in C. It handles executing multiple commands where the output of one command is redirected as the input of the next.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Bonus](#bonus)
- [Implementation Details](#implementation-details)

## Features
- **Mandatory:** Replicates `< infile cmd1 | cmd2 > outfile`.
- **Bonus:**
  - Handles **multiple pipes**: `< infile cmd1 | cmd2 | ... | cmdn > outfile`.
  - Handles **here_doc**: `<< LIMITER cmd | cmd1 >> outfile`.
- Custom path resolution from the `PATH` environment variable.
- Handles quotes in commands (e.g., `grep "hello world"`).
- Robust error handling (command not found, permission denied, file access, etc.).

## Installation

The project uses a `Makefile` to compile the source files.

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/pipex.git
   cd pipex
   ```
2. Compile the mandatory part:
   ```bash
   make
   ```
3. Compile the bonus part:
   ```bash
   make bonus
   ```

## Usage

### Mandatory Part
The program takes 4 arguments:
```bash
./pipex file1 cmd1 cmd2 file2
```
It behaves exactly like the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

**Example:**
```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile
```

### Bonus Part
The bonus program handles multiple pipes:
```bash
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
```
It behaves like:
```bash
< file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```

**Example:**
```bash
./pipex_bonus infile "cat" "grep hello" "wc -l" outfile
# Equivalent to: < infile cat | grep hello | wc -l > outfile
```

#### Here Doc
The bonus also supports `here_doc` when the first argument is `here_doc`:
```bash
./pipex_bonus here_doc LIMITER cmd cmd1 file
```
It behaves like:
```bash
cmd << LIMITER | cmd1 >> file
```

**Example:**
```bash
./pipex_bonus here_doc END "cat" "grep hello" outfile
# It will read from stdin until "END" is typed, then pipe to grep and append to outfile.
```

## Implementation Details

### Process Management
- Uses `pipe()` to create communication channels between processes.
- Uses `fork()` to create child processes for each command.
- Uses `dup2()` to redirect standard input and output.
- Uses `execve()` to execute commands.
- Parent process waits for all children to finish using `waitpid()`.

### Path Resolution
The program extracts the `PATH` from the environment variables (`envp`) and searches for the executable in each directory. It also handles absolute and relative paths.

### Memory & File Descriptors
- All allocated memory is properly freed upon exit or error.
- All file descriptors are closed to prevent leaks and ensure processes don't hang waiting for input.
- Uses a custom `ft_split_quotes` to correctly parse command arguments containing spaces within quotes.

---
*This project was developed by afaugero as part of the 42 school curriculum.*
