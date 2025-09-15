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
string formatuoti(string s, int plotis);

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
        cout << "|" << formatuoti("Vardas", 14) << "|" << formatuoti(" Pavarde", 15) << "|"
             << formatuoti("Vidurkis", 10) << "|" << formatuoti("Mediana", 9) << "|\n";
        cout << "-----------------------------------------------------\n";
        for (auto &temp : Grupe)
            cout << "|" << formatuoti(temp.vard, 14) << "|" << formatuoti(temp.pav, 15) << "|"
                 << formatuoti(std::to_string(temp.rez), 10) << "|" << formatuoti(std::to_string(temp.mediana), 9) << "|\n";
    }

    string failoVardas = "studentai.txt";
    vector<Studentas> GrupeIsFailo = skaitytiIsFailo(failoVardas);

    cout << "\n--- Studentai (skaityta is failo) ---\n";
    cout << "|" << formatuoti("Vardas", 14) << "|" << formatuoti(" Pavarde", 15) << "|"
             << formatuoti("Vidurkis", 10) << "|" << formatuoti("Mediana", 9) << "|\n";
    cout << "-----------------------------------------------------\n";
    for (auto &temp : GrupeIsFailo)
        cout << "|" << formatuoti(temp.vard, 14) << "|" << formatuoti(temp.pav, 15) << "|"
                 << formatuoti(std::to_string(temp.rez), 10) << "|" << formatuoti(std::to_string(temp.mediana), 9) << "|\n";

    return 0;
}

// Funkcija studento ivedimui rankiniu budu
Studentas ivesk() {
    Studentas Laik;
    cout << "Ivesk varda: "; getline(cin, Laik.vard);
    cout << "Ivesk pavarde: "; getline(cin, Laik.pav);
    cout << "Iveskite namu darbu pazymius po viena. Kai baigsite, tiesiog paspauskite ENTER:\n";
    string temp;
    Laik.paz.clear();

    while (true) {
        cout << "Pazymys: ";
        getline(cin, temp);
        if (temp.empty()) break;
        try {
            int paz = std::stoi(temp);
            Laik.paz.push_back(paz);
        } catch (...) {
            cout << "Klaida: iveskite skaiciu arba paspauskite ENTER, kad baigti.\n";
        }
    }
    if (Laik.paz.empty()) {
        cout << "Studentas neturi namu darbu. Bus naudojamas 0.\n";
        Laik.paz.push_back(0);
    }
    while (true) {
        cout << "Iveskite egzamino bala: ";
        getline(cin, temp);
        try {
            Laik.egzas = std::stoi(temp);
            break;
        } catch (...) {
            cout << "Klaida: iveskite skaiciu!\n";
        }
    }

    int sum = 0;
    for (int p : Laik.paz) sum += p;
    Laik.rez = Laik.egzas * 0.6 + (float)sum / Laik.paz.size() * 0.4;
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

// Funkcija, kuri prideda tarpų, kad stringas užimtų n simbolių
string formatuoti(string s, int plotis) {
    int tarpai = plotis - s.length();
    int kaire = tarpai / 2;
    int desine = tarpai - kaire;
    return string(kaire, ' ') + s + string(desine, ' ');
}