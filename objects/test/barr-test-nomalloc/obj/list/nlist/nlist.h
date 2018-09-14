#ifndef _NLIST_
#define _NLIST_

#ifndef T_NLIST 19
  #define T_NLIST 19
#endif

struct nlist
{
  
};

/*---SETTERS---*/

void nlist_addat(struct nlist* src, struct obj* elem, int at);

void nlist_addtofront(struct nlist* src, struct obj* elem); // extends push

void nlist_addtorear(struct nlist* src, struct obj* elem);

void nlist_removeat(struct nlist* src, int at);

void nlist_remove(struct nlist* src, struct obj* elem);

void nlist_removehead(struct nlist* src, struct obj* elem); // extends pop

void nlist_removetail(struct nlist* src, struct obj* elem);

/*---GETTERS---*/

int nlist_locate(struct nlist* src, struct obj* elem);

bool nlist_contains(struct nlist* src, struct obj* elem);

struct obj nlist_getat(struct nlist* src, int at);

/*---CASTS---*/

struct stack nlist_tostack(struct nlist* src);

struct list nlist_tolist(struct nlist* src);

struct obj nlist_toobj(struct nlist* src);

#endif
