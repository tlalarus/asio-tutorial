//
// Created by minkyung on 23. 4. 3.
//

#include <iostream>
#include <boost/asio.hpp>

// 타이머를 동기식으로 사용하는 예제
int main(){

	// io 기능을 담당하는 컨텍스트 객체를 선언한다.
	boost::asio::io_context io;

	// 두번째 인자는 타이머가 종료되는 시간: 5초 후 만료됨.
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	// 타이머가 만료될 때까지 반환되지 않는다.
	// 타이머는 항상 "expired" 또는 "not expired" 중 하나 이다.
	t.wait();

	std::cout << "Timer expired" << std::endl;
	return 0;
}