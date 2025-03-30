#pragma once
#include "BLL.precompile.h"

class LoginManager {
public:
    static bool login(const std::string& username, const std::string& password);
};