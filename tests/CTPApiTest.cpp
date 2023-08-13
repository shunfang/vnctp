#include <string>
#include <iostream>

#include "ThostFtdcTraderApi.h"

using namespace std;

int main(){
    CThostFtdcTraderApi* api = CThostFtdcTraderApi::CreateFtdcTraderApi("./");
    cout << CThostFtdcTraderApi::GetApiVersion() << endl;
}

// compile command:
// g++ ./tests/CTPApiTest.cpp -o test -L./lib -lthosttraderapi_se -I ./include/ctp/
