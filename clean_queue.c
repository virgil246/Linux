#define _GNU_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>

void main()
{
    int random_num1, random_num2;
    int ttid, count;
    char    str[300];

    
    struct timeval  t1, t2;

    gettimeofday(&t1, NULL);
    ttid=gettid();
    count=0;

    // open a file for writing. The filename consist of the following two substrings, 
    // "file_" and the string converting from the result of gettid(). Hence, if the result of gettid is 123,
    // the file name is file_123. We use file_gettid to call this file in the following pseudo code. 

    FILE *fptr;
   // use appropriate location if you are using MacOS or Linux
    char filename[100];
    sprintf(filename, "file_%d.txt", ttid);
    fptr = fopen(filename, "w");


    while(1)
    {
    gettimeofday(&t2, NULL);
    
    //If the time difference between t2 and t1 is greater than 5 minutes, break;
    if (abs(t1.tv_sec - t2.tv_sec) > 300) break;


    random_num1= (rand()%3)+1;
    random_num2= (rand()%60);
    sleep(random_num2);

    sprintf(str, "Wake up all processes in wait queue project2_queue_%d at time %ld\n", random_num1, t2.tv_sec);
    //write the string stored in array str[] into file file_gettid;
    fwrite(str, 1, strlen(str)+1, filename);
    enter_wait_queue(random_num);
    
    syscall(352, random_num1); //clean_wait_queue(random_num1);                        

    } 

    syscall(352, 1);
    //write the string "Clean wait wait queue project2_queue_1" into file file_gettid;
    sprintf(str, "Wake up all process in the project2_queue_1 at time %ld\n", t2.tv_sec);
    fwrite(str, 1, strlen(str)+1, filename);

    syscall(352, 2); 
    //write the string "Clean wait wait queue project2_queue_2" into file file_gettid;
    sprintf(str, "Wake up all process in the project2_queue_2 at time %ld\n", t2.tv_sec);
    fwrite(str, 1, strlen(str)+1, filename);

    syscall(352, 2); 
    //write the string "Clean wait wait queue project2_queue_3" into file file_gettid;
    sprintf(str, "Wake up all process in the project2_queue_3 at time %ld\n", t2.tv_sec);
    fwrite(str, 1, strlen(str)+1, filename);
    
    fclose(fptr);
    printf("process %d completes!\n", ttid); 
}