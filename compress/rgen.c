#include <assert.h>
#include <stdio.h>

// primitves
#define u8 unsigned char
#define u32 unsigned int

struct u32Image {
  u32 seed;
  u32 fails;
  u32 iter;   // iterations
};

struct u32Image build_u32(u32 src, u32 seed) {

  u32 downshift = 0;
  struct u32Image img;
  img.seed = seed;
  img.fails = 0;
  img.iter = 0;

  u32 s = seed;
  u32 m = 0;

  while(s != src){

      if(s > src){
        s = s >> 1;
        img.iter--;
        img.fails++;
        printf("s=%d\timg.iter=%d\n", s, img.iter);
      }
      else{
        m++;
        img.iter = img.iter * m;
        s = s + img.iter;
      }
  }
  printf("%d == %d", s , src);

  return img;
}

int main(){

  struct u32Image img = build_u32(799,11);
  printf("Done:\n\t{img.seed=%d,img.fails=%d,img.iter=%d}\n", img.seed, img.fails, img.iter);

}
