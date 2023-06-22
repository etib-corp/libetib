/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** JSONParser
*/

#include "JSONParser.hpp"

JSONParser::JSONParser(std::string path)
{
    std::fstream file;
    std::stringstream ss;
    this->buff = "";
    file.open(path, std::ios::in);
    if (!file.is_open())
        return;
    ss << file.rdbuf();
    this->buff = ss.str();
    file.close();
}

JSONParser::~JSONParser()
{
}

bool JSONParser::parse(void)
{
    return true;
}
