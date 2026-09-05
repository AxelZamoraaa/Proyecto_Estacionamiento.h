
#include <iostream>
using namespace std;

int main() {
    cout << "Bienvenido al Estacionamiento" << endl;

    const int max_Compacto = 8;
    const int max_Sedan = 12;
    const int max_SUV = 5;
    const int max_total = max_Compacto + max_Sedan + max_SUV;
    cout << "Tenemos " << max_total << " espacios disponibles." << endl;

    cout << "Espacios disponibles por tipo de vehiculo:" << endl;
    cout << "Compacto: " << max_Compacto << endl;
    cout << "Sedan: " << max_Sedan << endl;
    cout << "SUV: " << max_SUV << endl;

    

    cout << "Ingrese el numero de espacios que va a usar y el tipo de vehiculo (Compacto, Sedan, SUV): ";
    int ocupados;
    cin >> ocupados;
    if (ocupados < 0 || ocupados > max_Compacto
    + max_Sedan + max_SUV) {
        cout << "Numero de espacios ocupados invalido." << endl;
        return 1;
    }

    cout << "Ha ingresado " << ocupados << " espacios ocupados." << endl;
    cout << "Espacios restantes: " << max_total - ocupados << endl;
    cout << "Espacios restantes por tipo de vehiculo:" << endl;
    cout << "Compacto: " << max_Compacto - ocupados << endl;
    cout << "Sedan: " << max_Sedan - ocupados << endl;
    cout << "SUV: " << max_SUV - ocupados << endl;
    
    int porcentajeOcupacion = (max_total - ocupados) * 100 / max_total;
    cout << "Porcentaje de ocupacion: " << porcentajeOcupacion << "%" << endl;
    cin.ignore(); // Limpiar el buffer de entrada


    string Nombre;
    cout << "Ingrese su nombre: ";
    cin >> Nombre;

    cout << "Hola, " << Nombre << endl;


    string tipoVehiculo;
    cout << "Ingrese el tipo de vehiculo (Compacto, Sedan, Suv): ";
    cin >> tipoVehiculo;

    cout << "Ha ingresado un vehiculo de tipo: " << tipoVehiculo << endl;

    string placa;
    cout << "Ingrese la placa del vehiculo: ";
    
    cin >> placa;
    cout << "La placa ingresada es: " << placa << endl;

    string color;
    cout << "Ingrese el color del vehiculo: ";
    cin >> color;
    cout << "El color ingresado es: " << color << endl;

    cout << "gracias por usar nuestro estacionamiento, " << Nombre << endl;


    string comando = "" ;
    while (comando != "salir") {
        cout << "Ingrese un comando (salir para terminar): ";
        cin >> comando;
        if (comando == "salir") {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Comando no reconocido: " << comando << endl;
        }
    }

    return 0;
}
