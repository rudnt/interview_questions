#include <stdexcept>

#include <gtest/gtest.h>

import ISolver;
import IGenerator;
import Mediator;
import InvalidStateError;

class DummyGenerator : public interviews::IGenerator<int> {
public:
    int generate() override { return 42; }
};

class DummySolver : public interviews::ISolver<int, int> {
public:
    int solve(const int& data) override { return data * 2; }
};

TEST(MediatorTest, Instantiation_ValidInput_Succeeds) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    EXPECT_NO_THROW((interviews::Mediator<int, int>(generator, solver)));
}

TEST(MediatorTest, Instantiation_Nullptrs_Throws) {
    EXPECT_THROW((interviews::Mediator<int, int>(nullptr, nullptr)), std::invalid_argument);
}

TEST(MediatorTest, GenerateProblemData_SetsProblemData) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    interviews::Mediator<int, int> mediator(generator, solver);

    mediator.generateProblemData();
    EXPECT_EQ(mediator.getProblemData(), "42");
}

TEST(MediatorTest, SolveProblem_SetsSolution) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    interviews::Mediator<int, int> mediator(generator, solver);

    mediator.generateProblemData();
    mediator.solveProblem();
    EXPECT_EQ(mediator.getSolution(), "84");
}

TEST(MediatorTest, GetProblemData_WithoutGeneration_Throws) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    interviews::Mediator<int, int> mediator(generator, solver);

    EXPECT_THROW(mediator.getProblemData(), interviews::InvalidStateError);
}

TEST(MediatorTest, GetSolution_WithoutSolving_Throws) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    interviews::Mediator<int, int> mediator(generator, solver);

    mediator.generateProblemData();
    EXPECT_THROW(mediator.getSolution(), interviews::InvalidStateError);
}

TEST(MediatorTest, SolveProblem_WithoutGeneration_Throws) {
    auto generator{ std::make_shared<DummyGenerator>() };
    auto solver{ std::make_shared<DummySolver>() };
    interviews::Mediator<int, int> mediator(generator, solver);

    EXPECT_THROW(mediator.solveProblem(), interviews::InvalidStateError);
}
