#include "Crawler.h"
#include <vector>

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
    //This keeps track of the crawlers path
    std::vector<Crawler*> crawlers;

  public:
    Crawler(int id, Position pos, Direction dir, int size)
        : id(id), pos(pos), dir(dir), size(size), alive(true) {
      crawlers.push_back(this);
        }

