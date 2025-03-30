#pragma once
#include "DAL.precompile.h"

using json = nlohmann::json;

class FileManager {
public:
    static json loadJSON(const std::string& filename);
    static void saveJSON(const std::string& filename, const json& data);
};