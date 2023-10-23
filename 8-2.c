#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int comp ( const void *aa, const  void *bb){
unsigned long long *a = (unsigned long long*)aa;
unsigned long long *b = (unsigned long long*)bb;
if (*a < *b) {
return 1;
} 
else if (*a > *b) {
return -1; }
else {
return 0;
}


}

unsigned long long bs(char* s) {
int k = strlen(s);
char c;
unsigned long long pow = 1; 
unsigned long long n = 0;
for (int i = (k - 1) ; i >= 0; i--) {
c = s[i];
if ( '0' <= c && c <= '9') {
n  += ((unsigned long long)(c - '0')) * pow;

}	
else if ('A' <= c && c <='G') {
n += ((unsigned long long)(c - 'A' + 10)) * pow;
}
else if ('a' <= c && c <='g') {
n += ((unsigned long long)(c - 'a' + 10)) * pow; 
}
pow *= 17;

}


return n;
}

int main (int argc, char **argv) {
int l;
int k = argc - 1;
int bsk = 17;
unsigned long long *arr = (unsigned long long*)malloc(sizeof(unsigned long long)*k);
for (int i = 1; i < argc; i++) {
arr[i-1] = strtoul(argv[i], NULL, bsk);
}
qsort(arr, k, sizeof(arr[0]), comp);
for (int j = 0; j < k; j++) {
printf("%llu\n", arr[j]);

}




return 0;
}
