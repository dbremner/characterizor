//
//  ZPFloatTests.c
//  Characterizor
//
//  Created by Pierre Lebeaupin on 21/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#include "ZPFloatTests.h"


#define ZP_FLOAT_REDUCE_TEMPLATE \
int ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME(void* ctx) \
{ \
    ZP_FLOAT_REDUCE_TEMPLATE__INIT; \
    size_t i, j; \
    float f1 = 1.0f, f2 = 2.0f, f3 = 3.0f, f4 = 4.0f; \
    float reduced = 0.0f; \
     \
    for (i = 0; i+3 < ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS; i+=4) \
    { \
        reduced = ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(reduced, f1), f2), f3), f4); \
        f1 += 4.0f; \
        f2 += 4.0f; \
        f3 += 4.0f; \
        f4 += 4.0f; \
    } \
     \
    for (j = i; j < ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS; j++) \
    { \
        reduced = ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(reduced, f1); \
        f1 += 1.0f; \
    } \
     \
    return *((int*)(&reduced)); \
}



#define ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME        ZPFloatReduce
#define ZP_FLOAT_REDUCE_TEMPLATE__INIT            ZPFloatReduce_ctx c = *((ZPFloatReduce_ctx*)ctx)
#define ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS      c.iterations
#define ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(a, b)  c.reductor(a, b)

ZP_FLOAT_REDUCE_TEMPLATE

#undef ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME
#undef ZP_FLOAT_REDUCE_TEMPLATE__INIT
#undef ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS
#undef ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR



float ZPReductorSum(float soFar, float newItem)
{
    return soFar+newItem;
}


float ZPReductorSumOfSquares(float soFar, float newItem)
{
    return soFar + newItem*newItem;
}



#define ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME        ZPFloatReduceSum
#define ZP_FLOAT_REDUCE_TEMPLATE__INIT            ZPFloatReduceSum_ctx c = *((ZPFloatReduceSum_ctx*)ctx)
#define ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS      c.iterations
#define ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(a, b)  (a+b)

ZP_FLOAT_REDUCE_TEMPLATE

#undef ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME
#undef ZP_FLOAT_REDUCE_TEMPLATE__INIT
#undef ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS
#undef ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR




#define ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME        ZPFloatReduceSumOfSquares
#define ZP_FLOAT_REDUCE_TEMPLATE__INIT            ZPFloatReduceSumOfSquares_ctx c = *((ZPFloatReduceSumOfSquares_ctx*)ctx)
#define ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS      c.iterations
#define ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR(a, b)  (a+(b*b))

ZP_FLOAT_REDUCE_TEMPLATE

#undef ZP_FLOAT_REDUCE_TEMPLATE__FUNCNAME
#undef ZP_FLOAT_REDUCE_TEMPLATE__INIT
#undef ZP_FLOAT_REDUCE_TEMPLATE__ITERATIONS
#undef ZP_FLOAT_REDUCE_TEMPLATE__REDUCTOR


