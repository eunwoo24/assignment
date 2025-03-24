#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

// BFS, 즉 너비 우선 탐색으로 문제를 해결해 본다
// BFS는 최단 경로를 찾을 때 사용할 수 있는 알고리즘이다

struct State {
    int missionariesUnder;
    int cannibalsUnder;
    int missionariesOver;
    int cannibalsOver;
    bool boatOnUnder;
    int steps;

    // 현재 상태가 유효한지 확인하는 함수
    bool isValid() const {
        if (missionariesUnder < 0 || cannibalsUnder < 0 || missionariesOver < 0 || cannibalsOver < 0)
            return false;
        if ((missionariesUnder > 0 && cannibalsUnder > missionariesUnder) ||
            (missionariesOver > 0 && cannibalsOver > missionariesOver))
            return false;
        return true;
    }

    // 목표 상태인지 확인하는 함수
    bool isGoal() const {
        return missionariesUnder == 0 && cannibalsUnder == 0;
    }

    // 상태를 비교하는 연산자 오버로딩
    bool operator<(const State& other) const {
        return std::tie(missionariesUnder, cannibalsUnder, missionariesOver, cannibalsOver, boatOnUnder) <
            std::tie(other.missionariesUnder, other.cannibalsUnder, other.missionariesOver, other.cannibalsOver, other.boatOnUnder);
    }
};

int main() {
    int n;
    std::cout << "식인종과 선교사의 수를 입력하세요: ";
    std::cin >> n;

    std::queue<State> q; // BFS를 위한 큐
    std::set<State> visited; // 방문한 상태를 저장하는 집합

    // 초기 상태 설정
    State initialState = { n, n, 0, 0, true, 0 };
    q.push(initialState);
    visited.insert(initialState);

    // 가능한 이동 조합
    std::vector<std::pair<int, int>> moves = { {1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1} };

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // 목표 상태에 도달했는지 확인
        if (current.isGoal()) {
            std::cout << "최소 횟수: " << current.steps << std::endl;
            return 0;
        }

        // 가능한 모든 이동을 시도
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

            // 다음 상태가 유효하고 방문하지 않은 상태인지 확인
            if (next.isValid() && visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
            }
        }
    }

    std::cout << "해결할 수 없습니다." << std::endl;
    return 0;
}
