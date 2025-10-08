#include <unordered_map>
#include <string>

#include "fixtures/problems/problems_repo.hpp"
#include "mocks/problems/problems_perm_storage.hpp"

import ProblemsRepo;

interviews::ProblemsRepo ProblemsRepoTest::getEmptySourceRepo() {
    return {std::make_unique<MockProblemsPermStorage>()};
}

interviews::ProblemsRepo ProblemsRepoTest::getSingleSourceRepo() {
    return {std::make_unique<MockProblemsPermStorage>(getData())}; 
}

interviews::ProblemsRepo ProblemsRepoTest::getMultiSourceRepo() {
    auto data{ getData() };
    std::unordered_map<std::string, std::string> data1(data.begin(), std::next(data.begin(), 2));
    std::unordered_map<std::string, std::string> data2(std::next(data.begin(), 2), data.end());

    return {
        std::make_unique<MockProblemsPermStorage>(data1),
        std::make_unique<MockProblemsPermStorage>(data2),
    }; 
}

interviews::ProblemsRepo ProblemsRepoTest::getMultiSourceSomeEmptyRepo() {
    auto data{ getData() };
    std::unordered_map<std::string, std::string> data1(data.begin(), std::next(data.begin(), 2));
    std::unordered_map<std::string, std::string> data2(std::next(data.begin(), 2), data.end());

    return {
        std::make_unique<MockProblemsPermStorage>(data1),
        std::make_unique<MockProblemsPermStorage>(),
        std::make_unique<MockProblemsPermStorage>(data2),
        std::make_unique<MockProblemsPermStorage>()
    }; 
}

interviews::ProblemsRepo ProblemsRepoTest::getRepoWithEmptyProblemName() {
    std::unordered_map<std::string, std::string> problems{
        {"", "Description A"},
        {"Problem B", "Description B"}
    };
    return {std::make_unique<MockProblemsPermStorage>(problems)};
}

interviews::ProblemsRepo ProblemsRepoTest::getRepoWithEmptyDescription() {
    std::unordered_map<std::string, std::string> problems{
        {"Problem A", ""},
        {"Problem B", "Description B"}
    };
    return {std::make_unique<MockProblemsPermStorage>(problems)};
}

std::unordered_map<std::string, std::string> ProblemsRepoTest::getData() {
    return {
        {"Problem_A", "Description A"},
        {"Problem B", "Description B"},
        {"Problem_C", "Description_C"},
        {"Problem D", "Description_D"}
    };
}
