#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Gamebuino-Meta.h>

enum State {
  MAINMENU,
  FADEOUT,
  PLAYING
};

enum Type
{
  platform,
  ice,
  spring,
  fake_wall,
  player_spawn,
  fall_floor,
  player,
  room_title,
  balloon,
  big_chest,
  orb,
  fruit,
  fly_fruit,
  life_up,
  key,
  chest,
  message,
  flag
};

typedef uint8_t u8;

#define MAP_SIDE 16
#define MAP_SIZE MAP_SIDE*MAP_SIDE
#define MAX_OBJECTS 300

template <typename T>
struct Vec2
{
  T x {};
  T y {};
};

typedef Vec2<int> Point;
typedef Vec2<float> Vec2d;
typedef Vec2<bool> Bools;

struct Hitbox {
  int x = 0;
  int y = 0;
  int w = 8;
  int h = 8;
};

void draw_time(int x, int y);
bool spikes_at(int x, int y, int w, int h, int xspd, int yspd);
int tile_at(int x, int y);
bool tile_flag_at(int x, int y, int w, int h, u8 flag);
bool ice_at(int x, int y, int w, int h);
bool solid_at(int x, int y, int w, int h);
bool maybe();
int sign(int v);
float sign(float v);
int clamp(int val, int a, int b);
float clamp(float val, float a, float b);
int appr(int val, int target, int amount);
float appr(float val, float target, float amount);
void rectfill(int x1, int y1, int x2, int y2, int c);
void circfill(int x, int y, int r, int c);
void print(const char* txt, int x, int y, int c);
void drawSprite(int spr, int x, int y, bool flip_x = false, bool flip_y = false);
bool btn(Button bouton);
bool fget(int tile_id, u8 flag);
int level_index();
bool is_title();
void next_room();
float rnd(int x);

const Button k_left = BUTTON_LEFT;
const Button k_right = BUTTON_RIGHT;
const Button k_up = BUTTON_UP;
const Button k_down = BUTTON_DOWN;
const Button k_jump = BUTTON_A;
const Button k_dash = BUTTON_B;

// extern variables
extern int max_djump;
extern bool has_dashed;
extern bool has_key;
extern int freeze;
extern int frames;
extern bool pause_player;
extern int deaths;

class Object;
class Player;
class FallFloor;
class Spring;

extern Object * objects[];
extern int objects_count;
extern bool got_fruit[];
void add_object(Object * obj);
void destroy_object(Object * obj);
void kill_player(Player * player);
void init_object(Object * object, int x, int y);
void draw_time(int x, int y);

#endif

