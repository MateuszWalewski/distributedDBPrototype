#include "TCPClient.h"
#include <Loki/Singleton.h>
#include <ParameterControllerNode/ParameterControllerNode.h>

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace boost::asio;
using ip::tcp;

template void TCPClient::Send<double>( std::vector<double>& data );
template void TCPClient::Send<float>( std::vector<float>& data );
template void TCPClient::Send<int>( std::vector<int>& data );

TCPClient::TCPClient( boost::asio::io_context& io_context ) : resolver( io_context )
{
    socket = std::make_shared<tcp::socket>( io_context );
}

void TCPClient::Connect()
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();
    /// TODO: take the host name from ENV instead of hardcoded value
    boost::asio::ip::tcp::resolver::query query( "hub", std::to_string( pCInstance.GetNodeTCPPort() ) );
    boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve( query );

    socket->connect( iter->endpoint() );
    std::cout << "Connected on port: " << std::to_string( pCInstance.GetNodeTCPPort() ) << '\n';
}

template <typename T>
void TCPClient::Send( std::vector<T>& data )
{
    Connect();
    boost::system::error_code error;
    boost::asio::write( *socket, boost::asio::buffer( data ), error );
    if ( !error )
    {
        std::cout << "Client sent sucessfully!" << '\n';
    }
}
