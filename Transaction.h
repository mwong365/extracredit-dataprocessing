#ifndef EXTRACREDIT_DATAPROCESSING_TRANSACTION_H
#define EXTRACREDIT_DATAPROCESSING_TRANSACTION_H
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


struct account {
    string key = "";
    int value = 0;
};

class Transaction {
    vector<account> temp;
    vector<account> database;
    bool transaction = false;
public:
    int get(string key);
    void put(string key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};


#endif //EXTRACREDIT_DATAPROCESSING_TRANSACTION_H
