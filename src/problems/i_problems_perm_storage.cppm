module;

#include <unordered_map>
#include <string>

import StringUnorderedMap;

export module IProblemsPermStorage;

namespace interviews {
    using ProblemsUnorderedMap = StringUnorderedMap<std::string>;
    export class IProblemsPermStorage {
    public:
        virtual ~IProblemsPermStorage() = default;
        virtual ProblemsUnorderedMap get() const = 0;
    };
}
