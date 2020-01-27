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
#ifndef ORG_CONSOLE_LIB_WIN_CONSOLE_HPP
#include "WindowsConsole.hpp"
#endif // !ORG_CONSOLE_LIB_WIN_CONSOLE_HPP

// Include Windows API
#include <Windows.h>

// ===========================================================
// console::win::WinConsole
// ===========================================================

namespace console
{

    namespace win
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        WinConsole::WinConsole() THROWABLE
            : BaseConsole(),
            mOutBuf()
        {
            SetConsoleOutputCP(CP_UTF8);
            setvbuf(stdout, nullptr, _IONBF, 0); // @see http://www.cplusplus.com/reference/cstdio/setvbuf/
            std::cout.rdbuf(&mOutBuf);
        }

        WinConsole::~WinConsole() THROWABLE
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        IConsole& WinConsole::SetTextColor(const EConsoleColors pColor) noexcept
        {

            if (mCurrentForeground == pColor)
                return ( *(static_cast<console::IConsole*>(static_cast<console::BaseConsole*>(this))) );

            mCurrentForeground = pColor;

            HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

            switch (mCurrentForeground)
            {
            case EConsoleColors::GREEN:
            {
                SetConsoleTextAttribute(hConsoleHandle, 10 | 0);
            }
                break;
            case EConsoleColors::RED:
            {
                SetConsoleTextAttribute(hConsoleHandle, 12 | 0);
            }
                break;
            case EConsoleColors::YELLOW:
            {
                SetConsoleTextAttribute(hConsoleHandle, 14 | 0);
            }
                break;
            case EConsoleColors::PINK:
            {
                SetConsoleTextAttribute(hConsoleHandle, 13 | 0);
            }
                break;
            case EConsoleColors::BLUE:
            {
                SetConsoleTextAttribute(hConsoleHandle, 9 | 0);
            }
                break;
            case EConsoleColors::BLACK:
            case EConsoleColors::WHITE:
            default:
                SetConsoleTextAttribute(hConsoleHandle, 15 | 0);
                break;
            }

            return (*(static_cast<console::IConsole*>(static_cast<console::BaseConsole*>(this))));
        }

        // ===========================================================
        // console::IConsole
        // ===========================================================

        void WinConsole::PrintLine(const char* const pText)
        {
            std::cout << pText << std::endl;
        }

        void WinConsole::PrintWLine(wchar_t* const pText)
        {
            std::wcout << pText << std::endl;
        }

        void WinConsole::PrintLine(const std::string& pText)
        {
            std::cout << pText << std::endl;
        }

        void WinConsole::PrintWLine(const std::wstring& pText)
        {
            std::wcout << pText << std::endl;
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        // -----------------------------------------------------------

    } /// console::win

} /// console

// -----------------------------------------------------------