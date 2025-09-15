#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rez;
    float mediana;
};

// Funkcijų deklaracijos
Studentas ivesk();
Studentas iveskIsFailo(const string &line);
vector<Studentas> skaitytiIsFailo(const string &failoPavadinimas);
float skaiciuotiMediana(vector<int> &pazymiai);

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
            cout << temp.vard << " | " << temp.pav << " | " << temp.rez << "|" << temp.mediana <<endl;
    }

    string failoVardas = "studentai.txt";
    vector<Studentas> GrupeIsFailo = skaitytiIsFailo(failoVardas);

    cout << "\n--- Studentai (skaityta is failo) ---\n";
    for (auto &temp : GrupeIsFailo)
        cout << temp.vard << " | " << temp.pav << " | " << temp.rez << "|" << temp.mediana <<endl;

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
    Laik.mediana = skaiciuotiMediana(Laik.paz);

    return Laik;
}

// Funkcija vienos eilutes skaitymui is failo
Studentas iveskIsFailo(const string &line) {
    Studentas Laik;
    Laik.paz.resize(15); 

    istringstream in(line);
    in >> Laik.vard >> Laik.pav;
    int sum = 0;
    for (int i = 0; i < 15; i++) {
        in >> Laik.paz[i];
        sum += Laik.paz[i];
    }
    in >> Laik.egzas;
    Laik.rez = Laik.egzas * 0.6 + (float)sum / 15 * 0.4;
    Laik.mediana = skaiciuotiMediana(Laik.paz);

    return Laik;
}

// Funkcija viso failo skaitymui
vector<Studentas> skaitytiIsFailo(const string &failoPavadinimas) {
    vector<Studentas> GrupeIsFailo;
    ifstream failas(failoPavadinimas);
    if (!failas) {
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return GrupeIsFailo;
    }

    string line;
    getline(failas, line);

    while (getline(failas, line)) {
        if (!line.empty())
            GrupeIsFailo.push_back(iveskIsFailo(line));
    }

    return GrupeIsFailo;
}

// Funkcija medianai skaiciuoti
float skaiciuotiMediana(vector<int> &pazymiai) {
    vector<int> temp = pazymiai;
    std::sort(temp.begin(), temp.end());
    int n = temp.size();
    if (n % 2 == 0)
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    else
        return temp[n/2];
}