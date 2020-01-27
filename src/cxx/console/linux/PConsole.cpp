/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef ORG_CONSOLE_LIB_POSIX_CONSOLE_HPP
#include "PConsole.hpp"
#endif // !ORG_CONSOLE_LIB_POSIX_CONSOLE_HPP

// Include C++ iostream
#include <iostream> // cin, cout

// ===========================================================
// console::posix::PConsole
// ===========================================================

namespace console
{

    namespace posix
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        PConsole::PConsole() THROWABLE
            : BaseConsole()
        {
        }

        PConsole::~PConsole() THROWABLE
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        IConsole& PConsole::SetTextColor(const EConsoleColors pColor) noexcept
        {
            if (mCurrentForeground == pColor)
                return (*(static_cast<console::IConsole*>(static_cast<console::BaseConsole*>(this))));

            mCurrentForeground = pColor;
            return (*(static_cast<console::IConsole*>(static_cast<console::BaseConsole*>(this))));
        }

        // ===========================================================
        // console::IConsole
        // ===========================================================

        void PConsole::PrintLine(const char* const pText)
        {
            std::cout << pText << std::endl;
        }

        void PConsole::PrintWLine(wchar_t* const pText)
        {
            std::wcout << pText << std::endl;
        }

        void PConsole::PrintLine(const std::string& pText)
        {
            std::cout << pText << std::endl;
        }

        void PConsole::PrintWLine(const std::wstring& pText)
        {
            std::wcout << pText << std::endl;
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        // -----------------------------------------------------------

    } /// console::posix

} /// console

// -----------------------------------------------------------