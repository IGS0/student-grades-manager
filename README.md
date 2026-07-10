# Student Grades Manager / Õpilaste hinnete haldur

A console application written in C for managing student records and grade data stored in text files.

C-keeles kirjutatud konsooliprogramm õpilaste ja hinnete andmete töötlemiseks tekstifailidest.

---

# English

## Features

* Reads student information and grade records from separate text files.
* Stores data using C structures.
* Filters students by subject.
* Displays matching student records and grades.
* Saves filtered results to an output file.
* Lists all available subjects and the number of grades for each subject.
* Supports custom input and output files via command-line arguments.
* Provides basic validation and error handling for file operations and input data.

## Project Structure

```text
grades_manager.c      Main source file
grades_manager.h      Header file
opilased.txt          Student data
hinded.txt            Grade data
```

## Building

Compile the program with GCC:

```bash
gcc grades_manager.c -o grades_manager
```

## Usage

### Default execution

If no command-line arguments are provided, the program uses the default file names.

```bash
./grades_manager
```

### Custom files

```bash
./grades_manager <students_file> <grades_file> <output_file>
```

Example:

```bash
./grades_manager opilased.txt hinded.txt tulemused.txt
```

## Command-line options

The program supports several execution modes.

### Interactive mode

```text
./grades_manager
```

Uses default files and asks the user for:

* subject name
* output destination

### Custom input files

```text
./grades_manager <students_file> <grades_file>
```

### Custom input and output files

```text
./grades_manager <students_file> <grades_file> <output_file>
```

### Fully automated execution

The program also supports command-line execution without interactive prompts.

```text
./grades_manager <output_mode> <subject>

./grades_manager <students_file> <grades_file> <output_mode> <subject>

./grades_manager <students_file> <grades_file> <output_file> <output_mode> <subject>
```

Output modes:

* `terminal` – display results in terminal only
* `fail` – save results to file only
* `kõik` – display in terminal and save to file

## Input file format

### Student file (`opilased.txt`)

```
StudentID FirstName LastName PersonalID
```

Example:

```
233344 Sten-Oliver Vallassaar 49011162694
```

### Grade file (`hinded.txt`)

```
PersonalID Subject Grade
```

Example:

```
49011162694 Geograafia 5
```

---

# Eesti

## Funktsioonid

* Loeb õpilaste ja hinnete andmeid kahest tekstifailist.
* Kasutab andmete hoidmiseks C struktuure.
* Võimaldab otsida õpilasi õppeaine järgi.
* Kuvab filtreeritud tulemused terminalis.
* Salvestab tulemused faili.
* Kuvab kõik olemasolevad õppeained ja hinnete arvu iga aine kohta.
* Toetab käsurea argumente sisend- ja väljundfailide määramiseks.
* Sisaldab põhilist sisendi ja failide vigade kontrolli.

## Projekti struktuur

```text
grades_manager.c      Programmi lähtekood
grades_manager.h      Päisefail
opilased.txt          Õpilaste andmed
hinded.txt            Hinnete andmed
```

## Kompileerimine

```bash
gcc grades_manager.c -o grades_manager
```

## Kasutamine

### Vaikimisi

```bash
./grades_manager
```

Programm kasutab vaikimisi failinimesid.

### Oma failidega

```bash
./grades_manager <opilaste_fail> <hinnete_fail> <väljundfail>
```

Näide:

```bash
./grades_manager opilased.txt hinded.txt tulemused.txt
```

## Käsurea kasutusvõimalused

Programm toetab mitut käivitusviisi.

### Interaktiivne režiim

```text
./grades_manager
```

Programm küsib kasutajalt:

* õppeaine nime;
* kuhu tulemused väljastada.

### Oma sisendfailidega

```text
./grades_manager <opilaste_fail> <hinnete_fail>
```

### Oma sisend- ja väljundfailidega

```text
./grades_manager <opilaste_fail> <hinnete_fail> <väljundfail>
```

### Automaatne käivitamine

Programm võimaldab kõik vajalikud parameetrid anda käsurealt.

```text
./grades_manager <kuhu_näidata> <aine>

./grades_manager <opilaste_fail> <hinnete_fail> <kuhu_näidata> <aine>

./grades_manager <opilaste_fail> <hinnete_fail> <väljundfail> <kuhu_näidata> <aine>
```

Väljundi valikud:

* `terminal` – ainult terminali;
* `fail` – ainult faili;
* `kõik` – terminali ja faili.

## Sisendfailide vorming

### opilased.txt

```
ÕpilaseID Eesnimi Perekonnanimi Isikukood
```

Näide:

```
233344 Sten-Oliver Vallassaar 49011162694
```

### hinded.txt

```
Isikukood Õppeaine Hinne
```

Näide:

```
49011162694 Geograafia 5
```


UML:
<img width="962" height="395" alt="image" src="https://github.com/user-attachments/assets/47f9e418-33ef-4f99-9093-c6966d00dda6" />

