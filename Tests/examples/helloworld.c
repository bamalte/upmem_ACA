#include <stdio.h>
#include <defs.h>
#include <mutex.h>
#include <barrier.h>

int shared_var = -1;
MUTEX_INIT(my_mutex);
BARRIER_INIT(my_barrier,NR_TASKLETS);

#define BUFFERSIZE 32
__mram int buffer[BUFFERSIZE];

int a=0; //use mutex to prevent race condition!
int checksums[NR_TASKLETS] = {0};
int main(){
    

for(int i = me()*NR_TASKLETS; i < (me()+1)*NR_TASKLETS; i++){
    checksums[i] += buffer[i];

}
barrier_wait(&my_barrier);
if(!me()){
        int checksum = 0;
        for(int i=0; i < NR_TASKLETS; i++){
        checksum += checksums[i];
        }
        printf("\n The checksum is %d \n", checksums[0]);
}


    /*
    mutex_lock(my_mutex);
    shared_var += 1;
    mutex_unlock(my_mutex);
    barrier_wait(&my_barrier);   
    if(!me())
        printf("\n The value of the shared var is %d! \n", shared_var);

        */
}