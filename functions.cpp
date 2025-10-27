#include "main.h"

// Funkcija studento ivedimui rankiniu budu
template <typename T>
Studentas<T> ivesk() {
    Studentas<T> Laik;
    cout << "Ivesk varda: "; 
    getline(cin, Laik.vard);
    cout << "Ivesk pavarde: "; 
    getline(cin, Laik.pav);
    cout << "Iveskite namu darbu pazymius po viena. Kai baigsite, tiesiog paspauskite ENTER:\n";
    string temp;
    Laik.paz.clear();

    while (true) {
        cout << "Pazymys: ";
        getline(cin, temp);
        if (temp.empty()) break;
        try {
            int paz = stoi(temp);
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
            Laik.egzas = stoi(temp);
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
template <typename T>
Studentas<T> iveskIsFailo(const string &line) {
    Studentas<T> Laik;
    istringstream in(line);

    in >> Laik.vard >> Laik.pav;
    T visiSkaiciai;
    string temp;
    while (in >> temp) { 
        try {
            size_t pos;
            int skaicius = stoi(temp, &pos);
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
template <typename T>
T skaitytiIsFailo(const string &failoPavadinimas) {
    T studentai;

    auto start = std::chrono::high_resolution_clock::now();

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
    using PazT = typename T::value_type::paz_type;
    while (getline(failas, line)) {
        if (!line.empty())
            studentai.push_back(iveskIsFailo<PazT>(line));
    }
    failas.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Failo skaitymas uztruko " << elapsed.count() << " sekundziu." << endl;


    return studentai;
}


// medianai skaiciuoti
template <typename Container>
float skaiciuotiMediana(const Container &pazymiai) {
    vector<int> temp(pazymiai.begin(), pazymiai.end());
    sort(temp.begin(), temp.end());
    int n = temp.size();
    if (n == 0) return 0;
    if (n % 2 == 1) return temp[n/2];
    return (temp[n/2 - 1] + temp[n/2]) / 2.0f;
}

// Funkcija, kuri prideda tarpu, kad stringas uzimtu n simboliu
string formatuoti(string s, int plotis) {
    int tarpai = plotis - s.length();
    int kaire = tarpai / 2;
    int desine = tarpai - kaire;
    return string(kaire, ' ') + s + string(desine, ' ');
}

// Funkcija atsitiktinio studento generavimui
template <typename T>
Studentas<T> generuokStudenta() {
    Studentas<T> Laik;
    cout << "Ivesk varda: "; 
    getline(cin, Laik.vard);
    cout << "Ivesk pavarde: "; 
    getline(cin, Laik.pav);

    int ndKiekis;
    while (true) {
        cout << "Kiek namu darbu pazymiu turi studentas? ";
        string temp;
        getline(cin, temp);
        try {
            ndKiekis = stoi(temp);
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

// Rusiavimo funkcija su 1 strategija
template <typename Container, typename Comparator>
void rikiuoti(Container &temp, Comparator comp) {
    if constexpr  (std::is_same_v<Container, std::list<typename Container::value_type>>) {
        temp.sort(comp);
    } else {
        std::sort(temp.begin(), temp.end(), comp);
    }
}
template <typename T>
void rikiuotiIrSukurtGrupe(const T &visiStudentai, T &vargsiukai, T &galvociai, const string &kriterijus) {
    auto start = std::chrono::high_resolution_clock::now();
    auto temp = visiStudentai;

    auto comparator = [&](const auto &a, const auto &b) {
        if (kriterijus == "vardas") 
            return a.vard < b.vard;
        if (kriterijus == "pavarde") 
            return a.pav < b.pav;
        if (kriterijus == "vidurkis") 
            return a.rez < b.rez;
        if (a.pav == b.pav) 
            return a.vard < b.vard;
        return a.pav < b.pav;
    };

    rikiuoti(temp, comparator);

    vargsiukai.clear();
    galvociai.clear();

    for (const auto &s : temp) {
        if (s.rez < 5)
            vargsiukai.push_back(s);
        else
            galvociai.push_back(s);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rikiavimas ir grupavimas uztruko: " << elapsed.count() << " sekundziu." << endl;
}

// Rusiavimo funkcija su 2 strategija
template <typename T>
void rikiuotiIrSukurtGrupe_2(T &visiStudentai, T &vargsiukai, const string &kriterijus) {
    auto start = std::chrono::high_resolution_clock::now();

    auto comparator = [&](const auto &a, const auto &b) {
        if (kriterijus == "vardas") 
            return a.vard < b.vard;
        if (kriterijus == "pavarde") 
            return a.pav < b.pav;
        if (kriterijus == "vidurkis") 
            return a.rez < b.rez;
        if (a.pav == b.pav) 
            return a.vard < b.vard;
        return a.pav < b.pav;
    };

    rikiuoti(visiStudentai, comparator);

    vargsiukai.clear();
    for (auto it = visiStudentai.begin(); it != visiStudentai.end(); ) {
        if (it->rez < 5) {
            vargsiukai.push_back(*it);
            it = visiStudentai.erase(it);
        } else {
            ++it;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rikiavimas ir grupavimas (2 strategija) uztruko: " 
         << elapsed.count() << " sekundziu." << endl;
}

// Rusiavimo funkcija su 3 strategija
template <typename T>
void rikiuotiIrSukurtGrupe_3(T &visiStudentai, T &vargsiukai, const string &kriterijus) {
    auto start = std::chrono::high_resolution_clock::now();

    auto comparator = [&](const auto &a, const auto &b) {
        if (kriterijus == "vardas") 
            return a.vard < b.vard;
        if (kriterijus == "pavarde") 
            return a.pav < b.pav;
        if (kriterijus == "vidurkis") 
            return a.rez < b.rez;
        if (a.pav == b.pav) 
            return a.vard < b.vard;
        return a.pav < b.pav;
    };
    rikiuoti(visiStudentai, comparator);

    vargsiukai.clear();

    if constexpr (std::is_same_v<T, std::vector<typename T::value_type>>) {
        std::copy_if(visiStudentai.begin(), visiStudentai.end(), std::back_inserter(vargsiukai),
                     [](const auto &s) { return s.rez < 5; });

        visiStudentai.erase(
            std::remove_if(visiStudentai.begin(), visiStudentai.end(),
                           [](const auto &s) { return s.rez < 5; }),
            visiStudentai.end());

    } else {
        for (auto it = visiStudentai.begin(); it != visiStudentai.end(); ) {
            if (it->rez < 5) {
                vargsiukai.push_back(*it);
                it = visiStudentai.erase(it);
            } else {
                ++it;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rikiavimas ir grupavimas (3 strategija) uztruko: "
         << elapsed.count() << " sekundziu." << endl;
}

// Funkcija studentų rezultatų spausdinimui į failą
template <typename T>
void spausdintiIFaila(const T &grupe, const string &failoVardas) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream out(failoVardas);
    if (!out) {
        cout << "Nepavyko sukurti failo: " << failoVardas << endl;
        return;
    }

    out << "|" << formatuoti("Vardas", 14) << "|" << formatuoti(" Pavarde", 15) 
        << "|" << formatuoti("Vidurkis", 10) << "|" << formatuoti("Mediana", 9) << "|\n";
    out << "-----------------------------------------------------\n";

    for (const auto &temp : grupe) {
        out << "|" << formatuoti(temp.vard, 14) << "|" << formatuoti(temp.pav, 15) 
            << "|" << formatuoti(SkaiciaiSuKableliu(temp.rez), 10) 
            << "|" << formatuoti(SkaiciaiSuKableliu(temp.mediana), 9) << "|\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Spausdinimas i faila (" << failoVardas << ") uztruko: " << elapsed.count() << " sekundziu." << endl;
}


// Funkcija skaiciaus formatavimui su kableliu
string SkaiciaiSuKableliu(float value) {
    int sveika = (int)value;
    int desimtys = (int)(value * 100 + 0.5) % 100;
    string rezultatas = std::to_string(sveika) + ".";
    rezultatas += std::to_string(desimtys);
    return rezultatas;
}

// Sablonų deklaracijos
template void rikiuotiIrSukurtGrupe<vector<Studentas<vector<int>>>>(const vector<Studentas<vector<int>>>&, vector<Studentas<vector<int>>>&, 
    vector<Studentas<vector<int>>>&, const string&);
template void rikiuotiIrSukurtGrupe<list<Studentas<list<int>>>>(const list<Studentas<list<int>>>&, list<Studentas<list<int>>>&,
    list<Studentas<list<int>>>&, const string&);
template void rikiuotiIrSukurtGrupe_2<vector<Studentas<vector<int>>>>(vector<Studentas<vector<int>>>&, vector<Studentas<vector<int>>>&, const string&);
template void rikiuotiIrSukurtGrupe_2<list<Studentas<list<int>>>>(list<Studentas<list<int>>>&, list<Studentas<list<int>>>&, const string&);
template void rikiuotiIrSukurtGrupe_3<vector<Studentas<vector<int>>>>(vector<Studentas<vector<int>>>&, vector<Studentas<vector<int>>>&, const string&);
template void rikiuotiIrSukurtGrupe_3<list<Studentas<list<int>>>>(list<Studentas<list<int>>>&, list<Studentas<list<int>>>&, const string&);
template void spausdintiIFaila<vector<Studentas<vector<int>>>>(const vector<Studentas<vector<int>>>&, const string&);
template void spausdintiIFaila<list<Studentas<list<int>>>>(const list<Studentas<list<int>>>&, const string&);
template Studentas<vector<int>> ivesk();
template Studentas<list<int>> ivesk();
template Studentas<vector<int>> iveskIsFailo(const string &line);
template Studentas<list<int>> iveskIsFailo(const string &line);
template vector<Studentas<vector<int>>> skaitytiIsFailo(const string &failoPavadinimas);
template list<Studentas<list<int>>> skaitytiIsFailo(const string &failoPavadinimas);
template Studentas<vector<int>> generuokStudenta();
template Studentas<list<int>> generuokStudenta();
