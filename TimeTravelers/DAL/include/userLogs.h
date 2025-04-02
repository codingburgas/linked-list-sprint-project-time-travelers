#include "json.hpp"
#include <string>

class UserLogs {
public:
    static bool loadUserProgress(const std::string& username);

    static std::string updateUserProgress(const std::string& username, int eventYear);

    static bool saveUserProgress();

private:
    static std::string determineEra(int year);

    static std::string getArtifactForEra(const std::string& era);

    static nlohmann::json logsData;
};

