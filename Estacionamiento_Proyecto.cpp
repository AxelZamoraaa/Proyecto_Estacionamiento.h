#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string aMinusculas(string texto) {
    for (size_t i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

int main() {
    cout << "Bienvenido al estacionamiento" << endl;
    
    // Este es el catalogo de las capacidades
    const int max_compacto = 10;
    const int max_sedan = 8;
    const int max_suv = 5;
    const int max_total = max_compacto + max_sedan + max_suv;

    cout << "Tenemos " << max_total << " espacios disponibles." << endl;

    cout << "Espacios disponibles por tipo de vehiculo:" << endl;
    cout << "compacto " << max_compacto << endl;
    cout << "sedan: " << max_sedan << endl;
    cout << "suv: " << max_suv << endl;


    // Aqui se guardan los lugares que estan ocupados (true = ocupado)
    
    bool lugarecompacto[10] = {false};
    bool lugaressedan[8] = {false};
    bool lugaressuv[5] = {false};

    // Contadores para no recorrer los arreglos
    int ocupcompacto = 0;
    int ocupsedan = 0;
    int ocupsuv = 0;

    
    cout << "Ingrese su vehiculo para la entrada (Compacto, Sedan, Suv)" << endl;
    cout << "o el numero de lugar para la salida (ej. Suv01)" << endl;
    cout << "Escriba salir para terminar" << endl;

    string entrada = "";

    while (true) {
        cout << "> ";
        cin >> entrada;
        string entradaMin = aMinusculas(entrada);

        if (entrada == "salir") {
            cout << "Simulacion finalizada." << endl;
            break;
        }

        else if (entrada == "compacto" || entrada == "sedan" || entrada == "suv") {
            // Alguien quiere entrar
            bool seAcepto = false;
            int lugarAsignado = 0;

            if (entrada == "compacto") {
                for (int i = 0; i < max_compacto; i++) {
                    if (!lugarecompacto[i]) {
                        lugarecompacto[i] = true;
                        lugarAsignado = i + 1;
                        ocupcompacto++;
                        seAcepto = true;
                        break;
                    }
                }
            } else if (entrada == "sedan") {
                for (int i = 0; i < max_sedan; i++) {
                    if (!lugaressedan[i]) {
                        lugaressedan[i] = true;
                        lugarAsignado = i + 1;
                        ocupsedan++;
                        seAcepto = true;
                        break;
                    }
                }
            } else if (entrada == "suv") {
                for (int i = 0; i < max_suv; i++) {
                    if (!lugaressuv[i]) {
                        lugaressuv[i] = true;
                        lugarAsignado = i + 1;
                        ocupsuv++;
                        seAcepto = true;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < max_suv; i++) {
                    if (!lugaressuv[i]) {
                        lugaressuv[i] = true;
                        lugarAsignado = i + 1;
                        ocupsuv++;
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
                cout << "Compacto: " << ocupcompacto << "/" << max_compacto << " ocupados" << endl;
                cout << "Sedan: " << ocupsedan << "/" << max_sedan << " ocupados" << endl;
                cout << "Suv: " << ocupsuv << "/" << max_suv << " ocupados" << endl;
                int totalOcup = ocupcompacto + ocupsedan + ocupsuv;
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

            if (entrada.length() > 8 && entrada.substr(0, 8) == "compacto") {
                tipo = "compacto";
                largoTipo = 8;
            } else if (entrada.length() > 5 && entrada.substr(0, 5) == "sedan") {
                tipo = "sedan";
                largoTipo = 5;
            } else if (entrada.length() > 3 && entrada.substr(0, 3) == "suv") {
                tipo = "suv";
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
                    if (tipo == "compacto") capacidad = max_compacto;
                    else if (tipo == "sedan") capacidad = max_sedan;
                    else if (tipo == "suv") capacidad = max_suv;

                    if (numLugar < 1 || numLugar > capacidad) {
                        cout << "Salida invalida: el lugar " << entrada << " no existe." << endl;
                    } else {
                        int indice = numLugar - 1;
                        bool estabaOcupado = false;

                        if (tipo == "compacto") {
                            estabaOcupado = lugarecompacto[indice];
                            if (estabaOcupado) {
                                lugarecompacto[indice] = false;
                                ocupcompacto--;
                            }
                        } else if (tipo == "sedan") {
                            estabaOcupado = lugaressedan[indice];
                            if (estabaOcupado) {
                                lugaressedan[indice] = false;
                                ocupsedan--;
                            }
                        } else if (tipo == "suv") {
                            estabaOcupado = lugaressuv[indice];
                            if (estabaOcupado) {
                                lugaressuv[indice] = false;
                                ocupsuv--;
                            }
                        }

                        if (!estabaOcupado) {
                            cout << "Salida invalida: el lugar " << entrada << " ya estaba libre." << endl;
                        } else {
                            cout << "Vehiculo de lugar " << entrada << " ha salido." << endl;

                            cout << "--- ESTADO DEL ESTACIONAMIENTO ---" << endl;
                            cout << "compacto: " << ocupcompacto << "/" << max_compacto << " ocupados" << endl;
                            cout << "sedan: " << ocupsedan << "/" << max_sedan << " ocupados" << endl;
                            cout << "suv: " << ocupsuv << "/" << max_suv << " ocupados" << endl;
                            int totalOcup = ocupcompacto + ocupsedan + ocupsuv;
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