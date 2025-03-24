#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int person;
    std::cout << "����� ��: ";
    std::cin >> person;

    std::vector<int> time(person);
    for (int i = 0; i < person; i++) {
        std::cin >> time[i];
    }

    // �ǳʴ� �� �ɸ��� �ð��� ������������ ����
    std::sort(time.begin(), time.end());

    int totalTime = 0;
    int n = person; // ���� ����� ��

    // ���� ����� 4�� �̻��� ��쿡 �� ���� ������ ���ϸ鼭 ó��
    while (n > 3) {
        // ���� A: ���� ���� �� ����� �ǳʰ�, ���� ���� ����� ���ƿ���,
        //         ���� ���� �� ����� �ǳʰ�, �� ��°�� ���� ����� ���ƿ�
        int costA = time[0] + 2 * time[1] + time[n - 1];
        // ���� B: ���� ���� ����� ���� ���� ����� �ǳʰ�, ���� ���� ����� ���ƿ���,
        //         ���� ���� ����� �� ��°�� ���� ����� �ǳʰ�, ���� ���� ����� ���ƿ�
        int costB = 2 * time[0] + time[n - 2] + time[n - 1];

        totalTime += std::min(costA, costB);
        n -= 2;
    }

    // ���� �ο��� 3�� ������ �� ó��
    if (n == 3)
        totalTime += time[0] + time[1] + time[2];
    else if (n == 2)
        totalTime += time[1];
    else if (n == 1)
        totalTime += time[0];

    std::cout << "�ּ� �ð�: " << totalTime << std::endl;
    return 0;
}
