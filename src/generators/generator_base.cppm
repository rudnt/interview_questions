export module GeneratorBase;

//TODO create docstrings for all public classe/methods
namespace interviews {
    export template<typename ArgsType>
    class GeneratorBase {
    public:
        virtual ~GeneratorBase() = default;

        virtual ArgsType generate() = 0;
    };
}