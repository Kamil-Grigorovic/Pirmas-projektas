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

// Funkciju deklaracijos
Studentas ivesk();
Studentas iveskIsFailo(const string &line);
float skaiciuotiMediana(vector<int> &pazymiai);
string formatuoti(string s, int plotis);
vector<Studentas> skaitytiIsFailo(const string &failoPavadinimas);
Studentas generuokStudenta();
void rikiuotiPagalPavarde(vector<Studentas> &studentai);
void spausdintiIFaila(const vector<Studentas> &studentai, const string &failoVardas);
string SkaiciaiSuKableliu(float value);

int main() {
    vector<Studentas> visiStudentai;
    bool veikia = true;

    while (veikia) {
        string pasirinkimas;

        cout << "Pasirinkite veiksma:\n";
        cout << "1 - Ivesti studenta rankiniu budu\n";
        cout << "2 - Sugeneruoti studentus\n";
        cout << "3 - Ivesti studentus is failo\n";
        cout << "4 - Baigti programa\n";
        cout << "Jusu pasirinkimas: ";
        getline(cin, pasirinkimas);

        if (pasirinkimas == "1") {
            int kiek;
            while (true) {
                string input;
                cout << "Kiek studentu ivesti rankiniu budu? ";
                getline(cin, input);
                try {
                    kiek = std::stoi(input);
                    if (kiek > 0) break;
                } catch (...) {
                    cout << "Klaida: iveskite skaiciu!\n";
                }
            }

            for (int j = 0; j < kiek; j++)
                visiStudentai.push_back(ivesk());

        } else if (pasirinkimas == "2") {
            int kiek;
            while (true) {
                string input;
                cout << "Kiek atsitiktiniu studentu sugeneruoti? ";
                getline(cin, input);
                try {
                    kiek = std::stoi(input);
                    if (kiek > 0) break;
                } catch (...) {
                    cout << "Klaida: iveskite skaiciu!\n";
                }
            }

            for (int j = 0; j < kiek; j++)
                visiStudentai.push_back(generuokStudenta());

        } else if (pasirinkimas == "3") {
            string failoVardas;
            cout << "Iveskite failo pavadinima: ";
            getline(cin, failoVardas);
            vector<Studentas> isFailo = skaitytiIsFailo(failoVardas);
            visiStudentai.insert(visiStudentai.end(), isFailo.begin(), isFailo.end());

        } else if (pasirinkimas == "4") {
            veikia = false;
            break;
        }

        rikiuotiPagalPavarde(visiStudentai);
        spausdintiIFaila(visiStudentai, "rezultatai.txt");
    }

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
    istringstream in(line);

    in >> Laik.vard >> Laik.pav;
    vector<int> visiSkaiciai;
    string temp;
    while (in >> temp) { 
        try {
            size_t pos;
            int skaicius = std::stoi(temp, &pos);
            if (pos != temp.length()) {
                throw std::invalid_argument("Ne skaicius");
            }
            visiSkaiciai.push_back(skaicius);
        } catch (...) {
            cout << "Klaida faile: studento \"" << Laik.vard << " " << Laik.pav 
                 << "\" pazymys \"" << temp << "\" yra netinkamas!" << endl;
        }
    }

    if (visiSkaiciai.empty()) {
        cout << "Klaida: studentas \"" << Laik.vard << " " << Laik.pav 
             << "\" neturi pazymiu." << endl;
        Laik.egzas = 0;
        Laik.rez = 0;
        Laik.mediana = 0;
        return Laik;
    }

    Laik.egzas = visiSkaiciai.back();
    visiSkaiciai.pop_back();
    Laik.paz = visiSkaiciai;

    int sum = 0;
    for (int p : Laik.paz) sum += p;
    float vid = (Laik.paz.empty()) ? 0 : (float)sum / Laik.paz.size();
    Laik.rez = Laik.egzas * 0.6 + vid * 0.4;
    Laik.mediana = skaiciuotiMediana(Laik.paz);

    return Laik;
}

// Funkcija viso failo skaitymui
vector<Studentas> skaitytiIsFailo(const string &failoPavadinimas) {
    vector<Studentas> studentai;
    ifstream failas(failoPavadinimas);
    if (!failas) {
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return studentai;
    }

    string line;
    if (!getline(failas, line)) {
        cout << "Klaida: Failas tuscias"<< endl;
        return studentai;
    }
    while (getline(failas, line)) {
        if (!line.empty())
            studentai.push_back(iveskIsFailo(line));
    }
    return studentai;
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

// Funkcija, kuri prideda tarpu, kad stringas uzimtu n simboliu
string formatuoti(string s, int plotis) {
    int tarpai = plotis - s.length();
    int kaire = tarpai / 2;
    int desine = tarpai - kaire;
    return string(kaire, ' ') + s + string(desine, ' ');
}

// Funkcija atsitiktinio studento generavimui
Studentas generuokStudenta() {
    Studentas Laik;
    cout << "Ivesk varda: "; getline(cin, Laik.vard);
    cout << "Ivesk pavarde: "; getline(cin, Laik.pav);

    int ndKiekis;
    while (true) {
        cout << "Kiek namu darbu pazymiu turi studentas? ";
        string temp;
        getline(cin, temp);
        try {
            ndKiekis = std::stoi(temp);
            if (ndKiekis > 0) break;
            else cout << "Turi buti bent vienas pazymys!\n";
        } catch (...) {
            cout << "Klaida: iveskite skaiciu!\n";
        }
    }

    Laik.paz.clear();
    for (int i = 0; i < ndKiekis; i++) {
        Laik.paz.push_back(rand() % 10 + 1);
    }
    Laik.egzas = rand() % 10 + 1;

    int sum = 0;
    for (int p : Laik.paz) sum += p;
    Laik.rez = Laik.egzas * 0.6f + (float)sum / Laik.paz.size() * 0.4f;
    Laik.mediana = skaiciuotiMediana(Laik.paz);
    return Laik;
}

// Rusiavimo funkcija
void rikiuotiPagalPavarde(vector<Studentas> &studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
        if (a.pav == b.pav)
            return a.vard < b.vard;
        return a.pav < b.pav;
    });
}

// Funkcija studentų rezultatų spausdinimui į failą
void spausdintiIFaila(const vector<Studentas> &visiStudentai, const string &failoVardas) {
    std::ofstream out(failoVardas);
    if (!out) {
        cout << "Nepavyko sukurti failo: " << failoVardas << endl;
        return;
    }

    out << "|" << formatuoti("Vardas", 14) << "|" << formatuoti(" Pavarde", 15) 
        << "|" << formatuoti("Vidurkis", 10) << "|" << formatuoti("Mediana", 9) << "|\n";
    out << "-----------------------------------------------------\n";

    for (auto &temp : visiStudentai) {
        out << "|" << formatuoti(temp.vard, 14) << "|" << formatuoti(temp.pav, 15) 
            << "|" << formatuoti(SkaiciaiSuKableliu(temp.rez), 10) << "|" << formatuoti(SkaiciaiSuKableliu(temp.mediana), 9) << "|\n";
    }
}

// Funkcija skaiciaus formatavimui su kableliu
string SkaiciaiSuKableliu(float value) {
    int sveika = (int)value;
    int desimtys = (int)(value * 100 + 0.5) % 100;
    string rezultatas = std::to_string(sveika) + ".";
    rezultatas += std::to_string(desimtys);
    return rezultatas;
}