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
#ifndef ORG_CONSOLE_LIB_CORE_CONSOLE_HPP
#include "Console.hpp"
#endif // !ORG_CONSOLE_LIB_CORE_CONSOLE_HPP

// Include console::ConsoleFactory
#ifndef ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP
#include "ConsoleFactory.hpp"
#endif // !ORG_CONSOLE_LIB_CORE_CONSOLE_FACTORY_HPP

// ===========================================================
// Console
// ===========================================================

namespace console
{

    // -----------------------------------------------------------

    // ===========================================================
    // FIELDS
    // ===========================================================

    IConsole* Console::mConsoleInstance(nullptr);

    // ===========================================================
    // CONSTRUCTORS & DESTRUCTOR
    // ===========================================================

    Console::Console() THROWABLE
    {
    }

    Console::~Console() THROWABLE
    {
    }

    // ===========================================================
    // GETTERS & SETTERS
    // ===========================================================

    IConsole& Console::inst() THROWABLE
    {
        return *mConsoleInstance;
    }

    // ===========================================================
    // METHODS
    // ===========================================================

    bool Console::Initialize() THROWABLE
    {
        if (!mConsoleInstance)
        {
            mConsoleInstance = ConsoleFactory::Build();
        }

        return mConsoleInstance;
    }

    void Console::Terminate() THROWABLE
    {
        delete mConsoleInstance;
        mConsoleInstance = nullptr;
    }

    // -----------------------------------------------------------

}

// -----------------------------------------------------------