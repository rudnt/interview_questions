module;

#include <unordered_map>
#include <string>

export module StringUnorderedMap;

namespace interviews {
    struct StringHash {
        using is_transparent = void; // Enables heterogeneous operations.

        std::size_t operator()(std::string_view sv) const {
            std::hash<std::string_view> hasher;
            return hasher(sv);
        }
    };

    export template<typename T>
    using StringUnorderedMap = std::unordered_map<std::string, T, StringHash, std::equal_to<>>;
}