#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

using RPCClientHandlers = std::vector<std::shared_ptr<rpc::client>>;

class RPCManager
{
public:
    explicit RPCManager( RPCClientHandlers rpcClientHandlers );
    explicit RPCManager( std::shared_ptr<rpc::server> rpcServerHandler );

    template <typename T, typename... Args>
    std::vector<T> CallRPCMethod( const std::string & methodName, Args... args )
    {
        std::vector<T> results;
        for ( auto & rpcClient : mRPCClientHandlers )
        {
            // Type promotion is not included here. May cause conversion problems while aggregatting floatig points
            // Promoted types should be included
            results.push_back( rpcClient->call( methodName, args... ).template as<T>() );
        }

        return results;
    }

    template <typename... Args>
    void CallRPCMethod( const std::string & methodName, Args... args )
    {
        for ( auto & rpcClient : mRPCClientHandlers )
        {
            // Type promotion is not included here. May cause conversion problems while aggregatting floatig points
            // Promoted types should be included
            rpcClient->call( methodName, args... );
        }
    }

    void RunServer();
    void BindMethods();

    std::shared_ptr<rpc::server> GetRPCServer();

private:
    RPCClientHandlers mRPCClientHandlers;
    std::shared_ptr<rpc::server> mRPCServerHandler;
};
