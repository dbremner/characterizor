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
#include "ZPDivisions.h"

static int ZPNothing(void* ctx)
{
    return 42;
}

void ZPBasicScen(void)
{
    ZPFloatReduce_ctx sum = { (1<<20), ZPReductorSum };

    ZPFloatReduceSum_ctx sumIters = { (1<<20) };
    uint32_t divisionIterations = 1000000;

    
    ZPChronometer(ZPNothing, NULL);
    
    ZPFloatReduce(&sum);
    ZPChronometer(ZPFloatReduce, &sum);

    ZPFloatReduceSum(&sumIters);
    ZPChronometer(ZPFloatReduceSum, &sumIters);

    ZPDivisions(&divisionIterations);
    ZPChronometer(ZPDivisions, &divisionIterations);
    ZPUnrolledDivisions(&divisionIterations);
    ZPChronometer(ZPUnrolledDivisions, &divisionIterations);
    ZPParallelDivisions(&divisionIterations);
    ZPChronometer(ZPParallelDivisions, &divisionIterations);
}

