/*
 * obj.h
 *
 *  Created on: Jul 30, 2018
 *      Author: james
 */

#ifndef OBJ_H_
#define OBJ_H_

#include <stdbool.h>
#include "obj.T.h"

struct obj_ {
	unsigned long long hashID;
};

typedef struct obj_ obj;

define_obj_h( obj )

#endif /* OBJ_H_ */
