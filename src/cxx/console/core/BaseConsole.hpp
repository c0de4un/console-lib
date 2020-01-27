/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_HPP
#define ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include console::IConsole.hpp
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
     * BaseConsole - base abstract class of Console-utility.
     *
     * @version 1.0
     * @since 26.01.2020
     * @authors Denis Z. (code4un@yandex.ru)
    **/
    class BaseConsole : public IConsole
    {

    private:

        // -----------------------------------------------------------

        // ===========================================================
        // DELETED
        // ===========================================================

        BaseConsole(const BaseConsole&) = delete;
        BaseConsole& operator=(const BaseConsole&) = delete;
        BaseConsole(BaseConsole&&) = delete;
        BaseConsole& operator=(BaseConsole&&) = delete;

        // -----------------------------------------------------------

    protected:

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        /** Current Text Color. **/
        EConsoleColors mCurrentForeground;

        // ===========================================================
        // CONSTRUCTOR
        // ===========================================================

        /**
         * @brief
         * BaseConsole constructor.
         *
         * @throws - can throw out-of-memory exceptions.
        **/
        explicit BaseConsole() THROWABLE;

        // -----------------------------------------------------------

    public:

        // -----------------------------------------------------------

        // ===========================================================
        // DESTRUCTOR
        // ===========================================================

        /**
         * @brief
         * BaseConsole destructor.
         *
         * @throws - can throw access-violation exceptions.
        **/
        virtual ~BaseConsole() THROWABLE;

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        // ===========================================================
        // console::IConsole
        // ===========================================================

        // ===========================================================
        // METHODS
        // ===========================================================

        // -----------------------------------------------------------

    }; /// console::BaseConsole

    // -----------------------------------------------------------

} /// console
#define ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_DECL

// -----------------------------------------------------------

#endif // !ORG_CONSOLE_LIB_CORE_BASE_CONSOLE_HPP