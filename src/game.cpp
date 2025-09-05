#include "../inc/game.hpp"


Game::Game():_s(),_te(),_bmp(""),_pos(0,0)
{
    _s.init();
    cout<<"Game::Game()"<<endl;
    _map = new Map(&_s);
    _snake = new Snake(_map, &_te);
}

Game::~Game()
{
    cout<<"Game::~Game()"<<endl;
}

void Game::run()
{
    _map->draw();
    _snake->draw();
    cout<<"Game::run()"<<endl;
}



