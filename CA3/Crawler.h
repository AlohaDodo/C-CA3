#ifndef CRAWLER_H
#define CRAWLER_H

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
class Crawler{

public:
    int id;
    Position pos;
    Direction dir;
    int size;
    bool alive;

    void move();
    bool wayIsBlocked();
};

void move();
void wayIsBlocked();


#endif //CRAWLER_H