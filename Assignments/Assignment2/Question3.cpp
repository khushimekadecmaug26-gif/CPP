#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

   
    Entity& setName(const string& name)
    {
        this->name = name;
        return *this;
    }

    
    Entity& setHealth(int health)
    {
        this->health = health;
        return *this;
    }

   
    Entity& setLevel(int level)
    {
        this->level = level;
        return *this;
    }

  
    Entity& setType(const string& type)
    {
        this->type = type;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

   
    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }


    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
    }
};


namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


// Part B - Nested Namespace

namespace Engine
{
    namespace Audio
    {
        void playSound(string name)
        {
            cout << "Playing: " << name << endl;
        }
    }
}


int level = 1;

int main()
{
 
    Entity player;
    Entity enemy;
    Entity item;


   
    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");


    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");


    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");


    // Display entities
    cout << "===== ENTITY INFORMATION =====" << endl;

    cout << "\nPlayer:" << endl;
    player.displayInfo();

    cout << "\nEnemy:" << endl;
    enemy.displayInfo();

    cout << "\nItem:" << endl;
    item.displayInfo();

    cout << "\n===== NAMESPACE EXAMPLE =====" << endl;

    double velocity = 120.5;

    cout << "Physics clamp: "
         << Physics::clamp(velocity, 0.0, 100.0)
         << endl;


    cout << "GameMath clamp: "
         << GameMath::clamp(150, 0, 100)
         << endl;


    cout << "Physics lerp: "
         << Physics::lerp(10.0, 20.0, 0.5)
         << endl;


    cout << "GameMath lerp: "
         << GameMath::lerp(10.0, 20.0, 0.5)
         << endl;


    {
        using namespace Physics;

        cout << "Using Physics namespace: "
             << clamp(150.0, 0.0, 100.0)
             << endl;
    }


    Engine::Audio::playSound("sword_clash");


    int level = 20;

    cout << "\n===== SCOPE RESOLUTION =====" << endl;

    cout << "Local level  : " << level << endl;
    cout << "Global level : " << ::level << endl;


    int R;
    int C;

    cout << "\nEnter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;

    int** gameMap = new int*[R];

    for (int i = 0; i < R; i++)
    {
        gameMap[i] = new int[C];
    }


    srand(time(0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            gameMap[i][j] = rand() % 5;
        }
    }


    // Display the map
    cout << "\n===== GAME MAP ("
         << R
         << " x "
         << C
         << ") ====="
         << endl;


    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << gameMap[i][j] << " ";
        }

        cout << endl;
    }


    // Legend
    cout << "\nLegend:" << endl;
    cout << "0 = Grass" << endl;
    cout << "1 = Water" << endl;
    cout << "2 = Mountain" << endl;
    cout << "3 = Forest" << endl;
    cout << "4 = Dungeon" << endl;



    int grass = 0;
    int water = 0;
    int mountain = 0;
    int forest = 0;
    int dungeon = 0;


    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (gameMap[i][j] == 0)
                grass++;

            else if (gameMap[i][j] == 1)
                water++;

            else if (gameMap[i][j] == 2)
                mountain++;

            else if (gameMap[i][j] == 3)
                forest++;

            else if (gameMap[i][j] == 4)
                dungeon++;
        }
    }


    cout << "\n===== TILE COUNT =====" << endl;

    cout << "Grass    : " << grass << endl;
    cout << "Water    : " << water << endl;
    cout << "Mountain : " << mountain << endl;
    cout << "Forest   : " << forest << endl;
    cout << "Dungeon  : " << dungeon << endl;


    
    for (int i = 0; i < R; i++)
    {
        delete[] gameMap[i];
    }

    delete[] gameMap;


    return 0;
}