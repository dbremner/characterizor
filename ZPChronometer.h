//
//  ZPChronometer.h
//  Characterizor
//
//  Created by Pierre Lebeaupin on 20/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#ifndef Characterizor_ZPChronometer_h
#define Characterizor_ZPChronometer_h

#include "ZPTestModel.h"


#define ZPChronometer(daFunc, ctx) ZPChronometerFull(daFunc, #daFunc, (void*)ctx, #ctx)

void ZPChronometerFull(ZPRunnerFuncPtr runner, char* runnerName, void* runnerCtx, char* runnerCtxName);


#endif
