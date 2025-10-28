#include "main.h"

int main() {
    bool veikia = true;
    string KonteinerioTipas;
    cout << "Pasirinkite konteinerio tipa (vector / list): ";
    getline(cin, KonteinerioTipas);

    if (KonteinerioTipas == "vector") {
        vector<Studentas<vector<int>>> visiStudentai;
        vector<Studentas<vector<int>>> vargsiukai;
        vector<Studentas<vector<int>>> galvociai;
        while (veikia) {
            string pasirinkimas;
            cout << "\nPasirinkite veiksma:\n";
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
                    try { kiek = stoi(input); if (kiek > 0) break; } catch (...) { cout << "Klaida: iveskite skaiciu!\n"; }
                }
                for (int j = 0; j < kiek; j++) visiStudentai.push_back(ivesk<vector<int>>());
            } else if (pasirinkimas == "2") {
                int kiek;
                while (true) {
                    string input;
                    cout << "Kiek atsitiktiniu studentu sugeneruoti? ";
                    getline(cin, input);
                    try { kiek = stoi(input); if (kiek > 0) break; } catch (...) { cout << "Klaida: iveskite skaiciu!\n"; }
                }
                for (int j = 0; j < kiek; j++) visiStudentai.push_back(generuokStudenta<vector<int>>());
            } else if (pasirinkimas == "3") {
                string failoVardas;
                cout << "Iveskite failo pavadinima: ";
                getline(cin, failoVardas);
                vector<Studentas<vector<int>>> isFailo = skaitytiIsFailo<vector<Studentas<vector<int>>>>(failoVardas);
                visiStudentai.insert(visiStudentai.end(), isFailo.begin(), isFailo.end());
            } else if (pasirinkimas == "4") {
                veikia = false;
                break;
            }
            string kriterijus;
            cout << "Pasirinkite rikiavimo kriteriju (vardas / pavarde / vidurkis): ";
            getline(cin, kriterijus);
            string strategija;
            cout << "Pasirinkite grupavimo strategija (1, 2 arba 3): ";
            getline(cin, strategija);
            if (strategija == "1") {
                rikiuotiIrSukurtGrupe(visiStudentai, vargsiukai, galvociai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(galvociai, "galvociai_vector.txt");
            }
            else if (strategija == "2") {
                rikiuotiIrSukurtGrupe_2(visiStudentai, vargsiukai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(visiStudentai, "galvociai_vector.txt");
            }
            else if (strategija == "3") {
                rikiuotiIrSukurtGrupe_3(visiStudentai, vargsiukai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(visiStudentai, "galvociai_vector.txt");
            }
        }
    } else if (KonteinerioTipas == "list") {
        list<Studentas<list<int>>> visiStudentai;
        list<Studentas<list<int>>> vargsiukai;
        list<Studentas<list<int>>> galvociai;
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
                    try { kiek = stoi(input); if (kiek > 0) break; } catch (...) { cout << "Klaida: iveskite skaiciu!\n"; }
                }
                for (int j = 0; j < kiek; j++) visiStudentai.push_back(ivesk<list<int>>());
            } else if (pasirinkimas == "2") {
                int kiek;
                while (true) {
                    string input;
                    cout << "Kiek atsitiktiniu studentu sugeneruoti? ";
                    getline(cin, input);
                    try { kiek = stoi(input); if (kiek > 0) break; } catch (...) { cout << "Klaida: iveskite skaiciu!\n"; }
                }
                for (int j = 0; j < kiek; j++) visiStudentai.push_back(generuokStudenta<list<int>>());
            } else if (pasirinkimas == "3") {
                string failoVardas;
                cout << "Iveskite failo pavadinima: ";
                getline(cin, failoVardas);
                list<Studentas<list<int>>> isFailo = skaitytiIsFailo<list<Studentas<list<int>>>>(failoVardas);
                visiStudentai.insert(visiStudentai.end(), isFailo.begin(), isFailo.end());
            } else if (pasirinkimas == "4") {
                veikia = false;
                break;
            }
            string kriterijus;
            cout << "Pasirinkite rikiavimo kriteriju (vardas / pavarde / vidurkis): ";
            getline(cin, kriterijus);
            string strategija;
            cout << "Pasirinkite grupavimo strategija (1, 2 arba 3): ";
            getline(cin, strategija);
            if (strategija == "1") {
                rikiuotiIrSukurtGrupe(visiStudentai, vargsiukai, galvociai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(galvociai, "galvociai_vector.txt");
            }
            else if (strategija == "2") {
                rikiuotiIrSukurtGrupe_2(visiStudentai, vargsiukai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(visiStudentai, "galvociai_vector.txt");
            }
            else if (strategija == "3") {
                rikiuotiIrSukurtGrupe_3(visiStudentai, vargsiukai, kriterijus);
                spausdintiIFaila(vargsiukai, "vargsiukai_vector.txt");
                spausdintiIFaila(visiStudentai, "galvociai_vector.txt");
            }
        }
    }
    return 0;
}
