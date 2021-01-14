#define _GNU_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>

void main()
{
    int random_num;
    int ttid, count;
    char    str[300];
    char    filename[100];

    struct timeval  t1, t2;

    gettimeofday(&t1, NULL);
    ttid=gettid();
    count=0;

    // open a file for writing. The filename consist of the following two substrings, 
    // "file_" and the string converting from the result of gettid(). Hence, if the result of gettid is 123,
    // the file name is file_123. We use file_gettid to call this file in the following pseudo code. 

    FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
    sprintf(filename, "file_%d.txt", ttid);
    fptr = fopen(filename, "w");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    
    printf("pid is %d\n", getpid());

    
    while(1)
    {
    gettimeofday(&t2, NULL);

    //If the time difference between t2 and t1 is greater than 3 minutes, break;
    if (abs(t1.tv_sec - t2.tv_sec) > 180) break;

    random_num= (rand()%3)+1;

    sprintf(str, "process %d is added into wait queue project2_queue_%d the %d th time at time %ld\n", ttid, random_num, count++, t2.tv_sec);
    //write the string stored in array str[] into file file_gettid.
    fwrite(str, 1, strlen(str)+1, fptr);
    syscall(355, random_num); 
                       

    } 
    fclose(fptr);
    printf("process %d completes!\n", ttid);
}