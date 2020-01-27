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
#include "main.hpp"

// ===========================================================
// MAIN
// ===========================================================

int main()
{
    // Initialize console-lib
    console_lib::Initialize();
    console_lib::inst().SetTextColor(console_color_t::YELLOW).PrintLine(u8"Привет Мир !");

    // Wait Input.
    std::cin.get();

    // Release console-lib
    console_lib::Terminate();

    // OK
    return 0;
}

// -----------------------------------------------------------