#include "elem.h"

struct url{
  struct elem128 elem;
};

struct elem128 url_compress(struct url u);

struct elem128 url_decompress(struct url u);

void url_serialize(struct* url u);

struct url url_deserialize(char* path);
