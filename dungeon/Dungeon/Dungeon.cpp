#include "Dungeon.h"

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
            for(int i = 0;i<b.size();i++){
                if(b[i]->getTag() == "monster"){
                    cout<<b[i]->getTag()<<' '<<b[i]->getName()<<endl;
                }
            }
            for(int i = 0;i<b.size();i++){
                if(b[i] -> getTag() == "monster"){
                    cout<<"Would you want to fight?: Y/N"<<endl;
                    char ch;
                    cin>>ch;
                    if(ch == 'N') break;
                    else{
                        Player* a = &origin;
                        while(!(b[i]->triggerEvent(a)));
                        ////judging problem!!!
                        if(checkGameLogic()) break;
                        b = origin.getCurrentRoom()->getObjects();
                    }

                }
                else if(b[i] -> getTag() == "sword"){
                    cout<<"Would you want to change/put on the weapon?: YN"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.gamecharacter[0].getweaponname();
                    char ch;
                    cin >> ch;
                    if(ch == 'N') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                        b.erase(b.begin());
                    }
                }
                else if(b[i] -> getTag() == "dice"){
                    cout<<"Would you want to change/put on the weapon?: YN"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.gamecharacter[1].getweaponname();
                    char ch;
                    cin >> ch;
                    if(ch == 'N') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                        b.erase(b.begin());
                    }
                }
                else if(b[i] -> getTag() == "winebottle"){
                    cout<<"Would you want to change/put on the weapon?: YN"<<endl;
                    cout<<"this weapon: "<<b[i]->getName()<<" your weapon: "<<origin.gamecharacter[2].getweaponname();
                    char ch;
                    cin >> ch;
                    if(ch == 'N') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                        b.erase(b.begin());
                    }
                }
                else if(b[i] -> getTag() == "NPC"){
                    cout<<"Would you want to talk with him?: Y/N"<<endl;
                    char ch;
                    cin >> ch;
                    if(ch == 'N') continue;
                    else{
                        Player* a =&origin;
                        while(!(b[i] ->triggerEvent(a)));
                    }

                }
                else{
                    cout<<"Get "<<b[i]->getName()<<endl;
                    Player* a =&origin;
                    while(!(b[i] ->triggerEvent(a)));
                    b.erase(b.begin());
                }
                origin.getCurrentRoom()->setObjects(b);
                cout<<"Would you want to stop searching this room? (Y/N)"<<endl;
                char ch;
                cin>>ch;
                if(ch == 'Y') break;
            }
        }
}

void Dungeon::createMap()
{
    for(int i = 0;i<25;++i){
            if(i == 0 || i == 4 || i == 20 || i == 24){
                rooms.push_back(bathroom(i));
            }
            if(i == 2 || i == 7 || i == 10 || i == 11 || i == 13 || i == 14 || i == 17 || i == 22){
                rooms.push_back(corridor(i));
            }
            if(i == 6 || i == 8 || i == 16 || i == 18){
                rooms.push_back(restaurant(i));
            }
            if(i == 1){
                rooms.push_back(store(i, "sword"));
            }
            if(i == 3 || i == 21){
                rooms.push_back(store(i, "winebottle"));
            }
            if(i == 23){
                rooms.push_back(store(i, "dice"));
            }
            if(i == 5 || i == 9 || i == 15 || i == 19){
                rooms.push_back(store(i, "medicine"));
            }
            if(i == 12){
                rooms.push_back(center(i));
            }
            if(i != 4 && i != 9 && i != 14 && i != 19 && i != 24){
                Room* tem = &rooms[i+1];
                rooms[i].setRightRoom(tem);
            }
            if(i != 0 && i != 1 && i != 2 && i != 3 && i != 4){
                Room* tem = &rooms[i-5];
                rooms[i].setUpRoom(tem);
            }
            if(i != 0 && i != 5 && i != 10 && i != 15 && i != 20){
                Room* tem = &rooms[i-1];
                rooms[i].setLeftRoom(tem);
            }
            if(i != 20 && i != 21 && i != 22 && i != 23 && i != 24){
                Room* tem = &rooms[i+5];
                rooms[i].setDownRoom(tem);
            }
            if(i == 6 || i == 12 || i == 24){
                vector<Object*> a;
                a = rooms[i].getObjects();
                a.push_back(&money(10));
                a.push_back(&character_frag(1));
                rooms[i].setObjects(a);
            }
            if(i == 20){
                vector<Object*> a;
                a = rooms[i].getObjects();
                a.push_back(&key());
                rooms[i].setObjects(a);
            }
        }
        for(int i = 25;i<34;++i){
            if(i == 25 || i == 27 || i == 31 || i == 33){
                rooms.push_back(bathroom(i));
            }
            if(i == 28 || i == 30){
                rooms.push_back(restaurant(i));
            }
            if(i == 26){
                rooms.push_back(store(i, "medicine"));
            }
            if(i == 32){
                rooms.push_back(store(i, "dice"));
            }
            if(i == 29){
                rooms.push_back(center(i));
            }
            if(i != 25 && i != 26 && i != 27){
                Room* tem = &rooms[i - 3];
                rooms[i].setUpRoom(tem);
            }
            if(i != 25 && i != 28 && i != 31){
                Room* tem = &rooms[i-1];
                rooms[i].setLeftRoom(tem);
            }
            if(i != 31 && i != 32 && i != 33){
                Room* tem = &rooms[i+3];
                rooms[i].setDownRoom(tem);
            }
            if(i != 27 && i != 30 && i != 33){
                Room* tem = &rooms[i+1];
                rooms[i].setRightRoom(tem);
            }
            if(i == 29 || i == 33){
                vector<Object*> a;
                a = rooms[i].getObjects();
                a.push_back(&money(50));
                a.push_back(&character_frag(2));
                rooms[i].setObjects(a);
            }
            if(i == 11){
                vector<Object*> a;
                a = rooms[i].getObjects();
                a.push_back(&key());
                rooms[i].setObjects(a);
            }
        }
        rooms.push_back(center(34));
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
        cout<<"knight"<<endl;
        cout<<"HP: "<<origin.gamecharacter[0].getCurrentHealth()<<'/'<<origin.gamecharacter[0].getMaxHealth()<<endl;
        cout<<"Attack: "<<origin.gamecharacter[0].getAttack()<<endl;
        cout<<"Defense: "<< origin.gamecharacter[0].getAttack()<<endl;
        cout<<"weapon: "<<origin.gamecharacter[0].getweaponname()<<endl;
        if(origin.ch["gambler"]){
            cout<<"gambler"<<endl;
            cout<<"HP: "<<origin.gamecharacter[1].getCurrentHealth()<<'/'<<origin.gamecharacter[1].getMaxHealth()<<endl;
            cout<<"Attack: "<<origin.gamecharacter[1].getAttack()<<endl;
            cout<<"Defense: "<< origin.gamecharacter[1].getAttack()<<endl;
            cout<<"weapon: "<<origin.gamecharacter[1].getweaponname()<<endl;
        }
        else{
            cout<<"gambler"<<endl;
            cout<<"No unlock yet."<<endl;
        }
        if(origin.ch["8+9"]){
            cout<<"8+9"<<endl;
            cout<<"HP: "<<origin.gamecharacter[2].getCurrentHealth()<<'/'<<origin.gamecharacter[2].getMaxHealth()<<endl;
            cout<<"Attack: "<<origin.gamecharacter[2].getAttack()<<endl;
            cout<<"Defense: "<< origin.gamecharacter[2].getAttack()<<endl;
            cout<<"weapon: "<<origin.gamecharacter[2].getweaponname()<<endl;
        }
        else{
            cout<<"8+9"<<endl;
            cout<<"No unlock yet."<<endl;
        }
}

void Dungeon::handleMovement()
{
    bool complete = false;
        for (;;) {
            char ch;
            cout << "What do you want to do next?" << endl;
            cout << "(8: up/4: left/6: right/2: down/5: upstairs/ 0: downstairs)" << endl;
            cout << "*You can try to do another thing, there is a \" annoying easter egg\"~" << endl;
            cin >> ch;
            Room* a = origin.getCurrentRoom();
            switch (ch) {
            case '8':
                if(a->getUpRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a->getUpRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the front room..."<<endl;
                }
                break;
            case '4':
                if(a->getLeftRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a->getLeftRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the left room..."<<endl;
                }
                break;
            case '6':
                if(a->getRightRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a->getRightRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the right room..."<<endl;
                }
                break;
            case '2':
                if(a->getDownRoom() != NULL){
                    origin.setPreviousRoom(a);
                    origin.setCurrentRoom(a ->getDownRoom());
                    complete = true;
                }
                else{
                    cout<<"It doesn't have the down room"<<endl;
                }
                break;
            case '5':
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
            case '0':
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
            if ((ch == '5' || ch == '8' || ch == '4' || ch == '2' || ch == '6') && complete){
                complete = false;
                break;
            }
        }
}

void Dungeon::startGame()
{
    createPlayer();
        createMap();
}

void Dungeon::chooseAction()
{
    bool complete = false;
        for(;;){
            cout<<"What do you want to do next?"<<endl;
            cout<<"1: move/ 2: show character status/ 3: see what are in the room."<<endl;
            int choose;
            cin>>choose;
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
            default:
                cout<<"No this action~~"<<endl;
                break;
            }
            if(complete) break;
        }
}

bool Dungeon::checkGameLogic()
{
        if(origin.gamecharacter[0].getCurrentHealth() == 0 && origin.gamecharacter[1].getCurrentHealth() == 0 && origin.gamecharacter[2].getCurrentHealth() ==0){
            return true;
        }
        else if(origin.getCurrentRoom()->getIndex() == 34 && origin.getCurrentRoom()->getObjects().size() == 0){
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
        startGame();
        for(;;){
            chooseAction();
            if(checkGameLogic()){
                if(origin.gamecharacter[0].getCurrentHealth() == 0 && origin.gamecharacter[1].getCurrentHealth() == 0 && origin.gamecharacter[2].getCurrentHealth() ==0){
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
