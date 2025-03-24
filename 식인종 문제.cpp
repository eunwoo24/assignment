#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

// BFS, �� �ʺ� �켱 Ž������ ������ �ذ��� ����
// BFS�� �ִ� ��θ� ã�� �� ����� �� �ִ� �˰����̴�

struct State {
    int missionariesUnder;
    int cannibalsUnder;
    int missionariesOver;
    int cannibalsOver;
    bool boatOnUnder;
    int steps;

    // ���� ���°� ��ȿ���� Ȯ���ϴ� �Լ�
    bool isValid() const {
        if (missionariesUnder < 0 || cannibalsUnder < 0 || missionariesOver < 0 || cannibalsOver < 0)
            return false;
        if ((missionariesUnder > 0 && cannibalsUnder > missionariesUnder) ||
            (missionariesOver > 0 && cannibalsOver > missionariesOver))
            return false;
        return true;
    }

    // ��ǥ �������� Ȯ���ϴ� �Լ�
    bool isGoal() const {
        return missionariesUnder == 0 && cannibalsUnder == 0;
    }

    // ���¸� ���ϴ� ������ �����ε�
    bool operator<(const State& other) const {
        return std::tie(missionariesUnder, cannibalsUnder, missionariesOver, cannibalsOver, boatOnUnder) <
            std::tie(other.missionariesUnder, other.cannibalsUnder, other.missionariesOver, other.cannibalsOver, other.boatOnUnder);
    }
};

int main() {
    int n;
    std::cout << "�������� �������� ���� �Է��ϼ���: ";
    std::cin >> n;

    std::queue<State> q; // BFS�� ���� ť
    std::set<State> visited; // �湮�� ���¸� �����ϴ� ����

    // �ʱ� ���� ����
    State initialState = { n, n, 0, 0, true, 0 };
    q.push(initialState);
    visited.insert(initialState);

    // ������ �̵� ����
    std::vector<std::pair<int, int>> moves = { {1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1} };

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // ��ǥ ���¿� �����ߴ��� Ȯ��
        if (current.isGoal()) {
            std::cout << "�ּ� Ƚ��: " << current.steps << std::endl;
            return 0;
        }

        // ������ ��� �̵��� �õ�
        for (const auto& move : moves) {
            State next = current;
            next.steps++;

            if (current.boatOnUnder) {
                next.missionariesUnder -= move.first;
                next.cannibalsUnder -= move.second;
                next.missionariesOver += move.first;
                next.cannibalsOver += move.second;
            }
            else {
                next.missionariesUnder += move.first;
                next.cannibalsUnder += move.second;
                next.missionariesOver -= move.first;
                next.cannibalsOver -= move.second;
            }

            next.boatOnUnder = !current.boatOnUnder;

            // ���� ���°� ��ȿ�ϰ� �湮���� ���� �������� Ȯ��
            if (next.isValid() && visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
            }
        }
    }

    std::cout << "�ذ��� �� �����ϴ�." << std::endl;
    return 0;
}
