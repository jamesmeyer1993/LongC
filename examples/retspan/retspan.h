#include <stdbool.h>
#include <stdlib.h>
#include <longc/lang.h>
#include <longc/string/string.h>

struct download {
    bool playlist;
    u32 year;
    String* artist;
    String* album;
    String* genre;
    String* url;
    String* titles;
    String* formats;
    // TODO: additional metadata
};

struct varg {
  String* opt_short;  // short option
  String* opt_long;   // long option
  u8 optc;        // option count
};

typedef struct retspan {
  String** formats;
  struct {
    struct varg* elem;
    u32 len;
    u32 cap;
  } vargs;
  struct {
    struct download* elem;
    u32 len;
    u32 cap;
  } dls;
} Retspan;
