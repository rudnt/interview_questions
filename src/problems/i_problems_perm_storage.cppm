module;

#include <unordered_map>
#include <string>

import StringUnorderedMap;

export module IProblemsPermStorage;

namespace interviews {
    using ProblemsUnorderedMap = StringUnorderedMap<std::string>;
    
    /**
     * @brief Interface for permanent storage implementations of interview problems.
     * 
     * Defines the contract for retrieving problems from various storage backends
     * such as databases, file systems, or remote APIs.
     */
    export class IProblemsPermStorage {
    public:
        virtual ~IProblemsPermStorage() = default;
        
        /**
         * @brief Retrieves all problems from the storage.
         * @return ProblemsUnorderedMap Unordered map of problem names to problem data.
         * @throws Storage-specific exceptions if retrieval fails.
         */
        virtual ProblemsUnorderedMap get() const = 0;
    };
}
