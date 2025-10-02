export module ISolver;

namespace interviews {
    export template<typename ArgsType, typename ReturnType>
    class ISolver {
    public:
        virtual ~ISolver() = default;

        virtual ReturnType solve(const ArgsType& data) = 0;
    };
}
