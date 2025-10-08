#include <string>
#include <unordered_set>
#include <thread>

#include <gtest/gtest.h>

#include "fixtures/problems/problems_repo.hpp"

import ProblemsRepo;

//// TODO check how to check if async is used

TEST_F(ProblemsRepoTest, GetProblems_NoSource_ReturnsEmptyCollection) {
    interviews::ProblemsRepo repo;
    auto problems{ repo.getProblems() };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_EmptySource_ReturnsEmptyCollection) {
    auto repo{ getEmptySourceRepo() };
    auto problems{ repo.getProblems() };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_SingleSource_ReturnsExpectedProblems) {
    auto repo{ getSingleSourceRepo() };
    auto problems{ repo.getProblems() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_MultipleSources_AggregatesAllProblems) {
    auto repo{ getMultiSourceRepo() };
    auto problems{ repo.getProblems() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_MultipleSourcesSomeEmpty_AggregatesAllProblems) {
    auto repo{ getMultiSourceSomeEmptyRepo() };
    auto problems{ repo.getProblems() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_RepoCopy_ReturnsConsistentResults) {
    auto repo1{ getSingleSourceRepo() };
    auto repo2{ getSingleSourceRepo() };
    auto problems1{ repo1.getProblems() };
    auto problems2{ repo2.getProblems() };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
}

TEST_F(ProblemsRepoTest, GetProblems_DuplicatedNameInSources_ThrowsException) {
    auto repo{ getMultiSourceRepo() };
    EXPECT_THROW(repo.getProblems(), std::runtime_error);
}

TEST_F(ProblemsRepoTest, GetProblems_EmptyProblemName_ThrowsException) {
    auto repo{ getRepoWithEmptyProblemName() };
    EXPECT_THROW(repo.getProblems(), std::runtime_error);
}

TEST_F(ProblemsRepoTest, GetProblems_EmptyDescription_ThrowsException) {
    auto repo{ getRepoWithEmptyDescription() };
    EXPECT_THROW(repo.getProblems(), std::runtime_error);
}

TEST_F(ProblemsRepoTest, GetProblems_Limited_ReturnsConsistentResults) {
    auto repo{ getSingleSourceRepo() };
    auto problems1{ repo.getProblems(2) };
    auto problems2{ repo.getProblems(2) };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
}

TEST_F(ProblemsRepoTest, GetProblems_Paginated_ReturnsConsistentResults) {
    auto repo{ getSingleSourceRepo() };
    auto problems1{ repo.getProblems(2, 2) };
    auto problems2{ repo.getProblems(2, 2) };
    auto problems3{ repo.getProblems(1, 2) };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
    for (const auto& [name, description] : problems3) {
        EXPECT_NE(problems1.find(name), problems1.end());
        EXPECT_EQ(problems1[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_PaginationOutOfRange_ReturnsEmptyCollection) {
    auto repo{ getSingleSourceRepo() };
    auto problems{ repo.getProblems(0, 5) };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_LimitExceedsTotal_ReturnsAllProblems) {
    auto repo{ getSingleSourceRepo() };
    auto expected{ repo.getProblems() };
    auto limitedProblems{ repo.getProblems(1000) };
    ASSERT_EQ(limitedProblems.size(), expected.size());
    EXPECT_EQ(limitedProblems, expected);
}

TEST_F(ProblemsRepoTest, GetProblems_ZeroLimit_ReturnsWholeCollection) {
    auto repo{ getSingleSourceRepo() };
    auto expected{ repo.getProblems() };
    auto problems{ repo.getProblems(0) };
    ASSERT_EQ(problems.size(), expected.size());
    EXPECT_EQ(problems, expected);
}

TEST_F(ProblemsRepoTest, ThreadSafety_ConcurrentAccess) {
    constexpr int num_threads{ 4 };
    constexpr int calls_per_thread{ 25 };

    std::vector<std::thread> threads;
    std::atomic successful_calls{ 0 };
    
    for (size_t i{ 0 }; i != num_threads; ++i) {
        threads.emplace_back([this, &successful_calls]() {
            for (size_t j{ 0 }; j != calls_per_thread; ++j) {
                try {
                    auto repo{ getMultiSourceRepo() };
                    auto problems{ repo.getProblems()};
                    if (!problems.empty()) {
                        successful_calls++;
                    }
                } catch (...) {
                    // Thread-safety violation detected
                }
            }
        });
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    EXPECT_EQ(successful_calls.load(), num_threads * calls_per_thread);
}
