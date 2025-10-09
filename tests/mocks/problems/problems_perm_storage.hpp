#pragma once

#include <unordered_map>
#include <string>

import IProblemsPermStorage;
import StringUnorderedMap;

class MockProblemsPermStorage : public interviews::IProblemsPermStorage {
public:
    explicit MockProblemsPermStorage(const interviews::StringUnorderedMap<std::string>& problems = {});

    interviews::StringUnorderedMap<std::string> get() const;

private:
    interviews::StringUnorderedMap<std::string> problems;
};
