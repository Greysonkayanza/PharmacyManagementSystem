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
class PharmacyManagement {
private:
    vector<Drug> drugs;
    vector<Sale> sales;
    vector<Prescription> prescriptions;
    int drugCounter = 1;
    int prescriptionCounter = 1;

