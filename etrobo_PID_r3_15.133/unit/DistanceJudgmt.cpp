#include "DistanceJudgmt.h"

const int16_t DistanceJudgmt::TARGET_DISTANCE = 19; // 25点の距離

/**
 * コンストラクタ
 * @param sonarSensor ソナーセンサ
 */
DistanceJudgmt::DistanceJudgmt(const ev3api::SonarSensor& sonarSensor) 
// DistanceJudgmtクラスのインスタンスを生成
// ev3api::SonarSensorクラスを参照する引数をsonarSensorで生成

    : mSonarSensor(sonarSensor), // メンバ変数mSonarSensorを引数sonarSenorで初期化
      mDistance(TARGET_DISTANCE) {
    //　メンバ変数mDistanceを定数TARGET_DISTANCEで初期化
}


/**
 * 25点まで到達したか判定
 * @retval true  25点の距離
 * @retval false 25点以外の距離
 */
bool DistanceJudgmt::DistanceJudgmtValue() const {
    // ソナーセンサからの取得値を見て
    // 20であれば「true」を、
    // そうでなければ「false」を返す
    //printf("%d\n",mSonarSensor.getDistance()); //距離の表示
    if (mSonarSensor.getDistance() <= mDistance) {
        return true;
    } else {
        return false;
    }
}

/**
 * スタート地点の距離を設定
 * @param Distance スタート地点の距離
 */
//void DistanceJudgmt::startDistance(int16_t Distance) {
//    mDistance = distance;
//}



