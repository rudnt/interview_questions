module;

#include <unordered_map>
#include <string>

export module StringUnorderedMap;

namespace interviews {
    /**
     * @brief Hash functor for string types supporting heterogeneous lookup.
     * 
     * Enables efficient lookup in unordered containers using string_view
     * without constructing temporary string objects.
     */
    struct StringHash {
        using is_transparent = void; // Enables heterogeneous operations.

        /**
         * @brief Computes hash value for a string view.
         * @param sv The string view to hash.
         * @return std::size_t The computed hash value.
         */
        std::size_t operator()(std::string_view sv) const {
            std::hash<std::string_view> hasher;
            return hasher(sv);
        }
    };

    /**
     * @brief Unordered map with string keys supporting heterogeneous lookup.
     * 
     * Type alias for std::unordered_map optimized for string keys, allowing
     * efficient lookup with string_view without temporary string construction.
     * 
     * @tparam T The value type stored in the map.
     */
    export template<typename T>
    using StringUnorderedMap = std::unordered_map<std::string, T, StringHash, std::equal_to<>>;
}