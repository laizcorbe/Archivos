#include <iostream>
using namespace std;

/*
    Escriba un programa que permita a un usuario ingresar n valores floatt y se guarden en un
    archivo, el número n lo informa al comienzo del programa. Al finalizar el programa debe listar
    todos los números guardados en el archivo.
*/



int main()
{
    int n = 0;

    cout <<  "Ingrese el numero de valores queea agregar: " << endl;
    cin >> n;

    float v[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el valor N" << i << ": " << endl;
        cin >> v[i];
    }


    FILE* f;                                    //creo el archivo

    f = fopen("archivo_ejercicio_uno", "wb");   //abro el archivo en modo "wb" = Escribir y pisar

    fwrite(v, sizeof(float), n, f);             //ingreso los valores del vector v

    fclose(f);                                  //cierro el archivo

    f = fopen("archivo_ejercicio_uno", "rb");   //abro el archivo en modo "rb" = Leer

    int i = 0;
    if(f)
    {
        do
        {
            cout << "byte " << i*sizeof(float) << "= " << v[i] << endl;
            i++;
        }while(fread(v, sizeof(float), n, f));      //una vez que termine de leer todos ssale
    }

    fclose(f);                                  //cierro el archivo
    return 0;
}
