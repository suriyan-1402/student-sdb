Student Database Management System in C // My first C programming project:

A simple command-line Student Database Management System written in C for Linux environments. This program allows you to manage student records through text files using a menu-driven interface.
Features:

    Add New Student - Enter new student details and create a new file

    Show Recent Student - Display the most recently entered student details

    Save & Reset - Save entered student details to a new file and delete existing file

    Read from File - Read student details from an existing file

    Append to File - Add student details to an existing file

    Remove Student - Remove a student by selecting their number from the list

    Exit - Close the program

How to use:

1. Add New Student

    Select option 1 from the menu

    Enter student details when prompted:

        StudentName Lastname coursename GroupNumber

2. Show Recent Student

    Select option 2 from the menu

    The program will display the most recently entered student's details

    This shows data from the current session only

3. Save & Reset

    Select option 3 from the menu

    All entered student details will be saved to a new file

    The existing temporary file will be deleted

    System will be reset for new entries

4. Read from File

    Select option 4 from the menu

    The program will display all student records from that saved file

5. Append to File

    Select option 5 from the menu

    Enter new student details when prompted

    Data will be added to the end of the existing file

6. Remove Student

    Select option 6 from the menu

    The program will display all students

    Enter the student number you want to remove

    That student will be deleted from the file

7. Exit

    Select option 7 from the menu

    The program will close

    Make sure to save your data before exiting

How to compile and run in linux:

-------------------------------------------------------------------------
	git clone https://github.com/suriyan-1402/student-sdb.git

	cd student-sdb/

	make

	./student-sdb
--------------------------------------------------------------------------
