#ifndef _DLISTH_
#define _DLISTH_

#ifndef T_DLIST
  #define T_DLIST 20
#endif

struct dlist
{
  EXTENDS_DLIST
};

/*---GETTERS---*/
int dlist_locate(struct dlist* src, struct obj* elem);

bool dlist_contains(struct dlist* src, struct obj* elem);

/*---SETTERS---*/
void dlist_add(struct dlist* src, struct obj* elem);

void dlist_resize(struct dlist* src);

/*---CASTS---*/

struct list dlist_tolist(struct dlist* src);

struct obj dlist_toobj(struct dlist* src);

#endif
