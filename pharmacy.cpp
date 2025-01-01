#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Drug {
    int id;
    string name;
    double price;
    int quantity;
};
struct Sale {
    int drugId;
    int quantitySold;
    double totalPrice;
};

struct Prescription {
    int id;
    vector<int> drugIds;
    vector<int> quantities;
};

