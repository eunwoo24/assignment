#include <iostream>
#include <bitset>

// 수열의 규칙이 2^n이다 -> 따라서 n을 2진수로 변환하면 되는 간단한 문제이다
// bitset으로 2진수로 변환한다

int main()
{
	unsigned int n;
	scanf_s("%d", &n);

	std::bitset<32> binary(n);

    std::string binaryString = binary.to_string();

    // 앞의 0을 제거
    size_t firstOne = binaryString.find('1');
    if (firstOne != std::string::npos) {
        binaryString = binaryString.substr(firstOne);
    }
    else {
        // 모든 비트가 0인 경우
        binaryString = "0";
    }

    std::cout << "주사위 수열: " << binaryString << std::endl;

	return 0;
}