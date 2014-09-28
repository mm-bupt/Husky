/*
 * =====================================================================================
 *        Class:  Director
 *  Description:  
 * =====================================================================================
 */
class Director
{
	public:
		static Director& GetInstance();
		~Director(){ return; };
		bool init();
		void start();
	protected:
		Director();                             /* constructor */
		Director(const Director &);
		Director& operator=(const Director &);

	private:
		bool initInternet(unsigned short usPort);
		bool initEpoll(int event_count);

		int m_listen_sock;
        int m_epoll_fd;
		int m_max_count;
		struct epoll_event *m_epoll_events;

		static Director instance_;
		Player * CPlayerFactory;
		GameFactory * CGameFactory;
		MMSocket *socket;
		MMTimer  *timer;
		MMEPOLL  *epoll;
}; /* -----  end of class Director  ----- */

