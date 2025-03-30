#pragma once
#include "BLL.precompile.h"

class RegisterManager {
public:
    static bool registerUser(const std::string& username, const std::string& password);
};
