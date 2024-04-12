#include "View.h"
#include "ViewOther.h"

int main() {
    View* view;
    view= new View();
    //view= new ViewOther();
    view->RunGame();
    if(view){
        delete view;
    }

    return 0;
}
