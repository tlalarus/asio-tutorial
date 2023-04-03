//
// Created by minkyung on 23. 4. 3.
//

#include <iostream>
#include <boost/asio.hpp>

// 타이머를 비동기식으로 사용하는 예제
// reference

// asio의 비동기는 비동기 작업 완료 후 호출되는 콜백함수를 의미한다.
// 비동기 대기가 끝나면 호출되는 print 함수를 정의 한다.
void print(const boost::system::error_code& ){
	std::cout << "Hello, world!" << std::endl;
}

int main(){
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	// timer1 예제와 달리, 비동기 대기를 수행하는 async_wait 함수를 호출한다.
	// timer가 만료되면 등록한 print함수가 호출된다.
	t.async_wait(&print);

	// asio 라이브러리는 현재 io_context::run()을 호출한 스레드에서만 콜백 핸들러가 호출되도록 보장한다.
	// 따라서 io_context::run() 함수는 비동기 대기 완료를 위한 콜백이 호출되지 않는한 호출되지 않는다.

	std::cout << "wait..." << std::endl;
	io.run();
	std::cout << "done..." << std::endl;

	return 0;
}