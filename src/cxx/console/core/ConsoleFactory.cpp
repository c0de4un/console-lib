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
#ifndef ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP
#include "ConsoleFactory.hpp"
#endif // !ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP

// PLATFORM
#if defined( WIN32 ) || defined( WIN64 ) // Windows

// Include console::WinConsole
#ifndef ORG_CONSOLE_LIB_WIN_CONSOLE_HPP
#include "../windows/WindowsConsole.hpp"
#endif // !ORG_CONSOLE_LIB_WIN_CONSOLE_HPP

#elif defined( LINUX ) || defined( Linux ) || defined( __linux ) || defined( _linux_ )

// Include console::LinuxConsole
#ifndef ORG_CONSOLE_LIB_POSIX_CONSOLE_HPP
#include "../linux/PConsole.hpp"
#endif // !ORG_CONSOLE_LIB_POSIX_CONSOLE_HPP

#else
#error "ConsoleFactory.hpp - can't iclude implementation for current platform, configuration required."
#endif
// PLATFORM

// ===========================================================
// console::ConsoleFactory
// ===========================================================

namespace console
{

    // -----------------------------------------------------------

    // ===========================================================
    // CONSTRUCTOR
    // ===========================================================

    ConsoleFactory::ConsoleFactory() THROWABLE
    {
    }

    // ===========================================================
    // DESTRUCTOR
    // ===========================================================

    ConsoleFactory::~ConsoleFactory() THROWABLE
    {
    }

    // ===========================================================
    // METHODS
    // ===========================================================

    IConsole* ConsoleFactory::Build() THROWABLE
    {
        return new console_t();
    }

    // -----------------------------------------------------------

} /// console

// -----------------------------------------------------------