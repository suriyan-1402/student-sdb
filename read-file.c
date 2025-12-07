
// student database system 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "common.h"


// this function is to show the students details from existing file...

int read_file(student **data, const char *file){
    int fd;
    int bytes_read = 1;
    int count = 0;
    student *tmp = NULL;

    fd = open(file, O_RDONLY);
    if (fd == -1){
	printf("File open error: %i (%s)\n", errno, strerror(errno));
	return 0;
    }

    *data = (student *)malloc(sizeof(student));
    if (!(*data)){
	printf("Memory allocation failed\n");
	close(fd);
	return 0;
    }

    while (bytes_read > 0){
	bytes_read = read(fd, (*data) + count, sizeof(student));

	if (bytes_read == -1){
	    printf("File read error: %i (%s)\n", errno, strerror(errno));
	    close(fd);
	    free(*data);
	    *data = NULL;
	    return 0;
	}

	if(bytes_read == 0){
	    break;
	}

	if(bytes_read < sizeof(student)){
	    printf("Error: incomplete record read\n");
	    close(fd);
	    free(*data);
	    *data = NULL;
	    return 0;
	}

	count++;
	tmp = (student*)realloc(*data, sizeof(student) * (count + 1));
	if(!tmp){
	    printf("Memory reallocation failed\n");
	    close(fd);
	    free(*data);
	    *data = NULL;
	    return count;
	}
	*data = tmp;

    }

    close(fd);

// Resize to exact count
    if(count > 0){
	tmp = (student *)realloc(*data, sizeof(student) * count);

	if(tmp){
	    *data = tmp;
	}
    }

    printf("Successfully read %d records from %s\n", count, file);
    return count;
}

