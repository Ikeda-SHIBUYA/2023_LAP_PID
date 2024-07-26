
#include "Sokoban.h"

//const int16_t DistanceJudgmt::DISTANCE = 20; // スタート地点の距離

/**
 * コンストラクタ
 * @param DistanceJudgmt 距離判定
 * @param walker 走行
 */
// Sokobanクラスのインスタンスを生成
Sokoban::Sokoban(const DistanceJudgmt* distanceJudgmt, // DistanceJudgmtクラスへのポインタを引数として受け取る
                       Walker* walker) // Walkerクラスへのポインタを引数として受け取る

    : mDistanceJudgmt(distanceJudgmt), // メンバ変数mDistanceJudgmtを引数distanceJudgmtで初期化
      //sDistance(DISTANCE),
      mWalker(walker), // メンバ変数mWalkerを引数walkerで初期化

      mIsInitialized(false) { // メンバ変数mIsInitializedをfalseで初期化
}

/**
 * ブロック運びをする
 */
void Sokoban::run() {
    if (mIsInitialized == false) {
        mWalker->init();
        //printf("初期化\n");
        mIsInitialized = true;
    }

    bool DistanceJudgmtValue = mDistanceJudgmt->DistanceJudgmtValue();
    // 変数DistanceJudgmtValueは、mDistanceJudgmt（DistanceJudgmtクラスへのポインタ)
    // メソッドDistanceJudgmtValue()の戻り値を格納する

    if (DistanceJudgmtValue == true) {

        // 走行体の向きを計算する
        //int direction = calcDirection(DistanceJudgmtValue);

        //mWalker->setCommand_B(Walker::LOW/*, direction*/);
        // 走行をやめる
        mWalker->terminate();

    } else {

        // 走行体の向きを計算する
        //int direction = calcDirection(DistanceJudgmtValue);

        mWalker->setCommand_B(Walker::LOW/*, direction*/);
        // 走行を行う
        mWalker->run();

    }
    
}

