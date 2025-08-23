long long inner_point2(int r) { // ≤ r (경계 포함)
    long long cnt = 0;
    long long y = 1;
    for (long long x = 1; x <= r; ++x) {
        while ( (long long)(r - y)*(r - y) + x*x > 1LL*r*r ) ++y;
        cnt += (long long)(r - y) * 2 + 1; // 2*K + 1
    }
    return cnt * 2 + 2LL*r + 1; // x=0 축(2r+1) 추가
}

long long inner_point1(int r) { // < r (경계 제외)
    long long cnt = 0;
    long long y = 1;
    for (long long x = 1; x < r; ++x) {
        while ( (long long)(r - y)*(r - y) + x*x >= 1LL*r*r ) ++y;
        cnt += (long long)(r - y) * 2 + 1;
    }
    return cnt * 2 + 2LL*r - 1; // x=0 축은 2(r-1)+1 = 2r-1
}

long long solution(int r1, int r2) {
    return inner_point2(r2) - inner_point1(r1); // ★ 특수처리 제거
}
