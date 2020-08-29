#include "Sort.h"
#include <iostream>
#include <chrono>		// �ð� ������ ���� ���̺귯��
using namespace std;
using namespace chrono;

void swap(int* a, int* b) {		// swap �Լ�
	int temp = *a;
	*a = *b;
	*b = temp;
};

// 5���� �迭�� ������ ä��� �Լ�
// argument : ���� �迭, ������ 4�� �迭, �迭 ����(n)
void getDataSet(int src[], int cp1[], int cp2[], int cp3[], int cp4[], int len) {
	for (int i = 0; i < len; i++)
		src[i] = rand() % (len * 10);					// 0 ~ (n * 10) ���� ������ ���� �迭�� ä���.

	for (int i = 0; i < len; i++)
		cp1[i] = cp2[i] = cp3[i] = cp4[i] = src[i];		// ���� �迭�� ������ 4���� �迭�� �����Ѵ�.
};

int main() {
	high_resolution_clock::time_point start1, start2, start3, start4, start5;		// �ð� ���� ������
	high_resolution_clock::time_point end1, end2, end3, end4, end5;					// �ð� ���� ����
	milliseconds gap1, gap2, gap3, gap4, gap5;										// �ҿ� �ð��� ����� gap ����
	int a = 0, n = 0, menu = 0;

	cout << "[ 12161756 ����ȣ ]" << endl;
	cout << "������ ���� ũ�⸦ [n = 2^a]���� �����մϴ�" << endl;
	cout << "a���� �Է��մϴ� : ";
	cin >> a;																		// a�� �Է�
	n = (int)pow(2, a);																// n = 2^a
	cout << "\n������ ���� ũ��(n) = " << n;

	int* set1 = new int[n];		int* set2 = new int[n];		int* set3 = new int[n];
	int* set4 = new int[n];		int* set5 = new int[n];								// 5�� �迭 ���� �Ҵ�
	getDataSet(set1, set2, set3, set4, set5, n);									// ������ 5���� ������ �� ����

	// �� ���� �Լ� �յڷ� ���۰� ���� �ð��� ���
	start1 = high_resolution_clock::now();	selection(set1, n);					end1 = high_resolution_clock::now();
	start2 = high_resolution_clock::now();	medianOfThreeQuick(set2, 0, n - 1);	end2 = high_resolution_clock::now();
	start3 = high_resolution_clock::now();	shell(set3, n);						end3 = high_resolution_clock::now();
	start4 = high_resolution_clock::now();	bitonic(set4, 0, n, up);			end4 = high_resolution_clock::now();
	start5 = high_resolution_clock::now();	oddEven(set5, 0, n);				end5 = high_resolution_clock::now();

	// ���� �ҿ� �ð� ��� (���� - ���� �ð�)
	gap1 = duration_cast<milliseconds>(end1 - start1);	gap2 = duration_cast<milliseconds>(end2 - start2);
	gap3 = duration_cast<milliseconds>(end3 - start3);	gap4 = duration_cast<milliseconds>(end4 - start4);
	gap5 = duration_cast<milliseconds>(end5 - start5);

	// �� ���� �˰��� �� �ð� ���
	cout << "\nSelection \t\t= " << gap1.count() << " ms" << endl;
	cout << "Median-of-three Quick \t= " << gap2.count() << " ms" << endl;
	cout << "Shell \t\t\t= " << gap3.count() << " ms" << endl;
	cout << "Bitonic \t\t= " << gap4.count() << " ms" << endl;
	cout << "Odd-Even Merge \t\t= " << gap5.count() << " ms" << endl;

	delete[] set1, set2, set3, set4, set5;									// �޸� ����
	return 0;
}