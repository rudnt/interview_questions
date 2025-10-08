#pragma once

#include <unordered_map>
#include <string>

#include <gtest/gtest.h>

#include "mocks/problems/problems_perm_storage.hpp"

import ProblemsRepo;
import StringUnorderedMap;

class ProblemsRepoTest : public ::testing::Test {
public:
    interviews::ProblemsRepo getEmptySourceRepo();
    interviews::ProblemsRepo getSingleSourceRepo();
    interviews::ProblemsRepo getMultiSourceRepo();
    interviews::ProblemsRepo getMultiSourceSomeEmptyRepo();
    interviews::ProblemsRepo getDuplicatedProblemRepo();

    interviews::StringUnorderedMap<std::string> getData();
};
