#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <longc/lang.h>
#include <longc/string/string.h>

#include "retspan.h"

void set_varg(struct varg* src, const char* str_short, const char* str_long, const u8 opts)
{
  src->opt_short = new_string_from(str_short);
  src->opt_long =  new_string_from(str_long);
  src->optc = opts;
}

Retspan init_Retspan(){

  Retspan self;
  self.dls.elem = NULL;
  self.dls.len = 0;
  self.dls.cap = 0;

  // TODO: add vargs
  self.vargs.elem = malloc(sizeof(struct varg) * 11);
  self.vargs.len = 11;
  self.vargs.cap = 11;
  set_varg(&self.vargs.elem[0], "v", "verbose", 0);
  set_varg(&self.vargs.elem[1], "a", "artist", 1);
  set_varg(&self.vargs.elem[2], "A", "album", 1);
  set_varg(&self.vargs.elem[3], "p", "playlist", 0);
  set_varg(&self.vargs.elem[4], "F", "formats", 5);
  set_varg(&self.vargs.elem[5], "o", "output", 5);
  set_varg(&self.vargs.elem[6], "d", "output-directory", 1);
  set_varg(&self.vargs.elem[7], "T", "test", 0);
  set_varg(&self.vargs.elem[9], "t", "titles", 1);
  set_varg(&self.vargs.elem[10], "h", "help", 0);

  self.formats = malloc(sizeof(String) * 5);
  self.formats[0] = new_string_from("mp3");
  self.formats[1] = new_string_from("flac");
  self.formats[2] = new_string_from("ogg");
  self.formats[3] = new_string_from("opus");
  self.formats[4] = new_string_from("wav");

  return self;
}

void Retspan_stack_free(Restpan* self){

  if(self->dls.elem != NULL){
    free(self->dls.elem);
  }

}

i32 main(void){

  Retspan app = init_Retspan();

  for(u32 i = 0; i < app.vargs.len; i++){
    printf("Short: %s\tLong: %s\tOption Count: %d\t", app.vargs.elem[i].opt_short->c, app.vargs.elem[i].opt_long->c, app.vargs.elem[i].optc);
  }

  return 0;
}
