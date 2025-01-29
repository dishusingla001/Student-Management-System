Student Information Management System
This is a simple command-line based Student Information Management System implemented in C++. The project allows users to perform various operations on student records stored in a file. The records include basic student details such as Roll Number, Name, and Class.

Features:
Write (w): Allows adding student records to a file.
Read (r): Displays all the student records stored in the file.
Copy (c): Creates a backup of the student records by copying them to a new file.
Search (s): Allows searching for a student by their roll number.
Insert (i): Inserts a new student record into the file if the roll number does not already exist.
Delete (d): Deletes a student record based on roll number.
Update (u): Updates an existing student record with new details.

How It Works:
The student records are stored in a binary file (switch.dat).
All operations, such as writing, reading, and modifying records, are carried out using file input and output operations in C++.
The program also handles the possibility of duplicate roll numbers, and ensures data integrity by renaming and removing files as necessary.

File Format:
switch.dat: Stores student records in binary format.
copy.dat: A temporary backup used during file copy, insert, update, or delete operations.

Usage:
Start the program: The user will be prompted with a menu of available options.
Perform Operations: Choose from the available options (write, read, update, etc.) to manage student records.
Exit the Program: The program will continue to prompt for actions until the user opts to exit.

Technologies Used:
C++ programming language
File Handling (Binary File I/O)
