/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORG_CONSOLE_LIB_WIN_CONSOLE_HPP
#define ORG_CONSOLE_LIB_WIN_CONSOLE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include console::BaseConsole
#ifndef ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_HPP
#include "../core/BaseConsole.hpp"
#endif // !ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_HPP

// Include C++ iostream
#include <iostream> // cin, cout

// Include stringbuf
#include <sstream> // stringbuf

// ===========================================================
// TYPES
// ===========================================================

namespace console
{

    namespace win
    {

        // -----------------------------------------------------------

        /**
         * @see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
        **/
        class MBuf final : public std::stringbuf
        {

        public:

            // -----------------------------------------------------------

            int sync()
            {
                std::fputs(str().c_str(), stdout);
                str("");
                return 0;
            }

            // -----------------------------------------------------------

        }; /// c0de4un::MBuf

        // -----------------------------------------------------------

        /**
         * @brief
         * WinConsole - IConsole implementation for Windows platforms.
         *
         * @version 1.0
         * @since 26.01.2020
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class WinConsole final : public BaseConsole
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // DELETED
            // ===========================================================

            WinConsole(const WinConsole&) = delete;
            WinConsole& operator=(const WinConsole&) = delete;
            WinConsole(WinConsole&&) = delete;
            WinConsole& operator=(WinConsole&&) = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Output Buffer **/
            MBuf mOutBuf;

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * WinConsole constructor.
             *
             * @throws - can throw out of memory exception.
            **/
            explicit WinConsole() THROWABLE;

            /**
             * @brief
             * WinConsole destructor.
             *
             * @throws - can throw access-violation exception.
            **/
            virtual ~WinConsole() THROWABLE;

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
            virtual IConsole& SetTextColor(const EConsoleColors pColor) noexcept final;

            // ===========================================================
            // console::IConsole
            // ===========================================================

            /**
             * @brieft
             * Prints c-string to console-output.
             *
             * @thread_safety - not required.
             * @param pText - c-string to print (must contain '0'-ending symbol).
            * @throws - can throw exception.
            **/
            virtual void PrintLine(const char* const pText) final;

            /**
             * @brieft
             * Prints wchar_t c-string to console-output.
             *
             * @thread_safety - not required.
             * @param pText - wchar_t c-string to print (must contain '0'-ending symbol).
             * @throws - can throw exception.
            **/
            virtual void PrintWLine(wchar_t* const pText) final;

            /**
             * @brieft
             * Prints C++ string to console-output.
             *
             * @thread_safety - not required.
             * @param pText - c-string to print (must contain '0'-ending symbol).
             * @throws - can throw exception.
            **/
            virtual void PrintLine(const std::string& pText) final;

            /**
             * @brieft
             * Prints wchar_t C++ string to console-output.
             *
             * @thread_safety - not required.
             * @param pText - wchar_t c-string to print (must contain '0'-ending symbol).
             * @throws - can throw exception.
            **/
            virtual void PrintWLine(const std::wstring& pText) final;

            // ===========================================================
            // METHODS
            // ===========================================================

            // ===========================================================
            // OPERATORS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// console::win::WinConsole

        // -----------------------------------------------------------

    } /// console::win

} /// console
#define ORG_CONSOLE_LIB_WIN_CONSOLE_DECL
using console_t = console::win::WinConsole;

// -----------------------------------------------------------

#endif // !ORG_CONSOLE_LIB_WIN_CONSOLE_HPP