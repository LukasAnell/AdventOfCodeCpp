//
// Created by Lukas on 8/28/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <string>
#include <vector>


class utils {
    public:
    static std::vector<std::string> readFile(const std::string& fileName, int year, int dayNumber, bool isSample);
    static std::vector<std::string> splitString(const std::string& input, const std::string& delimiter);
    static std::vector<int> extractInts(const std::string& str);
    static std::string toLower(const std::string& str);
    static std::string toUpper(const std::string& str);
    static std::string trim(const std::string& str);
    static std::string joinStrings(const std::vector<std::string>& strings, const std::string& delimiter);
    static bool fileExists(const std::string& filePath);
    static std::string replaceSubstring(const std::string& str, const std::string& from, const std::string& to);
    static int stringToInt(const std::string& str);
    static double stringToDouble(const std::string& str);
    static std::string generateRandomString(size_t length);
    static bool isNumeric(const std::string& str);
    static std::string reverseString(const std::string& str);
    static std::vector<int> removeDuplicates(const std::vector<int>& vec);
    static std::vector<int> findAndReplace(std::vector<int>& vec, int oldVal, int newVal);
    static std::string vectorToString(const std::vector<int>& vec, const std::string& delimiter);
    static bool contains(const std::vector<int>& vec, int element);
    static std::string getCurrentDateTime();
    static std::string formatTime(const std::chrono::system_clock::time_point& timePoint, const std::string& format);
    static std::chrono::system_clock::time_point addDays(const std::chrono::system_clock::time_point& timePoint, int days);
    static std::chrono::duration<double> calculateDuration(const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end);
    static std::string readFileToString(const std::string& filePath);
    static void writeStringToFile(const std::string& filePath, const std::string& content);
    static void appendStringToFile(const std::string& filePath, const std::string& content);
    static void deleteFile(const std::string& filePath);
    static std::uintmax_t getFileSize(const std::string& filePath);
    static std::string capitalize(const std::string& str);
    static std::string removeNonAlphanumeric(const std::string& str);
    static int countSubstring(const std::string& str, const std::string& sub);
    static bool startsWith(const std::string& str, const std::string& prefix);
    static bool endsWith(const std::string& str, const std::string& suffix);
    static void createDirectoryIfNotExists(const std::string& path);
    static std::string fetchAdventOfCodeInput(int year, int day);
    static void writeAdventOfCodeInput(int year, int day, const std::string& input);
};



#endif //UTILS_H
