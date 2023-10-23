#include <stdio.h>
#include <stdlib.h>


/*
     void
     qsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
*/

int compare (const void *aa, const void *bb) {
long long int *a = (long long int*)aa;
long long int *b = (long long int*)bb;
if (*a < *b){
	return -1;
	}
else if (*a == *b) {
	return 0; 
}
else {
	return 1;
}
}

int main(void) {
long long int arr[10000];
long long int n;
int res = 1;
int i = 0;
while (res > 0) {
	res = scanf("%lld", &n);
	if ( res == 1) {
		arr[i] = n;
		i++;
		}
}
qsort(arr, i, sizeof(n),compare);
for (int j = 0; j < i; j++) {
printf("%lld ", arr[j]);

} 
printf("\n");
int l = 0;
int r = i - 1;
long long int sum = 0;
while (l < r) {
sum += arr[l] + arr[r];
r--;
l++;
}
if (l == r) {
sum += arr[l];
} 
printf("%lld\n", sum);
return 0;
}
