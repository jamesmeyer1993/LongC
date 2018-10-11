# LongC
Extensions for general purpose C code. Written in plain C.

## Design Goals

### Complete
- lang/primitives.h
- lang/reference.h

#### Lang
- lang/primitives.h
  - Description: Everything in longc depends on this header file.
  - status: *complete. possible additions - no refractoring please*

- lang/reference.h && lang/reference.c
  - Description: Used for enforcing ownership and pointer types.
  - status: *complete. possible additions - no refractoring please*

#### Util
*Array Types*
*array.h - the ref form of an array.*
- array.h       && array.c      --> array.o
*array_tmpl.h - used to generate the following primitive types*
- array_tmpl.h
- array_u8      && array_u8.c   --> array_u8.o
- array_i8      && array_i8     --> array_i8
- array_i32.h   && array_i32.c  --> array_i32.o
- array_u32.h   && array_u32.c  --> array_u32.o
- array_f64     && array_f64    --> array_f64s.o
*String types*
- utf4.h  && utf4.c --> utf4.o
- utf8.h  && utf8.c --> utf8.o
*Linked data structures*
- node.h    && node.c --> node.o
- list.h    && list.c --> list.o
- stack.h   && strack.c --> stack.o
- stack.u8  && strack.c --> stack.o
- stack.i8  && strack.c --> stack.o
*Trees*
- tree.h        && tree.c       --> tree.o
- bitree.h      && bitree.c     --> bitree.o
*Tabels*
- hashtable.h   && hashtable.c  --> hashtable.o
- row.h         && row.c        --> row.o
- table.h       && table.c      --> table.o

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
