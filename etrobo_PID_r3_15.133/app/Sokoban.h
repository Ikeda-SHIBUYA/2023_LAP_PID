#ifndef EV3_APP_SOKOBAN_H_
#define EV3_APP_SOKOBAN_H_

#include "DistanceJudgmt.h"
#include "Walker.h"

class Sokoban {
public:
    Sokoban(const DistanceJudgmt* DistanceJudgmt, // DistanceJudgmt クラスのオブジェクトへのポインタ
               Walker* walker); // Walker クラスのオブジェクトへのポインタ

    void run();

private:
    const DistanceJudgmt* mDistanceJudgmt; // DistanceJudgmt クラスのオブジェクトへのポインタ
    Walker* mWalker; // Walker クラスのオブジェクトへのポインタ

    bool mIsInitialized;

    //int calcDirection(bool DistanceJudgmntValue);
};

#endif  // EV3_APP_SOKOBAN_H_

