
// student database system 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "common.h"


void data_input(student *data, int num);
void data_show(student *data, int num);
void write_file(student *data, int num, const char *file);
int read_file(student **data, const char *file);
void append_file(student *data, int num, const char *file);
void remove_file(const char *file, int student_num);

int main()
{
    int choice;
    int num_sp;
    student *sp = NULL;
    int read_count = 0;
    char *file = "students.bin";
    int remove_num;
    student *file_students = NULL;
    int file_count = 0;

    do{
	printf("\n\n\n========= STUDENT DATABASE SYSTEM ==========\n\n\n");
	printf("1. Enter new student\n");
	printf("2. Display the entered new students details \n");
	printf("3. Save students details to a new file\n");
	printf("4. Read students details from file\n");
	printf("5. Add students details to existing file\n");
	printf("6. Remove student\n");
	printf("7. EXIT\n");
	printf("\n\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	getchar();

	switch(choice){
	    case 1: // for new students
		printf("Enter number of students to input: ");
		scanf("%d", &num_sp);
		getchar();

	        if (sp != NULL){
		    free(sp);
		    sp = NULL;
		}

	        sp = (student *)malloc(sizeof(student) * num_sp);
		if(!sp){
		    printf("Memory allocation failed\n");
		break;
		}

		data_input(sp, num_sp);
		printf("%d students added to memory\n", num_sp);
		break;

	    case 2: // to display students
		if(sp == NULL){
		    printf("No students in memory. Please Enter students first...\n");
		}else{
		    printf("\n==== New Students details which are entered ====\n");
		    data_show(sp, num_sp);
		}
		break;

	    case 3: // write to file
		if(sp == NULL){
		    printf("No students to save. Please enter students first...\n");
		}else {
		    write_file(sp, num_sp, file);
		}
		break;

	    case 4: // read file
		if(sp != NULL){
		    free(sp);
		    sp = NULL;
		}

		read_count = read_file(&sp, file);
		if(read_count > 0){
		    num_sp = read_count;
		    printf("\n==== Student details in the File ====\n");
		    data_show(sp, num_sp);
		}
		break;

	    case 5: // Append to file
		if (sp ==NULL){
		    printf("No students to append. Please enter students first...\n");
		}else{
		    append_file(sp, num_sp, file);
		}
		break;

	    case 6: // to remove student
	// first read current file to show students
		    int file_count = read_file(&file_students, file);

		    if (file_count > 0){
			printf("\n==== Current Students in File ====\n");
			data_show(file_students, file_count);

			printf("\nEnter Student number to remove (1-%d)", file_count);
			scanf("%d", &remove_num);
			getchar();

			if (remove_num >= 1 && remove_num <= file_count){
			    remove_file(file, remove_num);
			    printf("Student %d removed successfully...\n", remove_num);
			}else{
			    printf("Invalid student number...\n");
			}

			free(file_students);
		    }else{
			printf("No students in file or error reading file...\n");
		    }
		    break;

	    case 7: // Exit
		printf("Exiting program....\n");
		break;

	    default:
		printf("Invalid choice. Please try again...\n");
	}

    }while (choice != 7);

// clean up

    if (sp != NULL){
	free(sp);
    }


    return 0;

}