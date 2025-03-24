#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int person;
    std::cout << "사람의 수: ";
    std::cin >> person;

    std::vector<int> time(person);
    for (int i = 0; i < person; i++) {
        std::cin >> time[i];
    }

    // 건너는 데 걸리는 시간을 오름차순으로 정렬
    std::sort(time.begin(), time.end());

    int totalTime = 0;
    int n = person; // 남은 사람의 수

    // 남은 사람이 4명 이상일 경우에 두 가지 전략을 비교하면서 처리
    while (n > 3) {
        // 전략 A: 가장 빠른 두 사람이 건너고, 가장 빠른 사람이 돌아오고,
        //         가장 느린 두 사람이 건너고, 두 번째로 빠른 사람이 돌아옴
        int costA = time[0] + 2 * time[1] + time[n - 1];
        // 전략 B: 가장 빠른 사람과 가장 느린 사람이 건너고, 가장 빠른 사람이 돌아오고,
        //         가장 빠른 사람과 두 번째로 느린 사람이 건너고, 가장 빠른 사람이 돌아옴
        int costB = 2 * time[0] + time[n - 2] + time[n - 1];

        totalTime += std::min(costA, costB);
        n -= 2;
    }

    // 남은 인원이 3명 이하일 때 처리
    if (n == 3)
        totalTime += time[0] + time[1] + time[2];
    else if (n == 2)
        totalTime += time[1];
    else if (n == 1)
        totalTime += time[0];

    std::cout << "최소 시간: " << totalTime << std::endl;
    return 0;
}
