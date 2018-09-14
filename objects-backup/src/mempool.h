#include "elem.h"

struct Mempool{
  // In total we will allocate 10 * 2048 bytes, 20480 bytes, 20.48 kilobytes
  struct elem2048 block_0x01;
  struct elem1024 block_0x02[2];
  struct elem512 block_0x03[4];
  struct elem256 block_0x04[8];
  struct elem128 block_0x05[16];
  struct elem64 block_0x06[32];
  struct elem32 block_0x07[64];
  struct elem16 block_0x08[128];
  struct elem8 block_0x09[256];
  struct elem4 block_0x0A[512];
};
