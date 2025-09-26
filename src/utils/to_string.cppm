export module ToString;

#include <string>
#include <vector>

namespace interviews {
    export template<typename T>
    std::string toString(const std::vector<T>& value);

    export template<typename T>
    std::string toString(const T& value);
}

namespace interviews {
    template<typename T>
    std::string toString(const std::vector<T>& value) {
        std::string result{ "[" };
        for (size_t i = 0; i != value.size(); ++i) {
            result += toString(value[i]);
            if (i < value.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    template<>
    std::string toString(const std::string& value) {
        return value;
    }

    template<typename T>
    std::string toString(const T& value) {
        return std::to_string(value);
    }
}