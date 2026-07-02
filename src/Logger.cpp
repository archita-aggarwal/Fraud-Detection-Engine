#include "D:/archita/CODES/FraudDetectionEngine/include/Logger.h"

#include <fstream>
#include <ctime>

using namespace std;

void Logger::log(string message)
{
    ofstream file(
        "D:/archita/CODES/FraudDetectionEngine/logs/fraud.log",
        ios::app);

    time_t now = time(0);

    file << ctime(&now)
         << " : "
         << message
         << endl;

    file.close();
}