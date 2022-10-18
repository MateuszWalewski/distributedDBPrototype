#include "GlobalContextNode.h"
#include "ParameterControllerNode/ParameterControllerNode.h"
#include <iostream>

GlobalContextNode::GlobalContextNode()
{
    mRPCManager =
        std::make_shared<RPCManager>( std::make_shared<rpc::server>( PCTRL().GetNodeIP(), std::stoi( PCTRL().GetNodePort() ) ) );

    std::cout << "GlobalContextNode called" << std::endl;
}

GlobalContextNode & GlobalContextNode::Instance()
{
    static GlobalContextNode instance;
    return instance;
}

RPCManager & GlobalContextNode::GetRPCManager()
{
    return *mRPCManager;
}
