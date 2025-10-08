module;

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

import IProblemsPermStorage;

export module ProblemsRepo;

namespace interviews {
    export class ProblemsRepo {
    public:
        ProblemsRepo(std::initializer_list<std::unique_ptr<IProblemsPermStorage>> sources = {});

        std::map<std::string, std::string> getProblems(size_t limit = 0, size_t offset = 0) const;
        //// TODO repo can use std::async to read from multiple sources concurrently - check how to do it (locking, mutexes, etc.)

    private:
        std::vector<std::unique_ptr<IProblemsPermStorage>> sources;
    };
}

namespace interviews {
    ProblemsRepo::ProblemsRepo(std::initializer_list<std::unique_ptr<IProblemsPermStorage>> _sources) {
        sources.reserve(_sources.size());
        for (auto&& source : _sources) {
            sources.push_back(std::move(const_cast<std::unique_ptr<IProblemsPermStorage>&>(source)));
        }
    }

    std::map<std::string, std::string> ProblemsRepo::getProblems(size_t limit, size_t offset) const {
        std::map<std::string, std::string> allProblems;
        for (const auto& source : sources) {
            auto problems{ source->get() };
            allProblems.insert(problems.begin(), problems.end());
        }

        if (offset != 0) {
            auto it{ allProblems.begin() };
            std::advance(it, std::min(offset, allProblems.size()));
            allProblems.erase(allProblems.begin(), it);
        }
        if (limit != 0) {
            auto it{ allProblems.begin() };
            std::advance(it, std::min(limit, allProblems.size()));
            allProblems.erase(it, allProblems.end());
        }

        return allProblems;
    }
}
