module;

#include <stdexcept>

export module NotImplementedError;

namespace interviews {
    export class NotImplementedError: public std::logic_error {
    public:
        explicit NotImplementedError(const std::string& what_arg);
        explicit NotImplementedError(const char* what_arg);
    };
}
namespace interviews {
    NotImplementedError::NotImplementedError(const std::string& what_arg)
        : std::logic_error(what_arg) {
    }

    NotImplementedError::NotImplementedError(const char* what_arg)
        : std::logic_error(what_arg) {
    }
}