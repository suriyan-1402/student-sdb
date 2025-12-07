
// student database system 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

// this function is to enter new students details to create a new file...


void data_input(student *data, int num){
    int idx = 0;

    while(num-- > 0){
	printf("Enter data (name, lastname, course, group):");
	scanf("%s %s %s %d", (data + idx)->name, (data + idx)->lastname,(data + idx)->course,&(data + idx)->group);

	idx++;
    }
    return;
}
