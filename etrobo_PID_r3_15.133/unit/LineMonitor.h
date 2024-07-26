/******************************************************************************
 *  LineMonitor.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineMonitor
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_UNIT_LINEMONITOR_H_
#define EV3_UNIT_LINEMONITOR_H_

#include "ColorSensor.h"

// 定義
class LineMonitor {
public:
    explicit LineMonitor(const ev3api::ColorSensor& colorSensor);
    // ev3api 名前空間内の ColorSensor クラスのオブジェクトへの参照

    bool isOnLine() const; // ライン上か判定
    void setThreshold(int8_t threshold); // ライントレースの閾値を設定する

    // 変更
    void setThresend(colorid_t thresend); // ライントレース終了時に検知する色を設定
    bool startSokoban() const; // LineTracr→Sokoban移行判定メソッド
    float calc_prop_value() const; //木村

private:
    static const int8_t INITIAL_THRESHOLD;

    const ev3api::ColorSensor& mColorSensor;
    int8_t mThreshold;
    
    static const colorid_t END_THRESEND;
    colorid_t mThresend;
    mutable double diff[2];
    // mutable double diff_sum;
};

#endif  // EV3_UNIT_LINEMONITOR_H_

