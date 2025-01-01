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

public:
    void addDrug() {
        Drug newDrug;
        newDrug.id = drugCounter++;
        cout << "Enter drug name: ";
        cin.ignore();
        getline(cin, newDrug.name);
        cout << "Enter drug price: ";
        cin >> newDrug.price;
        cout << "Enter drug quantity: ";
        cin >> newDrug.quantity;
        drugs.push_back(newDrug);
        cout << "Drug added successfully!\n";
    }

   void displayDrugs() {
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        for (const auto &drug : drugs) {
            cout << setw(10) << drug.id << setw(20) << drug.name << setw(10) << drug.price << setw(10) << drug.quantity << endl;
        }
    }

    void sellDrug() {
        int drugId, quantity;
        cout << "Enter drug ID: ";
        cin >> drugId;
        cout << "Enter quantity to sell: ";
        cin >> quantity;

        for (auto &drug : drugs) {
            if (drug.id == drugId) {
                if (drug.quantity >= quantity) {
                    drug.quantity -= quantity;
                    double totalPrice = quantity * drug.price;
                    sales.push_back({drugId, quantity, totalPrice});
                    cout << "Sale successful! Total Price: " << totalPrice << "\n";
                } else {
                    cout << "Insufficient stock!\n";
                }
                return;
            }
        }
        cout << "Drug not found!\n";
    }

    void displaySales() {
        cout << left << setw(10) << "Drug ID" << setw(15) << "Quantity Sold" << setw(15) << "Total Price" << endl;
        for (const auto &sale : sales) {
            cout << setw(10) << sale.drugId << setw(15) << sale.quantitySold << setw(15) << sale.totalPrice << endl;
        }
    }

 void createPrescription() {
        Prescription newPrescription;
        newPrescription.id = prescriptionCounter++;
        int numDrugs;
        cout << "Enter number of drugs in the prescription: ";
        cin >> numDrugs;

        for (int i = 0; i < numDrugs; i++) {
            int drugId, quantity;
            cout << "Enter drug ID: ";
            cin >> drugId;
            cout << "Enter quantity: ";
            cin >> quantity;
            newPrescription.drugIds.push_back(drugId);
            newPrescription.quantities.push_back(quantity);
        }
        prescriptions.push_back(newPrescription);
        cout << "Prescription created successfully!\n";
    }

   