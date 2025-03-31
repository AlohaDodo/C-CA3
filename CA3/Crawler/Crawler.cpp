#include "Crawler.h"
#include <vector>
#include <sstream>
#include <list>

using namespace std;

//Vector for Crawler
vector<Crawler*> crawlers;

int id = 101;
int size;
bool alive = alive;

//Struct for position
struct Position
{
  int x;
  int y;
};

//Enum for direction
enum Direction{
  north,
  east,
  south,
  west
}

//Class representing a bug/Crawler
class Crawler {
  private:
    int id;
    Position pos;
    Direction dir;
    int size;
    bool alive;

    }

//List for paths taken by the bug
List <Position> path;






