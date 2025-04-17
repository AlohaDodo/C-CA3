#ifndef CRAWLER_H
#define CRAWLER_H
#include <list>
#include <string>
using namespace std;

//Struct for position
struct Position
{
    int x;
    int y;

    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
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
    list<Position> path;

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
    //void addPathToHistory();
    //const list<Position> getPathHistory();
    Position pos;
//void move();
//void wayIsBlocked();

};
#endif //CRAWLER_H