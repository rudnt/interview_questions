#include <unordered_map>
#include <string>

#include "fixtures/problems/problems_repo.hpp"
#include "mocks/problems/problems_perm_storage.hpp"

import ProblemsRepo;
import StringUnorderedMap;

interviews::ProblemsRepo ProblemsRepoTest::getEmptySourceRepo() {
    return {std::make_unique<MockProblemsPermStorage>()};
}

interviews::ProblemsRepo ProblemsRepoTest::getSingleSourceRepo() {
    return {std::make_unique<MockProblemsPermStorage>(getData())}; 
}

interviews::ProblemsRepo ProblemsRepoTest::getMultiSourceRepo() {
    auto data{ getData() };
    interviews::StringUnorderedMap<std::string> data1(data.begin(), std::next(data.begin(), 2));
    interviews::StringUnorderedMap<std::string> data2(std::next(data.begin(), 2), data.end());

    return {
        std::make_unique<MockProblemsPermStorage>(data1),
        std::make_unique<MockProblemsPermStorage>(data2),
    }; 
}

interviews::ProblemsRepo ProblemsRepoTest::getMultiSourceSomeEmptyRepo() {
    auto data{ getData() };
    interviews::StringUnorderedMap<std::string> data1(data.begin(), std::next(data.begin(), 2));
    interviews::StringUnorderedMap<std::string> data2(std::next(data.begin(), 2), data.end());

    return {
        std::make_unique<MockProblemsPermStorage>(data1),
        std::make_unique<MockProblemsPermStorage>(),
        std::make_unique<MockProblemsPermStorage>(data2),
        std::make_unique<MockProblemsPermStorage>(),
    }; 
}

interviews::ProblemsRepo ProblemsRepoTest::getDuplicatedProblemRepo() {
    auto finalData{ getData() };
    auto dataOverwritten{ finalData };
    dataOverwritten["Problem_A"] = "Different Description A";
    
    return {
        std::make_unique<MockProblemsPermStorage>(dataOverwritten),
        std::make_unique<MockProblemsPermStorage>(finalData),
    };
}

interviews::StringUnorderedMap<std::string> ProblemsRepoTest::getData() {
    return {
        {"Problem_A", "Description A"},
        {"Problem B", "Description B"},
        {"Problem_C", "Description_C"},
        {"Problem D", "Description_D"},
    };
}
