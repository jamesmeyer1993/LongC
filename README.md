# LongC
Extensions for general purpose C code. Written in plain C.

## Design Goals

### Complete

#### Lang
- lang/primitives.h **everything in longc depends on this header file**
- lang/reference.h && lang/reference.c  **used for enforcing ownership and types of pointers**

#### Util
- util/array.h
- util/string.h
- util/node.h
- util/list.h
- util/stack.h
- util/tree.h
- util/binarytree.h
- util/hashtable.h
- util/row.h
- util/table.h

#### Math
##### Math Types
- [ ] - math/u32d.h
- [ ] - math/i32d.h
- [ ] - math/f32d.h
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
