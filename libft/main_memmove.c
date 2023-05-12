#include <stdio.h>
#include <string.h>

int main () {
   char dest[] = "oldstringewew";
   const char src[]  = "newstrg";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 4);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   printf("Before memcpy dest = %s, src = %s\n", dest, src);
   memcpy(dest, src, 8);
   printf("After memcpy dest = %s, src = %s\n", dest, src);

   return(0);
}
