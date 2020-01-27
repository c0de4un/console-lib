/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORG_CONSOLE_LIB_CORE_CONSOLE_HPP
#define ORG_CONSOLE_LIB_CORE_CONSOLE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// defines.
#ifndef ORG_CONSOLE_LIB_CFG_DEFINES_HPP
#include "../cfg/defines_cfg.hpp"
#endif // !ORG_CONSOLE_LIB_CFG_DEFINES_HPP

// Include console::IConsole
#ifndef ORG_CONSOLE_LIB_CORE_I_CONSOLE_HXX
#include "IConsole.hxx"
#endif // !ORG_CONSOLE_LIB_CORE_I_CONSOLE_HXX

// ===========================================================
// TYPES
// ===========================================================

namespace console
{

    // -----------------------------------------------------------

    /**
     * @brief
     * Console - utility-class (facade) to access console-lib api.
     *
     * @version 1.0
     * @since 26.01.2020
     * @authors Denis Z. (code4un@yandex.ru)
    **/
    class Console final
    {

    private:

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        /** Console instance.**/
        static IConsole* mConsoleInstance;

        // ===========================================================
        // DELETED
        // ===========================================================

        Console(const Console&) = delete;
        Console& operator=(const Console&) = delete;
        Console(Console&&) = delete;
        Console& operator=(Console&&) = delete;

        // ===========================================================
        // CONSTRUCTOR
        // ===========================================================

        explicit Console() THROWABLE;

        // -----------------------------------------------------------

    public:

        // -----------------------------------------------------------

        // ===========================================================
        // DESTRUCTOR
        // ===========================================================

        /**
         * Console destructor.
        **/
        ~Console() THROWABLE;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        /**
         * @brief
         * Returns IConsole interface reference.
         *
         * (?) console-lib must be initialized before.
         *
         * @thread_safety - not thread-safe.
         * @returns - IConsole reference.
         * @throws - can throw exception.
        **/
        static IConsole& inst() THROWABLE;

        // ===========================================================
        // METHODS
        // ===========================================================

        /**
         * @brief
         * Initialize console-lib.
         *
         * @thread_safety - not thread-safe. Call only from main-thread.
         * @returns - 'true' if initialized, 'false' if failed.
         * @throws - can throw exception.
        **/
        static bool Initialize() THROWABLE;

        /**
         * @brief
         * Terminate console-lib.
         *
         * @thread_safety - not thread-safe. Call only from main-thread.
         * @throws - can throw exception.
        **/
        static void Terminate() THROWABLE;

        // -----------------------------------------------------------

    }; /// console::Console

    // -----------------------------------------------------------

} /// console
using console_lib = console::Console;

// -----------------------------------------------------------

#endif // !ORG_CONSOLE_LIB_CORE_CONSOLE_HPP