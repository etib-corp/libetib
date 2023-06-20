/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** JSONParser
*/

#ifndef JSONPARSER_HPP_
#define JSONPARSER_HPP_

#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <memory>
#include <fstream>

class 

class JSONParser {
    public:
        std::string buff;
        JSONParser(std::string path);
        ~JSONParser();
        bool parse(void);
    protected:
    private:
};

#endif /* !JSONPARSER_HPP_ */
