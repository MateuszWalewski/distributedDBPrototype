#include "Context/GlobalContextNode.h"
#include "ParameterController/ParameterControllerNode.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    PCTRL().LoadNodeConnectionInfo( argv );
    PCTRL().PrintNodeConnectionInfo();

    CTX().GetSessionHandler().BindMethods();
    CTX().GetSessionHandler().RunServer();

    return 0;
}
