#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

int main (int argc, char **argv) {
int fd = open(argv[1], O_RDWR);
int m;
off_t size = lseek(fd, 0, SEEK_END);
char* buf = (char *)malloc(sizeof(char)*size);
lseek(fd, 0, SEEK_SET);
ssize_t n = read(fd, buf, size);
m = sqrt(size * 8.0);
for (int i = 0; i < m; i++) {
int index = i*m + i;
int byt = index / 8;
int bt_in_byt = index % 8;
buf[byt] = buf[byt] | (1 << bt_in_byt);

}
lseek(fd, 0, SEEK_SET);
ssize_t k = write(fd, buf, size);
close(fd);
return 0;
}
