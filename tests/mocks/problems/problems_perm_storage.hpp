#pragma once

#include <unordered_map>
#include <string>

import IProblemsPermStorage;

class MockProblemsPermStorage : public interviews::IProblemsPermStorage {
public:
    MockProblemsPermStorage(const std::unordered_map<std::string, std::string>&problems = {});

    std::unordered_map<std::string, std::string> get() const;

private:
    std::unordered_map<std::string, std::string> problems;
};
