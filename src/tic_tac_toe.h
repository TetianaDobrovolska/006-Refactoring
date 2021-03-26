#ifndef TIC
#define TIC

extern char win;
extern char PlayerName1[80], PlayerName2[80];
extern char cells[9];

void show_cells();
void make_move(int num);

bool is_out_of_range(int cell);
bool is_occupied(int cell);
bool is_valid(int cell);

char check();
void result();

#endif
