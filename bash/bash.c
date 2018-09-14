/*
 * bash.c
 *
 *  Created on: Aug 23, 2018
 *      Author: james
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bash.h"

int bash_grep_count(const char* s, const char* filename){
	char cmd[128];
	strcpy(&cmd, "grep -c \"");
	strcat(&cmd, s);
	strcat(&cmd, "\" ");
	strcat(&cmd, filename);
	printf("%s\n", &cmd);
	int x = system(cmd);
	printf("bash.c: status=%d\n", x);
	return x;
}

void bash_pwd(){
	int x = system("pwd");
	printf("bash.c: status=%d\n", x);
}

void bash_touch(const char* filename){
	char cmd[128];
	strcpy(&cmd, "touch ");
	strcat(&cmd, filename);
	printf("%s\n", &cmd);
	int x = system(cmd);
	printf("bash.c: status=%d\n", x);
}

void bash_write(const char* s, const char* filename){
	char cmd[128];
	strcpy(&cmd, "printf \"");
	strcat(&cmd, s);
	strcat(&cmd, "\"");
	strcat(&cmd, " > ");
	strcat(&cmd, filename);
	printf("%s\n", &cmd);
	int x = system(cmd);
	printf("bash.c: status=%d\n", x);
}

void bash_append(const char* s, const char* filename){
	char cmd[128];
	strcpy(&cmd, "printf \"");
	strcat(&cmd, s);
	strcat(&cmd, "\"");
	strcat(&cmd, " >> ");
	strcat(&cmd, filename);
	printf("%s\n", &cmd);
	int x = system(cmd);
	printf("bash.c: status=%d\n", x);
}

void bash_remove(const char* filename){
	char cmd[128];
	strcpy(&cmd, "rm ");
	strcat(&cmd, filename);
	printf("%s\n", &cmd);
	int x = system(cmd);
	printf("bash.c: status=%d\n", x);
}
