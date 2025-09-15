#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rez;
};

// Funkcijų deklaracija
Studentas ivesk();

int main() {
    vector<Studentas> Grupe;
    string pasirinkimas;

    cout << "Ar norite prideti studentus rankiniu budu? (taip/ne): ";
    getline(cin, pasirinkimas);

    if (pasirinkimas == "taip" || pasirinkimas == "Taip" || pasirinkimas == "TAIP") {
        cout << "Kiek studentu norite prideti rankiniu budu? ";
        int kiek;
        string input;
        getline(cin, input);
        kiek = std::stoi(input);

        for (int j = 0; j < kiek; j++) {
            cout << "Iveskite " << j + 1 << " studenta:\n";
            Grupe.push_back(ivesk());
        }

        cout << "\n--- Studentai (isvedimas is konsoles) ---\n";
        for (auto &temp : Grupe)
            cout << temp.vard << " | " << temp.pav << " | " << temp.rez << endl;
    }

    return 0;
}

// Funkcija studentui rankiniu budu
Studentas ivesk() {
    Studentas Laik;
    cout << "Ivesk varda: "; getline(cin, Laik.vard);
    cout << "Ivesk pavarde: "; getline(cin, Laik.pav);

    cout << "Kiek pazymiu turi studentas: ";
    int n, sum = 0;
    string temp;
    getline(cin, temp);
    n = std::stoi(temp);

    Laik.paz.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << " pazymi: ";
        getline(cin, temp);
        Laik.paz[i] = std::stoi(temp);
        sum += Laik.paz[i];
    }

    cout << "Iveskite egzamino bala: ";
    getline(cin, temp);
    Laik.egzas = std::stoi(temp);

    Laik.rez = Laik.egzas * 0.6 + (float)sum / n * 0.4;
    return Laik;
}