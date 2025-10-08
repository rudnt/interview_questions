#include "mocks/problems/problems_perm_storage.hpp"


MockProblemsPermStorage::MockProblemsPermStorage(const std::unordered_map<std::string, std::string>& _problems)
    : problems(_problems) {
    }

std::unordered_map<std::string, std::string> MockProblemsPermStorage::get() const {
    return problems;
}

