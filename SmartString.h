// SmartString.h
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>  // For std::isspace, std::tolower, std::toupper

class SmartString {
private:
    std::string data;

public:
    // Constructors
    SmartString() = default;
    SmartString(const std::string& str) : data(str) {}
    SmartString(const char* str) : data(str) {}

    // Basic string operations
    size_t length() const { return data.length(); }
    bool isEmpty() const { return data.empty(); }
    const std::string& toString() const { return data; }

    // Enhanced features
    SmartString trim() const {
        auto start = data.begin();
        auto end = data.end();
        
        // Trim left
        while (start != end && std::isspace(*start)) start++;
        
        // Trim right
        while (start != end && std::isspace(*(end - 1))) end--;
        
        return SmartString(std::string(start, end));
    }

    std::vector<SmartString> split(const std::string& delimiter) const {
        std::vector<SmartString> tokens;
        size_t start = 0;
        size_t end = 0;
        
        while ((end = data.find(delimiter, start)) != std::string::npos) {
            tokens.push_back(data.substr(start, end - start));
            start = end + delimiter.length();
        }
        
        tokens.push_back(data.substr(start));
        return tokens;
    }

    SmartString toLower() const {
        std::string result = data;
        std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c){ return std::tolower(c); });
        return SmartString(result);
    }

    SmartString toUpper() const {
        std::string result = data;
        std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c){ return std::toupper(c); });
        return SmartString(result);
    }

    bool contains(const std::string& substr) const {
        return data.find(substr) != std::string::npos;
    }

    // Operator overloads
    SmartString operator+(const SmartString& rhs) const {
        return SmartString(data + rhs.data);
    }

    bool operator==(const SmartString& rhs) const {
        return data == rhs.data;
    }

    // Conversion operator
    operator std::string() const { return data; }
};