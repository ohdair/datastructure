#ifndef PROJECT_H
# define PROJECT_H

# define  UP    0
# define  RIGHT 1
# define  DOWN  2
# define  LEFT  3

# define  MAPSIZE 7

int DIRECTION_OFFSETS[4][2] = {
    {0, -1}, // 위쪽으로이동.
    {1, 0}, // 오른쪽으로이동.
    {0, 1}, // 아래쪽으로이동.
    {-1, 0} // 왼쪽으로이동.
  };

void  move(t_coordinate *point, int direction);
int   isMovable(int map[][MAPSIZE], int x, int y);
void  findRoute(int map[][MAPSIZE]);

#endif