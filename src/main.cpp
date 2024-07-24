/* date = April 07, 2024 4:09 PM */

#include <iostream>
#include <vector>
#include <string>
#include "App.h"
#include "scenes/BouncyRectangles.h"
#include "scenes/Painter.h"

using namespace std;
using namespace MiniMario;

int main() {
    cout << "hello pookie bear";
    cout << flush;

    auto *app = App::get();
    app->setScene(new BouncyRectangles());
    app->run();

    return 0;
}
