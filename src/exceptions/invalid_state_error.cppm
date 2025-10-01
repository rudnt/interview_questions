module;

#include <stdexcept>

export module InvalidStateError;

namespace interviews {
    export class InvalidStateError: public std::logic_error {
    public:
        explicit InvalidStateError(const std::string& what_arg);
        explicit InvalidStateError(const char* what_arg);
    };
}
namespace interviews {
    InvalidStateError::InvalidStateError(const std::string& what_arg)
        : std::logic_error(what_arg) {
    }

    InvalidStateError::InvalidStateError(const char* what_arg)
        : std::logic_error(what_arg) {
    }
}