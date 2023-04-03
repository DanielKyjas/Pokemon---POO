// BatallaPokemon2_POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<windows.h> 
#include<string>
#include <vector>
using namespace std;

class Pokemon
{
    protected:
    //Atributos
    string nombre;
    string tipo;
    string color;
    int ataque;
    int vida;
    int vida2;
public:
    Pokemon()
    {
        nombre = "";
        tipo = "";
        color = "";
        ataque = 20;
        vida = 100;
        vida2 = vida;
    }
    Pokemon(string name, string type, string Color, int attack, int healthpoints)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
    }
    ~Pokemon()
    {
        
    }

    virtual void mostrar()
    {
        cout << "Su nombre es " << nombre << endl;
        cout << "Es tipo " << tipo << endl;
        cout << "De color " << color << endl;
        cout << "Con un ataque de " << ataque << " de danio" << endl;
        cout << "Y tiene " << vida << " puntos de vida" << endl;
    }
    virtual void mostrarContricante()
    {
        cout << "Tu contricante invoco a " << nombre << endl;
        cout << "Es tipo " << tipo << endl;
        cout << "De color " << color << endl;
        cout << "Con un ataque de " << ataque << " de danio" << endl;
        cout << "Y tiene " << vida << " puntos de vida" << endl;
    }
    virtual void atacar()
    {
        cout << "El pokemon ha atacado\n";
    }
    virtual void atacarfuerte()
    {
        cout << "El pokemon ha atacado fuerte\n";
    }
    string getnombre() { return nombre; }
    void setnombre(string name) { nombre = name; }
    string gettipo() { return tipo; }
    void settipo(string type) { tipo = type; }
    string getcolor() { return color; }
    void setcolor(string Color) { color = Color; }
    int getataque() { return ataque; }
    void setataque(int attack) { ataque = attack; }
    int getvida() { return vida; }
    void setvida(int healthpoints) { vida = healthpoints; }
    int getvida2() { return vida2; }
    void setvida2(int statichealth) { vida2 = statichealth; }

};
class PokemonAgua : public Pokemon
{
public:
    PokemonAgua() :Pokemon()
    {
        nombre = "hola";
        tipo = "agua";
        color = "azul";
        ataque = 15;
        vida = 90;
        vida2 = vida;
    }
    PokemonAgua(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
    }
    ~PokemonAgua()
    {
        
    }
    void atacar() override
    {
        ataque = 15;
        cout << nombre << " ha usado torrente" << endl;
    }
    void atacarfuerte() override
    {
        ataque = 22;
        cout << nombre << " ha usado tsunami" << endl;
    }
};
class PokemonFuego : public Pokemon
{
public:
    PokemonFuego() :Pokemon()
    {
        nombre = "";
        tipo = "fuego";
        color = "naranja";
        ataque = 25;
        vida = 70;
        vida2 = vida;
    }
    PokemonFuego(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
    }
    ~PokemonFuego()
    {
       
    }
    void atacar() override
    {
        ataque = 25;
        cout << nombre << " ha usado lanzallamas" << endl;
    }
    void atacarfuerte() override
    {
        ataque = 32;
        cout << nombre << " ha usado bomba ignea" << endl;
    }
};
class PokemonPlanta : public Pokemon
{
public:
    PokemonPlanta() :Pokemon()
    {
        nombre = "";
        tipo = "planta";
        color = "verde";
        ataque = 18;
        vida = 80;
        vida2 = vida;
    }
    PokemonPlanta(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
    }
    ~PokemonPlanta()
    {
       
    }
    void atacar() override
    {
        ataque = 18;
        cout << nombre << " ha usado hoja afilada" << endl;
    }
    void atacarfuerte() override
    {
        ataque = 25;
        cout << nombre << " ha usado raiz mortifera" << endl;
    }
};
class PokemonElectrico : public Pokemon
{
public:
    PokemonElectrico() :Pokemon()
    {
        nombre = "";
        tipo = "eletrico";
        color = "amarillo";
        ataque = 22;
        vida = 78;
        vida2 = vida;
    }
    PokemonElectrico(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
    }
    ~PokemonElectrico()
    {
        
    }
    void atacar() override
    {
        ataque = 22;
        cout << nombre << " ha usado trueno" << endl;
    }
    void atacarfuerte() override
    {
        ataque = 28;
        cout << nombre << " ha usado tormenta electrica" << endl;
    }
};


 void sanar(Pokemon* pokemon1)
{
     int vida = pokemon1->getvida();

    pokemon1->setvida(vida += 50);
    if (pokemon1->getvida() > pokemon1->getvida2())
    {
        pokemon1->setvida(pokemon1->getvida2());
    }
    cout << "El pokemon " << pokemon1->getnombre() << " se ha curado y ahora su vida es de " <<  pokemon1->getvida() << "\n";
}

 void Ataquenormal(Pokemon* pokemon1, Pokemon* pokemon2)
 {
     pokemon1->atacar();
     pokemon2->setvida(pokemon2->getvida() - pokemon1->getataque());
     cout << "la vida de " << pokemon2->getnombre() << " es " << pokemon2->getvida() << endl;
 }
 void AtaqueFuerte(Pokemon* pokemon1, Pokemon* pokemon2, int random)
 {
     if (random <= 50) {
         std::cout << pokemon1->getnombre() << " ha fallado\n";
     }
     else {
         pokemon1->atacarfuerte();
         pokemon2->setvida(pokemon2->getvida() - pokemon1->getataque());
         std::cout << "El ataque fue efectivo y ahora " << pokemon2->getnombre() << " tiene " << pokemon2->getvida() << " puntos de vida\n";
     }
 }

 void ganador(Pokemon* pokemon1, Pokemon* pokemon2)
 {
     if (pokemon1->getvida() > pokemon2->getvida()) {
         cout << "El pokemon " << pokemon1->getnombre() << " ha resultado victorioso" << endl;
         Sleep(3885);
     }
     else {

         cout << "El pokemon " << pokemon2->getnombre() << " ha resultado victorioso" << endl;
         Sleep(3885);

     }
     
 }


 int main()
 {
     bool eleccion = false;
     int numeropokemon = 4;
     int numeroeleccion = 3;
     int victoria = 0, acertar = 0, cura = 3, cura2 = 3;
     srand(time(NULL));

     Pokemon* peleador = new Pokemon[2];


     PokemonAgua* greninja = new PokemonAgua();
     greninja->setnombre("greninja");

     PokemonFuego* charizard = new PokemonFuego();
     charizard->setnombre("charizard");

     PokemonPlanta* bulbasaur = new PokemonPlanta();
     bulbasaur->setnombre("bulbasaur");

     PokemonElectrico* pikachu = new PokemonElectrico();
     pikachu->setnombre("pikachu");

     vector<Pokemon*> Combatiente;

     do {
         std::cout << "---------------------------------\n";
         std::cout << "|      Escoge a un pokemon      |\n";
         std::cout << "|       1.- para Greninja       |\n";
         std::cout << "|       2.- para Bulbasaur      |\n";
         std::cout << "|       3.- para Charizard      |\n";
         std::cout << "|       4.- para Pikachu        |\n";
         std::cout << "---------------------------------\n";
         cin >> numeropokemon;
         switch (numeropokemon) {
         case 1:
             greninja->mostrar();
             cout << "Seguro de tu eleccion? (1 para si y 0 para no)" << endl;
             cin >> eleccion;
             if (eleccion != 1) {
                 system("CLS");
                 break;
             }
             system("CLS");
             peleador[0] = *greninja;
             Combatiente.push_back(greninja);
             break;
         case 2:
             bulbasaur->mostrar();
             cout << "Seguro de tu eleccion? (1 para si y 0 para no)" << endl;
             cin >> eleccion;
             if (eleccion != 1) {
                 system("CLS");
                 break;
             }
             system("CLS");
             Combatiente.push_back(bulbasaur);
             break;
         case 3:
             charizard->mostrar();
             cout << "Seguro de tu eleccion? (1 para si y 0 para no)" << endl;
             cin >> eleccion;
             if (eleccion != 1) {
                 system("CLS");
                 break;
             }
             system("CLS");
             Combatiente.push_back(charizard);
             break;
         case 4:
             pikachu->mostrar();
             cout << "Seguro de tu eleccion? (1 para si y 0 para no)" << endl;
             cin >> eleccion;
             if (eleccion != 1) {
                 system("CLS");
                 break;
             }
             system("CLS");
             Combatiente.push_back(pikachu);
             break;
         default:
             cout << "Escoge una opcion valida\n";
             eleccion = 0;
             system("CLS");
             break;
         }
     } while (eleccion != true);
     int tupokemon = numeropokemon;
     do {
         numeropokemon = rand() % (4 - 1);
     } while (numeropokemon == tupokemon);
     switch (numeropokemon) {
     case 1:
         peleador[1] = *greninja;
         Combatiente.push_back(greninja);
         Combatiente[1]->mostrarContricante();
         break;
     case 2:
         Combatiente.push_back(bulbasaur);
         Combatiente[1]->mostrarContricante();
         break;
     case 3:
         Combatiente.push_back(charizard);
         Combatiente[1]->mostrarContricante();
         break;
     case 4:
         Combatiente.push_back(pikachu);
         Combatiente[1]->mostrarContricante();
         break;
     default:
         Combatiente.push_back(pikachu);
         Combatiente[1]->mostrarContricante();
         break;
     }
     do {
         do {
             std::cout << "-------------------------------------\n";
             std::cout << "|          Escoge a una accion       |\n";
             std::cout << "|       1.- Ataque normal (100%)     |\n";
             std::cout << "|       2.- Ataque fuerte (50%)      |\n";
             std::cout << "|       3.- Curar                    |\n";
             std::cout << "--------------------------------------\n";
             cin >> numeroeleccion;
             switch (numeroeleccion) {
             case 1:
                 Ataquenormal(Combatiente[0], Combatiente[1]);
                 break;
             case 2:
                 acertar = rand() % 101;
                 AtaqueFuerte(Combatiente[0], Combatiente[1], acertar);
                 break;
             case 3:
                 cura -= 1;
                 if (cura <= 0) {
                     cout << "Te has quedado sin medicina, asi que solo atacaras \n";
                     Ataquenormal(Combatiente[0], Combatiente[1]);
                 }
                 else {
                     sanar(Combatiente[0]);
                 }
                 break;
             default:
                 system("CLS");
                 cout << "escoge una opcion valida\n";
                 victoria = 0;
             }
         } while (numeroeleccion > 3);
             if (Combatiente[1]->getvida() < 30) {
                 numeroeleccion = 3;
             }
             else {
                 numeroeleccion = 1 + rand() % (3 - 1);
             }
             switch (numeroeleccion)
             {
             case 1: 
                 if (Combatiente[1]->getvida() <= 0) {
                     std::cout << "Fin de la batalla";
                     
                 }
                 else {
                     Ataquenormal(Combatiente[1], Combatiente[0]);
                 }
                 break;
             case 2:
                 if (Combatiente[1]->getvida() <= 0) {
                     std::cout << "Fin de la batalla";
                     
                 }
                 else {
                     acertar = rand() % 101;
                     AtaqueFuerte(Combatiente[1], Combatiente[0], acertar);
                 }
                 break;
             case 3:
                 if (Combatiente[1]->getvida() <= 0) {
                     std::cout << "Fin de la batalla";
                     
                     break;
                 }
                 else {
                     cura2 -= 1;
                     if (cura2 <= 0) {
                         cout << "El contricante se ha quedado sin medicina, asi que solo atacara \n";
                         Ataquenormal(Combatiente[1], Combatiente[0]);
                     }
                     else {
                         sanar(Combatiente[1]);
                     }
                 }
                 break;
             default:
                 if (Combatiente[1]->getvida() <= 0) {
                     std::cout << "Fin de la batalla";
                     
                 }
                 else {
                     Ataquenormal(Combatiente[1], Combatiente[0]);
                 }
                 break;
             }
             Sleep(3885);
             system("CLS");
         } while (Combatiente[0]->getvida() > 1 && Combatiente[1]->getvida() > 1);
         ganador(Combatiente[0], Combatiente[1]);
         delete greninja;
         delete charizard;
         delete bulbasaur;
         delete pikachu;
     }

