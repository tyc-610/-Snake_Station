#include "../inc/game.hpp"


Game::Game():_s(),_te(),_bmp(""),_pos(0,0)
{
    _s.init();
    cout<<"Game::Game()"<<endl;
    _map = new Map;
}

Game::~Game()
{
    cout<<"Game::~Game()"<<endl;
}

void Game::run()
{
    _map->draw(_s);
    cout<<"Game::run()"<<endl;
}



