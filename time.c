#include <time.h>
#include <stdio.h>


int main(void){
time_t t = time(NULL);
printf("%ld\n", t);
return 0;
}
