//
//  ZPChronometer.c
//  Characterizor
//
//  Created by Pierre Lebeaupin on 20/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#include "ZPChronometer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/time.h>

#include "ZPSupport.h"


void ZPChronometerFull(ZPRunnerFuncPtr runner, char* runnerName, void* runnerCtx, char* runnerCtxName)
{
    struct timeval start, stop;
    int temp;
    int32_t diff;
    
    gettimeofday(&start, NULL);
    temp = (*runner)(runnerCtx);
    gettimeofday(&stop, NULL);
    
    gAnchoringSink = temp;
    
    
    diff = (int)(stop.tv_sec - start.tv_sec);
    diff *= 1000000;
    diff += stop.tv_usec;
    diff -= start.tv_usec;
    
    
    printf("%s(%s) was measured to take %s%ld.%03ld ms\n", runnerName, runnerCtxName,
           ( diff<0 ? "-" : "" ), labs((long)diff)/1000, labs((long)diff)%1000);
}
