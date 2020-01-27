/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORG_CONSOLE_LIB_CORE_I_CONSOLE_HXX
#define ORG_CONSOLE_LIB_CORE_I_CONSOLE_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include defines.
#ifndef ORG_CONSOLE_LIB_CFG_DEFINES_HPP
#include "../cfg/defines_cfg.hpp"
#endif // !ORG_CONSOLE_LIB_CFG_DEFINES_HPP

// Include C++ string
#include <string> // string, wstring, to_string, to_wstring

// ===========================================================
// TYPES
// ===========================================================

namespace console
{

    // -----------------------------------------------------------

    /**
     * @brief
     * ConsoleColors - console-supported colors enum.
    **/
    enum EConsoleColors : unsigned char
    {

        // -----------------------------------------------------------

        WHITE,
        DEFAULT = WHITE,
        BLACK,
        BLUE,
        GREEN,
        RED,
        YELLOW,
        PINK

        // -----------------------------------------------------------

    }; /// console::ConsoleColors

    // -----------------------------------------------------------

    /**
     * @brief
     * IConsole - interface for Console utility class.
     * 
     * @version 0.1
     * @since 26.01.2020
     * @authors Denis Z. (code4un@yandex.ru)
    **/
    class IConsole
    {

    public:

        // -----------------------------------------------------------

        // ===========================================================
        // DESTRUCTOR
        // ===========================================================

        /**
         * IConsole destructor.
        **/
        virtual ~IConsole() THROWABLE
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        /**
         * @brief
         * Sets Console-output text color.
         * 
         * @thread_safety - not thread-safe.
         * @param pColor - Color.
         * @throws - no exceptions.
        **/
        virtual IConsole& SetTextColor(const EConsoleColors pColor) noexcept = 0;

        // ===========================================================
        // METHODS
        // ===========================================================

        /**
         * @brieft
         * Prints c-string to console-output.
         * 
         * @thread_safety - not required.
         * @param pText - c-string to print (must contain '0'-ending symbol).
         * @throws - can throw exception.
        **/
        virtual void PrintLine(const char* const pText) = 0;

        /**
         * @brieft
         * Prints wchar_t c-string to console-output.
         *
         * @thread_safety - not required.
         * @param pText - wchar_t c-string to print (must contain '0'-ending symbol).
         * @throws - can throw exception.
        **/
        virtual void PrintWLine(wchar_t* const pText) = 0;

        /**
         * @brieft
         * Prints C++ string to console-output.
         *
         * @thread_safety - not required.
         * @param pText - c-string to print (must contain '0'-ending symbol).
         * @throws - can throw exception.
        **/
        virtual void PrintLine(const std::string& pText) = 0;

        /**
         * @brieft
         * Prints wchar_t C++ string to console-output.
         *
         * @thread_safety - not required.
         * @param pText - wchar_t c-string to print (must contain '0'-ending symbol).
         * @throws - can throw exception.
        **/
        virtual void PrintWLine(const std::wstring& pText) = 0;

        // ===========================================================
        // OPERATORS
        // ===========================================================

        // -----------------------------------------------------------

    }; /// console::IConsole

    // -----------------------------------------------------------

} /// console
#define ORG_CONSOLE_LIB_CORE_I_CONSOLE_DECL
using console_color_t = console::EConsoleColors;

// -----------------------------------------------------------

#endif // !ORG_CONSOLE_LIB_CORE_I_CONSOLE_HXX