//
// Clock.h
//
// Copyright (c) 2015-2016 Embedded Technology Software Design Robot Contest
//
 
#ifndef EV3CPPAPI_CLOCK_H_
#define EV3CPPAPI_CLOCK_H_
 
#include "ev3api.h"
 
namespace ev3api {
/**
 * EV3 クロッククラス
 */
class Clock
{
public:
    /**
     * コンストラクタ
     * 開始時間をシステム時刻で初期化する
     * @param -
     * @return -
     */
    Clock(void);

    /**
     * リセット
     * 開始時間を現在のシステム時刻でリセットする
     * @param -
     * @return -
     */ 
    void reset(void);

    /**
     * 経過時間取得
     * 開始時間からの経過時間を取得する
     * @param -
     * @return 経過時間[usec]
     */ 
    uint64_t now(void) const;

    /**
     * 自タスク遅延
     * @param duration 遅延時間[usec]
     * @return -
     */ 
    inline void wait(uint64_t duration)
    {
        dly_tsk(duration);
    }

    /**
     * 自タスクスリープ
     * @param duration スリープ時間[usec]
     * @return -
     */ 
    inline void sleep(uint64_t duration)
    {
        tslp_tsk(duration);
    }
 
protected:
    /**
     * システム時刻取得
     * @param -
     * @return 現在のシステム時刻[usec]
     */
    static uint64_t getTim();
 
private:
    uint64_t mStartClock;
}; // class Clock
}  // namespace ev3api
 
#endif // !EV3CPPAPI_CLOCK_H_