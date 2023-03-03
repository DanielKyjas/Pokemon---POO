// Pokemon - POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Pokemon
{
public:
    //Atributos
    char nombre[15];
    char tipo[15];
    string color;
    int ataque;
    int vida;

public:
    Pokemon()
    {
        strcpy_s(nombre, "squirtle");
        strcpy_s(tipo, "agua");
        color = "azul";
        ataque = 50;
        vida = 100;
    }
    Pokemon(char n[15], char t[15], string c, int a, int v)
    {
        strcpy_s(nombre, n);
        strcpy_s(nombre, t);
        color = c;
        ataque = a;
        vida = v;
    }
    ~Pokemon()
    {
        cout << "Tu pokemon " << nombre << " ha sido destruido\n";
    }
    void sanar()
    {
        vida = vida + 50;
        cout << "Tu pokemon ha sido curado\nahora su vida es de " << vida << "\n\n";

    }
    void mostrar()
    {
        cout << "Has invocado a un pokemon:\n";
        cout << "Su nombre es " << nombre << endl;
        cout << "Es tipo " << tipo << endl;
        cout << "De color " << color << endl;
        cout << "Con un ataque de " << ataque << " de danio" << endl;
        cout << "Y tiene " << vida << " puntos de vida\n" << endl;

    }
    void mostrare()
    {
        cout << "Tu pokemon evoluciono:\n";
        cout << "Su nombre es " << nombre << endl;
        cout << "Es tipo " << tipo << endl;
        cout << "De color " << color << endl;
        cout << "Con un ataque de " << ataque * 1.30 << " de danio" << endl;
        cout << "Y tiene " << vida << " puntos de vida\n" << endl;

    }
    char* getnombre()
    {
        return nombre;
    }
    void setnombre(char n[15])
    {
        strcpy_s(nombre, n);
    }
    char* gettipo()
    {
        return tipo;
    }
    void settipo(char t[15])
    {
        strcpy_s(tipo, t);
    }
    string getcolor()
    {
        return color;
    }
    void setcolor(string c)
    {
        color = c;
    }
    int getataque()
    {
        return ataque;
    }
    void setataque(int a)
    {
        ataque = 50;
    }
    int getvida()
    {
        return vida;
    }
    void setvida(int v)
    {
        vida = 40;
    }

};
int main()
{
    Pokemon squirtle;
    squirtle.mostrar();
    squirtle.sanar();
    Pokemon evolucion;
    
    char Nom[15];
    char Tip[15];
    strcpy_s(Nom, "Wartortle");
    strcpy_s(Tip, "agua");
    evolucion.setnombre(Nom);
    evolucion.settipo(Tip);
    evolucion.setcolor("azul");
    evolucion.setataque(squirtle.ataque);

    evolucion.mostrare();
}



