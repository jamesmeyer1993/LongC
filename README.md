# LongC
Extensions for general purpose C code. Written in plain C.

## Design Goals

### Complete

#### Lang
- [ ] - lang/primitives.h       *everything in longc depends on this header file*

#### Util
- [ ] - util/array.h                      | includes:[**primitives.h**]
- [ ] - util/array/i32_array.h            | includes:[primitives.h,array.h]
- [ ] - util/array/ui8_array.h            | includes:[primitives.h,array.h] *this is the base array for the string type*
- [ ] - util/string.h                     | includes:[primitives.h,ui8.h]
- [ ] - util/node.h                       | includes:[**primitives.h**]
- [ ] - util/node/string_node.h           | includes:[primitives.h,string.h]
- [ ] - util/node/ui32.h                  | includes:[primitives.h,node.h]
- [ ] - util/node/ui64.h                  | includes:[primitives.h,node.h]
- [ ] - util/list.h                       | includes:[**primitives.h**]
- [ ] - util/list/string_list.h           | includes:[primitives.h,list.h]
- [ ] - util/stack.h                      | includes:[**primitives.h**]
- [ ] - util/stack/ui8_stack.h            | includes:[primitives.h,stack.h]
- [ ] - util/stack/i32_stack.h            | includes:[primitives.h,stack.h]
- [ ] - util/tree.h                       | includes:[**primitives.h**]
- [ ] - util/binarytree.h                 | includes:[**primitives.h**]
- [ ] - util/hashtable.h                  | includes:[**primitives.h**]
- [ ] - util/hashtable/string_hashtable.h | includes:[primitives.h,hashtable.h,string.h]
- [ ] - util/row.h                        | includes:[**primitives.h**]
- [ ] - util/table.h                      | includes:[primitives.h,row.h]

#### Math
##### Math Types
- [ ] - math/ui32d.h
- [ ] - math/i32d.h
- [ ] - math/if32d.h
##### Math Containers
- [ ] - math/sequence.h
- [ ] - math/vector.h
- [ ] - math/matrix.h

##### Math Functions
- [ ] - math/factorial.h
- [ ] - math/exponents.h

#### SQLite
- [ ] - sqlite/*

#### Download
- [ ] - util/downloader.h
