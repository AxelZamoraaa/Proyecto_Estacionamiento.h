#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    cout << "Bienvenido al estacionamiento" << endl;
    
    // Este es el catalogo de las capacidades
    const int max_Compacto = 10;
    const int max_Sedan = 8;
    const int max_SUV = 5;
    const int max_total = max_Compacto + max_Sedan + max_SUV;

    cout << "Tenemos " << max_total << " espacios disponibles." << endl;

    cout << "Espacios disponibles por tipo de vehiculo:" << endl;
    cout << "Compacto: " << max_Compacto << endl;
    cout << "Sedan: " << max_Sedan << endl;
    cout << "SUV: " << max_SUV << endl;


    // Aqui se guardan los lugares que estan ocupados (true = ocupado)
    
    bool lugaresCompacto[10] = {false};
    bool lugaresSedan[8] = {false};
    bool lugaresSUV[5] = {false};

    // Contadores para no recorrer los arreglos
    int ocupCompacto = 0;
    int ocupSedan = 0;
    int ocupSUV = 0;

    
    cout << "Ingrese su vehiculo para la entrada (Compacto, Sedan, suv)" << endl;
    cout << "o el numero de lugar para la salida (ej. SUV01)" << endl;
    cout << "Escriba SALIR para terminar" << endl;

    string entrada = "";

    while (true) {
        cout << "> ";
        cin >> entrada;

        if (entrada == "SALIR") {
            cout << "Simulacion finalizada." << endl;
            break;
        }

        else if (entrada == "Compacto" || entrada == "Sedan" || entrada == "Suv") {
            // Alguien quiere entrar
            bool seAcepto = false;
            int lugarAsignado = 0;

            if (entrada == "Compacto") {
                for (int i = 0; i < max_Compacto; i++) {
                    if (!lugaresCompacto[i]) {
                        lugaresCompacto[i] = true;
                        lugarAsignado = i + 1;
                        ocupCompacto++;
                        seAcepto = true;
                        break;
                    }
                }
            } else if (entrada == "Sedan") {
                for (int i = 0; i < max_Sedan; i++) {
                    if (!lugaresSedan[i]) {
                        lugaresSedan[i] = true;
                        lugarAsignado = i + 1;
                        ocupSedan++;
                        seAcepto = true;
                        break;
                    }
                }
            } else if (entrada == "Suv") {
                for (int i = 0; i < max_SUV; i++) {
                    if (!lugaresSUV[i]) {
                        lugaresSUV[i] = true;
                        lugarAsignado = i + 1;
                        ocupSUV++;
                        seAcepto = true;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < max_SUV; i++) {
                    if (!lugaresSUV[i]) {
                        lugaresSUV[i] = true;
                        lugarAsignado = i + 1;
                        ocupSUV++;
                        seAcepto = true;
                        break;
                    }
                }
            }

            if (seAcepto) {
                string numTexto = to_string(lugarAsignado);
                if (lugarAsignado < 10) {
                    numTexto = "0" + numTexto;
                }
                cout << "Vehiculo aceptado. Lugar asignado: " << entrada << numTexto << endl;

                cout << "--- ESTADO DEL ESTACIONAMIENTO ---" << endl;
                cout << "Compacto: " << ocupCompacto << "/" << max_Compacto << " ocupados" << endl;
                cout << "Sedan: " << ocupSedan << "/" << max_Sedan << " ocupados" << endl;
                cout << "Suv: " << ocupSUV << "/" << max_SUV << " ocupados" << endl;
                int totalOcup = ocupCompacto + ocupSedan + ocupSUV;
                double porcentaje = (double(totalOcup) / max_total) * 100;
                cout << fixed << setprecision(1);
                cout << "Ocupacion total: " << porcentaje << "% (" << totalOcup << "/" << max_total << ")" << endl;
                cout << "-----------------------------------" << endl;
            } else {
                cout << "Entrada rechazada: no hay lugares disponibles para " << entrada << "." << endl;
            }
        }

        else {
            // Aqui es un intento de salida (SUV01) o algo invalido (CAMION)
            string tipo = "";
            int largoTipo = 0;

            if (entrada.length() > 8 && entrada.substr(0, 8) == "Compacto") {
                tipo = "Compacto";
                largoTipo = 8;
            } else if (entrada.length() > 5 && entrada.substr(0, 5) == "Sedan") {
                tipo = "Sedan";
                largoTipo = 5;
            } else if (entrada.length() > 3 && entrada.substr(0, 3) == "Suv") {
                tipo = "Suv";
                largoTipo = 3;
            }

            if (tipo == "") {
                cout << "Entrada invalida: tipo de vehiculo no reconocido." << endl;
            } else {
                string numTexto = entrada.substr(largoTipo);
                int largoNum = numTexto.length();
                bool esNumero = true;
                for (int i = 0; i < largoNum; i++) {
                    if (numTexto[i] < '0' || numTexto[i] > '9') {
                        esNumero = false;
                    }
                }

                if (!esNumero || largoNum == 0) {
                    cout << "Salida invalida: el lugar " << entrada << " no existe." << endl;
                } else {
                    int numLugar = 0;
                    for (int i = 0; i < largoNum; i++) {
                        numLugar = numLugar * 10 + (numTexto[i] - '0');
                    }

                    int capacidad = 0;
                    if (tipo == "Compacto") capacidad = max_Compacto;
                    else if (tipo == "Sedan") capacidad = max_Sedan;
                    else capacidad = max_SUV;

                    if (numLugar < 1 || numLugar > capacidad) {
                        cout << "Salida invalida: el lugar " << entrada << " no existe." << endl;
                    } else {
                        int indice = numLugar - 1;
                        bool estabaOcupado = false;

                        if (tipo == "Compacto") {
                            estabaOcupado = lugaresCompacto[indice];
                            if (estabaOcupado) {
                                lugaresCompacto[indice] = false;
                                ocupCompacto--;
                            }
                        } else if (tipo == "Sedan") {
                            estabaOcupado = lugaresSedan[indice];
                            if (estabaOcupado) {
                                lugaresSedan[indice] = false;
                                ocupSedan--;
                            }
                        } else {
                            estabaOcupado = lugaresSUV[indice];
                            if (estabaOcupado) {
                                lugaresSUV[indice] = false;
                                ocupSUV--;
                            }
                        }

                        if (!estabaOcupado) {
                            cout << "Salida invalida: el lugar " << entrada << " ya estaba libre." << endl;
                        } else {
                            cout << "Vehiculo de lugar " << entrada << " ha salido." << endl;

                            cout << "--- ESTADO DEL ESTACIONAMIENTO ---" << endl;
                            cout << "Compacto: " << ocupCompacto << "/" << max_Compacto << " ocupados" << endl;
                            cout << "Sedan: " << ocupSedan << "/" << max_Sedan << " ocupados" << endl;
                            cout << "Suv: " << ocupSUV << "/" << max_SUV << " ocupados" << endl;
                            int totalOcup = ocupCompacto + ocupSedan + ocupSUV;
                            double porcentaje = (double(totalOcup) / max_total) * 100;
                            cout << fixed << setprecision(1);
                            cout << "Ocupacion total: " << porcentaje << "% (" << totalOcup << "/" << max_total << ")" << endl;
                            cout << "-----------------------------------" << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}