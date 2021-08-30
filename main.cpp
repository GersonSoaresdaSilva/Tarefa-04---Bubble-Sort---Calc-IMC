/*Faça um algoritmo com struc e menu completo para ler uma lista de NOMES, PESOS, ALTURAS e armazenar o cálculo do índice de massa
corpórea, IMC. Faça um menu com a opções: 1 Ler, processar, 2 exibir tabela, 3 pesquisar por nome, 4 Classificar por nome, 5 sair. Na opção pesquisar por nome, faça uma pesquisa sequencial para encontrar e exibir o nome da pessoa, seu peso, sua altura e seu IMC assim como seu status de classificação de peso. Use as mensagens de classificação obtidas no site: http://www.calcularpesoideal.com.br*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int const n = 4;
int reg = -1;

typedef struct dados IMC;

struct dados {
    string nomes [n];
    double pesos [n];
    double alturas [n];
    double resIMC [n];
    string status [n];
};
dados tab;

//sub rotinas
string lerNomes();
double lerPesos();
double lerAlturas();
void novoReg();
void statusIMC();
void exibir();
void pesqNome();
int buscaSeq(string nom_);
void orgNomes();
void controle();

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << setprecision(4);
    controle();
    return 0;
}

string lerNomes() {
    string nome;
    cout << "\nDigite o Nome.: ";
    getline(cin, nome);
    return nome;
}

double lerPesos() {
    double peso;
    cout << "Digite o Peso.: ";
    cin >> peso;
    return peso;
}

double lerAlturas() {
    double altura;
    cout << "Digite a Altura.: ";
    cin >> altura;
    return altura;
}

void novoReg() {
    reg++;
    if (reg <= n - 1) {
        cin.ignore();
        string nom_ = lerNomes();
        tab.nomes [reg] = nom_;

        double pes_ = lerPesos();
        tab.pesos [reg] = pes_;

        double alt_ = lerAlturas();
        tab.alturas [reg] = alt_;

        double calcIMC;
        calcIMC = pes_ / (alt_ * alt_);
        tab.resIMC [reg] = calcIMC;

        statusIMC();

    } else {
        system("clear");
        cout << "Limite de Dados foram atingidos!" << endl;
        system("sleep 4");
        return;
    }
}

void statusIMC() {
    for (int i = 0; i < n - 1; i++) {
        if (tab.resIMC [reg] <= 18.4) {
            tab.status [reg] = "Abaixo do Peso.";
        } else {
            if (tab.resIMC [reg] <= 24.9) {
                tab.status [reg] = "Peso Normal.";
            } else {
                if (tab.resIMC [reg] <= 29.9) {
                    tab.status [reg] = "Sobrepeso.";
                } else {
                    if (tab.resIMC [reg] <= 34.9) {
                        tab.status [reg] = "Obesidade Grau I.";
                    } else {
                        if (35.0 >= tab.resIMC [reg] <= 39.9) {
                            tab.status [reg] = "Obesidade Grau II.";
                        } else {
                            tab.status [reg] = "Obesidade Grau III.";
                        }
                    }
                }
            }
        }
    }
}

void exibir() {
    string nome_;
    double peso_, altura_, imc_;
    system("clear");
    cout << "\n*** Exibir Tabela ***" << endl;
    for (int i = 0; i <= n - 1; i++) {
        nome_ = tab.nomes [i];
        peso_ = tab.pesos [i];
        altura_ = tab.alturas [i];
        imc_ = tab.resIMC [i];
        if (nome_ != "" && peso_ != 0 && altura_ != 0 && imc_ != 0) {
            cout << "Nome...: " << nome_ << endl;
            cout << "Peso...: " << peso_ << endl;
            cout << "Altura.: " << altura_ << endl;
            cout << "IMC....: " << imc_ << endl;
            cout << "---------------------------\n";
            system("sleep 4");
        }
    }
}

void pesqNome() {
    string nomePesq;
    int buscaNom;
    system("clear");
    cout << "\n*** Pesquisar por Nome ***";
    cin.ignore();
    cout << "\nDigite o nome.: ";
    getline(cin, nomePesq);
    buscaNom = buscaSeq(nomePesq);

    if (buscaNom == -1) {
        cout << "\nO nome " << nomePesq << " não foi localizado." << endl;
        system("sleep 4");
    } else {
        cout << "\nNome localizado com Sucesso!" << endl;
        cout << "Nome...: " << tab.nomes [buscaNom] << endl;
        cout << "Peso...: " << tab.pesos [buscaNom] << endl;
        cout << "Altura.: " << tab.alturas[buscaNom] << endl;
        cout << "IMC....: " << tab.resIMC[buscaNom] << endl;
        cout << "Status.: " << tab.status [buscaNom] << endl;
        system("sleep 4");
    }
}

int buscaSeq(string nom_) {
    for (int i = 0; i <= n; i++) {
        if (nom_ == tab.nomes [i]) {
            return i;
        }
    }
    return -1;
}

void orgNomes() {
    string auxNom, auxSta;
    double auxPes, auxAlt, auxIMC;

    for (int i = 0; i <= (n - 2); i++) {
        for (int j = i; j <= (n - 1); j++) {
            if (tab.nomes [i] > tab.nomes [j]) {
                auxNom = tab.nomes [i];
                auxPes = tab.pesos [i];
                auxAlt = tab.alturas [i];
                auxIMC = tab.resIMC [i];
                auxSta = tab.status [i];

                tab.nomes [i] = tab.nomes [j];
                tab.pesos [i] = tab.pesos [j];
                tab.alturas [i] = tab.alturas [j];
                tab.resIMC [i] = tab.resIMC [j];
                auxSta = tab.status [j];

                tab.nomes [j] = auxNom;
                tab.pesos [j] = auxPes;
                tab.alturas [j] = auxAlt;
                tab.resIMC [j] = auxIMC;
                tab.status [j] = auxSta;
            }
        }
    }

    cout << "\n*** Itens organizados com Sucesso !***" << endl;
    system("sleep 4");
}

void controle() {
    int opcMenu;
    while (true) {
        system("clear");
        cout << "\n\n*** Calcular Peso Ideal ***";
        cout << "\n *** Menu Principal ***";
        cout << "\n1 - Ler e Processar \n2 - Exibir \n3 - Pesquisar por Nome \n4 - Classificar por Nome \n5 - Sair \nOpção: ";
        cin >> opcMenu;
        switch (opcMenu) {
            case 1: novoReg();
                break;
            case 2: exibir();
                break;
            case 3: pesqNome();
                break;
            case 4: orgNomes();
                break;
            case 5: exit(0);
        }
    }
}
