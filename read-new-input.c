
// student database system 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

// this function is to show the students details which you had already entered to create new file...


void data_show(student *data, int num){
    int idx = 0;

    printf("      Name          |"
	"       Lastname      |"
	"      Course    |"
	"    Group  | \n");
    while(num-- > 0){
	printf("%20s| %20s| %15s| %10d|\n", (data + idx)->name,(data + idx)->lastname,(data + idx)->course,(data + idx)->group);
	idx++;
    }
}

