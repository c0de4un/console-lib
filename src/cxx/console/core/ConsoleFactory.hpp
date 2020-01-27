/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP
#define ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include defines.
#ifndef ORG_CONSOLE_LIB_CFG_DEFINES_HPP
#include "../cfg/defines_cfg.hpp"
#endif // !ORG_CONSOLE_LIB_CFG_DEFINES_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-declare console::Console
#ifndef ORG_CONSOLE_LIB_CORE_I_CONSOLE_DECL
#define ORG_CONSOLE_LIB_CORE_I_CONSOLE_DECL
namespace console { class IConsole; }
#endif // !ORG_CONSOLE_LIB_CORE_I_CONSOLE_DECL

// ===========================================================
// TYPES
// ===========================================================

namespace console
{

    // -----------------------------------------------------------

    /**
     * @brief
     * ConsoleFactory - factory-type for IConsole implementation.
     *
     * @version 1.0
     * @since 26.01.2020
     * @authors Denis Z. (code4un@yandex.ru)
    **/
    class ConsoleFactory final
    {

    private:

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR
        // ===========================================================

        explicit ConsoleFactory() THROWABLE;

        // ===========================================================
        // DELETED
        // ===========================================================

        ConsoleFactory(const ConsoleFactory&) = delete;
        ConsoleFactory& operator=(const ConsoleFactory&) = delete;
        ConsoleFactory(ConsoleFactory&&) = delete;
        ConsoleFactory& operator=(ConsoleFactory&&) = delete;

        // -----------------------------------------------------------

    public:

        // -----------------------------------------------------------

        // ===========================================================
        // DESTRUCTOR
        // ===========================================================

        /**
         * @brief
         * ConsoleFactory destructor.
         *
         * @throws - can throw exception.
        **/
        ~ConsoleFactory() THROWABLE;

        // ===========================================================
        // METHODS
        // ===========================================================

        /**
         * @brief
         * Constructs IConsole implementation for current platform.
         *
         * @thread_safety - not thread-safe, must be called
         * only from main-thread during application start.
         * @returns - IConsole, or null.
         * @throws - can throw exception.
        **/
        static IConsole* Build() THROWABLE;

        // -----------------------------------------------------------

    }; /// console::ConsoleFactory

    // -----------------------------------------------------------

} /// console
#define ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_DECL

// -----------------------------------------------------------

#endif // !ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP