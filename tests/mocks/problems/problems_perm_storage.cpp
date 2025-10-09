#include "mocks/problems/problems_perm_storage.hpp"

import StringUnorderedMap;

MockProblemsPermStorage::MockProblemsPermStorage(const interviews::StringUnorderedMap<std::string>& _problems)
    : problems(_problems) {
    }

interviews::StringUnorderedMap<std::string> MockProblemsPermStorage::get() const {
    return problems;
}

