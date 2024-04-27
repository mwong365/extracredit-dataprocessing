#include "Transaction.h"
using namespace std;

int Transaction::get(string key) {
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->key == key) {
            return it->value;
        }
    }
    throw std::invalid_argument("Key does not exist.");
}
void Transaction::put(string key, int val) {
    bool found = false;
    if (transaction) {
        for (auto it = temp.begin(); it != temp.end(); ++it) {
            if (it->key == key) {
                found = true;
                it->value = val;
                return;
            }
        }
        if (!found) {
            temp.push_back(account{key, val});
            return;
        }
    } else {
        throw std::invalid_argument("No transaction in progress.");
    }
}
void Transaction::begin_transaction() {
    if (!transaction) {
        transaction = true;
        return;
    } else {
        throw std::invalid_argument("Transaction already in progress.");
    }
}
void Transaction::commit() {
    if (transaction) {
        transaction = false;
        string tempkey = "";
        int tempvalue = 0;
        for (auto it = temp.begin(); it != temp.end(); ++it) {
            bool found = false;
            tempkey = it->key;
            tempvalue = it->value;
            for (auto it2 = database.begin(); it2 != database.end(); ++it2) {
                if (it2->key == it->key) {
                    it2->value = it->value;
                    found = true;
                }
            }
            if (!found) {
                database.push_back(account{tempkey, tempvalue});
            }
        }
        return;
    } else {
        throw std::invalid_argument("No transaction in progress.");
    }
}
void Transaction::rollback() {
    if (transaction) {
        transaction = false;
        return;
    } else {
        throw std::invalid_argument("No transaction in progress.");
    }
}