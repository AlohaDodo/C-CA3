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
    north=1,
    east=2,
    south=3,
    west=4
  };

//Class representing a bug/Crawler
class Crawler{

private:
    int id;
    Direction dir;
    int size;
    bool alive;

public:
    Crawler();
    void move();
    bool wayIsBlocked();
    int getId();
    int getSize();
    int getDirection();
    bool getAlive();
    void setId(int id);
    void setSize(int size);
    void setDirection(int dir);
    Position pos;

//void move();
//void wayIsBlocked();

};
#endif //CRAWLER_H