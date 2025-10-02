export module IGenerator;

//TODO create docstrings for all public classe/methods
namespace interviews {
    export template<typename ArgsType>
    class IGenerator {
    public:
        virtual ~IGenerator() = default;

        virtual ArgsType generate() = 0;
    };
}
