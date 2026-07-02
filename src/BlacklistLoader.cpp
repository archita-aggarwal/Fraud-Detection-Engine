#include "D:/archita/CODES/FraudDetectionEngine/include/BlacklistLoader.h"

#include <fstream>
#include <sstream>

using namespace std;

unordered_set<string>
BlacklistLoader::loadMerchants(string filename)
{
    unordered_set<string> merchants;

    ifstream file(filename);

    string line;

    getline(file,line);

    while(getline(file,line))
    {
        if(!line.empty())
            merchants.insert(line);
    }

    return merchants;
}