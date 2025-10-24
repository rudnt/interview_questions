module;

#include <string>
#include <vector>

export module ToString;

namespace interviews {
    /**
     * @brief Converts a value to its string representation.
     * 
     * Generic function for converting various types to strings.
     * Specializations exist for common types including primitives,
     * strings, and containers.
     * 
     * @tparam T The type of value to convert.
     * @param value The value to convert to a string.
     * @return std::string String representation of the value.
     */
    export template<typename T>
    std::string toString(const T& value);

    /**
     * @brief Converts a vector to its string representation.
     * 
     * Formats a vector as a comma-separated list enclosed in square brackets.
     * Example: [1, 2, 3]
     * 
     * @tparam T The element type of the vector.
     * @param value The vector to convert to a string.
     * @return std::string String representation of the vector.
     */
    export template<typename T>
    std::string toString(const std::vector<T>& value);
}

namespace interviews {
    template<typename T>
    std::string toString(const T& value) {
        return std::to_string(value);
    }
    
    template<>
    std::string toString(const std::string& value) {
        return value;
    }
    
    template<>
    std::string toString(const char& value) {
        return std::string(1, value);
    }

    template<>
    std::string toString(const char* const& value) {
        return std::string(value);
    }

    template<>
    std::string toString(const bool& value) {
        return value ? "true" : "false";
    }

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
    std::string toString(const std::vector<bool>& value) {
        std::string result{ "[" };
        for (size_t i = 0; i != value.size(); ++i) {
            result += value[i] ? "true" : "false";
            if (i < value.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
}
