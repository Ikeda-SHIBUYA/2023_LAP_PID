/******************************************************************************
 *  LineMonitor.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineMonitor
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineMonitor.h"

// 定数宣言
const int8_t LineMonitor::INITIAL_THRESHOLD = 20;  // トレースホールド黒色の光センサ値
const colorid_t LineMonitor::END_THRESEND = COLOR_BLUE;  // トレースエンド赤色



/**
 * コンストラクタ
 * @param colorSensor カラーセンサ
 */
LineMonitor::LineMonitor(const ev3api::ColorSensor& colorSensor)
    : mColorSensor(colorSensor),
      mThreshold(INITIAL_THRESHOLD),
      mThresend(END_THRESEND) {
        diff[0] = 0;
        diff[1] = 0;
        // diff_sum = 0;
}

/**
 * ライン上か否かを判定する
 * @retval true  ライン上
 * @retval false ライン外
 */
bool LineMonitor::isOnLine() const {
    // 光センサからの取得値を見て
    // 黒以上であれば「true」を、
    // そうでなければ「false」を返す
    if (mColorSensor.getBrightness() >= mThreshold) {
        return true;
    } else {
        return false;
    }
}

// 変更
/**
 * ブロック運びを行うか判定する
 * @retval true ブロック運び開始地点
 * @retval false LineTracer続行
*/
bool LineMonitor::startSokoban() const{
    // 光センサからの取得値を見て
    // 赤であれば「true」を、
    // そうでなければ「false」を返す
    if(mColorSensor.getColorNumber() == mThresend){
        printf("赤\n");
        return true;
    } else {
        return false;
    }
}

/**
 * ライン閾値を設定する
 * @param threshold ライン閾値
 */
void LineMonitor::setThreshold(int8_t threshold) {
    mThreshold = threshold;
}

/**
 * ライントレース終了閾値を設定する
 * @param thresend 
*/
void LineMonitor::setThresend(colorid_t thresend) {
    mThresend = thresend;
}

float LineMonitor::calc_prop_value() const { //木村
    const float Kp = 5.41; // 3.5
    const float Ki = 0.5; //0.035
    const float Kd = 128; //0.3
    // const double target = 16; // <2>  20.94-pwd stable   27.5-1.2*pwd quick
    const double target = 23;
    double i = 0;
    double p, d;
    // double diff_0;
    // double diff_1;
    double sum = 0;
    double diff_sum = 0.0;

    diff[1] = diff[0];
    diff[0] = target - mColorSensor.getBrightness(); // <3>
    // diff_0 = mColorSensor.getBrightness() - target;

    diff_sum += diff[0];

    p = diff[0] * Kp;
    i = diff_sum * Ki;
    d = (diff[0] - diff[1]) * Kd;
    sum = p + i + d;

    return sum; // <4>
}
