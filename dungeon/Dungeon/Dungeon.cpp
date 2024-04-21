#include "Dungeon.h"

Dungeon::Dungeon()
{
    rooms.resize(35);
}

void Dungeon::createPlayer()
{
    string name;
    cout<<"Please enter your player's name:"<<endl;
    cin>>name;
    origin.setName(name);
    origin.setCurrentRoom(&rooms[0]);
    origin.setPreviousRoom(&rooms[0]);
}

void Dungeon::interaction()
{
    if(origin.getCurrentRoom()->getObjects().size() == 0){
            cout<<"There's nothing here~"<<endl;
        }
        else{
            vector<Object*> b = origin.getCurrentRoom()->getObjects();
            for (int i = 0; i < b.size(); i++) {
                if (b[i]->getTag() == "monster") {
                    cout << b[i]->getTag() << ' ' << b[i]->getName() << endl;
                }
            }
            for(int i = 0;i<b.size();i++){
                if(b[i] -> getTag() == "monster"){
                    char ch='x';
                    while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                        cout << "Would you want to fight?: Y/N" << endl;
                        string tem;
                        stringstream ss;
                        cin >> tem;
                        ss << tem;
                        ss >> ch;
                        if (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n') {
                            cout << "No this action~" << endl;
                        }
                    }
                    if(ch == 'N'||ch=='n') break;
                    else{
                        Player* a = &origin;
                        while(!(b[i]->triggerEvent(a)));
                        ////judging problem!!!
                        if(checkGameLogic()) break;
                        //b = origin.getCurrentRoom()->getObjects();
                    }

                }
                else if(b[i] -> getTag() == "sword"){
                    cout<<"Would you want to change/put on the weapon?: Y/N"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.weapon[0]->getName();
                    char ch='x';
                    while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                        string tem;
                        stringstream ss;
                        cin >> tem;
                        ss << tem;
                        ss >> ch;
                        if (ch != 'Y' && ch != 'N' && ch != 'n' && ch != 'y') {
                            cout << "follow the rules bro ^_^" << endl;
                            cout << "Would you want to change/put on the weapon?: Y/N" << endl;
                        }
                    }
                    if(ch == 'N' ||ch=='n') continue;
                    else{
                        Item* arm = dynamic_cast<Item*>(b[i]);
                        while (!(arm->triggerEvent(&origin)));
                        //origin.gamecharacter[0].weapon = *b[i];
                        //Player* a =&origin;
                       // while(!(b[i] ->triggerEvent(a)));
                        //b.erase(b.begin());//have problem
                    }
                }
                else if(b[i] -> getTag() == "dice"){
                    cout<<"Would you want to change/put on the weapon?: YN"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.weapon[1]->getName();
                    char ch='x';
                    while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                        string tem;
                        stringstream ss;
                        cin >> tem;
                        ss << tem;
                        ss >> ch;
                        if (ch != 'Y' && ch != 'N' && ch != 'n' && ch != 'y') {
                            cout << "follow the rules bro ^_^" << endl;
                            cout << "Would you want to change/put on the weapon?: Y/N" << endl;
                        }
                    }
                    if(ch == 'N'||ch=='n') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                        b.erase(b.begin());//have problem
                    }
                }
                else if(b[i] -> getTag() == "winebottle"){
                    cout<<"Would you want to change/put on the weapon?: YN"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.weapon[2]->getName();
                    char ch='x';
                    while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                        string tem;
                        stringstream ss;
                        cin >> tem;
                        ss << tem;
                        ss >> ch;
                        if (ch != 'Y' && ch != 'N' && ch != 'n' && ch != 'y') {
                            cout << "follow the rules bro ^_^" << endl;
                            cout << "Would you want to change/put on the weapon?: Y/N" << endl;
                        }
                    }
                    if(ch == 'N'||ch=='n') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                        b.erase(b.begin());//have problem
                    }
                }
                else if(b[i] -> getTag() == "NPC"){
                    cout<<"Would you want to talk with him?: Y/N"<<endl;
                    char ch='x';
                    while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                        string tem;
                        stringstream ss;
                        cin >> tem;
                        ss << tem;
                        ss >> ch;
                        if (ch != 'Y' && ch != 'N' && ch != 'n' && ch != 'y') {
                            cout << "follow the rules bro ^_^" << endl;
                            cout << "Would you want to talk with him?: Y/N" << endl;
                        }
                    }
                    if(ch == 'N'||ch=='n') continue;
                    else{
                        Player* a =&origin;
                        cout << b[i]->getName() << endl;
                        while(!(b[i] ->triggerEvent(a)));
                    }//END TALK TO NPC SHOULD BREAK

                }
                else{
                    cout<<"Get:"<<b[i]->getName()<<" amount: " << b[i]->getamount() << endl;
                    Player* a =&origin;
                    while(!(b[i] ->triggerEvent(a)));
                    origin.getCurrentRoom()->popObject(b[i]);
                    continue;
                    //b.erase(b.begin());
                }//should judge whether player dead
                if (checkGameLogic()) {
                    break;
                }
                //origin.getCurrentRoom()->setObjects(b);
                if (i == b.size() - 1 && b[i]->getTag()!="NPC") {
                    cout << "The room is completely empty~" << endl;
                    break;
                }
                char ch='x';
                while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                    cout << "Would you want to keep searching this room? (Y/N)" << endl;
                    string tem;
                    stringstream ss;
                    cin >> tem;
                    ss << tem;
                    ss >> ch;
                    if (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n') {
                        cout << "follow the rules bro ^_^" << endl;
                    }
                }
                if (ch == 'N'||ch=='n') {
                    //cout << "Except merchant, there is nothing." << endl;
                    break;
                }
                else if ((ch == 'Y' || ch == 'y')&&i==b.size()-1) {
                    cout << "There is no another stuff there." << endl;
                    break;
                }
            }
        }
}

void Dungeon::createMap()
{
    for (int i = 0; i<25; ++i) {
            if(i == 0 || i == 4 || i == 20 || i == 24){
                bathroom x = bathroom(i);
                rooms[i] = x;
            }
            if(i == 2 || i == 7 || i == 10 || i == 11 || i == 13 || i == 14 || i == 17 || i == 22){
                corridor x = corridor(i);
                rooms[i] = x;
               
            }
            if(i == 6 || i == 8 || i == 16 || i == 18){
                restaurant x = restaurant(i);
                rooms[i] = x;
            }
            if(i == 1){
                store x = store(i, "sword");
                rooms[i] = x;
            }
            if(i == 3 || i == 21){
                store x = store(i, "winebottle");
                rooms[i] = x;
            }
            if(i == 23){
                store x = store(i, "dice");
                rooms[i] = x;
            }
            if(i == 5 || i == 9 || i == 15 || i == 19){
                store x = store(i, "medicine");
                rooms[i] = x;
            }
            if(i == 12){
                center x = center(i);
                rooms[i] = x;
            }

    }
    rooms[0].setDownRoom(&rooms[5]);
    rooms[0].setRightRoom(&rooms[1]);
    rooms[1].setDownRoom(&rooms[6]);
    rooms[1].setLeftRoom(&rooms[0]);
    rooms[1].setRightRoom(&rooms[2]);
    rooms[2].setDownRoom(&rooms[7]);
    rooms[2].setLeftRoom(&rooms[1]);
    rooms[2].setRightRoom(&rooms[3]);
    rooms[3].setDownRoom(&rooms[8]);
    rooms[3].setLeftRoom(&rooms[2]);
    rooms[3].setRightRoom(&rooms[4]);
    rooms[4].setDownRoom(&rooms[9]);
    rooms[4].setLeftRoom(&rooms[3]);
    rooms[5].setDownRoom(&rooms[10]);
    rooms[5].setUpRoom(&rooms[0]);
    rooms[5].setRightRoom(&rooms[6]);
    rooms[6].setUpRoom(&rooms[1]);
    rooms[6].setDownRoom(&rooms[11]);
    rooms[6].setLeftRoom(&rooms[5]);
    rooms[6].setRightRoom(&rooms[7]);
    rooms[7].setUpRoom(&rooms[2]);
    rooms[7].setDownRoom(&rooms[12]);
    rooms[7].setLeftRoom(&rooms[6]);
    rooms[7].setRightRoom(&rooms[8]);
    rooms[8].setUpRoom(&rooms[3]);
    rooms[8].setDownRoom(&rooms[13]);
    rooms[8].setLeftRoom(&rooms[7]);
    rooms[8].setRightRoom(&rooms[9]);
    rooms[9].setUpRoom(&rooms[4]);
    rooms[9].setDownRoom(&rooms[14]);
    rooms[9].setLeftRoom(&rooms[8]);
    rooms[10].setUpRoom(&rooms[5]);
    rooms[10].setDownRoom(&rooms[15]);
    rooms[10].setRightRoom(&rooms[11]);
    rooms[11].setUpRoom(&rooms[6]);
    rooms[11].setDownRoom(&rooms[16]);
    rooms[11].setLeftRoom(&rooms[10]);
    rooms[11].setRightRoom(&rooms[12]);
    rooms[12].setUpRoom(&rooms[7]);
    rooms[12].setDownRoom(&rooms[17]);
    rooms[12].setLeftRoom(&rooms[11]);
    rooms[12].setRightRoom(&rooms[13]);
    rooms[13].setUpRoom(&rooms[8]);
    rooms[13].setDownRoom(&rooms[18]);
    rooms[13].setLeftRoom(&rooms[12]);
    rooms[13].setRightRoom(&rooms[14]);
    rooms[14].setUpRoom(&rooms[9]);
    rooms[14].setDownRoom(&rooms[19]);
    rooms[14].setLeftRoom(&rooms[13]);
    rooms[15].setUpRoom(&rooms[10]);
    rooms[15].setDownRoom(&rooms[20]);
    rooms[15].setRightRoom(&rooms[16]);
    rooms[16].setUpRoom(&rooms[11]);
    rooms[16].setDownRoom(&rooms[21]);
    rooms[16].setLeftRoom(&rooms[15]);
    rooms[16].setRightRoom(&rooms[17]);
    rooms[17].setUpRoom(&rooms[12]);
    rooms[17].setDownRoom(&rooms[22]);
    rooms[17].setLeftRoom(&rooms[16]);
    rooms[17].setRightRoom(&rooms[18]);
    rooms[18].setUpRoom(&rooms[13]);
    rooms[18].setDownRoom(&rooms[23]);
    rooms[18].setLeftRoom(&rooms[17]);
    rooms[18].setRightRoom(&rooms[19]);
    rooms[19].setUpRoom(&rooms[14]);
    rooms[19].setDownRoom(&rooms[24]);
    rooms[19].setLeftRoom(&rooms[18]);
    rooms[20].setUpRoom(&rooms[15]);
    rooms[20].setRightRoom(&rooms[21]);
    rooms[21].setUpRoom(&rooms[16]);
    rooms[21].setLeftRoom(&rooms[20]);
    rooms[21].setRightRoom(&rooms[22]);
    rooms[22].setUpRoom(&rooms[17]);
    rooms[22].setLeftRoom(&rooms[21]);
    rooms[22].setRightRoom(&rooms[23]);
    rooms[23].setUpRoom(&rooms[18]);
    rooms[23].setLeftRoom(&rooms[22]);
    rooms[23].setRightRoom(&rooms[24]);
    rooms[24].setUpRoom(&rooms[19]);
    rooms[24].setLeftRoom(&rooms[23]);
    for (int i = 0; i < 25; i++) {
        if (i == 6 || i == 12 || i == 24) {//money(10), character_frag(1)
            Object* tem = new money(10);
            rooms[i].addItem(tem);
            tem = new character_frag(2);
            rooms[i].addItem(tem);
        }
        if (i == 20) {//key()
            Object* tem = new key();
            rooms[i].addItem(tem);
        }
    }
    bathroom b25 = bathroom(25);
    rooms[25] = b25;
    store x26 = store(26, "medicine");
    rooms[26] = x26;
    bathroom b27 = bathroom(27);
    rooms[27] = b27;
    restaurant r28 = restaurant(28);
    rooms[28] = r28;//this one bug!!
    //rooms[0].setRightRoom(&rooms[1]);
    center c29 = center(29);
    rooms[29] = c29;
    restaurant r30 = restaurant(30);
    rooms[30] = r30;
    bathroom b31 = bathroom(31);
    rooms[31] = b31;
    store s32 = store(32, "dice");
    rooms[32] = s32;
    bathroom b33 = bathroom(33);
    rooms[33] = b33;
    rooms[25].setDownRoom(&rooms[28]);
    rooms[25].setRightRoom(&rooms[26]);
    rooms[26].setDownRoom(&rooms[29]);
    rooms[26].setLeftRoom(&rooms[25]);
    rooms[26].setRightRoom(&rooms[27]);
    rooms[27].setDownRoom(&rooms[30]);
    rooms[27].setLeftRoom(&rooms[26]);
    rooms[28].setUpRoom(&rooms[25]);
    rooms[28].setDownRoom(&rooms[31]);
    rooms[28].setRightRoom(&rooms[29]);
    rooms[29].setUpRoom(&rooms[26]);
    rooms[29].setDownRoom(&rooms[32]);
    rooms[29].setLeftRoom(&rooms[28]);
    rooms[29].setRightRoom(&rooms[30]);
    rooms[30].setUpRoom(&rooms[27]);
    rooms[30].setDownRoom(&rooms[33]);
    rooms[30].setLeftRoom(&rooms[29]);
    rooms[31].setUpRoom(&rooms[29]);
    rooms[31].setRightRoom(&rooms[32]);
    rooms[32].setUpRoom(&rooms[29]);
    rooms[32].setLeftRoom(&rooms[31]);
    rooms[32].setRightRoom(&rooms[33]);
    rooms[33].setUpRoom(&rooms[30]);
    rooms[33].setLeftRoom(&rooms[32]);
    for (int i = 25; i < 34; i++) {
        if (i == 29 || i == 33) {//money(50), character_frag(2)
            Object* tem = new money(50);
            rooms[i].addItem(tem);
            tem = new character_frag(2);
            rooms[i].addItem(tem);
        }
        if (i == 31) {//key
            Object* tem = new key();
            rooms[i].addItem(tem);
        }
    }

    center x1 = center(34);
    rooms[34] = x1;
    Room* tem = &rooms[29];
    rooms[12].setupstairs(tem);
    tem = &rooms[34];
    rooms[29].setupstairs(tem);
    tem = &rooms[12];
    rooms[29].setdownstairs(tem);
    tem = &rooms[29];
    rooms[34].setdownstairs(tem);
        
}

void Dungeon::showplayerstatus()
{
    cout<<"Player's name: "<<origin.getName()<<endl;
    cout << "You are in " << origin.getCurrentRoom()->getIndex() <<" room" << endl;
    cout << "You stuff: "<<endl;
    vector<Item> b = origin.getInventory();
    for (int i = 0; i < b.size(); i++) {
        if (b[i].getamount() > 0) {
            cout << b[i].getName() << ' ' << b[i].getamount() << endl;
        }
    }
    cout << "\n---------------------------------------------\n";
        cout<<"knight"<<endl;
        cout<<"HP: "<<origin.gamecharacter[0].getCurrentHealth()<<'/'<<origin.gamecharacter[0].getMaxHealth()<<endl;
        cout<<"Attack: "<<origin.gamecharacter[0].getAttack()<<endl;
        cout<<"Defense: "<< origin.gamecharacter[0].getDefense()<<endl;
        if (origin.weapon[0] != NULL) {
            cout << "weapon: " << origin.weapon[0]->getName() << endl;
        }
        else {
            cout << "No weapon now."<<endl;
        }
        cout << "active skill   strong defense:  double for the defense during two round. CD 3" << endl;
        cout << "passive skill   Dauntless Escort:  immune death for once." << endl;
        cout << "\n---------------------------------------------\n";
        if(origin.ch["gambler"]){
            cout<<"gambler"<<endl;
            cout<<"HP: "<<origin.gamecharacter[1].getCurrentHealth()<<'/'<<origin.gamecharacter[1].getMaxHealth()<<endl;
            cout<<"Attack: "<<origin.gamecharacter[1].getAttack()<<endl;
            cout<<"Defense: "<< origin.gamecharacter[1].getDefense()<<endl;
            if (origin.weapon[1] != NULL) {
                cout << "weapon: " << origin.weapon[1]->getName() << endl;
            }
            else {
                cout << "No weapon now." << endl;
            }
            cout << "active skill   recover magically:   get +5 health CD:5" << endl;
            cout << "passive skill   complete defense:   20% immune the next damage." << endl;
        }
        else{
            cout<<"gambler"<<endl;
            cout<<"No unlock yet."<<endl;
        }
        cout << "\n---------------------------------------------\n";
        if(origin.ch["8+9"]){
            cout<<"8+9"<<endl;
            cout<<"HP: "<<origin.gamecharacter[2].getCurrentHealth()<<'/'<<origin.gamecharacter[2].getMaxHealth()<<endl;
            cout<<"Attack: "<<origin.gamecharacter[2].getAttack()<<endl;
            cout<<"Defense: "<< origin.gamecharacter[2].getDefense()<<endl;
            if (origin.weapon[2] != NULL) {
                cout << "weapon: " << origin.weapon[2]->getName() << endl;
            }
            else {
                cout << "No weapon now" << endl;
            }
            cout << "active skill   beat to death:   make double attack damage.  CD: 2" << endl;
            cout << "passive skill   more fight more brave:   when health<5, attack+3 defense +3" << endl;
        }
        else{
            cout<<"8+9"<<endl;
            cout<<"No unlock yet."<<endl;
        }
        cout << "\n---------------------------------------------\n";
}

void Dungeon::handleMovement()
{
    bool complete = false;
        for (;;) {
            int ch;
            cout << "What do you want to do next?" << endl;
            cout << "8: up\n4: left\n6: right\n2: down\n5: upstairs\n3: downstairs" << endl;
            string tem;
            stringstream ss;
            cin >> tem;
            ss << tem;
            ss >> ch;
            Room* a = origin.getCurrentRoom();
            switch (ch) {
            case 8:
                if(a->getUpRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a->getUpRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the front room..."<<endl;
                }
                break;
            case 4:
                if(a->getLeftRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a->getLeftRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the left room..."<<endl;
                }
                break;
            case 6:
                if(a->getRightRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(origin.getPreviousRoom()->getRightRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the right room..."<<endl;
                }
                break;
            case 2:
                if(a->getDownRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a ->getDownRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the down room"<<endl;
                }
                break;
            case 5:
                if(a -> getupstairs() != NULL){
                    if(a -> getlock() == true){
                        origin.setPreviousRoom(a);
                        origin.setCurrentRoom(a ->getupstairs());
                        complete = true;
                    }
                    else{
                        if(a ->islock(origin)){
                            cout<<"Congulation! unlock"<<endl;
                            origin.setPreviousRoom(a);
                            origin.setCurrentRoom(a ->getupstairs());
                            complete = true;
                        }
                        else{
                            cout<<"Oh, you don't have the key..."<<endl;
                        }
                    }
                }
                else{
                    cout<<"It doesn't have the upstairs..."<< endl;
                }
                break;
            case 3:
                if(a-> getdownstairs() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a -> getdownstairs());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the downstairs..."<<endl;
                }
                break;
            default:
                cout << "HaHa, come on, don't be silly~" << endl;
                break;
            }
            if ((ch == 5 || ch == 8 || ch == 4 || ch == 2 || ch == 6||ch==3) && complete){
                cout <<"you now are in: " << origin.getCurrentRoom()->getIndex() << endl;
                complete = false;
                break;
            }
        }
}

void Dungeon::startGame()
{
    createMap();
    createPlayer();   
}

void Dungeon::chooseAction()
{
    bool complete = false;
        for(;;){
            bool complete1 = false;
            int a = 0;
            cout<<"What do you want to do next?"<<endl;
            cout<<"1: move\n2: show character status\n3: see what are in the room.\n4: show map.\n5: increasing your character(you should have 20money)\n"<<endl;
            int choose =9;
            int choose1 = 0;
            string tem;
            stringstream ss;
            stringstream sss;
            cin >> tem;
            ss << tem;
            ss >> choose;
            switch(choose){
            case 1:
                handleMovement();
                complete = true;
                break;
            case 2:
                showplayerstatus();
                complete = true;
                break;
            case 3:
                interaction();
                complete = true;
                break;
            case 4:
                showmap();
                complete = true;
                break;
            case 5:
                complete1 = false;
                if (origin.getmoney() > 20) {
                    int i = 0;
                    while (i != 1 && i != 2 && i != 3) {
                        cout << "which character you want to enhance\n";
                        cout << "1: knight\n2: gambler\n3: 8+9"<<endl;
                        cin >> i;
                        if (i != 1 && i != 2 && i != 3) {
                            cout << "No this one" << endl;
                        }
                        if (i == 2 && origin.ch["gambler"] == false) {
                            cout << "This character still unlock" << endl;
                            i = 0;
                        }
                        if (i == 3 && origin.ch["8+9"]==false) {
                            cout << "This character still unlock" << endl;
                            i = 0;
                        }
                    }
                    while (1) {
                        cout << "which one you want to inhance:\n";
                        cout << "1: attack\n2: defense" << endl;
                        cin >> tem;
                        sss << tem;
                        sss >> choose1;
                        switch (choose1) {
                        case 1:
                            a = origin.gamecharacter[i-1].getAttack();
                            origin.gamecharacter[i-1].setAttack(a+1);
                            cout << "enhance attack complete!" << endl;
                            complete = true;
                            complete1 = true;
                            break;
                        case 2:
                            a = origin.gamecharacter[i-1].getDefense();
                            origin.gamecharacter[i-1].setDefense(a+1);
                            cout << "enhance defense complete!" << endl;
                            complete = true;
                            complete1 = true;
                            break;
                        default:
                            cout << "No this order~" << endl;
                            break;
                        }
                        vector<Item> b = origin.getInventory();
                        vector<Item>::iterator it;
                        for (it=b.begin(); it->getName() != "money" && it != b.end(); it++) {
                            if (it->getName() != "money" && it + 1 == b.end()) {
                                break;
                            }
                        }
                        it->addamount(-20);
                        origin.setInventory(b);
                        if (complete1) break;
                    }
                }
                else {
                    cout << "You don't have enough money\n";
                }
                break;
            default:
                cout<<"No this action~~"<<endl;
                break;
            }
            if(complete) break;
        }
}

bool Dungeon::checkGameLogic()
{
        if((origin.gamecharacter[0].getCurrentHealth() == 0)&&(origin.ch["gambler"] == false || origin.gamecharacter[1].getCurrentHealth()==0)&&(origin.ch["8+9"] == false || origin.gamecharacter[2].getCurrentHealth()==0)) {
            return true;
        }
        else if(rooms[34].getObjects().size() == 0){
            return true;
        }
        else{
            return false;
        }
}

void Dungeon::runDungeon()
{
    bool winorlose;
        cout<<"Hello, welcome to dungeon!"<<endl;
        cout << "In here, you have to clear the top room, where the final boss live." << endl;
        cout << "if you complete the mission, you win, so easy huh^_^" << endl;
        cout << "Now let's us start!" << endl;
        cout << "--------------------------" << endl;
        startGame();
        for(;;){
            chooseAction();
            if(checkGameLogic()){
                if((origin.gamecharacter[0].getCurrentHealth() == 0) && (origin.ch["gambler"] == false || origin.gamecharacter[1].getCurrentHealth() == 0) && (origin.ch["8+9"] == false || origin.gamecharacter[2].getCurrentHealth() == 0)){
                    winorlose = false;
                    break;
                }
                else{
                    winorlose = true;
                    break;
                }
            }
        }
        if(winorlose){
            cout<<"Congulation, you win!!"<<endl;
            }
        else{
                cout<<"Oh, you lose"<<endl;
        }
        
}

void Dungeon::showmap() {
    if (origin.getCurrentRoom()->getIndex() < 25) {
        cout << "00   01   02   03   04" << endl;
        cout << "05   06   07   08   09" << endl;
        cout << "10   11   12   13   14" << endl;
        cout << "15   16   17   18   19" << endl;
        cout << "20   21   22   23   24" << endl;
        cout << "\n merchants are in: 01   03   05   09   15   19   21   23\n";
        cout << "You are in: " << origin.getCurrentRoom()->getIndex()<<endl;
    }
    else if (origin.getCurrentRoom()->getIndex() > 24 && origin.getCurrentRoom()->getIndex() < 34) {
        cout << "25   26   27" << endl;
        cout << "28   29   30" << endl;
        cout << "31   32   33" << endl;
        cout << "\n merchants are in: 26   32\n";
        cout << "You are in: " << origin.getCurrentRoom()->getIndex() << endl;
    }
    else {
        cout << "Just this room. clear this room and get win!!" << endl;
    }

}
