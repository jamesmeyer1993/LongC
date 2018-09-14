/*
 * bash.h
 *
 *  Created on: Aug 23, 2018
 *      Author: james
 */

#ifndef BASH_H_
#define BASH_H_

struct bash {

};

int bash_grep_count(const char* s, const char* filename);

void bash_pwd();

void bash_touch(const char* filename);

void bash_write(const char* s, const char* filename);

void bash_append(const char* s, const char* filename);

void bash_remove(const char* filename);

#endif /* BASH_H_ */
