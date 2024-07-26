/******************************************************************************
 *  RandomWalker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_RANDOMWALKER_H_
#define EV3_APP_RANDOMWALKER_H_

#include "Starter.h"
#include "SimpleTimer.h"

#include "LineTracer.h"
#include "ScenarioTracer.h"
// 変更
#include "Sokoban.h"
#include "LineMonitor.h"
#include "DistanceJudgmt.h"
#include "Walker.h"


class RandomWalker {
public:
    RandomWalker(LineTracer* lineTracer,
                 ScenarioTracer* scenarioTracer,
                 const Starter* starter,
                 SimpleTimer* simpleTimer,

                 // 変更
                 Sokoban* sokoban,
                 const LineMonitor* lineMonitor,
                 const DistanceJudgmt* distanceJudgmt,
                 Walker* walker);

    void run();

private:
    enum State {
        UNDEFINED,
        WAITING_FOR_START,
        LINE_TRACING,
        SCENARIO_TRACING,
        // 変更
        SOKOBAN
    };

    static const int MIN_TIME;
    static const int MAX_TIME;

    // koko
    LineTracer* mLineTracer;
    ScenarioTracer* mScenarioTracer;
    const Starter* mStarter;
    SimpleTimer* mSimpleTimer;
    // 変更
    Sokoban* mSokoban;
    const LineMonitor* mlineMonitor;
    const DistanceJudgmt* mdistanceJudgmt;
    Walker* mWalker;

    State mState;

    //int getRandomTime();
    void modeChangeAction();
    void execUndefined();
    void execWaitingForStart();
    void execLineTracing();
    void execScenarioTracing();
    // 変更
    void execSokoban();
    int JudgeSokoban(bool startSokoban);

};

#endif  // EV3_APP_RANDOMWALKER_H_

