#include <iostream>
using namespace std;

char angka[10] = {'0','1','2',
				  '3','4','5','6',
				  '7','8','9'};
int cetak_hasil();
void papan_permainan();

int main() {
    int pemain = 1, i, pilih;
    char simbol;
    do {
        papan_permainan();
        pemain = (pemain % 2) ? 1 : 2;
        cout << "pemain " << pemain << ", masukan angka: ";
        cin >> pilih;
        simbol = (pemain == 1) ? 'X' : 'O';
        if (pilih >= 1 && pilih <= 9 && angka[pilih] == '0' + pilih)
            angka[pilih] = simbol;
        else {
            cout << "jawaban tidak valid ";
            pemain--;
            cin.ignore();
            cin.get();
        }
        i = cetak_hasil();
        pemain++;
    } while (i == -1);
    papan_permainan();
    if (i == 1)
        cout << "==>\aPemain " << --pemain << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
    return 0;
}

int cetak_hasil() {
    if (angka[1] == angka[2] && angka[2] == angka[3])
        return 1;
    else if (angka[4] == angka[5] && angka[5] == angka[6])
        return 1;
    else if (angka[7] == angka[8] && angka[8] == angka[9])
        return 1;
    else if (angka[1] == angka[4] && angka[4] == angka[7])
        return 1;
    else if (angka[2] == angka[5] && angka[5] == angka[8])
        return 1;
    else if (angka[3] == angka[6] && angka[6] == angka[9])
        return 1;
    else if (angka[1] == angka[5] && angka[5] == angka[9])
        return 1;
    else if (angka[3] == angka[5] && angka[5] == angka[7])
        return 1;
    else if (angka[1] != '1' && angka[2] != '2' && angka[3] != '3' && angka[4] != '4' && angka[5] != '5' && angka[6] != '6' && angka[7] != '7' && angka[8] != '8' && angka[9] != '9')
        return 0;
    else
        return -1;
}

void papan_permainan() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "pemain 1 (X)  -  pemain 2 (O)" << endl << endl;
    cout << "      |     |     " << endl;
    cout << "  " << angka[1] << "   |  " << angka[2] << "  |  " << angka[3] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "  " << angka[4] << "   |  " << angka[5] << "  |  " << angka[6] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "  " << angka[7] << "   |  " << angka[8] << "  |  " << angka[9] << endl;
    cout << "      |     |     " << endl << endl;
}

