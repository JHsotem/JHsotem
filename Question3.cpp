#include <iostream>																				// ����� ����� �����ϴ� iostream ���̺귯���� �߰�
#include <fstream>																				// file ����� ����� �����ϴ� fstream ���̺귯���� �߰�
#include <cmath>																				// �ﰢ�Լ� ����� ���� ǥ�ض��̺귯���� cmath�� �߰� 
#include <string>																				// �Լ��� �Է��� ���ڿ��� �����ϱ� ���� string ���̺귯�� �߰�
#include "complex.h"																			// ���Ҽ��� ���Ǹ� ������ ��������� complex.h�� �߰�		
#define cons_PHI 3.141592																		// ����� ���� cons_PHI�� ���� 3.141592�� ��	
using namespace std;																			// ǥ�� namespace�� ���

// x(t)�׷����� ���� ��� ���� �Լ� ���� (��� ��ȣ x(t) ����), S_fre(���ø� ���ļ�), time_name(t�� �����̸�), output_name(��°� �����̸�)
double get_xt_graph(double S_fre, string(time_name), string(output_name)) {
	ofstream data1;																				// ������½�Ʈ�� data1�� ����
	ofstream data2;																				// ������½�Ʈ�� data2�� ����
	data1.open(time_name);																		// data1�� �Ҵ�Ǵ� ���� �̿��� time_name ������ open
	data2.open(output_name);																	// data2�� �Ҵ�Ǵ� ���� �̿��� output_name ������ open
	double fre, t, dt;																			// t, dt�� �Ǽ��� double�� ����
	t = 0;																						// t�� �ʱⰪ: 0 
	fre = 15;																					// x(t)�� fm (2*cons_PHI / 30*cons_PHI)
	dt = 1.0 / S_fre;																			// ���ø� �ֱ� dt�� ���ø� ���ļ��� ���� ��Ÿ�� 
	for (int i = 0; i < 50; i++, t = t + dt) {													// i�� �ʱⰪ�� 0�̸� i�� 50�� �Ǳ� ������ t���� ���ϸ� for�� ���� ������ �ݺ�
		data1 << t << endl;																		// data1�� �־��� t�� ���� ���
		data2 << 2 + 2 * cos(2 * cons_PHI * fre * t - 1.0 / 5 * cons_PHI) + 4 * cos(2 * cons_PHI * fre * t - 1.0 / 4 * cons_PHI) + 3 * cos(2 * cons_PHI * fre * t - 2.0 / 5 * cons_PHI) << endl;
		// data2�� �־��� [x(t) = x1(t) + x2(t) + x3(t) + x4(t)]�� output�� ���
	}
	t = 0;																						// �ʱ�ȭ���� ���� ���� ���� ����
	dt = 0;																						// �ʱ�ȭ���� ���� ���� ���� ����
	return 0;																					// �Լ��� ���ϰ� 0
}

int main()																						// main() �Լ��� ����� �� return���� �������� ����
{

	ofstream out_file1;																			// ������½�Ʈ�� out_file1�� ����
	out_file1.open("sig_magnitude_phase.txt");													// out_file1�� �Ҵ�Ǵ� ���� �̿��� sig_magnitude_phase.txt ������ open

	// Question 3 - (1) 
	complex x1t_com(2, 0);																		// x1(t)�� ���Ҽ��� ǥ�� 2 + 0j
	complex x2t_com(2 * cos(1.0 / 5 * cons_PHI), 2 * sin(1.0 / 5 * cons_PHI));					// x2(t)�� ���Ҽ��� ǥ�� 2cos(1/5*cons_PHI) + 2sin(1/5*cons_PHI)j (amplitude: 2 phase: 1/5 cons_PHI)
	complex x3t_com(4 * cos(1.0 / 4 * cons_PHI), 4 * sin(1.0 / 4 * cons_PHI));					// x3(t)�� ���Ҽ��� ǥ�� 4cos(1/4*cons_PHI) + 4sin(1/4*cons_PHI)j (amplitude: 4 phase: 1/4 cons_PHI)
	complex x4t_com(3 * cos(2.0 / 5 * cons_PHI), 3 * sin(2.0 / 5 * cons_PHI));					// x4(t)�� ���Ҽ��� ǥ�� 3cos(2/5*cons_PHI) + 3sin(2/5*cons_PHI)j (amplitude: 3 phase: 2/5 cons_PHI)
		
	complex sum = x1t_com + x2t_com + x3t_com + x4t_com;										// x1(t), x2(t), x3(t), x3(t)�� ��ģ ��ȣ�� x(t)�� ���Ҽ��� sum�� ����
	out_file1 << "Verify result value : ";														// out_file1�� "Verify result value : "�� ���
	out_file1 << sum.r_E << "+" << sum.i_M << "j" << endl;										// out_file1�� x(t)�� ���Ҽ� ������ sum�� ���
	out_file1 << "Magnitude : ";																// out_file1�� "Magnitude : "�� ���
	out_file1 << sum.magni() << endl;															// out_file1�� x(t)�� amplitude�� ���
	out_file1 << "Phase : ";																	// out_file1�� "Phase : "�� ���			
	out_file1 << sum.gEtphase() << endl;														// out_file1�� x(t)�� phase�� ���
	get_xt_graph(240.0, "time_graph.txt", "sinusoidal_graph.txt");								// sampling frequency�� 240(Hz)�� ���� t�� x(t)�� ��°��� �������� �Լ�

	// Question 3 - (2)	
	get_xt_graph(20.0, "time_graph1.txt", "sinusoidal_graph1.txt");								// sampling frequency�� 20(Hz)�� ���� t�� x(t)�� ��°��� �������� �Լ�
	get_xt_graph(30.0,  "time_graph2.txt", "sinusoidal_graph2.txt");							// sampling frequency�� 30(Hz)�� ���� t�� x(t)�� ��°��� �������� �Լ�
	get_xt_graph(120.0,  "time_graph3.txt", "sinusoidal_graph3.txt");							// sampling frequency�� 120(Hz)�� ���� t�� x(t)�� ��°��� �������� �Լ�
}