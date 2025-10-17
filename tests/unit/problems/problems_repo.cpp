#include <string>
#include <unordered_set>
#include <thread>

#include <gtest/gtest.h>

#include "fixtures/problems/problems_repo.hpp"

import ProblemsRepo;

TEST_F(ProblemsRepoTest, GetProblems_NoSource_ReturnsEmptyCollection) {
    interviews::ProblemsRepo repo;
    auto problems{ repo.get() };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_EmptySource_ReturnsEmptyCollection) {
    auto repo{ getEmptySourceRepo() };
    auto problems{ repo.get() };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_SingleSource_ReturnsExpectedProblems) {
    auto repo{ getSingleSourceRepo() };
    auto problems{ repo.get() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_MultipleSources_AggregatesAllProblems) {
    auto repo{ getMultiSourceRepo() };
    auto problems{ repo.get() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_MultipleSourcesSomeEmpty_AggregatesAllProblems) {
    auto repo{ getMultiSourceSomeEmptyRepo() };
    auto problems{ repo.get() };
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
    auto problems1{ repo1.get() };
    auto problems2{ repo2.get() };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
}

TEST_F(ProblemsRepoTest, GetProblems_DuplicatedNameInSources_ReturnsLastOccurrence) {
    auto repo{ getMultiSourceRepo() };
    auto problems{ repo.get() };
    auto expected{ getData() };
    
    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_Limited_ReturnsConsistentResults) {
    auto repo{ getSingleSourceRepo() };
    auto problems1{ repo.get(2) };
    auto problems2{ repo.get(2) };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
}

TEST_F(ProblemsRepoTest, GetProblems_Paginated_ReturnsConsistentResults) {
    auto repo{ getSingleSourceRepo() };
    auto problems1{ repo.get(2, 2) };
    auto problems2{ repo.get(2, 2) };
    auto problems3{ repo.get(1, 2) };

    ASSERT_EQ(problems1.size(), problems2.size());
    EXPECT_EQ(problems1, problems2);
    for (const auto& [name, description] : problems3) {
        EXPECT_NE(problems1.find(name), problems1.end());
        EXPECT_EQ(problems1[name], description);
    }
}

TEST_F(ProblemsRepoTest, GetProblems_PaginationOutOfRange_ReturnsEmptyCollection) {
    auto repo{ getSingleSourceRepo() };
    auto problems{ repo.get(0, 5) };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_LimitExceedsTotal_ReturnsAllProblems) {
    auto repo{ getSingleSourceRepo() };
    auto expected{ repo.get() };
    auto limitedProblems{ repo.get(1000) };
    ASSERT_EQ(limitedProblems.size(), expected.size());
    EXPECT_EQ(limitedProblems, expected);
}

TEST_F(ProblemsRepoTest, GetProblems_ZeroLimit_ReturnsWholeCollection) {
    auto repo{ getSingleSourceRepo() };
    auto expected{ repo.get() };
    auto problems{ repo.get(0) };
    ASSERT_EQ(problems.size(), expected.size());
    EXPECT_EQ(problems, expected);
}

TEST_F(ProblemsRepoTest, ThreadSafety_ConcurrentAccess) {
    constexpr int num_threads{ 4 };
    constexpr int calls_per_thread{ 25 };

    std::vector<std::jthread> threads;
    std::atomic successful_calls{ 0 };
    
    for (size_t i{ 0 }; i != num_threads; ++i) {
        threads.emplace_back([this, &successful_calls]() {
            for (size_t j{ 0 }; j != calls_per_thread; ++j) {
                try {
                    auto repo{ getMultiSourceRepo() };
                    auto problems{ repo.get() };
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

TEST_F(ProblemsRepoTest, GetProblems_AllSourcesThrowException_ReturnsEmptyCollection) {
    auto repo{ getAllThrowingMultiSourceRepo() };
    auto problems{ repo.get() };
    ASSERT_EQ(problems.size(), 0);
}

TEST_F(ProblemsRepoTest, GetProblems_OnlyOneSourceThrowsException_ReturnsValidProblems) {
    auto repo{ getOneThrowingMultiSourceRepo() };
    auto problems{ repo.get() };
    auto expected{ getData() };

    ASSERT_EQ(problems.size(), expected.size());
    for (const auto& [name, description] : expected) {
        EXPECT_NE(problems.find(name), problems.end());
        EXPECT_EQ(problems[name], description);
    }
}
