#include <stdio.h>
#include <dpu.h>
#include <dpu_log.h>
#include <assert.h>

#define BINARY "helloworld"

int main(){
    struct dpu_set_t set, dpu;
    DPU_ASSERT(dpu_alloc(1,NULL,&set));    
    DPU_ASSERT(dpu_load(set,BINARY,NULL));
    DPU_ASSERT(dpu_launch(set,DPU_SYNCHRONOUS));
    DPU_FOREACH(set, dpu){
    DPU_ASSERT(dpu_log_read(dpu,stdout));
    }
    DPU_ASSERT(dpu_free(set));

     

}