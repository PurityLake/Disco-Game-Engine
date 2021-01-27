#pragma once

#include <exception>
#include <string>

namespace Disco {
    struct GameEngineException : public std::exception {
        std::string message;
        
        GameEngineException() : message("") { }
        GameEngineException(std::string message) : message(message) { }

        virtual const char *what() const throw () {
            return ("GameEngine Exception: " + message).c_str();
        }
    };

    struct WindowException : public GameEngineException {
        WindowException() : GameEngineException("") { }
        WindowException(std::string message) : GameEngineException(message) { }

        virtual const char *what() const throw () {
            return ("Window Exception: " + message).c_str();
        }
    };
}