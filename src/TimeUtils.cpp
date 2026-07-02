#include "D:/archita/CODES/FraudDetectionEngine/include/TimeUtils.h"

using namespace std;

int TimeUtils::toMinutes(string time)
{
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));

    return hour*60 + minute;
}