module;

#include <stdexcept>

export module InvalidStateError;

namespace interviews {
    /**
     * @brief Exception thrown when an operation is attempted in an invalid state.
     * 
     * Used to indicate that a method was called when the object is not in
     * the appropriate state (e.g., trying to get a solution before solving
     * the problem, or solving before generating data).
     */
    export class InvalidStateError: public std::logic_error {
    public:
        /**
         * @brief Constructs an InvalidStateError with a string message.
         * @param what_arg Description of the invalid state condition.
         */
        explicit InvalidStateError(const std::string& what_arg);
        
        /**
         * @brief Constructs an InvalidStateError with a C-string message.
         * @param what_arg Description of the invalid state condition.
         */
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
