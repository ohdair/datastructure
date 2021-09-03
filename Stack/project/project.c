#include "linked_list.h"
#include "project.h"


int main () {
  
  int myMaze[MAPSIZE][MAPSIZE] = {
    {0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0},
  };

  findRoute(myMaze);

  return (0);
}

void move(t_coordinate *point, int direction)
{
  point->x += DIRECTION_OFFSETS[direction][0];
  point->y += DIRECTION_OFFSETS[direction][1];
}

/*
  인자로 넘겨진 위치가 이동가능한지? -> 맵크기비교 + 그 자리가 0인지?
*/
int isMovable(int map[][MAPSIZE], int x, int y)
{
  if (x < 0 || x > MAPSIZE - 1 || y < 0 || y > MAPSIZE - 1)
    return (0);
  if (map[y][x] == 1)
    return (0);
  return (1);
}

void  findRoute(int map[][MAPSIZE])
{
  t_coordinate  point;
  t_linked_list *list;

  list = ft_create_linked_list();
  point.x = 0;
  point.y = 0;

  while (!(point.x == MAPSIZE - 1 && point.y == MAPSIZE - 1)) {  
    map[point.y][point.x] = 1;
    //printf("[%d, %d]\n", point.x, point.y);
    if (isMovable(map, point.x, point.y - 1)) {
      ft_push(list, point);
      move(&point, UP);
      //printf("u");
    }
    else if (isMovable(map, point.x + 1, point.y)) {
      ft_push(list, point);
      move(&point, RIGHT);
      //printf("r");
    }
    else if (isMovable(map, point.x, point.y + 1)) {
      ft_push(list, point);
      move(&point, DOWN);
      //printf("d");
    }
    else if (isMovable(map, point.x - 1, point.y)) {
      ft_push(list, point);
      move(&point, LEFT);
      //printf("l");
    }
    else {  // 전부 못간다면
      if (point.x == 0 && point.y == 0) // 출구 없음!
      {
        printf("Error! No EXIT");
        exit(1);
      }
      point = ft_peek(list)->point; // 이전 위치로 이동
      ft_pop(list);
      //printf("what?\n");
    }
  }
  if (point.x == MAPSIZE - 1 && point.y == MAPSIZE - 1)
    ft_push(list, point);
  ft_reverse_linked_list(list); // 역순
  ft_print_linked_list(list); //출력
}