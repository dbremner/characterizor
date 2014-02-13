//
//  ZPBasicScen.c
//  Characterizor
//
//  Created by Pierre Lebeaupin on 21/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#include "ZPBasicScen.h"

#include <stdlib.h>

#include "ZPChronometer.h"
#include "ZPFloatTests.h"

static int ZPNothing(void* ctx)
{
    return 42;
}

void ZPBasicScen(void)
{
    ZPFloatReduce_ctx sum = { (1<<20), ZPReductorSum };

    ZPFloatReduceSum_ctx sumIters = { (1<<20) };

    
    ZPChronometer(ZPNothing, NULL);
    
    
    ZPChronometer(ZPFloatReduce, &sum);

    ZPChronometer(ZPFloatReduceSum, &sumIters);

}