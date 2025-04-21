#include "Crawler.h"
#include <vector>
#include <sstream>

using namespace std;

//getters and setters
int Crawler::getId() {
  return id;
}

int Crawler::getSize() {
  return size;
}

bool Crawler::getAlive() {

  return alive;
}

void Crawler::setId(int id) {
 	 this->id = id;
}

void Crawler::setSize(int size) {
	 this->size = size;
}


Direction Crawler::getDirection() {
  return dir;
}

void Crawler::setDirection(Direction dir) {
	 this->dir = dir;
}

void Crawler::setAlive(bool alive) {
  this->alive = alive;
}

Crawler::Crawler() {
}



//moves Crawler 1 space in the direction it's facing
void Crawler::move()
{
  bool blocked=wayIsBlocked(); //calls blocked function

  if (blocked) //sets a random direction value if it's blocked and then runs the function again to test the new direction.
  {
    int n = rand()%3;

    if (n==0)
    {
      dir = north;
    }

    else if (n==1)
    {
      dir = east;
    }

    else if (n==2)
    {
      dir = south;
    }

    else
    {
      dir = west;
    }

    move();
  }

  else
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



}//end of move(), in crawler


//since the grid is 10x10 0-9 it should hopefully check the direction, and if its on the edge (0 or 9) its blocked
//haven't tested yet, so might not even work
bool Crawler::wayIsBlocked()
{
  bool isblocked=false; //should stay and return false if no blocks

  if(dir==north && pos.y>=9)
    {
      isblocked=true;
    }

  else if(dir==east && pos.x>=9)
    {
      isblocked=true;
    }

  else if(dir==west && pos.x<=0)
    {
      isblocked=true;
    }

  else if(dir==south && pos.y<=0)
    {
      isblocked=true;
    }

  return isblocked;
}//end of wayIsBlocked(), in crawler