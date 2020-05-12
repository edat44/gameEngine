//
// Created by edat44 on 4/20/20.
//

#include <game/Game.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace game {

Game::Game() {
    this->mEngine = std::make_shared<Engine>();
    this->mServer = std::make_shared<network::Server>(9010, this->mEngine);
    //this->engine->AddTickable(this);
}


void Game::Start(int winWidth, int winHeight, int winX, int winY, const std::string& winTitle) {
    std::cout << "Starting game..." << std::endl;
    this->mServer->Activate();
    this->mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Close & sf::Style::Titlebar);
    this->mWindow->setPosition({winX, winY});
    this->mWindow->setActive(true);
    this->mWindow->setVerticalSyncEnabled(true);
    this->mEngine->Run();
}

Game::~Game() {
    this->mServer->Deactivate();
}

void Game::Tick(sf::Time dt) {
    std::cout << "Game ticking" << std::endl;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    auto event = std::make_shared<sf::Event>();
    while (this->mWindow->pollEvent(*event)) {
        this->mEngine->Events()->Enqueue(event);
    }
    this->mWindow->clear();
    this->mWindow->draw(shape);
    this->mWindow->display();
}

} // ns game
