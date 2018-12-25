#ifndef _COLLECTION_H_
#define _COLLECTION_H_

struct node {
  void *data;
};

typedef struct collection {
  struct {
    u32 length;
    node *nodes;
  } priv;
} collection;

#define getlen( T ) \
 	T ## _getlen( T )

#define at( T , INDEX ) T ## _at( INDEX )

#define collection_getlen priv.length

#define collection_at( INDEX ) priv.nodes[ INDEX ].data

#endif // _COLLECTION_H_
