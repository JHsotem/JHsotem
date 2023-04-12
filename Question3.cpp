#include <iostream>																				// 입출력 기능을 제공하는 iostream 라이브러리를 추가
#include <fstream>																				// file 입출력 기능을 제공하는 fstream 라이브러리를 추가
#include <cmath>																				// 삼각함수 계산을 위해 표준라이브러리인 cmath를 추가 
#include <string>																				// 함수의 입력을 문자열로 선언하기 위해 string 라이브러리 추가
#include "complex.h"																			// 복소수의 정의를 정리한 헤더파일인 complex.h를 추가		
#define cons_PHI 3.141592																		// 계산을 위해 cons_PHI의 값을 3.141592로 함	
using namespace std;																			// 표준 namespace를 사용

// x(t)그래프를 쉽게 얻기 위해 함수 선언 (출력 신호 x(t) 고정), S_fre(샘플링 주파수), time_name(t값 파일이름), output_name(출력값 파일이름)
double get_xt_graph(double S_fre, string(time_name), string(output_name)) {
	ofstream data1;																				// 파일출력스트림 data1를 선언
	ofstream data2;																				// 파일출력스트림 data2를 선언
	data1.open(time_name);																		// data1에 할당되는 값을 이용해 time_name 파일을 open
	data2.open(output_name);																	// data2에 할당되는 값을 이용해 output_name 파일을 open
	double fre, t, dt;																			// t, dt를 실수형 double로 선언
	t = 0;																						// t의 초기값: 0 
	fre = 15;																					// x(t)의 fm (2*cons_PHI / 30*cons_PHI)
	dt = 1.0 / S_fre;																			// 샘플링 주기 dt를 샘플링 주파수를 통해 나타냄 
	for (int i = 0; i < 50; i++, t = t + dt) {													// i의 초기값이 0이며 i가 50이 되기 전까지 t값이 변하며 for문 안의 내용을 반복
		data1 << t << endl;																		// data1에 주어진 t의 값을 출력
		data2 << 2 + 2 * cos(2 * cons_PHI * fre * t - 1.0 / 5 * cons_PHI) + 4 * cos(2 * cons_PHI * fre * t - 1.0 / 4 * cons_PHI) + 3 * cos(2 * cons_PHI * fre * t - 2.0 / 5 * cons_PHI) << endl;
		// data2에 주어진 [x(t) = x1(t) + x2(t) + x3(t) + x4(t)]의 output을 출력
	}
	t = 0;																						// 초기화되지 않은 변수 오류 방지
	dt = 0;																						// 초기화되지 않은 변수 오류 방지
	return 0;																					// 함수의 리턴값 0
}

int main()																						// main() 함수가 종료될 때 return값을 정수형을 받음
{

	ofstream out_file1;																			// 파일출력스트림 out_file1을 선언
	out_file1.open("sig_magnitude_phase.txt");													// out_file1에 할당되는 값을 이용해 sig_magnitude_phase.txt 파일을 open

	// Question 3 - (1) 
	complex x1t_com(2, 0);																		// x1(t)를 복소수로 표현 2 + 0j
	complex x2t_com(2 * cos(1.0 / 5 * cons_PHI), 2 * sin(1.0 / 5 * cons_PHI));					// x2(t)를 복소수로 표현 2cos(1/5*cons_PHI) + 2sin(1/5*cons_PHI)j (amplitude: 2 phase: 1/5 cons_PHI)
	complex x3t_com(4 * cos(1.0 / 4 * cons_PHI), 4 * sin(1.0 / 4 * cons_PHI));					// x3(t)를 복소수로 표현 4cos(1/4*cons_PHI) + 4sin(1/4*cons_PHI)j (amplitude: 4 phase: 1/4 cons_PHI)
	complex x4t_com(3 * cos(2.0 / 5 * cons_PHI), 3 * sin(2.0 / 5 * cons_PHI));					// x4(t)를 복소수로 표현 3cos(2/5*cons_PHI) + 3sin(2/5*cons_PHI)j (amplitude: 3 phase: 2/5 cons_PHI)
		
	complex sum = x1t_com + x2t_com + x3t_com + x4t_com;										// x1(t), x2(t), x3(t), x3(t)를 합친 신호인 x(t)의 복소수인 sum을 구함
	out_file1 << "Verify result value : ";														// out_file1에 "Verify result value : "을 출력
	out_file1 << sum.r_E << "+" << sum.i_M << "j" << endl;										// out_file1에 x(t)의 복소수 형태인 sum을 출력
	out_file1 << "Magnitude : ";																// out_file1에 "Magnitude : "을 출력
	out_file1 << sum.magni() << endl;															// out_file1에 x(t)의 amplitude를 출력
	out_file1 << "Phase : ";																	// out_file1에 "Phase : "을 출력			
	out_file1 << sum.gEtphase() << endl;														// out_file1에 x(t)의 phase를 출력
	get_xt_graph(240.0, "time_graph.txt", "sinusoidal_graph.txt");								// sampling frequency가 240(Hz)일 때의 t와 x(t)의 출력값을 가져오는 함수

	// Question 3 - (2)	
	get_xt_graph(20.0, "time_graph1.txt", "sinusoidal_graph1.txt");								// sampling frequency가 20(Hz)일 때의 t와 x(t)의 출력값을 가져오는 함수
	get_xt_graph(30.0,  "time_graph2.txt", "sinusoidal_graph2.txt");							// sampling frequency가 30(Hz)일 때의 t와 x(t)의 출력값을 가져오는 함수
	get_xt_graph(120.0,  "time_graph3.txt", "sinusoidal_graph3.txt");							// sampling frequency가 120(Hz)일 때의 t와 x(t)의 출력값을 가져오는 함수
}