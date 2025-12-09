
// student database system 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "common.h"



// this function is to remove student details by entering the no. of student details shown there...

void remove_file(const char *file, int student_num){
    int fd_in, fd_tmp;
    student student_buffer;
    int bytes_read, bytes_written;
    int current_student = 0;
    char tmp_file[] = "tmp_students.bin";

    // open file for reading
    fd_in = open(file, O_RDONLY);
    if (fd_in == -1){
	printf("Error opening file for reading: %s\n", strerror(errno));
	return;
    }

    // open temporary file for writing
    fd_tmp = open(tmp_file, O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if(fd_tmp == -1){
	printf("Error creating temporary file: %s\n", strerror(errno));
	close(fd_in);
	return;
    }

    // copy all students except the one to remove
    while ((bytes_read = read(fd_in, &student_buffer, sizeof(student))) > 0){
	current_student++;

	if (current_student != student_num){
	    bytes_written = write(fd_tmp, &student_buffer, sizeof(student));
	    if (bytes_written == -1){
		printf("Error writing to temporary file: %s\n", strerror(errno));
		close(fd_in);
		close(fd_tmp);
		remove(tmp_file);
		return;
	    }
	}else{
	    printf("Skipping student %d: %s %s\n", current_student, student_buffer.name, student_buffer.lastname);
	}
    }

    if(bytes_read == -1){
	printf("Error reading from file: %s\n", strerror(errno));
    }

    close(fd_in);
    close(fd_tmp);

// replace file with temporary file

    if(remove(file) != 0){
	printf("Error removing original file: %s\n", strerror(errno));
    }

    if(rename(tmp_file, file) != 0){
	printf("Error renaming temporary file: %s\n", strerror(errno));
	printf("Original data might be in %s\n", tmp_file);
    }else{
	printf("File updated successfully...\n");
    }
}


