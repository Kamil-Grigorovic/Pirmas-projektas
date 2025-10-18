#include "main.h"

int main() {
    list<Studentas<list<int>>> visiStudentai;
    bool veikia = true;

    while (veikia) {
        string KonteinerioTipas;
        cout << "Pasirinkite konteinerio tipa (vector / list): ";
        getline(cin, KonteinerioTipas);
        if (KonteinerioTipas == "vector") {
            vector<Studentas<vector<int>>> visiStudentai;

            
        } else if (KonteinerioTipas == "list") {
            list<Studentas<list<int>>> visiStudentai;
            
        }
            return 0;
    }
}
