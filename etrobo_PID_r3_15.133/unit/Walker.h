/******************************************************************************
 *  Walker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class Walker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_UNIT_WALKER_H_
#define EV3_UNIT_WALKER_H_

#include "Motor.h"

class Walker {
public:
    static const int LOW;
    static const int NORMAL;
    static const int HIGH;
    // 変更
    static const int MAX;
    
    static const int RIGHT;
    static const int LEFT;
    // 変更
    static const int BACKWARD;

    Walker(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel);

    void init();
    void run();
    // 変更
    void terminate();

    void setCommand(int forward, int turn);

    void setPID(int pwm_l, int pwm_r); //木村
    
    // 変更
    void setCommand_B(int forward);

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int mForward;
    int mTurn;
};

#endif  // EV3_UNIT_WALKER_H_

