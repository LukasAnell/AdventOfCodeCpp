//
// Created by Lukas on 8/28/2024.
//

#include "utils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <regex>
#include <unordered_set>

std::vector<std::string> utils::readFile(const std::string& fileName, const int year, const int dayNumber, const bool isSample) {
    std::string fullFileName = "..\\Year" + std::to_string(year) + "\\";
    if (isSample) {
        fullFileName += "Sample";
    }
    fullFileName += "Inputs\\day" +  std::to_string(dayNumber) + fileName;
    std::ifstream file(fullFileName);

    std::vector<std::string> output;
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {\
            if(line.empty()) {
                output.emplace_back("");
            } else {
                output.push_back(line);
            }
        }
    } else {
        std::cout << "File failed to open" << std::endl;
    }

    return output;
}

std::vector<std::string> utils::splitString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> output;
    size_t start = 0;
    size_t end = input.find(delimiter);
    while (end != std::string::npos) {
        output.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    output.push_back(input.substr(start, end));
    return output;
}

std::vector<int> utils::extractInts(const std::string& str) {
    std::vector<int> result;
    const std::regex re("-?\\d+");
    std::sregex_iterator next(str.begin(), str.end(), re);
    const std::sregex_iterator end;
    while (next != end) {
        result.push_back(std::stoi(next->str()));
        ++next;
    }
    return result;
}

std::string utils::toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string utils::toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string utils::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::string utils::joinStrings(const std::vector<std::string>& strings, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < strings.size(); ++i) {
        if (i != 0) {
            oss << delimiter;
        }
        oss << strings[i];
    }
    return oss.str();
}

bool utils::fileExists(const std::string& filePath) {
    return std::filesystem::exists(filePath);
}

std::string utils::replaceSubstring(const std::string& str, const std::string& from, const std::string& to) {
    std::string result = str;
    size_t start_pos = 0;
    while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
        result.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return result;
}

int utils::stringToInt(const std::string& str) {
    return std::stoi(str);
}

double utils::stringToDouble(const std::string& str) {
    return std::stod(str);
}

std::string utils::generateRandomString(const size_t length) {
    constexpr char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    std::string result;
    result.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        result += charset[dist(rng)];
    }
    return result;
}

bool utils::isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string utils::reverseString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

std::vector<int> utils::removeDuplicates(const std::vector<int>& vec) {
    std::unordered_set<int> seen;
    std::vector<int> result;
    for (int value : vec) {
        if (seen.insert(value).second) {
            result.push_back(value);
        }
    }
    return result;
}

std::vector<int> utils::findAndReplace(std::vector<int>& vec, const int oldVal, const int newVal) {
    std::replace(vec.begin(), vec.end(), oldVal, newVal);
    return vec;
}

std::string utils::vectorToString(const std::vector<int>& vec, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != 0) {
            oss << delimiter;
        }
        oss << vec[i];
    }
    return oss.str();
}

bool utils::contains(const std::vector<int>& vec, const int element) {
    return std::ranges::find(vec, element) != vec.end();
}

std::string utils::getCurrentDateTime() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    const std::tm nowTm = *std::localtime(&nowTime);
    std::ostringstream oss;
    oss << std::put_time(&nowTm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string utils::formatTime(const std::chrono::system_clock::time_point& timePoint, const std::string& format) {
    const std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    const std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, format.c_str());
    return oss.str();
}

std::chrono::system_clock::time_point utils::addDays(const std::chrono::system_clock::time_point& timePoint, const int days) {
    return timePoint + std::chrono::hours(days * 24);
}

std::chrono::duration<double> utils::calculateDuration(const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end) {
    return end - start;
}

std::string utils::readFileToString(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void utils::writeStringToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    file << content;
}

void utils::appendStringToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath, std::ios_base::app);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    file << content;
}

void utils::deleteFile(const std::string& filePath) {
    if (!std::filesystem::remove(filePath)) {
        throw std::runtime_error("Could not delete file: " + filePath);
    }
}

std::uintmax_t utils::getFileSize(const std::string& filePath) {
    const std::filesystem::path path(filePath);
    if (!exists(path)) {
        throw std::runtime_error("File does not exist: " + filePath);
    }
    return file_size(path);
}

std::string utils::capitalize(const std::string& str) {
    std::string result = str;
    bool capitalizeNext = true;
    for (char& c : result) {
        if (std::isspace(c)) {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            c = std::toupper(c);
            capitalizeNext = false;
        } else {
            c = std::tolower(c);
        }
    }
    return result;
}

std::string utils::removeNonAlphanumeric(const std::string& str) {
    std::string result;
    std::copy_if(str.begin(), str.end(), std::back_inserter(result), [](const char c) {
        return std::isalnum(c);
    });
    return result;
}

int utils::countSubstring(const std::string& str, const std::string& sub) {
    if (sub.empty()) return 0;
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != std::string::npos) {
        ++count;
        pos += sub.length();
    }
    return count;
}

bool utils::startsWith(const std::string& str, const std::string& prefix) {
    return str.rfind(prefix, 0) == 0;
}

bool utils::endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void utils::createDirectoryIfNotExists(const std::string& path) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directories(path);
    }
}

size_t WriteCallback(void* contents, const size_t size, const size_t nmemb, std::string* s) {
    const size_t newLength = size * nmemb;
    try {
        s->append(static_cast<char *>(contents), newLength);
    } catch ([[maybe_unused]] std::bad_alloc& e) {
        // Handle memory problem
        return 0;
    }
    return newLength;
}
/*
std::string fetchAdventOfCodeInput(const int year, const int day) {
    // Read session cookie from file
    std::ifstream cookiesFile("E:\\CodeProjects\\CLion\\AdventOfCodeCpp\\.aoc_cookies");
    if (!cookiesFile.is_open()) {
        throw std::runtime_error("Could not open cookies file");
    }
    std::string cookies;
    std::getline(cookiesFile, cookies);
    cookiesFile.close();

    // Read user agent from file
    std::ifstream userAgentFile("E:\\CodeProjects\\CLion\\AdventOfCodeCpp\\.aoc_user_agent");
    if (!userAgentFile.is_open()) {
        throw std::runtime_error("Could not open user agent file");
    }
    std::string userAgent;
    std::getline(userAgentFile, userAgent);
    userAgentFile.close();

    // Set up the client

    httplib::SSLClient cli("adventofcode.com");
    cli.set_connection_timeout(10); // 10 seconds timeout

    // Prepare headers
    httplib::Headers headers = {
        {"Cookie", "session=" + cookies},
        {"User-Agent", userAgent}
    };

    // Make the request
    std::string path = "/" + std::to_string(year) + "/day/" + std::to_string(day) + "/input";
    auto result = cli.Get(path.c_str(), headers);

    // Check if request was successful
    if (!result) {
        throw std::runtime_error("Failed to connect to Advent of Code");
    }
    if (result->status != 200) {
        throw std::runtime_error("HTTP error: " + std::to_string(result->status) +
                               " - " + result->body);
    }

    return result->body;
}
*/
void utils::writeAdventOfCodeInput(int year, int day, const std::string& input) {
    std::string directory = "Year" + std::to_string(year) + "/Input";
    createDirectoryIfNotExists(directory);

    std::string fileName = directory + "/day" + std::to_string(day) + "Input.txt";
    writeStringToFile(fileName, input);
}
