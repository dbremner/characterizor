//
//  ZPDivisions.c
//  Characterizor
//
//  Created by Pierre Lebeaupin on 14/02/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#include "ZPDivisions.h"

#include <stdint.h>



int ZPDivisions(void* context)
{
    uint32_t i, accum = 0;
    uint32_t iterations = *((uint32_t*)context);
    
    for (i = 0; i < 4*iterations; i+=1)
    {
        accum += (4*iterations)/(i+1);
    }
    
    return accum;
}



int ZPUnrolledDivisions(void* context)
{
    uint32_t i, accum = 0;
    uint32_t iterations = *((uint32_t*)context);
    
    for (i = 0; i < 4*iterations; i+=4)
    {
        accum += (4*iterations)/(i+1) + (4*iterations)/(i+2) + (4*iterations)/(i+3) + (4*iterations)/(i+4);
    }
    
    return accum;
}




int ZPParallelDivisions(void* context)
{
    uint32_t i, accum1 = 0, accum2 = 0, accum3 = 0, accum4 = 0;
    uint32_t iterations = *((uint32_t*)context);
    
    for (i = 0; i < 4*iterations; i+=4)
    {
        accum1 += (4*iterations)/(i+1);
        accum2 += (4*iterations)/(i+2);
        accum3 += (4*iterations)/(i+3);
        accum4 += (4*iterations)/(i+4);
    }
    
    return accum1 + accum2 + accum3 + accum4;
}

