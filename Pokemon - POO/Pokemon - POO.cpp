// Pokemon - POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<windows.h> 
#include<string>
using namespace std;

class Pokemon
{
protected:
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
        strcpy_s(tipo, t);
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
        ataque = a;
    }
    int getvida()
    {
        return vida;
    }
    void setvida(int v)
    {
        vida = v;
    }

};
class PokemonAgua : public Pokemon
{
    int tiempoAgua;
    int tiempoAire;

public:
    PokemonAgua() :Pokemon()
    {
        strcpy_s(tipo, "agua");
        tiempoAgua = 0;
        tiempoAire = 0;
    }
    PokemonAgua(int TA, int TAR, char n[15], char t[15], string c, int a, int v) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        tiempoAgua = TA;
        tiempoAire = TAR;
        strcpy_s(nombre, n);
        strcpy_s(tipo, t);
        color = c;
        ataque = a;
        vida = v;
    }
    ~PokemonAgua()
    {

    }
    void mostrarPA()
    {
        cout << "El tiempo que paso tu pokemon en el agua es de " << tiempoAgua << " segundos\n";
        cout << "El tiempo que paso tu pokemon en el aire es de " << tiempoAire << " segundos\n\n";
    }
    void nadar()
    {
        tiempoAgua += 5;
        cout << "Tu pokemon ha nadado\n";

    }
    int gettiempoAgua() { return tiempoAgua; }
    int gettiempoAire() { return tiempoAire; }
    void settiempoAgua(int TA) { tiempoAgua = 0; }
    void settiempoAire(int TAR) { tiempoAire = 0; }
};
class PokemonPlanta : public Pokemon
{
    int tiempoVida;
    string Olor;
public:
    PokemonPlanta() :Pokemon()
    {
        tiempoVida = 5000;
        Olor = "pasto";
        strcpy_s(tipo, "planta");
        color = "verde";
    }
    PokemonPlanta(int TV, string o, char n[15], char t[15], string c, int a, int v) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        tiempoVida = TV;
        Olor = o;
        strcpy_s(nombre, n);
        strcpy_s(tipo, t);
        color = c;
        ataque = a;
        vida = v;
    }
    ~PokemonPlanta()
    {

    }
    void mostrarPP()
    {
        cout << "El tiempo que tarda tu pokemon en curarse es de " << tiempoVida/1000 << " segundos\n";
        cout << "Tu pokemon huele a " << Olor << "\n";
    }
    void fotosintesis()
    {
        cout << "Tu pokemon se esta curando\n";
        Sleep(tiempoVida);
        vida = vida + 50;
        cout << "Tu pokemon se ha curado\n\n";

    }
    int gettiempoAgua() { return tiempoVida; }
    string gettiempoAire() { return Olor; }
    void settiempoAgua(int TA) { tiempoVida = 0; }
    void settiempoAire(string TAG) { Olor = "paston m"; }
};
class PokemonFuego : public Pokemon
{
    int temperatura;

public:
    PokemonFuego() : Pokemon()
    {
        temperatura = 20;
        strcpy_s(tipo, "fuego");
        color = "rojo";
    }
    PokemonFuego(int temp, char n[15], char t[15], string c, int a, int v) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        temperatura = temp;
        strcpy_s(nombre, n);
        strcpy_s(tipo, t);
        color = c;
        ataque = a;
        vida = v;
    }
    ~PokemonFuego()
    {

    }
    void mostrarPF()
    {
        cout << "Tu pokemon tiene una temperatura de " << temperatura << " grados celcius\n";
    }
    void AumentarTemperatura()
    {
        temperatura += 30;
        cout << "Tu pokemon aumento su temperatura\n";
    }
    int gettemperatura() { return temperatura; }
    void settemperatura(int t) { temperatura = 20; }
};
class PokemonElectrico : public Pokemon
{
    int voltaje;
    int corriente;
    int potencia;
public:
    PokemonElectrico() : Pokemon()
    {
        voltaje = 100;
        corriente = 25;
        potencia = 200;
        strcpy_s(tipo, "electrico");
        color = "amarillo";
    }
    PokemonElectrico(int vol, int cor, int po, char n[15], char t[15], string c, int a, int v) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        voltaje = vol;
        corriente = cor;
        potencia = po;
        strcpy_s(nombre, n);
        strcpy_s(tipo, t);
        color = c;
        ataque = a;
        vida = v;
    }
    ~PokemonElectrico()
    {

    }
    void mostrarPE()
    {
        cout << "Tu pokemon tiene un voltaje de " << voltaje << " voltios\n";
        cout << "Una corriente de " << corriente << " amperes\n";
        cout << " Y una potencia de " << potencia << " Joules\n";
    }
    void PrenderFoco()
    {
        cout << "Has comandado a tu pokemon a prender un foco\n";
        voltaje += 10;
        corriente = voltaje / 4;
        potencia = voltaje * 2;
    }
    int getvoltaje() { return voltaje; }
    int getcorriente() { return corriente; }
    int getpotencia() {}
};
int main()
{
    char AuxPA[15];
    strcpy_s(AuxPA, "Greninja");
    char Auxt[15];
    strcpy_s(Auxt, "agua");

    Pokemon squirtle;
    squirtle.mostrar();
    squirtle.sanar();

    PokemonAgua Greninja;
    Greninja.setnombre(AuxPA);
    Greninja.settipo(Auxt);
    Greninja.setataque(60);
    Greninja.setvida(120);
    Greninja.mostrar();
    Greninja.mostrarPA();
    Greninja.nadar();
    Greninja.mostrarPA();

    char NomPP[15];
    strcpy_s(NomPP, "Bulbasour");
    PokemonPlanta Bulbasour;
    Bulbasour.setnombre(NomPP);
    Bulbasour.setataque(60);
    Bulbasour.setvida(120);
    Bulbasour.mostrar();
    Bulbasour.mostrarPP();
    Bulbasour.fotosintesis();

    char NomPF[15];
    strcpy_s(NomPF, "Charizard");
    PokemonFuego Charizard;
    Charizard.setnombre(NomPF);
    Charizard.setataque(100);
    Charizard.setvida(150);
    Charizard.mostrar();
    Charizard.mostrarPF();
    Charizard.AumentarTemperatura();
    Charizard.mostrarPF();

    char NomPE[15];
    strcpy_s(NomPE, "Pikachu");
    PokemonElectrico Pikachu;
    Pikachu.setnombre(NomPE);
    Pikachu.setataque(90);
    Pikachu.setvida(90);
    Pikachu.mostrar();
    Pikachu.mostrarPE();
    Pikachu.PrenderFoco();
    Pikachu.mostrarPE();

}


