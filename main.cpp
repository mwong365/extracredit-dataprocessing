#include <iostream>
#include "Transaction.h"
#include "Transaction.cpp"

int main() {
    Transaction transaction;

    transaction.get("A");
    transaction.put("A",5);
    transaction.begin_transaction();
    transaction.put("A",5);
    cout<<transaction.get("A")<<endl;
    transaction.commit();
    transaction.put("A",6);
    transaction.commit();
    cout<<transaction.get("A")<<endl;
    transaction.commit();
    transaction.rollback();
    cout<<transaction.get("B")<<endl;
    transaction.begin_transaction();
    transaction.put("B",10);
    transaction.rollback();
    transaction.rollback();
}
