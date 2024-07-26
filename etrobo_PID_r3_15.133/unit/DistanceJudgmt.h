#ifndef EV3_UNIT_DISTANCEJUDGMT_H_
#define EV3_UNIT_DISTANCEJUDGMT_H_

#include "SonarSensor.h"

// 定義
class DistanceJudgmt {
public:
    // DistanceJudgmtクラスのコンストラクタ
    // 引数としてev3api::SonarSensorクラスの参照を受け取る
    explicit DistanceJudgmt(const ev3api::SonarSensor& sonarSensor);
    // ev3api 名前空間内の SonarSensor クラスのオブジェクトへの参照


    bool DistanceJudgmtValue() const; // 指定の距離に到達したかの判定値

    //void startDistance(int16_t Distance); // 開始時の場所を取得する

    //void settargetDistance(int16_t targetDistance); // 25点の場所までの距離


private:
    static const int16_t TARGET_DISTANCE;

    const ev3api::SonarSensor& mSonarSensor;
    int16_t mDistance;

};

#endif  // EV3_UNIT_DISTANCEJUDGMT_H_
