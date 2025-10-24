export module IGenerator;

namespace interviews {
    /**
     * @brief Interface for generating input data for interview problems.
     * 
     * Implementations of this interface generate random or structured input data
     * that can be used to test problem-solving algorithms.
     * 
     * @tparam ArgsType The type of data to generate (e.g., vector<int>, string).
     */
    export template<typename ArgsType>
    class IGenerator {
    public:
        virtual ~IGenerator() = default;

        /**
         * @brief Generates a new instance of problem input data.
         * @return ArgsType The generated input data.
         */
        virtual ArgsType generate() = 0;
    };
}
