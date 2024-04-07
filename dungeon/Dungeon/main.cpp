#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include "Room.h"


using namespace std;

int main(){
    /*Dungeon dungeon = Dungeon();
    dungeon.runDungeon();*/
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    return 0;
}
