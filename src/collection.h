#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#define CONTAINS( T ) T##_contains
#define INDEX_OF( T ) T##_index_of
#define STARTS_WITH( T ) T##_starts_with
#define ENDS_WITH( T ) T##_ends_with
#define RESIZE( T ) T##resize
#define NEW_WITH_CAPACITY( T ) new_##T##_with_capacity
#define INIT_WITH_CAPACITY( T ) init_##T##_with_capacity

#define COLLECTION_TRAIT_H_( T , T_OWNED ) \
  OPTION(REF(T)) NEW_WITH_CAPACITY(T)(const size_t cap); \
  OPTION(T) INIT_WITH_CAPACITY(T)(const size_t cap); \
  bool CONTAINS(T)(const T* self, const T_OWNED* item); \
  u32 INDEX_OF(T)(const T* self, const T_OWNED* item); \
  bool STARTS_WITH(T)(const T* self, const T_OWNED* item); \
  bool ENDS_WITH(T)(const T* self, const T_OWNED* item);

#endif /* _COLLECTION_H_ */
