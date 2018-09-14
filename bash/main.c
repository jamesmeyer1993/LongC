/*
 * main.c
 *
 *  Created on: Aug 23, 2018
 *      Author: james
 */
#include <stdio.h>
#include "bash.h"

int main(void){
	printf("main.c:\tRunning.\n");
	bash_pwd();

	bash_touch("testfile.txt");
	bash_write("This is the first line.", "testfile.txt");
	bash_append("Second line.", "testfile.txt");
	bash_append("Third line.", "testfile.txt");
	bash_grep_count("line", "testfile.txt");
	bash_remove("testfile.txt");

	const char* msg = "\"string\"";
	printf("%s", msg);
}
