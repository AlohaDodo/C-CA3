#include "Crawler.h"
#include <vector>
#include <sstream>
#include <list>

using namespace std;

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
};

//Class representing a bug/Crawler
class crawler {
  private:
    int id;
    Position pos;
    Direction dir;
    int size;
    bool alive;

//moves Crawler 1 space in the direction it's facing
void move()//still need to add iswayblocked and set random dir if blocked
{
  if(dir==north)
    {
      pos.y+=1;
    }

  else if(dir==east)
    {
      pos.x+=1;
    }

    else if(dir==west)
    {
      pos.x-=1;
    }

    else
    {
      pos.y-=1;
    }

}//end of move()
};//end of crawler class

//List for paths taken by the bug
list <Position> path;
