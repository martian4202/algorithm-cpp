#pragma once

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <string>

class HttpClient {
public:
	HttpClient();
	~HttpClient();

	int Post(const std::string& url, const std::string)
};
#endif // !__CLIENT_H__

