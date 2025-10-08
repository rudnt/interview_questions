module;

#include <unordered_map>
#include <string>

export module IProblemsPermStorage;

namespace interviews {
    export class IProblemsPermStorage {
    public:
        virtual ~IProblemsPermStorage() = default;
        virtual std::unordered_map<std::string, std::string> get() const = 0;
    };
}
