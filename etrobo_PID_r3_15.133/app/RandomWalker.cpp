/******************************************************************************
 *  RandomWalker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include <stdlib.h>
//#include <iostream>
#include "Clock.h"

#include "RandomWalker.h"

// 定数宣言
const int RandomWalker::MIN_TIME = 5000 * 1000;    // 切り替え時間の最小値
const int RandomWalker::MAX_TIME = 15000 * 1000;   // 切り替え時間の最大値

/**
 * コンストラクタ
 * @param lineTracer      ライントレーサ
 * @param scenarioTracer  シナリオトレーサ
 * @param starter         スタータ  
 * @param simpleTimer     タイマ
 * // 変更
 * @param Sokoban         ブロック運搬
 * @param LineMonitor     ライン監視部
 * @param DistanceJudgmt　距離監視部
 */
RandomWalker::RandomWalker(LineTracer* lineTracer,
                           ScenarioTracer* scenarioTracer,
                           const Starter* starter,
                           SimpleTimer* simpleTimer,
                           // 変更
                           Sokoban* sokoban,
                           const LineMonitor* lineMonitor,
                           const DistanceJudgmt* distanceJudgmt,
                           Walker* walker)

    : mLineTracer(lineTracer),
      mScenarioTracer(scenarioTracer),
      mStarter(starter),
      mSimpleTimer(simpleTimer),
      
      // 変更
      mSokoban(sokoban),
      mlineMonitor(lineMonitor),
      mdistanceJudgmt(distanceJudgmt),
      mWalker(walker),
      mState(UNDEFINED){
    ev3api::Clock* clock = new ev3api::Clock();

    //srand(clock->now());  // 乱数をリセットする

    delete clock;
}


/**
 * ランダム走行する
 */
void RandomWalker::run() {
    switch (mState) {
    case UNDEFINED:
        //printf("%d\n",mState);
        execUndefined();
        break;
    case WAITING_FOR_START:
        //printf("%d\n",mState);
        execWaitingForStart();
        break;
    case LINE_TRACING:
        //printf("%d\n",mState);
        execLineTracing();
        break;
    case SCENARIO_TRACING:
        //printf("%d\n",mState);
        execScenarioTracing();
        break;
    // 変更
    case SOKOBAN:
        //printf("%d\n",mState);
        execSokoban();
    default:
        break;
    }
}

/**
 * 乱数を取得する
 * @retrun 乱数
 */
/*
int RandomWalker::getRandomTime() {
    return MIN_TIME +
        static_cast<int>(static_cast<double>(rand()) *
                         (MAX_TIME - MIN_TIME + 1.0) / (1.0 + RAND_MAX));
}
*/

/**
 * シーン変更処理
 */
/*
void RandomWalker::modeChangeAction() {
    //mSimpleTimer->setTime(getRandomTime());
    //mSimpleTimer->start();
}
*/

/**
 * 未定義状態の処理
 */
void RandomWalker::execUndefined() {
    mState = WAITING_FOR_START;
}

/**
 * 開始待ち状態の処理
 */
void RandomWalker::execWaitingForStart() { //ここでシナリオからスタート
    if (mStarter->isPushed()) {
        mState = LINE_TRACING; //シナリオ・ラインの管理はmStateの変更で行う
        // mSimpleTimer->setTime(16650*1000);
        mSimpleTimer->setTime(19000*1000);
        mSimpleTimer->start();
    }else {
        mState = WAITING_FOR_START;
    }
    //mState = LINE_TRACING;
    
}

/**
 * ライントレース状態の処理
 */
void RandomWalker::execLineTracing() {
    
    // 変更
    /*
    if (mSimpleTimer->isTimedOut()) {
        mSimpleTimer->stop();

        mState = SCENARIO_TRACING;
    }
    */
        
        //modeChangeAction();
    
    if (mSimpleTimer->isTimedOut()) {
    // if (mlineMonitor->startSokoban()) {
        mSimpleTimer->stop();

        mWalker->terminate();
        mState = SOKOBAN;
        // printf("ブロック運びへ移行\n");
    }
    mLineTracer->run(); //木村追加
}

// 変更
/**
 * ブロック運搬状態の処理
*/
void RandomWalker::execSokoban(){
    
    if(mdistanceJudgmt->DistanceJudgmtValue()){
        mState = SCENARIO_TRACING;
        // printf("シナリオトレースへ移行\n");
    }
    mSokoban->run(); //木村追加
}


/**
 * シナリオトレース状態の処理
 */
void RandomWalker::execScenarioTracing() {
    mScenarioTracer->run();
    //mState = SCENARIO_TRACING;

    // 変更
    /*
    if (mSimpleTimer->isTimedOut()) {
        mSimpleTimer->stop();

        mState = LINE_TRACING;

        modeChangeAction();
    }
    */
}
