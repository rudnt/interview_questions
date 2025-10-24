module;

#include <stdexcept>

export module NotImplementedError;

namespace interviews {
    /**
     * @brief Exception thrown when a feature or function is not yet implemented.
     * 
     * Used to indicate that a particular functionality or problem type
     * has not been implemented yet but may be added in the future.
     */
    export class NotImplementedError: public std::logic_error {
    public:
        /**
         * @brief Constructs a NotImplementedError with a string message.
         * @param what_arg Description of the unimplemented feature.
         */
        explicit NotImplementedError(const std::string& what_arg);
        
        /**
         * @brief Constructs a NotImplementedError with a C-string message.
         * @param what_arg Description of the unimplemented feature.
         */
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
