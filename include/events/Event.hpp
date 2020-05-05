//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_EVENT_HPP
#define GAME_EVENT_HPP


#include <string>

class Event {
public:
    explicit Event(std::string type) : type(std::move(type)) {}

    virtual void Handle() = 0;
    [[nodiscard]] std::string GetType() const;

private:
    std::string type;
};


#endif //GAME_EVENT_HPP
