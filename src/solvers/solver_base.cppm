export module SolverBase;

export template<typename ArgsType, typename ReturnType>
class SolverBase {
public:
    virtual ~SolverBase() = default;

    virtual ReturnType solve(const ArgsType& data) = 0;
};