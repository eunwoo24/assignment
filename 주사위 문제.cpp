#include <iostream>
#include <bitset>

// ������ ��Ģ�� 2^n�̴� -> ���� n�� 2������ ��ȯ�ϸ� �Ǵ� ������ �����̴�
// bitset���� 2������ ��ȯ�Ѵ�

int main()
{
	unsigned int n;
	scanf_s("%d", &n);

	std::bitset<32> binary(n);

    std::string binaryString = binary.to_string();

    // ���� 0�� ����
    size_t firstOne = binaryString.find('1');
    if (firstOne != std::string::npos) {
        binaryString = binaryString.substr(firstOne);
    }
    else {
        // ��� ��Ʈ�� 0�� ���
        binaryString = "0";
    }

    std::cout << "�ֻ��� ����: " << binaryString << std::endl;

	return 0;
}