#include <stdio.h>


void increment(int x) {
	x += 1;
}


void increment_ptr(int *x) {
	*x += 1;
}

int main(void){

	int b = 16;
	increment(b);
	printf("%d\n", b);
	increment_ptr(&b);
	printf("%d\n", b);
	

	int a[5];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;


	printf("%d %d\n", *(a + 3), a[3]);
	printf("%llu %llu\n", a, a + 3);

	char c1 = "a";
	char c2 = "z";
	char *cc = &c1;
	printf("%c\n", *cc);


	return 0;
}

/*

char *endptr;
strtoul(str, &endptr, 17);

char **endpt;
*/

// (char*)*
void change_ptr(char **cc){
	cc = ...;

}


/*
int *ptr;


ptr - int*
*ptr - int
ptr[0] - int

(ptr + 1) - int*
*(ptr + 1) - int
ptr[1]

*/
