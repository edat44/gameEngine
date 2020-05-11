//
// Created by edat44 on 4/20/20.
//

#include <game/Game.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace game {

Game::Game() {
    this->engine = std::make_shared<Engine>();
    this->server = std::make_shared<network::Server>(9010, this->engine);
    this->engine->AddTicker(this);
}


void Game::Start(int winWidth, int winHeight, int winX, int winY, const std::string& winTitle) {
    std::cout << "Starting game..." << std::endl;
    this->server->SetActive(true);
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Close & sf::Style::Titlebar);
    this->window->setPosition({winX, winY});
    this->window->setActive(true);
    this->window->setVerticalSyncEnabled(true);
    this->engine->Run();
}

Game::~Game() {
    this->server->SetActive(false);
}

void Game::Tick(sf::Time dt) {
    std::cout << "Game ticking" << std::endl;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    auto event = std::make_shared<sf::Event>();
    while (this->window->pollEvent(*event)) {
        this->engine->Events()->Enqueue(event);
    }
    this->window->clear();
    this->window->draw(shape);
    this->window->display();
}

} // ns game
