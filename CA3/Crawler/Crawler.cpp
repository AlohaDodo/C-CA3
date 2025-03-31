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
void move()  //still need to set random dir if blocked
{
  bool blocked=wayIsBlocked();

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


//since the grid is 10x10 0-9 it should hopefully check the direction, and if its on the edge (0 or 9) its blocked
//haven't tested yet, so might not even work
bool wayIsBlocked()
{
  bool isblocked=false; //should stay and return false if no blocks

  if(dir==north&&pos.y>=9)
    {
      isblocked=true;
    }

  else if(dir==east&&pos.x>=9)
    {
      isblocked=true;
    }

  else if(dir==west&&pos.x<=0)
    {
      isblocked=true;
    }

  else if(dir==south&&pos.y<=0)
    {
      isblocked=true;
    }

  return isblocked;
}//end of wayIsBlocked

};//end of crawler class


//List for paths taken by the bug
list <Position> path;