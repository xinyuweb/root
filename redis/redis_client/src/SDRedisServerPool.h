#ifndef __SD_REDIS_SERVER_POOL_H__
#define __SD_REDIS_SERVER_POOL_H__

#include "SDRedisServer.h"
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>

#include <string>


class SDRedisServerPool : boost::noncopyable
{
public:
	SDRedisServerPool(const std::string& host, uint16_t port, uint16_t db_index);
	~SDRedisServerPool();

	SDRedisServer_ptr get();

	//return back redis server to pool
	//void put(SDRedisServer_ptr redis_server);
    void put(SDRedisServer* redis_server);

	inline std::string	get_host() const {return m_host;}
	inline uint16_t	get_port() const {return m_port;}
	inline uint16_t get_db_index() const {return m_db_index;}
		
private:
	
	std::string m_host;
	uint16_t	m_port;
	uint16_t m_db_index;
    boost::mutex m_mutex;
    int m_conn_num;
	
	list<SDRedisServer_ptr> m_conn_ptrs;

 private:
 	DECL_LOGGER(logger);
	
};

typedef boost::shared_ptr<SDRedisServerPool> SDRedisServerPool_ptr;

#endif // __SD_REDIS_SERVER_POOL_H__

