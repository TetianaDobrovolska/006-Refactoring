#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
public:
    static constexpr int kMaxNameSize = 80;
    const char kOSymbol = 'O';
    const char kXSymbol = 'X';

    Player(const char name[kMaxNameSize], const char symbol);

    const char * getName() const;
    const char getSymbol() const;
private:
    char PlayerName[kMaxNameSize];
    char Symbol;
};

#endif  //_PLAYER_H_