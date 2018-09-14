#ifdef SET_H
#define SET_H

extern const void * Set;
void * add(void * set, const void * element);
void * find(const void * set, const void * element);
void * drop(const void * set, const void * element); // don't use "remove because stdio"
int contains(const void * set, const * void element);

#endif
