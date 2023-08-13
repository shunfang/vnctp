#include <string>
#include <iostream>

#include "ThostFtdcTraderApi.h"

using namespace std;

int main(){
    CThostFtdcTraderApi* api = CThostFtdcTraderApi::CreateFtdcTraderApi("./");
    cout << CThostFtdcTraderApi::GetApiVersion() << endl;
}

//g++ ./tests/test.cpp -o test -L./lib -lthosttraderapi_se -I ./include/ctp/
