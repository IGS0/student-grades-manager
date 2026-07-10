# Student Grades Manager

A console application written in C for processing student and grade records stored in text files.

## Features

* Reads student information and grade records from separate text files.
* Filters students by subject.
* Displays matching results in the terminal.
* Saves filtered results to an output file.
* Lists available subjects and the number of records for each.
* Supports command-line arguments for custom input and output files.
* Includes basic input validation and file error handling.

## Project Structure

```
.
├── code.c          # Main source file
├── code.h          # Header file
├── students.txt    # Sample student data
├── grades.txt      # Sample grade data
```

## Build

```bash
gcc code.c -o grades_manager
```

## Run

Using default files:

```bash
./grades_manager
```

Using custom files:

```bash
./grades_manager students.txt grades.txt output.txt
```

The program prompts the user to enter a subject name, filters matching records, and displays or saves the results depending on the selected option.
