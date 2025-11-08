#include <iostream>
#include <fstream>
using namespace std;

void func1(){
    ofstream file("studenti.txt");
    string ime, specialnost;
    int n, num, grupa;
    double uspeh;

    cout << "\n\nZa kolko studenti iskate da vuvedete danni (MAX 30): ";
    cin >> n;
    while(n<1 || n>30){
        cout << "\nNevalidna stoinost. Vuvedete chislo ot 1 do 30: ";
        cin >> n;
    }

    cout << "\nVuvedete dannite za vashite studenti: ";
    for(int i = 0;i<n;i++){
        cout << "\nIme: ";
        cin >> ime;
        cout << "Fakulteten nomer: ";
        cin >> num;
        cout << "Specialnost (E ili AIUT): ";
        cin >> specialnost;
        while(specialnost!="E"&&specialnost!="AIUT"){
            cout << "Specialnost (E ili AIUT): ";
            cin >> specialnost;
        }
        cout << "Grupa (1-4): ";
        cin >> grupa;
        while(grupa<1 || grupa>4){
            cout << "Grupa (1-4): ";
            cin >> grupa;
        }
        cout << "Sreden uspeh ot semestura (2.00-6.00): ";
        cin >> uspeh;
        while(uspeh<2||uspeh>6){
            cout << "Sreden uspeh ot semestura (2.00-6.00): ";
            cin >> uspeh;
        }
        file << ime << " " << num << " " << specialnost << " " << grupa << " " << uspeh << endl;
    }
    file.close();

    ifstream infile("studenti.txt");
    cout << "\nVashite studenti: ";
    while (infile >> ime >> num >> specialnost >> grupa >> uspeh){
        cout << "\n" << ime << " " << num << " " << specialnost << " " << grupa << " " << uspeh;
    }
    infile.close();
}

void func2(){
    string ime, specialnost;
    int search, num, grupa;
    double uspeh;
    bool found = false;
    ifstream file("studenti.txt");

    cout << "\n\nVuvedete fakultetniq nomer na turseniq ot vas student: ";
    cin >> search;
    while(file >> ime >> num >> specialnost >> grupa >> uspeh){
        if(num==search){
            cout << "Student: " << ime << " " << num << " " << specialnost << " " << grupa << " " << uspeh;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "\nNe e nameren student s tozi fakulteten nomer!";
    }
    file.close();
}

void func3(){
     string ime, specialnost;
    int num, grupa;
    double uspeh;
    ifstream file("studenti.txt");

    cout << "\n\nOtlichnici po grupi: " << endl;
    for(int i=1;i<=4;i++){
        bool found = false;
        cout << "\nSpecialnost E, grupa " << i << ": ";
        file.clear();
        file.seekg(0);
        while(file >> ime >> num >> specialnost >> grupa >> uspeh){
            if(specialnost=="E"&&grupa==i&&uspeh>5.5){
                cout << "\n" << ime << " " << num << " " << specialnost << " " << grupa << " " << uspeh;
                found = true;
            }
        }
        if(!found) cout << "\nNqma otlichnici v grupata!";
    }
    cout << endl;
    for(int i=1;i<=4;i++){
        bool found = false;
        cout << "\nSpecialnost AIUT, grupa " << i << ": ";
        file.clear();
        file.seekg(0);
        while(file >> ime >> num >> specialnost >> grupa >> uspeh){
            if(specialnost=="AIUT"&&grupa==i&&uspeh>5.5){
                cout << "\n" << ime << " " << num << " " << specialnost << " " << grupa << " " << uspeh;
                found = true;
            }
        }
        if(!found) cout << "\nNqma otlichnici v grupata!";
    }

    file.close();
}

int main(){
    int functionIndex = 0;
    while (functionIndex!=4){
        cout << "\n\n#-------------------------------------------------------------------------------------------------------------------------#\n";
        cout << "  Funkcii: ";
        cout << "\n\n1) Vavezhdane ot klaviaturata vuv fail dannite za N na broy studenta: ime, fakulteten nomer, spetsialnost, grupa, sreden uspeh ot semestara. Izvezhdane tekushtoto sadarzhanie na faila na ekrana.";
        cout << "\n2) Izvezhdane na danni za student po vuvedeni ot klaviaturata fakulteten nomer, spetsialnost i grupa ili suobshtenie, che nyama danni za studenta.";
        cout << "\n3) Izvezhdane dannite za studentite s otlichen sreden uspeh za vsyaka grupa ili \"Nyama danni za studenti ot grupata\" ili \"Nyama otlichnitsi v grupata\".";
        cout << "\n4) Zatvarqne";
        cout << "\n#-------------------------------------------------------------------------------------------------------------------------#\n";
        cout << "\nIzberete nomer na funkciq: ";
        cin >> functionIndex;
        switch (functionIndex){
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        default:
            break;
        }
    }
    return 0;
}