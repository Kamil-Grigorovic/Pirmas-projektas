#include "main.h"

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

        vector<Studentas> vargsiukai, galvociai;
        string kriterijus;
        
        cout << "Pasirinkite rikiavimo kriteriju (vardas / pavarde / vidurkis): ";
        getline(cin, kriterijus);
        rikiuotiIrSukurtGrupe(visiStudentai, vargsiukai, galvociai, kriterijus);

        spausdintiIFaila(vargsiukai, "vargsiukai.txt");
        spausdintiIFaila(galvociai, "galvociai.txt");
    }

    return 0;
}