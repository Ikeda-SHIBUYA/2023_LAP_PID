/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "LineMonitor.h"
#include "Walker.h"
#include "Motor.h"

class LineTracer {
public:
    LineTracer(const LineMonitor* lineMonitor, // LineMonitor クラスのオブジェクトへのポインタ
               Walker* walker); // Walker クラスのオブジェクトへのポインタ

    void run();

private:
    const LineMonitor* mLineMonitor; // LineMonitor クラスのオブジェクトへのポインタ
    Walker* mWalker; // Walker クラスのオブジェクトへのポインタ
    
    bool mIsInitialized;

    #ifndef MAKE_RASPIKE
        const int8_t pwm = 100;
    #else
        const int8_t pwm = 100;
    #endif
};

#endif  // EV3_APP_LINETRACER_H_

