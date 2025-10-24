export module ISolver;

namespace interviews {
    /**
     * @brief Interface for solving interview problems.
     * 
     * Implementations of this interface provide solutions to specific interview problems,
     * taking input data and computing the result.
     * 
     * @tparam ArgsType The type of input data (e.g., vector<int>, string).
     * @tparam ReturnType The type of the solution result (e.g., int, string).
     */
    export template<typename ArgsType, typename ReturnType>
    class ISolver {
    public:
        virtual ~ISolver() = default;

        /**
         * @brief Solves the problem with the given input data.
         * @param data The input data for the problem.
         * @return ReturnType The computed solution.
         * @throws std::invalid_argument if the input data is invalid.
         */
        virtual ReturnType solve(const ArgsType& data) = 0;
    };
}
