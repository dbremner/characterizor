//
//  ZPFloatTests.h
//  Characterizor
//
//  Created by Pierre Lebeaupin on 21/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#ifndef Characterizor_ZPFloatTests_h
#define Characterizor_ZPFloatTests_h

#include "string.h"



typedef float (*ZPReductorFuncPtr)(float soFar, float newItem);


int ZPFloatReduce(void* ctx);

typedef struct
{
    size_t iterations;
    ZPReductorFuncPtr reductor;
} ZPFloatReduce_ctx;


float ZPReductorSum(float soFar, float newItem);

float ZPReductorSumOfSquares(float soFar, float newItem);





typedef struct
{
    size_t iterations;
} ZPFloatReduceSum_ctx;

int ZPFloatReduceSum(void* ctx);




typedef struct
{
    size_t iterations;
} ZPFloatReduceSumOfSquares_ctx;

int ZPFloatReduceSumOfSquares(void* ctx);



#endif

