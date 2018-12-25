/*
 * download.h
 *
 *  Created on: Aug 23, 2018
 *      Author: james
 */

#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_

struct download
{
	int* dlcount;
	char url[64];
};

void is_download_verify(struct download* check, struct download* against);

int download_run(struct download* d);

#endif /* DOWNLOAD_H_ */
