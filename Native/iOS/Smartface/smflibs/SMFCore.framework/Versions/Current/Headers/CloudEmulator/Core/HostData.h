#ifndef __SF_CLOUDEMULATOR_HOSTDATA_H__
#define __SF_CLOUDEMULATOR_HOSTDATA_H__

#include "Poco/URI.h"

#include <string>

/**
 *  HostData class represents the dispatcher host information of a cloud Smartface Workspace.
 */
class HostData 
{
public:
  /**
   *  Resolves dispatcher host information from given url.
   */
  HostData(const std::string& url);

  /**
   *  Gets dispatcher host url.
   */
  std::string getHost() const;
  /**
   *  Gets dispatcher uri
   */
  std::string getUri() const;
  /**
   *  Gets dispatcher port.
   */
  int getPort() const;
  /**
   *  Gets protocol version of QR code.
   */
  std::string getProtocolVersion() const;
  /**
   *  Gets minimum supported version of dispatcher.
   */
  std::string getMinimumSupportedVersion() const;
  /**
   *  Gets guid of browser that runs Cloud IDE.
   */
  std::string getBrowserGuid() const;
  /**
   *  Gets security guid of browser.
   */
  std::string getSecurityGuid() const;
  /**
   *  Gets if connection should open in secure mode or not.
   */
  bool getSsl() const;
  /**
   *  Gets if protocol is valid.
   */
  bool isValid() const;

private:
  std::string host = "";
  std::string uri = "";
  int port = 0;
  std::string protocolVersion = "";
  std::string minimumSupportedVersion = "";
  std::string browserGuid = "";
  std::string securityGuid = "";
  bool ssl = true;

  void parseParameters(const Poco::URI::QueryParameters& parameters);
};

#endif // __SF_CLOUDEMULATOR_HOSTDATA_H__