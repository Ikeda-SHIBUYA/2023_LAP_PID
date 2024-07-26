/******************************************************************************
 *  LineTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/26
 *  Implementation of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineTracer.h"

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param walker 走行
 */
LineTracer::LineTracer(const LineMonitor* lineMonitor,
                       Walker* walker) //木村追加
    : mLineMonitor(lineMonitor),
      mWalker(walker),
      mIsInitialized(false) {
}


/**
 * 走行体の向きを計算する
 * @param isOnLine true:ライン上/false:ライン外
 * @retval RIGHT  ライン上にある場合(右旋回指示)
 * @retval LEFT ライン外にある場合(左旋回指示)
 */


void LineTracer::run() //木村
{
    if (mIsInitialized == false) {
        mWalker->init();
        mIsInitialized = true;
    }

        float turn = mLineMonitor->calc_prop_value(); // <1>

        int pwm_l = pwm - turn; // <2>
        int pwm_r = pwm + turn; // <2>

        mWalker->setPID(pwm_l,pwm_r);
    //}
}