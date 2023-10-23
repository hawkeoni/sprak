#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(void){
    
    char path[300];
    uid_t uid;
    scanf("%s %u", path, &uid);
    DIR* drt;
    drt = opendir(path);
    struct dirent* drnt;
    drnt = readdir(drt);
    struct stat buf;
    off_t sum = 0;
    while (drnt != NULL) {
        if (! (!strcmp(drnt->d_name, ".") || !strcmp(drnt->d_name, ".."))) {

            lstat(drnt->d_name, &buf);
            
            if (S_ISREG(buf.st_mode)) {
                printf("%s %llu\n", drnt->d_name, buf.st_size);
                sum = sum + buf.st_size;
            }
        }
        drnt = readdir(drt);
    }
    printf("%llu\n", sum);
    return 0;
}