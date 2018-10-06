//#pragma once

#ifndef IO_H
#define IO_H

enum class Response
{
	NO,
	YES,
	INVALID,
};

Response userVerify(std::string);

#endif
