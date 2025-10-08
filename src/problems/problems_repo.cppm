module;

#include <algorithm>
#include <future>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

import IProblemsPermStorage;
import StringUnorderedMap;

export module ProblemsRepo;

namespace interviews {
    using ProblemsMap = std::map<std::string, std::string, std::less<>>;
    using ProblemsUnorderedMap = StringUnorderedMap<std::string>;

    export class ProblemsRepo {
    public:
        ProblemsRepo() = default;
        ProblemsRepo(std::initializer_list<std::unique_ptr<IProblemsPermStorage>>);

        ProblemsMap get(size_t maxSize = 0, size_t offset = 0) const;

    private:
        std::vector<std::unique_ptr<IProblemsPermStorage>> sources;

        ProblemsMap fetch() const;
        void erase(ProblemsMap&, size_t) const;
        void limit(ProblemsMap&, size_t) const;

        std::vector<std::future<ProblemsUnorderedMap>> fetchAsync() const;
        ProblemsMap gather(std::vector<std::future<ProblemsUnorderedMap>>&) const;
    };
}

namespace interviews {
    ProblemsRepo::ProblemsRepo(std::initializer_list<std::unique_ptr<IProblemsPermStorage>> _sources) {
        sources.reserve(_sources.size());
        for (auto&& source : _sources) {
            sources.push_back(std::move(const_cast<std::unique_ptr<IProblemsPermStorage>&>(source)));
        }
    }

    ProblemsMap ProblemsRepo::get(size_t maxSize, size_t offset) const {
        auto problems{ fetch() };
        erase(problems, offset);
        limit(problems, maxSize);
        return problems;
    }

    ProblemsMap ProblemsRepo::fetch() const {
        auto futures{ fetchAsync() };
        return gather(futures);
    }

    std::vector<std::future<ProblemsUnorderedMap>> ProblemsRepo::fetchAsync() const {
        std::vector<std::future<ProblemsUnorderedMap>> futures;
        futures.reserve(sources.size());
        for (const auto& source : sources) {
            futures.push_back(std::async(std::launch::async, &IProblemsPermStorage::get, source.get()));
        }
        return futures;
    }

    ProblemsMap ProblemsRepo::gather(std::vector<std::future<ProblemsUnorderedMap>>& futures) const {
        ProblemsMap allProblems;
        for (auto& future : futures) {
            // TODO consider logging warning if problem duplicated
            auto problems{ future.get() };
            allProblems.insert(problems.begin(), problems.end());
        }
        return allProblems;
    }

    void ProblemsRepo::erase(ProblemsMap& problems, size_t count) const {
        if (count == 0) {
            return;
        }

        auto it{ problems.begin() };
        std::advance(it, std::min(count, problems.size()));
        problems.erase(problems.begin(), it);
    }

    void ProblemsRepo::limit(ProblemsMap& problems, size_t count) const {
        if (count == 0) {
            return;
        }

        auto it{ problems.begin() };
        std::advance(it, std::min(count, problems.size()));
        problems.erase(it, problems.end());
    }
}
