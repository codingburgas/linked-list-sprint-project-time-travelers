#include "AIchat.h"
using json = nlohmann::json;

static std::string API_KEY = "AIzaSyAYeY2l75PWFTA_YWBwbYl1IKZUn-tV-Ag";
static std::string API_URL = "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-pro:generateContent?key=" + API_KEY;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void AIchat::startChat() {
    std::string userInput;
    std::string historicalFigure;

    std::cout << "\n===== AI Chat with Historical Figures =====\n";
    std::cout << "Who would you like to talk to? (e.g., Napoleon, Einstein): ";
    std::getline(std::cin >> std::ws, historicalFigure);

    std::cout << "Start chatting with " << historicalFigure << ". Type 'exit' to quit.\n";

    while (true) {
        std::cout << "\nYou: ";
        std::getline(std::cin, userInput);
        if (userInput == "exit") break;

        json request = {
            {"contents", json::array({
                {
                    {"role", "user"},
                    {"parts", json::array({
                        { {"text", "Pretend you are " + historicalFigure + ". " + userInput} }
                    })}
                }
            })}
        };

        std::string requestStr = request.dump();
        std::string readBuffer;
        CURL* curl = curl_easy_init();
        if (curl) {
            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, "Content-Type: application/json");

            curl_easy_setopt(curl, CURLOPT_URL, API_URL.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestStr.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            CURLcode res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);

            if (res != CURLE_OK) {
                std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
                continue;
            }

            try {
                auto response = json::parse(readBuffer);

                if (response.contains("candidates")) {
                    auto reply = response["candidates"][0]["content"]["parts"][0]["text"];
                    std::cout << historicalFigure << ": \"" << reply.get<std::string>() << "\"\n";
                }
                else if (response.contains("error")) {
                    std::cout << "API Error: " << response["error"]["message"] << "\n";
                }
                else {
                    std::cout << "Unexpected response format.\n";
                }
            }
            catch (const std::exception& e) {
                std::cout << "JSON Parse Error: " << e.what() << "\n";
            }
        }
    }

    std::cout << "\nExiting chat with " << historicalFigure << "...\n";
}
