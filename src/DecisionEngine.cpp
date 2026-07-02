#include "D:/archita/CODES/FraudDetectionEngine/include/DecisionEngine.h"

using namespace std;

string DecisionEngine::getDecision(int score)
{

    if(score<30)
        return "APPROVED";

    if(score<60)
        return "MANUAL REVIEW";

    return "REJECTED";
}